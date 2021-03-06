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
#include "mainwindow.hpp"

int main(int argc, const char * argv[]) {
    sampleData data = sampleData();
    data.setup();
    marketManager manager = marketManager(data);
    manager.test();
    //manager.printAll();
    //MainWindow window = MainWindow();

    return 0;
}
