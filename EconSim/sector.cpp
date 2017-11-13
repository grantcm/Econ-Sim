//
//  sector.cpp
//  EconSim
//
//  Created by Grant Miller on 11/10/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include <stdio.h>

#include "sector.hpp"

void sector::runBusinesses() {
    for (auto p : businesses) {
        cout<<"About to run: "<<p.first<<endl;
        p.second.run();
    }
    
    
}
