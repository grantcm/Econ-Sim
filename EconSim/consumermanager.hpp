//
//  consumermanager.hpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef consumermanager_hpp
#define consumermanager_hpp

#include <stdio.h>
#include <map>
#include "consumer.hpp"

class consumerManager {
    map<string, consumer> consumerMap;
public:
    consumerManager () {}
    void printConsumers ();
    inline void addConsumer (consumer toAdd){ if (consumerMap.count(toAdd.getName()) == 0) { consumerMap[toAdd.getName()] = toAdd; }}
    inline void removeConsumer (string toRemove) {/*TODO*/}
    inline consumer * getPointerToConsumer (string name) { return &consumerMap[name]; }
    
};


#endif /* consumermanager_hpp */
