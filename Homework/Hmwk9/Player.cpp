#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Companions.h"
#include "Supplies.h"
#include "Player.h"
using namespace std;

string Player :: getName(){
    return playerName;  //returns the playerName
}
void Player :: setName(string playerName_){
    playerName = playerName_;   //sets the playerName to a given value
}
    
int Player :: getBalance(){
    return playerBalance;   //returns the current playerBalance
}
void Player :: setBalance(int balance_){
    playerBalance = balance_;   //sets the playerBalance to the given value
}
    
Companions Player :: getCompanion(int index){
    return myCompanions[index];     //returns the companion at the specified index in the array
}
void Player :: setCompanion(int index, Companions newCompanion){
    myCompanions[index] = newCompanion;     //sets the Companion at a given index to the given Companion
}
    
Supplies Player :: getSupplies(){
    return mySupplies;      //returns mySupplies
}
void Player :: setSupplies(Supplies newSupply){
    mySupplies = newSupply;     //sets mySupplies to the given value
}

bool Player :: checkAlive(){
    return alive;   //returns if the player is alive, true, or dead, false
}
void Player :: setAliveStatus(bool status){
    alive = status;     //sets the players alive status to the given value
}