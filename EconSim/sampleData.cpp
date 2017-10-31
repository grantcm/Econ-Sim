//
//  sampleData.cpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include "sampleData.h"

bool sampleData::generateGoods() {
    sampleGoods.addGood(Good("Coal", 5, goodType(0)));
    sampleGoods.addGood(Good("Iron", 4, goodType(0)));
    sampleGoods.addGood(Good("Wheat", 3, goodType(0)));
    sampleGoods.addGood(Good("Corn", 2, goodType(0)));
    sampleGoods.addGood(Good("Steel", {"Coal", "Iron"}, goodType(1)));
    sampleGoods.addGood(Good("Water", 2, goodType(0)));
    
    return true;
}

void sampleData::generateConsumers() {
    sampleConsumers.addConsumer(consumer("1","Wheat"));
    sampleConsumers.addConsumer(consumer("2","Wheat"));
    sampleConsumers.addConsumer(consumer("3","Wheat"));
    sampleConsumers.addConsumer(consumer("4","Wheat"));
    sampleConsumers.addConsumer(consumer("5","Wheat"));
    sampleConsumers.addConsumer(consumer("6","Wheat"));
    sampleConsumers.addConsumer(consumer("7","Wheat"));
    sampleConsumers.addConsumer(consumer("8","Wheat"));
    sampleConsumers.addConsumer(consumer("9","Wheat"));
    sampleConsumers.addConsumer(consumer("10","Wheat"));
}


void sampleData::generateSectors() {
    sampleSectors.addSector(sector("Mining"));
    sampleSectors.addSector(sector("Agriculture"));
    sampleSectors.addSector(sector("Manufacturing"));
    sampleSectors.addBusinessToSector(business("Wheat Growers", sampleGoods.getPointerToGood("Wheat"),{sampleConsumers.getPointerToConsumer("1")}), "Agriculture");
    sampleSectors.addBusinessToSector(business("Water Supply", sampleGoods.getPointerToGood("Water"),{sampleConsumers.getPointerToConsumer("2")}), "Agriculture");
    sampleSectors.addBusinessToSector(business("Corn Growers", sampleGoods.getPointerToGood("Corn"),{sampleConsumers.getPointerToConsumer("3")}), "Agriculture");
    sampleSectors.addBusinessToSector(business("Coal Miners", sampleGoods.getPointerToGood("Coal"),{sampleConsumers.getPointerToConsumer("4")}), "Mining");
    sampleSectors.addBusinessToSector(business("Iron Miners", sampleGoods.getPointerToGood("Iron"),{sampleConsumers.getPointerToConsumer("5")}), "Mining");
    sampleSectors.addBusinessToSector(business("Steel's Steel", sampleGoods.getPointerToGood("Steel"),{sampleConsumers.getPointerToConsumer("6")}), "Manufacturing");
}


