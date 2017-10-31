//
//  sampleData.cpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include "sampleData.h"

bool sampleData::generateGoods() {
    sampleGoods.addGood(Good("Coal", 5));
    sampleGoods.addGood(Good("Iron", 4));
    sampleGoods.addGood(Good("Wheat", 3));
    sampleGoods.addGood(Good("Corn", 2));
    sampleGoods.addGood(Good("Steel", {"Coal", "Iron"}));
    sampleGoods.addGood(Good("Water", 2));
    
    return true;
}

void sampleData::generateSectors() {
    sampleSectors.addSector(sector("Mining"));
    sampleSectors.addSector(sector("Agriculture"));
    sampleSectors.addSector(sector("Manufacturing"));
    sampleSectors.addBusinessToSector(business("Wheat Growers", sampleGoods.getPointerToGood("Wheat")), "Agriculture");
    sampleSectors.addBusinessToSector(business("Water Supply", sampleGoods.getPointerToGood("Water")), "Agriculture");
    sampleSectors.addBusinessToSector(business("Corn Growers", sampleGoods.getPointerToGood("Corn")), "Agriculture");
    sampleSectors.addBusinessToSector(business("Coal Miners", sampleGoods.getPointerToGood("Coal")), "Mining");
    sampleSectors.addBusinessToSector(business("Iron Miners", sampleGoods.getPointerToGood("Iron")), "Mining");
    sampleSectors.addBusinessToSector(business("Steel's Steel", sampleGoods.getPointerToGood("Steel")), "Manufacturing");
}


