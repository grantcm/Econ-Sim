//
//  MarketManager.hpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef MarketManager_hpp
#define MarketManager_hpp

#include <stdio.h>
#include "goodmarket.h"
#include "sectormanager.hpp"

class marketManager {
    goodmarket goods;
    sectormanager sectors;
public:
    marketManager (goodmarket, sectormanager);
    inline marketManager () {}
    inline bool addGood (Good toAdd) { return goods.addGood(toAdd); }
    inline bool removeGood (Good toRemove) { return goods.removeGood(toRemove); }
    inline void addSector (sector toAdd) { sectors.addSector(toAdd);}
    inline void addBusinessToSector (business toAdd, string toAddTo) { sectors.addBusinessToSector(toAdd, toAddTo); }
    void printGoodPrices ();
    void printSectors ();
    void printBusinesses ();
};

#endif /* MarketManager_hpp */
