//
//  MarketManager.cpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include "marketmanager.hpp"

marketManager::marketManager (goodmarket market, sectormanager sector, consumerManager consumer) : goods (market), manager(sector), consumers(consumer) {}
marketManager::marketManager (sampleData data) : goods(data.getMarket()) , manager(data.getSectors()), consumers(data.getConsumers()) {}

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
    manager.printSectors();
}

void marketManager::printBusinesses() {
    cout << "Businesses:" << endl;
    manager.printBusinesses();
}

void marketManager::printConsumers() {
    cout << "Consumers: " << endl;
    consumers.printConsumers();
}

void marketManager::test() {
    business * b1  = manager.getSector("Mining")->getBusiness("Iron Miners");
    business * b2 = manager.getSector("Manufacturing")->getBusiness("Steel's Steel");
    business * b3 = manager.getSector("Agriculture")->getBusiness("Wheat Growers");
    b2->addRequest(b3, true, 1);
    manager.runSectors();
}
