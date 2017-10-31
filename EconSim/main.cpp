//
//  main.cpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include <iostream>
#include "sampleData.h"
#include "marketmanager.hpp"

int main(int argc, const char * argv[]) {
    sampleData market = sampleData();
    market.generateGoods();
    market.generateSectors();
    marketManager manager = marketManager(market.getMarket(), market.getSectors());
    manager.printGoodPrices();
    manager.printSectors();
    manager.printBusinesses();
    return 0;
}
