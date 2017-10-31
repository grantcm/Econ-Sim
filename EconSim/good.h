//
//  good.h
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef good_h
#define good_h

#include <vector>
#include <string>

using namespace std;

class Good {
    string name;
    vector<string> components;
    int cost;
    bool raw;
public:
    inline Good () {}
    inline Good (string newName, vector<string> parts) : name(newName), components(parts) {raw = false;}
    inline Good (string newName, int price) : name(newName), cost(price) {raw = true;}
    inline string getName () {return name;}
    inline vector<string> getComponents () {return components;}
    inline int getCost () {return cost;}
    inline bool getRaw () {return raw;}
};


#endif /* good_h */
