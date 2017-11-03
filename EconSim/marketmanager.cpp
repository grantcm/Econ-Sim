//
//  MarketManager.cpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include <iostream>

#include "marketmanager.hpp"

marketManager::marketManager (goodmarket market, sectormanager sector, consumerManager consumer) : goods (market), sectors(sector), consumers(consumer) {}
marketManager::marketManager (sampleData data) : goods(data.getMarket()) , sectors(data.getSectors()), consumers(data.getConsumers()) {}

void marketManager::printAll() {
    printGoodPrices();
    printConsumers();
    printSectors();
    printBusinesses();
}

void marketManager::printGoodPrices() {
    vector<pair<string, int>> goodPrices = goods.getAllGoodPrices();
    for (pair<string, int> p : goodPrices) {
        cout<<p.first<<" costs: "<<p.second<<endl;
    }
}

void marketManager::printSectors() {
    cout << "Sectors:" <<endl;
    sectors.printSectors();
}

void marketManager::printBusinesses() {
    cout << "Businesses:" << endl;
    sectors.printBusinesses();
}

void marketManager::printConsumers() {
    cout << "Consumers: " << endl;
    consumers.printConsumers();
}
