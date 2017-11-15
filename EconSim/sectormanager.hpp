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

struct deal {
    //Trading partner
    business * partner;
    //True indicates import, false export
    bool isComponent;
    //Good we are trading
    Good * good;
    //quantity of good traded
    int quantity;
};

class sectormanager {
    map<string, sector> sectors;
    queue<deal> globalRequestQueue;
public:
    inline sectormanager() { }
    inline void addSector (sector toAdd) { if (sectors.count(toAdd.getName()) == 0) { sectors[toAdd.getName()] = toAdd; }}
    inline void addBusinessToSector (business toAdd, string toAddTo) {sectors[toAddTo].addBusiness(toAdd); }
    inline void printBusinesses () { for (pair<string, sector> p : sectors) {p.second.printBusinesses();}}
    inline void printSectors () { for (pair<string, sector> p : sectors) {cout<<p.first<<endl;}}
    inline sector * getSector (string name) { return &sectors[name]; }
    void addRequest(business * ,bool , int);
    void addRequest(deal);
    inline deal getRequest() { return globalRequestQueue.front(); }
    inline void popRequest() { globalRequestQueue.pop(); }
    void runSectors ();
    bool pollSectors ();
};

#endif /* sectormanager_h */
