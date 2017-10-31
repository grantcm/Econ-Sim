//
//  consumermanager.cpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include "consumermanager.hpp"

void consumerManager::printConsumers() {
    for (pair<string, consumer> p : consumerMap) {
        p.second.printConsumer();
    }
}
