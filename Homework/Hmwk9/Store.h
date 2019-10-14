#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Player.h"
#include "cmath"
using namespace std;


class Store{
    private:
        int yokePrice;
        double foodPrice;
        int bulletPrice;
        int wagonPartPrice;
        int medicalKitPrice;
        
    public:
    Store(){    //default constructor with initial prices
        yokePrice = 20;     //20 dollars for 2 oxens or 1 yoke
        foodPrice = 0.5;     //50 cents per pound
        bulletPrice = 2;    //2 dollars for 20 bullets
        wagonPartPrice = 20; //20 dollars per wagon part
        medicalKitPrice = 25; //25 dollars per med kit
    }
    int getYokePrice();  //get the price for a yoke
    double getFoodPrice();  //get the price for food
    int getBulletPrice();    //get the price for bullets
    int getWagonPartPrice(); //get the price for wagonParts
    int getMedKitPrice();    //get the price for a medKits
    void upDatePrices();    //updatePrices of the store
    
    
    int oxenPurchase(int playerBalance);        //runs purchase menu for oxen, returns number purchased
    int foodPurchase(int playerBalance);        //runs purchase menu for food, returns number purchased
    int bulletsPurchase(int playerBalance);     //runs purchase menu for bullets, returns number purchased
    int wagonPartPurchase(int playerBalance);   //runs purchase menu for wagonParts, returns number purchased
    int medKitPurchase(int playerBalance);      //runs purchase menu for medKits, returns number purchased
    Player storeMenu(Player myPlayer);          //runs the store menu ui and functionality
};
#endif