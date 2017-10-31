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
    inline int getCost (Good good) {
        if (goodExists(good)) {
            if (good.getType() == goodType(0)) {
                return good.getCost();
            } else {
                int cost = 0;
                for (string g : good.getComponents()) {
                    cost += goodMap[g].getCost();
                }
                return cost;
            }
        }
        return 0;
    }
    
    inline int getCost (string good) {
        return getCost(goodMap[good]);
    }
    
    inline bool addGood (Good toAdd) {
        if (!goodExists(toAdd)) {
            goodMap[toAdd.getName()]=toAdd;
            goodNames.insert(toAdd.getName());
            return true;
        }
        return false;
    }
    
    inline bool removeGood (Good toRemove) {
        //TODO
        if (goodExists(toRemove)) {
            return true;
        }
        return false;
    }
    
    inline vector<pair<string, int>> getAllGoodPrices () {
        vector<pair<string, int>> prices;
        for (string name : goodNames) {
            prices.push_back(pair<string, int> (name, getCost(name)));
        }
        return prices;
    }
    
    inline bool goodExists (Good exists) { return goodMap.count(exists.getName()) != 0;}
    inline bool goodExists (string exists) { return goodNames.count(exists) != 0;}
    inline Good* getPointerToGood (string name) { return &goodMap[name]; }
};

#endif /* goodmarket_h */
