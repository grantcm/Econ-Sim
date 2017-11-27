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
bool business::run(){
    request current = getRequest();
    if (canHandleRequest(current) && current.handled == false) {
        updateExistingRequests(current);
        //Decrement inventory
        inventory[current.good->getName()] -= current.quantity;
        popRequest();
        return true;
    } else {
        //Need to request
        return false;
    }
}

void business::updateExistingRequests(request current) {
    if (existingRequests.count(current.partner->getName()) == 0) {
        existingRequests[current.partner->getName()] = current;
    } else {
        //Update value
        existingRequests[current.partner->getName()].quantity += current.quantity;
    }
}

//Indicates whether the request queue is empty
bool business::isRunnable() {
    return !requestQueue.empty();
}

//Check if the inventory has enough goods to handle the new request
bool business::canHandleRequest(request request ) {
    return inventory[request.good->getName()] >= request.quantity;
}
void business::addRequest(business * from, bool type, int quantity) {
    cout<<"Requesting good: "<<product->getName()<<" for: "<<from->getName()<<" from: "<<name<<endl;
    requestQueue.push(request {from, this, type, false, product, quantity});
}

void business::addRequest(request request) {
    cout<<"Requesting good: "<<request.good->getName()<<" for: "<<request.partner->getName()<<" from: "<<name<<endl;
    requestQueue.push(request);
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
