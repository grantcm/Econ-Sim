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
    struct request {
        //Trading partner
        business * partner;
        //Owner of request
        business * owner;
        //True indicates import, false export
        bool isComponent;
        //Good we are trading
        Good * good;
        //quantity of good traded
        int quantity;
    };
    
    string name;
    set<consumer *> employees;
    //each company has a unique request queue
    queue<request> requestQueue;
    //map of company names to requests
    map<string, request> existingRequests;
    //inventory of components and output
    map<string, int> inventory;
    Good * product;
    //Indicates whether a request has been made to another business
    bool madeRequest;
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
    void removeEmployee (string);
    inline int getOperatingRevenue() { return price*quantity - cost*quantity; }
    void addRequest(business * ,bool , int);
    void addRequest(request);
    inline request getRequest() { return requestQueue.front(); }
    void popRequest();
    inline request * getRequest(string name) { return &existingRequests[name]; }
    void run ();
    bool isRunnable ();
    void syncInventory ();
    bool canHandleRequest (request);
    void setupProduction ();
};


#endif /* business_hpp */
