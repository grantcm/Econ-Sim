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
#include <iostream>
#include "good.h"

class business {
    string name;
    Good * product;
public:
    inline business () {}
    inline business (string newName, Good * newGood) : name(newName), product(newGood) {}
    inline string getName () { return name;}
    inline Good getProduct () { return *product;}
    inline void printBusiness () { cout<<name<<": "<<product->getName()<<endl;}
};


#endif /* business_hpp */
