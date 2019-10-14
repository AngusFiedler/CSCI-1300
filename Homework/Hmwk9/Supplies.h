#ifndef Supplies_H
#define Supplies_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Supplies{
    private:        //supplies private varibles
        int numOfOxen;
        int poundsOfFood;
        int numOfBullets;
        int numOfWagonParts;
        int numOfMedicalKits;
        bool wagonStatus;
    public:
    Supplies(){ //default constructor
        numOfOxen = 0;      //set NumOfOxen to zero
        poundsOfFood = 0;   //set poundsOfFood to zero
        numOfBullets = 0;   //set NumOfBullets to zero
        numOfWagonParts = 0;    //set NumOfWagonParts to zero
        numOfMedicalKits = 0;   //set NumOfMedicalKits to zero
        wagonStatus = true;     //sets wagon status to true
    }
    Supplies(int numOfOxen_, int poundsOfFood_, int numOfBullets_, int numOfWagonParts_,int numOfMedicalKits_){     //param constructor
        numOfOxen = numOfOxen_; //set NumOfOxen to the given val
        poundsOfFood = poundsOfFood_;   //set poundsOfFood to the given val
        numOfBullets = numOfBullets_;   //set NumOfBullets to the given val
        numOfWagonParts = numOfWagonParts_; //set NumOfWagonParts to the given val
        numOfMedicalKits = numOfMedicalKits_;   //set NumOfMedicalKits to the given val
        wagonStatus = true;     //sets wagon status to true
    }
    int getNumOxen();   //return the num of Oxen
    void setNumOxen(int numOfOxen_); //set numOxen to the given val
    
    int getPoundsOfFood();  //return pounds of food
    void setPoundsOfFood(int poundsOfFood_);    //set poundsOfFood to the given val
    
    int getNumBullets();    //return the num of bullets
    void setNumBullets(int numOfBullets_);  //set numofBullets to the given val
    
    int getNumWagonParts(); //return the num of wagon parts
    void setNumWagonParts(int numOfWagonParts_);    //set numWagonParts to the given val
    
    int getNumMedicalKits();    //return the num of medical kits
    void setNumMedicalKits(int numOfMedicalKits_);  //set numOfMedicalKits to the given val
    
    bool getWagonStatus();  //returns the current wagon status
    void setWagonStatus(bool status);   //sets the wagon status to a given value 
};
#endif