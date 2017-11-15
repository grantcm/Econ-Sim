//
//  sectormanager.cpp
//  EconSim
//
//  Created by Grant Miller on 11/15/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include <stdio.h>
#include "sectormanager.hpp"

void sectormanager::runSectors () {
    while (pollSectors()) {
        for(auto p: sectors) {
            p.second.runBusinesses();
        }
    }

}


// Indicates whether a sector has runnable businesses
bool sectormanager::pollSectors() {
    return false;
}



