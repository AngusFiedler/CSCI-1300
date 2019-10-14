#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Supplies.h"
using namespace std;

int Supplies :: getNumOxen(){
    return numOfOxen;       //returns the numOfOxen
}
void Supplies :: setNumOxen(int numOfOxen_){
    numOfOxen = numOfOxen_; //sets the numOfOxen to the given value
}
    
int Supplies :: getPoundsOfFood(){
    return poundsOfFood;    //returns poundsOfFood
}
void Supplies :: setPoundsOfFood(int poundsOfFood_){
    if(poundsOfFood_ > 1000){       //if poundsOfFood_ is greater than 1000
        cout << "The wagon can only hold 1,000 pounds of food. The rest was left behind..." << endl;    //print food was left behind
        poundsOfFood = 1000;    //set pounds of food to 1000
    }
    else{   //in all other cases
        poundsOfFood = poundsOfFood_;   //set poundsOfFood to the given value
    }
}
    
int Supplies :: getNumBullets(){
    return numOfBullets;    //returns numOfBullets
}
void Supplies :: setNumBullets(int numOfBullets_){
    numOfBullets = numOfBullets_;   //sets the numberOfBullets to the given value
}
    
int Supplies :: getNumWagonParts(){
    return numOfWagonParts;     //returns the numOfwagonParts
}
void Supplies :: setNumWagonParts(int numOfWagonParts_){
    numOfWagonParts = numOfWagonParts_;     //sets numOfWagonParts to the given value
}
    
int Supplies :: getNumMedicalKits(){
    return numOfMedicalKits;    //return the numOfMedicalKits
}
void Supplies :: setNumMedicalKits(int numOfMedicalKits_){
    numOfMedicalKits = numOfMedicalKits_;   //set numOfMedicalKits to the given value
}
bool Supplies :: getWagonStatus(){
    return wagonStatus;     //returns the wagonStatus
}
void Supplies :: setWagonStatus(bool status){
    wagonStatus = status;   //sets the wagonStatus to the given value
}