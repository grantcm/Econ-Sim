//
//  business
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef business_hpp
#define business_hpp
#include <string>
#include <set>
#include <queue>
#include <iostream>
#include <map>

#include "consumer.hpp"
#include "good.h"

class business {
    
    struct deal {
        //Trading partner
        business * partner;
        //True indicates import, false export
        bool isComponent;
        //Good we are trading
        Good * good;
        //quantity of good traded
        int quantity;
    };
    
    string name;
    set<consumer *> employees;
    queue<deal> requestQueue;
    map<string, deal> existingDeals;
    map<string, int> inventory;
    Good * product;
    
    //cost and price are per unit
    int cost, price;
    
    int quantity;
    

    
public:
    inline business () {}
    business (string newName, Good * newGood, set<consumer *> _employees);
    inline string getName () { return name;}
    inline Good getProduct () { return *product;}
    inline void printBusiness () { cout<<name<<": "<<product->getName()<<endl;}
    inline void addEmployee (consumer * newEmp) { employees.insert(newEmp);}
    inline void removeEmployee (string name) { /*TODO*/ }
    inline int getOperatingRevenue() { return price*quantity - cost*quantity; }
    void addRequest(business * ,bool , int);
    void addRequest(deal);
    inline deal getRequest() { return requestQueue.front(); }
    inline void popRequest() { requestQueue.pop(); }
    inline void addDeal(deal toAdd) {existingDeals[toAdd.good->getName()] = toAdd;}
    inline deal * getDeal(string name) { return &existingDeals[name]; }
    void run ();
    void syncInventory ();
    bool canHandleRequest (deal request);
    void setupProduction ();
};


#endif /* business_hpp */
