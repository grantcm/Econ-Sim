//
//  business.cpp
//  EconSim
//
//  Created by Grant Miller on 11/9/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include <stdio.h>
#include "business.hpp"

business::business (string newName, Good * newGood, set<consumer *> _employees) : name(newName), product(newGood) {
    for (consumer * c: _employees) {
        if (!c->getEmployed()){
            c->setEmployed(true);
            c->setEmployer(name);
            addEmployee(c);
        }
    }
}

/*
 When running, look at price of good in market and current cost
 If profit can be increased then increase production, otherwise try to mitigate costs
 */
void business::run(){
    if (isRunnable()) {
        request current = getRequest();
        syncInventory();
        if (canHandleRequest(current)) {
            addRequest(current);
            syncInventory();
            popRequest();
        }
    }
}

//Indicates whether the request queue is empty
bool business::isRunnable() {
    return !requestQueue.empty();
}

//Check if the inventory has enough goods to handle the new request, if not then spawn new requests to increase inventory
bool business::canHandleRequest(request request ) {
    bool canHandle = true;
    for (auto p: inventory) {
        if (request.quantity > p.second - quantity) {
            //go to existing requests and request more goods from other company
            struct request currentRequest = existingRequests[request.good->getName()];
            //Create new request for the good we need at the quantity we lack
            struct request newRequest = {currentRequest.partner, this, true, currentRequest.good, p.second - quantity};
            cout<<"Creating new request from "<<currentRequest.partner<<" for "<<currentRequest.good<<" amount: "
            <<p.second-quantity<<endl;
            currentRequest.partner->addRequest(newRequest);
            canHandle = false;
        }
    }
    
    return canHandle;
}
void business::addRequest(business * from, bool type, int quantity) {
    cout<<"Requesting good: "<<product->getName()<<" for: "<<from->getName()<<" from: "<<name<<endl;
    requestQueue.push(request {from, this, type, product, quantity});
    madeRequest = true;
}

void business::addRequest(request request) {
    cout<<"Requesting good: "<<request.good->getName()<<" for: "<<request.partner->getName()<<" from: "<<name<<endl;
    requestQueue.push(request);
    madeRequest = true;
}


void business::syncInventory() {
    for ( auto p: existingRequests) {
        if (inventory[p.first] != p.second.quantity) {
            inventory[p.first] = p.second.quantity;
            cout<<"Updated inventory for "<<this->getName()<<endl<<"Updated "<<p.first<<" to amt: "<<p.second.quantity<<endl;
        }
    }
}

//For now just sell product at a price 3 above cost
//TODO: Use elasticity and market demand/supply to calculate ideal selling price
void business::setupProduction() {
    cost = product->getCost();
    price = cost + 3;
}

void business::removeEmployee(string toRemove){
    for (consumer * p: employees){
        if (p->getName()==toRemove) {
            employees.erase(p);
            break;
        }
    }
}

void business::popRequest() {
    requestQueue.pop();
}
