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
    inline business getBusiness (string name) { return businesses[name];}
    inline void addBusiness (business toAdd) { if(businesses.count(toAdd.getName()) == 0) { businesses[toAdd.getName()] = toAdd; }}
    inline void removeBusiness (business ToRemove) {
        //TODO
    }
    inline void printBusinesses () { for ( pair<string, business> p: businesses) {p.second.printBusiness();} }
};



#endif /* sector_hpp */
