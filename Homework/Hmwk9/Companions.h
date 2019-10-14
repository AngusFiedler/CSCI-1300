#ifndef Companions_H
#define Companions_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Companions{
    private:
        string companionName;   //string var that stores the name of the companion
        bool alive;     //bool that stores if the companion is alive, true, or dead, false
    public:
    Companions(){   //default constructor 
        companionName = ""; //set name to a blank space
        alive = true;   //set aliveState to true
    }
    Companions(string name_, bool alive_){  //param constructor
        companionName = name_;  //set compName to the given name    
        alive = alive_;     //sets aliveState to the given value
    }
    string getName();   //returns the name of the campanion
    bool isAlive();     //returns if the companion is alive or dead
    void setAliveState(bool alive_);    //sets the alive state to the given var
    void setName(string name_);     //sets the name of the given companion
};
#endif