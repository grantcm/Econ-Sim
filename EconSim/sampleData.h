//
//  sampleData.h
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef sampleData_h
#define sampleData_h

#include "goodmarket.h"
#include "sectormanager.hpp"
#include "consumermanager.hpp"

class sampleData {
    goodmarket sampleGoods;
    sectormanager sampleSectors;
    consumerManager sampleConsumers;
    
public:
    inline sampleData() {}
    inline sampleData(goodmarket market) : sampleGoods(market) {}
    
    void setup();
    void printAll();
    void generateGoods();
    void generateSectors();
    void generateConsumers();
    inline goodmarket getMarket(){ return sampleGoods;}
    inline sectormanager getSectors (){ return sampleSectors;}
    inline void setMarket (goodmarket newMarket) { sampleGoods = newMarket;}
    inline consumerManager getConsumers() { return sampleConsumers;}
};

#endif /* sampleData_h */
