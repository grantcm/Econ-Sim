//
//  GoodMarket.cpp
//  EconSim
//
//  Created by Grant Miller on 11/27/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include <stdio.h>
#include "goodmarket.h"

int goodmarket::getCost (Good good) {
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


void goodmarket::addGood (Good toAdd) {
    if (!goodExists(toAdd)) {
        goodMap[toAdd.getName()]=toAdd;
        goodNames.insert(toAdd.getName());
    }
}

void goodmarket::removeGood (Good toRemove) {
    goodMap.erase(toRemove.getName());
    goodNames.erase(toRemove.getName());
}

vector<pair<string, int>> goodmarket::getAllGoodPrices () {
    vector<pair<string, int>> prices;
    for (string name : goodNames) {
        prices.push_back(pair<string, int> (name, getCost(name)));
    }
    return prices;
}
