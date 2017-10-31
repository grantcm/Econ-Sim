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

typedef enum : int {
    raw,
    intermediate,
    finalGood,
} goodType;

class Good {
    string name;
    vector<string> components;
    int cost;
    goodType type;
public:
    inline Good () {}
    inline Good (string newName, vector<string> parts, goodType _type) : name(newName), components(parts), type(_type) {}
    inline Good (string newName, int price, goodType _type) : name(newName), cost(price), type(_type) {}
    inline string getName () {return name;}
    inline vector<string> getComponents () {return components;}
    inline int getCost () {return cost;}
    inline goodType getType () {return type;}
};


#endif /* good_h */
