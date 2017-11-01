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
    sampleData data = sampleData();
    data.generateGoods();
    data.generateConsumers();
    data.generateSectors();
    marketManager manager = marketManager(data);
    manager.printGoodPrices();
    manager.printSectors();
    manager.printBusinesses();
    manager.printConsumers();
    return 0;
}
