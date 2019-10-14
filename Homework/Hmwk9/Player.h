#ifndef Player_H
#define Player_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Companions.h"
#include "Supplies.h"
using namespace std;

class Player{
    private:
        string playerName;  //string that stores the player name
        int playerBalance;  //int that stores the player balance
        Companions myCompanions[4]; //companion array that stores 4 companion objects
        Supplies mySupplies;    //supplies object
        bool alive;
        
    public:
    Player(){   //default constructor
        playerName = "";    //set playername to empty
        playerBalance = 1200;   //set playerBalance to 1200
        for(int i = 0; i < 4; i++){ //for each companion in the array, i++
            myCompanions[i] = Companions(); //set the companion at i to a new Companions object
        }
        mySupplies = Supplies();    //set mySupplies to a new supplies object
        alive = true;
    }
    Player(string name_,int playerBalance_, Companions myCompanions_[], Supplies mySupplies_){  //param constructor
        playerName = name_;     //set playername to the given val
        playerBalance = playerBalance_; //set playerbalance to the given val
        for(int i = 0; i < 4; i++){ //for each companion in the array
            myCompanions[i] = myCompanions_[i]; //set mycompanions at i to the given companion array at i
        }
        mySupplies = mySupplies_;   //set mySupplies to the given supplies object
        alive = true;
    }
    string getName(); //return the player name
    void setName(string name_); //set the playername to a given value
    
    int getBalance();   //return the balance
    void setBalance(int balance_);  //set the player balance to a given value
    
    Companions getCompanion(int index); //return the Companion object at a given index
    void setCompanion(int index, Companions newCompanion); //set a companion given the index and a companion object
    
    Supplies getSupplies();     //return the supplies object
    void setSupplies(Supplies newSupply);   //set the supply object given a supply object
    
    bool checkAlive();      //returns the players alive status
    void setAliveStatus(bool status);   //sets the players alive status to the given value
    
};
#endif