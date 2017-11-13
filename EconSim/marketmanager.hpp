//
//  MarketManager.hpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef MarketManager_hpp
#define MarketManager_hpp

#include "goodmarket.h"
#include "sectormanager.hpp"
#include "consumermanager.hpp"
#include "sampleData.h"

class marketManager {
    goodmarket goods;
    sectormanager manager;
    consumerManager consumers;
public:
    marketManager (goodmarket, sectormanager, consumerManager);
    marketManager (sampleData);
    inline marketManager () {}
    inline void addGood (Good toAdd) { goods.addGood(toAdd); }
    inline void removeGood (Good toRemove) { goods.removeGood(toRemove); }
    inline void addSector (sector toAdd) { manager.addSector(toAdd);}
    inline void addBusinessToSector (business toAdd, string toAddTo) { manager.addBusinessToSector(toAdd, toAddTo);}
    inline void addConsumer (consumer toAdd) { consumers.addConsumer(toAdd);}
    inline void removeConsumer (string toRemove) { consumers.removeConsumer(toRemove);}
    void printAll();
    void printGoodPrices ();
    void printSectors ();
    void printBusinesses ();
    void printConsumers ();
    void test ();
};

#endif /* MarketManager_hpp */
