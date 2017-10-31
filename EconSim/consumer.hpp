//
//  consumer.hpp
//  EconSim
//
//  Created by Grant Miller on 10/31/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef consumer_h
#define consumer_h

#include <string>
#include <iostream>

using namespace std;

class consumer {
    string goodPreference, employer, name;
    bool employed;
public:
    inline consumer () {}
    inline consumer (string _name, string goods) : goodPreference(goods), name(_name), employed(false) {}
    inline bool getEmployed () { return employed;}
    inline void setEmployed (bool _employed) { employed = _employed;}
    inline string getGoodPreference() { return goodPreference;}
    inline string getEmployer() { return employer;}
    inline string getName() { return name;}
    inline void setEmployer (string newEmp) { employer = newEmp; }
    inline void setGoodPreference(string newPref) { goodPreference = newPref;}
    inline void printConsumer() {cout<<name<<" "<<employer<<" "<<goodPreference<<endl; }
};

#endif /* consumer_h */
