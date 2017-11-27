//
//  goodmarket.h
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef goodmarket_h
#define goodmarket_h

#include <stdio.h>
#include <map>
#include <set>

#include "good.h"

class goodmarket {
    map<string, Good> goodMap;
    set<string> goodNames;
public:
    int getCost (Good);
    inline int getCost (string good) { return getCost(goodMap[good]); }
    void addGood (Good);
    void removeGood (Good);
    vector<pair<string, int>> getAllGoodPrices ();
    inline bool goodExists (Good exists) { return goodMap.count(exists.getName()) != 0;}
    inline bool goodExists (string exists) { return goodNames.count(exists) != 0;}
    inline Good* getPointerToGood (string name) { return &goodMap[name]; }
};

#endif /* goodmarket_h */
