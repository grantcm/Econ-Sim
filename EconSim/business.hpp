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
#include <iostream>

#include "consumer.hpp"
#include "good.h"

class business {
    string name;
    set<consumer *> employees;
    Good * product;
public:
    inline business () {}
    inline business (string newName, Good * newGood, set<consumer *> _employees) : name(newName), product(newGood) {
        for (consumer * c: employees) {
            if (!c->getEmployed()){
                c->setEmployed(true);
                c->setEmployer(name);
                addEmployee(c);
            }
        }
    }
    inline string getName () { return name;}
    inline Good getProduct () { return *product;}
    inline void printBusiness () { cout<<name<<": "<<product->getName()<<endl;}
    inline void addEmployee (consumer * newEmp) { employees.insert(newEmp);}
    inline void removeEmployee (string name) { /*TODO*/ }
};


#endif /* business_hpp */
