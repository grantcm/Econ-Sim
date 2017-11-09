//
//  sectormanager.hpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef sectormanager_h
#define sectormanager_h

#include "sector.hpp"

class sectormanager {
    map<string, sector> sectors;
    
public:
    inline sectormanager () {}
    inline void addSector (sector toAdd) { if (sectors.count(toAdd.getName()) == 0) { sectors[toAdd.getName()] = toAdd; }}
    inline void addBusinessToSector (business toAdd, string toAddTo) {sectors[toAddTo].addBusiness(toAdd); }
    inline void printBusinesses () { for (pair<string, sector> p : sectors) {p.second.printBusinesses();}}
    inline void printSectors () { for (pair<string, sector> p : sectors) {cout<<p.first<<endl;}}
    inline sector * getSector (string name) { return &sectors[name]; }
};

#endif /* sectormanager_h */
