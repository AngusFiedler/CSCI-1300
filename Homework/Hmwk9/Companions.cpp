#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Companions.h"
using namespace std;

string Companions :: getName(){
    return companionName;   //returns the name of the companion
}
void Companions :: setName(string name_){
    companionName = name_;  //sets the name of the companion to the given value
}

bool Companions :: isAlive(){
    return alive;   //returns the value of alive, true or false
}
void Companions :: setAliveState(bool alive_){
    alive = alive_; //sets alive to the given value, true or false
}