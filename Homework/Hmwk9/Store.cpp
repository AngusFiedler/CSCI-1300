#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Store.h"
#include "Util.h"
using namespace std;

int Store :: getYokePrice(){
    return yokePrice;   //returns the yokePrice
}

double Store :: getFoodPrice(){
    return foodPrice;   //retuns the price of food
}

int Store :: getBulletPrice(){
    return bulletPrice;     //returns the bulletPrice
}

int Store :: getWagonPartPrice(){
    return wagonPartPrice;      //returns wagonPartPrice
}

int Store :: getMedKitPrice(){
    return medicalKitPrice;     //returns the price of a med kit
}

//////////////////////////////////////////////////////////////////////////
/*
    upDatePrices:
    updates the prices of all items in  the store

    sets each item to the result of the current price * the increase value
*/
//////////////////////////////////////////////////////////////////////////
void Store :: upDatePrices(){
    double increase = 1.25;     //init increase to 1.25
    yokePrice = (int)(yokePrice*increase);      //set yokePrice to yokePrice * increase
    foodPrice = (foodPrice*increase);       //set foodPrice to foodPrice * increase
    bulletPrice = (int)(bulletPrice*increase);      //set bulletPrice to bulletPrice * increase
    wagonPartPrice =  (int)(wagonPartPrice*increase);   //set wagonPartPrice to WagonPartPrice * increase
    medicalKitPrice = (int)(medicalKitPrice*increase);  //set medicalKitPrice to medicalKitPrice * increase
}
//////////////////////////////////////////////////////////////////////////
/*
    OxenPurchase:
    returns the number of Oxen purchased

    loop while loop is true
        print info on oxen
        getUserInput and store as input
        if everyCharIsInt on the givenInput
            set amount to purchase to the int val of input
            set tempCost to amountToPurchase times the price of yokes
            if amount to purchase is zero set loop to false
            else if cost is greater than 200, print statement as such
            else if cost is less than 100, print statement as such
            else if the cost is more than the player balance, print statement as such
            else
                set loop to false
    return amountToPurchase
*/
//////////////////////////////////////////////////////////////////////////
int Store :: oxenPurchase(int playerBalance){
    bool loop = true;   //init loop to true
    string input;       //create string input
    int amountToPurchase = 0;   //init amountToPurchase to zero
    
    while(loop){        //loop while loop is true
        amountToPurchase = 0;   //init amountToPurchase to zero
        cout << "There are two oxen in a yoke, Each yoke costs $" << yokePrice << endl; //print statement
        cout << "You must buy between $100 and $200 worth of oxen" << endl; //print statement
        cout << "How many would you like to purchase:" << endl;     //print statement
        getline(cin, input);    //get userInput
        if (Util().everyCharIsInt(input) && input.length() > 0){        //if everycharIsInt returns true
            amountToPurchase = stoi(input);     //set amountToPurchase to input as a int
            double tempCost = amountToPurchase * yokePrice; //set tempCost to amountToPurchase times yokePrice
            if(amountToPurchase == 0){  //if amountToPurchase is zero
                loop = false;   //set loop to false
            }
            else if(tempCost > 200){    //if tempCost is greater than 200
                cout << "You have chosen to buy more than $200 worth of Oxen, please try again" << endl;    //print statement
                Util().printSep();  //printSep method
            }
            else if(tempCost < 100){    //if tempCost is less than 100
                cout << "You have chosen to buy less than $100 worth of Oxen, please try again" << endl;    //print statement
                Util().printSep();  //printSep method
            }
            else if(playerBalance - tempCost < 0){      //if the player does not have enough money
                cout << "You don't have enough money for this purchase" << endl;    //print statement
                Util().printSep();  //printSep method 
            }
            else{
                loop = false;   //set loop to false
            }
        }
        else{
            cout << "invalid input" << endl;    //print invalid input
            Util().printSep();  //printSep method
        }
    }
    return amountToPurchase;    //return amountToPurchase
}


//////////////////////////////////////////////////////////////////////////
/*
    foodPurchase:
    returns amount purchased

    loop while loop is true
        print the statements
        get user input, store as input
        if everyCharIsInt on the user input
            set amountToPurchase to the int value of input
            set tempCost to the foodPrice times the amountToPurchase
            if the amount would be greater than the player balance
                print you do not enough
            else
                set loop to false
        else
            print invalid input
    return the amountToPurchase
*/
//////////////////////////////////////////////////////////////////////////
int Store :: foodPurchase(int playerBalance){
    bool loop = true;       //init loop to true
    string input;   //create string input
    int amountToPurchase = 0;   //init amountToPurchase to zero
    
    while(loop){    //loop while loop is true 
        cout << "The store owner recommends that you have at least 200lbs of food per person" << endl;  //print statement
        cout << "Food currently costs $" << foodPrice << " per pound" << endl;      //print statement
        cout << "How many pounds of food do you wish to purchase:" << endl;     //print statement
        getline(cin, input);    //get userInput and store as input
        if (Util().everyCharIsInt(input)){      //if everyCharIsInt given input
            amountToPurchase = stoi(input);     //set amountToPurchase to int val of input
            double tempCost = foodPrice*amountToPurchase;   //set tempCost to foodPrice times amountToPurchase
            if(playerBalance - tempCost < 0){   //if the player does not have enough
                cout << "You don't have enough money for this purchase" << endl;    //print you do not have...
                Util().printSep();  //printSep method
            }
            else{
                loop = false;   //set loop to false
            }
        }
        else{
            cout << "invalid input" << endl;    //print invalid input
            Util().printSep();      //printSep method
        }
    }
    
    return amountToPurchase;    //return amountToPurchase
}

//////////////////////////////////////////////////////////////////////////
/*
    bulletsPurchase:
    returns the amount of bullets to purchase

    loop while loop is true
        print needed statements
        get user input
        if everyCharIsInt given input
            set amountToPurchase to the int val of input
            if the player does not have enough
                print you do not have
            else
                set loop to false
        else
            print invalid input
    return amountToPurchase
*/
//////////////////////////////////////////////////////////////////////////
int Store :: bulletsPurchase(int playerBalance){
    bool loop = true;
    string input;
    int amountToPurchase = 0;
    
    while(loop){    //loop while loop is true
        cout << "A box of 20 bullets costs $" << bulletPrice << endl;   //print statement
        cout << "How many boxes of bullets would you like to purchase:" << endl;    //print statement
        getline(cin, input);    //get userInput and store as input
        if (Util().everyCharIsInt(input)){      //if everyCharIsInt given input
            amountToPurchase = stoi(input);     //set amountToPurchase to input
            double tempCost = bulletPrice*amountToPurchase; //set tempCost to bulletPice times amountToPuchase
            if(playerBalance - tempCost < 0){   //if player does not have enough money
                cout << "You don't have enough money for this purchase" << endl;    //print you don't have enough
                Util().printSep();  //printSep method
            }
            else{
                loop = false;   //set loop to false
            }
        }
        else{
            cout << "invalid input" << endl;    //print invalid input
            Util().printSep();  //printSep method
        }
    }
    
    return amountToPurchase;    //return amountToPurchase
}


//////////////////////////////////////////////////////////////////////////
/*
    wagonPartPurchase:
    returns the number of wagonParts to purchase 

    loop while loop is true
        print needed statements
        get user input
        if everyCharIsInt given input
            set amountToPurchase to the int val of input
            if the player does not have enough
                print you do not have
            else
                set loop to false
        else
            print invalid input
    return amountToPurchase
*/
//////////////////////////////////////////////////////////////////////////
int Store :: wagonPartPurchase(int playerBalance){
    bool loop = true;   //init loop to true
    string input;       //create string input
    int amountToPurchase = 0;   //init amountToPurchase to zero
    
    while(loop){
        cout << "Wagon parts currently cost $" << wagonPartPrice << endl;   //print statement
        cout << "How many wagon parts do you wish to purchase:" << endl;    //print statement
        getline(cin, input);    //get userInput
        if (Util().everyCharIsInt(input)){      //if user input is a int
            amountToPurchase = stoi(input);     //set amountToPurchase to input
            double tempCost = wagonPartPrice*amountToPurchase;  //set cost to wagonPartPrice times amountToPurchase
            if(playerBalance - tempCost < 0){   //if the player does not have enough money
                cout << "You don't have enough money for this purchase" << endl;    //print you dont have...
                Util().printSep();  //printSep method
            }
            else{
                loop = false;   //set loop to false
            }
        }
        else{
            cout << "invalid input" << endl;    //print invalid...
            Util().printSep();  //printSep method
        }
    }
    
    return amountToPurchase;
}

//////////////////////////////////////////////////////////////////////////
/*
    medKitPurchase:
    returns the number of medKits to purchase 

    loop while loop is true
        print needed statements
        get user input
        if everyCharIsInt given input
            set amountToPurchase to the int val of input
            if the player does not have enough
                print you do not have
            else
                set loop to false
        else
            print invalid input
    return amountToPurchase
*/
//////////////////////////////////////////////////////////////////////////
int Store :: medKitPurchase(int playerBalance){
    bool loop = true;   //init loop to true
    string input;       //create string input
    int amountToPurchase = 0;   //init amountToPurchase to zero
    
    while(loop){    //loop while loop is true
        cout << "A medical kit currently costs $" << medicalKitPrice << endl;   //print statement
        cout << "How many medical kits do you wish to purchase:" << endl;       //print statement
        getline(cin, input);    //get userinput and store as input
        if (Util().everyCharIsInt(input)){      //if everychar of userInput in an int
            amountToPurchase = stoi(input);     //set amount to purchase to input
            double tempCost = medicalKitPrice*amountToPurchase;     //set temp cost to medicalKitPrice times amount to purchase    
            if(playerBalance - tempCost < 0){   //if the player does not have enough money
                cout << "You don't have enough money for this purchase" << endl;    //print you don't...
                Util().printSep();  //printSep util method
            }
            else{
                loop = false;   //set loop to false
            }
        }
        else{
            cout << "invalid input" << endl;    //print invalid...
            Util().printSep();  //printSep util method
        }
    }
    
    return amountToPurchase;    //return the amount to purchase
}
//////////////////////////////////////////////////////////////////////////
/*
    storeMenu:
    runs the entire store menu and functionality

    loop while loop is true
        get user input
        if everycharIsInt given input returns true
            set choice to the user input
            run a switch statement on choice
                if it is 1
                    run OxenPurchase method
                    set balance and num of oxen given the result of the purchase method
                if it is 2
                    run foodPurchase method
                    set balance and lbs of food given the result of the purchase method
                if it is 3
                    run bulletPurchase method
                    set balance and num bullets given the result of the purchase method
                if it is 4
                    run wagonPartPurchase and MedKitPurchase method
                    set balance  given the result of the purchase method
                if it is 5
                    set loop to false
                any other value
                    print invalid input
            print the current bill
    set player supplies
    set player balance

    return the player
*/
//////////////////////////////////////////////////////////////////////////
Player Store :: storeMenu(Player myPlayer){
    Supplies mySupplies = myPlayer.getSupplies();   //set mySupplies to myPlayer.getSupplies method
    bool loop = true;       //init loop to true
    double currentBill = 0;     //init currentBill to zero
    string input;       //create string called input
    double cost = 0;        //init cost to zero
    int numPurchased = 0;   //init numPurchased to zero
    int playerBalance = myPlayer.getBalance();
    
    Util().printSep();      //printSep util method
    Util().printStoreOptions(); //printStoreOptions util method
    
    while(loop){    //loop while loop is true
        cost = 0;   //set cost to zero
        getline(cin, input);    //get user input and store as input
        if (Util().everyCharIsInt(input)){  //if userinput is a number
            int choice = stoi(input);   //set choice to the int val of input
            switch(choice){     //run a switch on the given choice
                case 1:
                {
                    Util().printSep();  //printSep util method
                    numPurchased = oxenPurchase(playerBalance);     //set numPurchased to the result of the oxenPurchase method
                    cost = numPurchased * yokePrice;    //set cost to numPurchased * yokeCost
                    mySupplies.setNumOxen(numPurchased * 2 + mySupplies.getNumOxen());      //set numOxen to the current num plus the amount purchased
                    break;  //break
                }
                case 2:
                {
                    Util().printSep();  //printSep util method
                    numPurchased = foodPurchase(playerBalance);
                    cost = numPurchased * foodPrice;     //set cost to numPurchased times food price
                    mySupplies.setPoundsOfFood(numPurchased + mySupplies.getPoundsOfFood());    //set poundsOfFood to the current + amountPurchased
                    break;      //break from the switch
                }
                case 3:
                {
                    Util().printSep();  //printSep util method
                    numPurchased = bulletsPurchase(playerBalance);  //set numPurchased to the result of the bulletsPurchase method
                    cost = numPurchased * bulletPrice;  //set cost to numPurchased * bulletPrice
                    mySupplies.setNumBullets(numPurchased*20 + mySupplies.getNumBullets()); //add the amount of bullets purchased to the player supply
                    break;  //break from the switch
                }
                case 4:
                {
                    Util().printSep();
                    int numWagonParts = wagonPartPurchase(playerBalance);   //find the amount of Wagon parts to be purchased
                    int tempBal = playerBalance - numWagonParts*wagonPartPrice; //set tempBal to the current cost spent on wagonParts
                    int numMedKits = medKitPurchase(tempBal);   //find the amount of medKits to be purchased given the tempBal
                    cost = numMedKits * medicalKitPrice + numWagonParts * wagonPartPrice;   //set the val of cost
                    mySupplies.setNumWagonParts(numPurchased + mySupplies.getNumWagonParts());      //add the numWagonParts Purchased
                    mySupplies.setNumMedicalKits(numPurchased + mySupplies.getNumMedicalKits());    //add the numMedicalKits purchased
                    break;     //break from the switch
                }
                case 5:
                {
                    loop = false;   //set loop to false
                    break;      //break
                }
                default: 
                {
                    cout << "Invalid input" << endl;    //print invalid...
                }
            }
            Util().printSep();      //printSep method
            currentBill = currentBill + cost;   //set currentBill to the CurrrentBill + cost
            playerBalance = playerBalance - cost;   //set playerBalance to playerBalance - cost
            
            if(choice == 5){
                cout << "Final bill: $" << currentBill << endl; //print the final bill
                Util().printSep();      //printSep method 
            }
            else{
                cout << "Current bill: $" << currentBill << endl;   //print the current bill
            }
        }
        else{
            cout << "Invalid input" << endl;    //print invalid...
        }
        if (loop){  //if loop is true
            Util().printSep();      //printSep method
            Util().printStoreOptions();     //print the store options
        }
    }
    myPlayer.setSupplies(mySupplies);       //set myplayer supplies to the given val
    myPlayer.setBalance(playerBalance);     //set playerBalance to the given val
    return myPlayer;    //return the current player
}