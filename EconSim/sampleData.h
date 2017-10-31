//
//  sampleData.h
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef sampleData_h

#include "goodmarket.h"
#include "sectormanager.hpp"

#define sampleData_h

class sampleData {
    goodmarket sampleGoods;
    sectormanager sampleSectors;
public:
    inline sampleData() {}
    inline sampleData(goodmarket market) : sampleGoods(market) {}
    
    bool generateGoods();
    void generateSectors();
    inline goodmarket getMarket(){ return sampleGoods;}
    inline sectormanager getSectors (){ return sampleSectors;}
    inline void setMarket (goodmarket newMarket) { sampleGoods = newMarket;}
};

#endif /* sampleData_h */
