//
//  sector.hpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef sector_hpp
#define sector_hpp

#include <stdio.h>
#include <map>
#include "business.hpp"

class sector {
    string name;
    map<string, business> businesses;
public:
    inline sector () {}
    inline sector (string newName) : name(newName) {}
    inline sector (string newName, map<string, business> newList) : name(newName), businesses(newList) {}
    inline string getName () { return name;}
    inline map<string, business> getBusinesses () { return businesses;}
    inline business * getBusiness (string name) { return &businesses[name];}
    void addBusiness (business toAdd);
    void removeBusiness (business ToRemove);
    void printBusinesses ();
    void runBusinesses ();
};



#endif /* sector_hpp */
