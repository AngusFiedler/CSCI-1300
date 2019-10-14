#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Player.h"
#include "Date.h"
#include "Companions.h"
#include "Supplies.h"
#include "Game.h"
#include "Milestones.h"
#include "Store.h"
#include "Util.h"
#include "cmath"
using namespace std;

Player Game :: getPlayer(){
    return myPlayer;    //returns myPlayer
}
void Game :: setPlayer(Player myPlayer_){
    myPlayer = myPlayer_;   //sets myPlayer to the given value
}
    
Date Game :: getDate(){
    return myDate;      //returns myDate
}
void Game :: setDate(Date myDate_){
    myDate = myDate_;   //sets myDate to the given Date 
}

int Game :: getMilesToGo(){
    return milesToGo;   //returns milesToGo
}
void Game :: setMilesToGo(int milesToGo_){
    milesToGo = milesToGo_;     //sets milesToGo to the given value
}
int Game :: getMilesTravelled(){
    return milesTravelled;      //returns milesTravelled
}
void Game :: addMiles(int milesToAdd){  //adds the given number of miles
    milesToGo = milesToGo - milesToAdd; //sets milesToGo to milesToGo minus milesToAdd
    milesTravelled = milesTravelled + milesToAdd;       //addds milesToAdd to milesTravelled
}
//////////////////////////////////////////////////////////////////////////
/*
    puzzle:
    runs the puzzle game functionality
    
    set solved to false
    loop from 1 to 3
        loop while userinput is not correct
            get userinput
            if userinput is valid
                if userinput is the random number
                    set solved to true
                else
                    print statement
                break from loop
            else
                print statement
    return the value of solved
*/
//////////////////////////////////////////////////////////////////////////
bool Game :: puzzle(){
    bool solved = false;                //init solved to false
    int random = rand() % 10 + 1;       //create a random number
    string input;                       //create string input
    bool innerLoop;                     //create bool called innerloop
    cout << "You must try to guess a number between 1 and 10" << endl;  //print statement
    
    for(int i = 1; i < 4; i++){     //loop from 1 to 3, i+1
        innerLoop = true;   //set inner loop to true
        while(innerLoop){   //while inner loop is true
            Util().printSep();  //printSep method
            cout << "Enter Guess, attempt number " << i << " of 3" << endl;     //print statement
            getline(cin,input); //get userInput
            bool validNum = Util().everyCharIsInt(input);   //set validNum to result of everyCharIsInt method
            if(validNum){   //if validNum is true
                if(stoi(input) == random){  //if random number is the same as userinput
                    cout << "You have Guessed correctly!" << endl;  //print statement
                    i = 4;  //set i to 4
                    solved = true;  //set solved to true
                }
                else{
                    cout << "That is not correct" << endl;  //print statement
                }
                innerLoop = false;  //set innerLoop to false
            }
            else{
                cout << "invalid input" << endl;    //print statement
            }
        }
    }
    return solved;  //return the value of solved
}
//////////////////////////////////////////////////////////////////////////
/*
    statusUpdate:
    prints the statusUpdate UI
    
    prints all important info
*/
//////////////////////////////////////////////////////////////////////////
void Game :: statusUpdate(){
    int nextMilestone = myMilestones.getDistance(milestoneIndex) - milesTravelled;
    cout << endl;
    cout << "-------------------------------Status Update-------------------------------" << endl;
    cout << "Current Date: " << myDate.getMonth() << "/" << myDate.getDay()  << '/' << myDate.getYear() << endl;
    cout << "Miles travelled: " << milesTravelled << " miles" << endl;
    cout << "Distance to next milestone: " << nextMilestone << " miles" << endl;
    cout << "Food remaining: " << myPlayer.getSupplies().getPoundsOfFood() << " lbs" << endl;
    cout << "Bullets remaining: " << myPlayer.getSupplies().getNumBullets() << endl;
    cout << "Cash remaining: $" << myPlayer.getBalance() << endl;
    cout << "-------------------------------Status Update-------------------------------" << endl;
    cout << endl;
}
//////////////////////////////////////////////////////////////////////////
/*
    checkForGameEnd:
    checks if the game should end
    
    get all important info
    if no food
        print statement
        set endGame to true
    if no Oxen
        print statement
        set endGame to true
    if wagonStatus is false
        print statement
        set endGame to true
    if the player is dead
        print statement
        set endgame to true
    if there are no more days
        print statement
        set endGame to true
    return endGame
*/
//////////////////////////////////////////////////////////////////////////
bool Game :: checkForGameEnd(){
    bool endGame = false;
    int poundsOfFood = myPlayer.getSupplies().getPoundsOfFood();
    int numOxen = myPlayer.getSupplies().getNumOxen();
    bool wagonStatus = myPlayer.getSupplies().getWagonStatus();
    int wagonParts = myPlayer.getSupplies().getNumWagonParts();
    bool playerAlive = myPlayer.checkAlive();
    
    if(poundsOfFood <= 0){  //if food is zero or below
        cout << "You have run out of food!" << endl;    //print statement
        endGame = true;     //set endGame to true
    }
    if(numOxen <= 0){   //if numOxen is zero or below
        cout << "You have run out Oxen" << endl;    //print statement
        endGame = true;     //set endGame to true
    }
    if(!wagonStatus){   //if wagon is broken
        cout << "Your wagon has broken down and you have no parts remaining" << endl;   //print statement
        endGame = true;     //set endGame to true
    }
    if(!playerAlive){   //if the player is dead
        cout << "You have died" << endl;    //print statement
        endGame = true;     //set endGame to true
    }
    if(!myDate.addDays(1)){
        cout << "You did not reach Oregon in time..." << endl;      //print Statement
        endGame = true;     //set endGame to true
    }
    return endGame;     //return the val of endGame
}
//////////////////////////////////////////////////////////////////////////
/*
    numPlayerAlive:
    checks the number of remaing players
    
    set playersAlive to 1
    loop from zero to 3, i++
        if companion at pos i is alived
            set players alive +1
    return playersAlive
*/
//////////////////////////////////////////////////////////////////////////
int Game :: numPlayerAlive(){
    int playersAlive = 1;   //init playersAlive to 1
    for(int i = 0; i < 4; i++){     //loop from zero to 3
        if (myPlayer.getCompanion(i).isAlive()){    //check if companion at pos i is alive
            playersAlive++;     //add one to players alive
        }
    }
    return playersAlive;    //return playersAlive
}

//////////////////////////////////////////////////////////////////////////
/*
    reachedMilestone:
    runs functionality when a mileStone has been reached
    
    prints that a mileStone has been reached
    checks if it is a crossing or store
    if store
        runs store menu options
    else
        runs river crossing options
*/
//////////////////////////////////////////////////////////////////////////
void Game :: reachedMilestone(){
    bool loop = true;
    string input;
    cout << "You have reached the " << myMilestones.getName(milestoneIndex) << endl; //print Statement
    if(myMilestones.getDepth(milestoneIndex) == -1){    //if mileStone has a depth of -1
        myStore.upDatePrices(); //update the prices at the store
        while(loop){    //loop while loop is true
            Util().printSep();  //print Sep method
            cout << "1) Visit Store" << endl;   //print Statement
            cout << "2) Rest" << endl;  //print Statement
            getline(cin,input); //get user inpiut
            if(Util().isValidIntChoice(input,1,2)){ //if userinput is valid
                int intInput = stoi(input); //set userinput to intInput
                if(intInput == 1){  //if input is 1 
                    myPlayer = myStore.storeMenu(myPlayer); //run store on myPlayer
                    loop = false;   //set loop to false
                }
                else{
                    rest(); //run rest method
                }
            }
        }
    }
    else{
        Util().printSep();  //printSepMethod
        loop = true;    //set loop to true
        while(loop){    //loop while loop is true
            cout << "How would you like to proceed?" << endl;   //print Statement
            cout << "1) Rest" << endl;      //print Statement
            cout << "2) Cross the river" << endl;   //print Statement
            getline(cin,input);     //get userInput
            Util().printSep();      //print sep Method
            if(Util().everyCharIsInt(input)){   //if userinput is a number
                int intInput = stoi(input); //set userInput to IntInput
                if(intInput == 1){  //if intInput is 1 
                    rest();     //run rest method
                }
                else if(intInput == 2){     //if userInput is 2 
                    if(myMilestones.getDepth(milestoneIndex) > 3){  //if the riverdepth is greater than 3
                        int ferryCost = 10*numPlayerAlive();    //calcualte ferry cost
                        cout << "The ferry cost $" << ferryCost << " to cross the river" << endl;   //print Statement
                        loop = false;   //set loop to false
                    }
                    else{
                        cout << "You crossed the river" << endl;    //print Statement
                        loop = false;       //set loop to false
                    }
                }
                else{
                    cout << "invalid input" << endl;    //print Statement
                }
            }
            else{
                cout << "invalid input" << endl;    //print Statement
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////
/*
    rest:
    runs resting functionality
    
    create a random num of days
    calculate how many pounds of food would be consumed
    set the player object with the new values
*/
//////////////////////////////////////////////////////////////////////////
void Game :: rest(){
    int poundsOfFood = myPlayer.getSupplies().getPoundsOfFood();    //get poundsOfFood from player and set it to pounds of Food
    Supplies tempSupplies = myPlayer.getSupplies();     //init tempSupplies to myPlayer.getSupplies() method
    
    int days = rand() % 3 + 1;  //create a random number inbetween 1 and 3 called days
    
    int playersAlive = numPlayerAlive();    //set playersAlive to the result of the playersAlive method
    int foodConsumed = 3*days*playersAlive;     //set foodConsumed to 3 times days * playersAlive
    
    poundsOfFood = poundsOfFood - foodConsumed; //subtract foodConsumed from poundsOfFood
    
    cout << "You have rested for " << days << " day(s) and consumed " << foodConsumed << " pounds of food in the process" << endl;  //print statement
    
    tempSupplies.setPoundsOfFood(poundsOfFood); //set poundsOfFood to the given num
    myPlayer.setSupplies(tempSupplies);     //set the supplies of the player to the given supply
    myDate.addDays(days);   //add the amount of days to the date
}
//////////////////////////////////////////////////////////////////////////
/*
    continueOn:
    runs the travelling functionality
    
    randomize a number for how far the player travels
    check if that distance reaches a milestone and act accordingly
    check if the player has reached oregon
    remove the food eaten as needed
    set food and add the corrent number of days
*/
//////////////////////////////////////////////////////////////////////////
void Game :: continueOn(){
    int milesTravelledTurn = rand() % 70 + 70;      //create random number between 70 and 140
    if(milesTravelledTurn + milesTravelled >= myMilestones.getDistance(milestoneIndex)){        //if milestone would be reached
        cout << "You were prepared to travel " << milesTravelledTurn << " miles but" << endl;   //print Statement
        reachedMilestone();     //run reachedMiestone method
        milesTravelledTurn = myMilestones.getDistance(milestoneIndex) - milesTravelled; //alter milestravelled
        milestoneIndex++;   //add one to mileStone index
    }
    if(milesToGo + milesTravelledTurn <= 0){    //if oregon would be reached
        cout << "You have reached Oregon!!!" << endl;   //print Statement
        milesTravelledTurn = milesToGo; //set milesTravelled to milesToGo
    }
    
    Supplies tempSupplies = myPlayer.getSupplies(); //get playerSupplies
    int poundsOfFood = myPlayer.getSupplies().getPoundsOfFood();    //getPounds Of Food
    int days = 14;  //set days tp 14
    int playersAlive = numPlayerAlive();    //set playersAlive to alive function
    int foodConsumed = 3*days*playersAlive;     //calcualte food consumed
    
    if(foodConsumed > poundsOfFood){    //if too much food is consumed
        foodConsumed = poundsOfFood;    //change amount consumed
    }
    poundsOfFood = poundsOfFood - foodConsumed; //set pounds of food - food consumed
    
    cout << "You have travelled " << milesTravelledTurn << " miles and consumed " << foodConsumed << " pounds of food in the process" << endl;  //print Statement
    
    tempSupplies.setPoundsOfFood(poundsOfFood);     //set poundsOf food
    myPlayer.setSupplies(tempSupplies);     //set player supply object
    addMiles(milesTravelledTurn);       //add the amount of milesTravelled
    myDate.addDays(days);       //add the given amount of days
}
//////////////////////////////////////////////////////////////////////////
/*
    successfulHunt:
    finds if a given hunt is successful
    
    
*/
//////////////////////////////////////////////////////////////////////////
bool Game :: successfulHunt(string animal, int bullets){
    bool loop = true;   //init loop to true
    bool result = false;    //init result to false
    string input;       //create string input
    while(loop){        //loop while loop is true
        cout << "You have encountered a " << animal << "! Do you wish to hunt? (y/n)" << endl;  //print Statement
        getline(cin,input);     //get user input
        if(tolower(input[0]) == 'y'){       //if initial input is y
            if(bullets > 10){       //if bullets is greater than 10
                if(puzzle()){       //if puzzle returns true
                    result = true;      //set result to true
                }
            }
            else{
                cout << "You do not have enough bullets to hunt" << endl;   //print Statement
            }
            loop = false;   //set loop to false
        }
        else if(tolower(input[0]) == 'n'){
            loop = false;
        }
        else{
            cout << "invalid input" << endl;    //print Statement
        }
    }
    return result;
}
//////////////////////////////////////////////////////////////////////////
/*
    animalHunt:
    runs hunting for specific animals
    
    
*/
//////////////////////////////////////////////////////////////////////////
bool Game :: animalHunt(string animalName, int& poundsOfFood, int& bullets, int percentage, int foodChange, int bulletChange){
    bool success = false;
    if((rand() % 100) < percentage){
        if(successfulHunt(animalName, bullets)){
            poundsOfFood += foodChange;
            bullets -= bulletChange;
            success = true;
        }
        Util().printSep();
    }
    return success;
}
//////////////////////////////////////////////////////////////////////////
/*
    hunt:
    runs hunting functionality
    
    
*/
//////////////////////////////////////////////////////////////////////////
void Game :: hunt(){
    Supplies tempSupplies = myPlayer.getSupplies();
    int poundsOfFood = myPlayer.getSupplies().getPoundsOfFood();
    int bullets = tempSupplies.getNumBullets();
    string input;
    bool success = false;
    bool loop = true;
    
    
    if(animalHunt("rabbit",poundsOfFood,bullets,50,2,10)){
            success = true;
    }
    if(animalHunt("fox",poundsOfFood,bullets,25,5,8)){
            success = true;
    }
    if(animalHunt("deer",poundsOfFood,bullets,15,rand() % 15 + 30,5)){
            success = true;
    }
    if(animalHunt("bear",poundsOfFood,bullets,7,rand() % 250 + 100,10)){
            success = true;
    }
    if(animalHunt("moose",poundsOfFood,bullets,5,rand() % 300 + 300,12)){
            success = true;
    }
    
    if(success){
        while(loop){
            cout << "How well do you wish to eat?" << endl;     //print Statement
            cout << "1) Poorly" << endl;        //print Statement
            cout << "2) Moderately" << endl;    //print Statement
            cout << "3) Well" << endl;  //print Statement
            getline(cin,input);
            if(Util().everyCharIsInt(input)){
                int intInput = stoi(input);
                if(intInput >= 1 && intInput < 4){
                    loop = false;
                    int playersAlive = numPlayerAlive();
                    switch(intInput){
                        case 1:
                        {
                            poundsOfFood -= 2*playersAlive;
                            break;
                        }
                        case 2:
                        {
                            poundsOfFood -= 3*playersAlive;
                            break;
                        }
                        case 3:
                        {
                            poundsOfFood -= 5*playersAlive;
                            break;
                        }
                    }
                }
                else{
                    cout << "Invalid input" << endl;    //print Statement
                    Util().printSep();
                }
            }
            else{
                cout << "Invalid input" << endl;    //print Statement
                Util().printSep();
            }
        }
    }
    else{
        cout << "The hunt was unsuccessful" << endl;    //print Statement
    }
    
    tempSupplies.setPoundsOfFood(poundsOfFood);
    myPlayer.setSupplies(tempSupplies);
    myDate.addDays(1);
}
//////////////////////////////////////////////////////////////////////////
/*
    quit:
    quits the game
    
    
*/
//////////////////////////////////////////////////////////////////////////
void Game :: quit(){
    
}
//////////////////////////////////////////////////////////////////////////
/*
    findSicknessname:
    finds the name of a random sickness
    
    switch on a random number 
*/
//////////////////////////////////////////////////////////////////////////
string findSicknessName(){
    int sicknessSwitch = rand() % 5 + 1;
    string sicknessName;

    switch(sicknessSwitch){
        case 1:
        {
            sicknessName = "typhoid";
            break;
        }
        case 2:
        {
            sicknessName = "cholera";
            break;
        }case 3:
        {
            sicknessName = "diarrhea";
            break;
        }case 4:
        {
            sicknessName = "the measles";
            break;
        }
        case 5:
        {
            sicknessName = "dysentery";
            break;
        }
        
    }
    return sicknessName;
}

//////////////////////////////////////////////////////////////////////////
/*
    sickness:
    runs sickness game functions
    
    
*/
//////////////////////////////////////////////////////////////////////////
void Game :: sickness(){
    int sicknessSwitch = rand() % 5 + 1;
    string sicknessName = findSicknessName();
    string input;
    
    bool loop = true;
    string sickName;
    int n;
    
    while(loop){
        n = rand() % 5 + 0;
        if(n < 4){
            if(myPlayer.getCompanion(n).isAlive()){
                sickName = myPlayer.getCompanion(n).getName();
                cout << "Oh No! " << sickName << " has " << sicknessName << "!" << endl;    //print Statement
                loop = false;
            }
        }
        else{
            sickName = "you";
            cout << "Oh No! You have " << sicknessName << '!' << endl;  //print Statement
            loop = false;
        }
    }
    
    loop = true;
    bool survives = true;
    Supplies mySupplies = myPlayer.getSupplies();
    int numMedKits = mySupplies.getNumMedicalKits();
    
    while(loop){
        Util().sicknessUI();
        getline(cin, input);
        if(Util().isValidIntChoice(input,1,3)){
            int intInput = stoi(input);
            if(intInput == 1){
                if(numMedKits >= 1){
                    if(rand() % 2 + 0 == 1){
                        mySupplies.setNumMedicalKits(numMedKits -1);
                        cout << "You have used the medkit successfully," << endl;   //print Statement
                        cout << sickName << " survived" << endl;        //print Statement
                        loop = false;
                    }
                    else{
                        mySupplies.setNumMedicalKits(numMedKits -1);
                        cout << "You used the medkit but it was not successful" << endl;    //print Statement
                        cout << sickName << " died from " << sicknessName << endl;  //print Statement
                        survives = false;
                        loop = false;
                    }
                }
                else{
                    cout << "You have no medkits remaining!" << endl;   //print Statement
                }
            }
            else if(intInput == 2){
                cout << "You rest for three days..." << endl;   //print Statement
                if((rand() % 100) < 30){
                    cout << "but " << sickName << " died from " << sicknessName << endl;    //print Statement
                    survives = false;
                    loop = false;
                }
                else{
                    cout << sickName << " survived" << endl;    //print Statement
                    loop = false;
                }
                myDate.addDays(3);
                mySupplies.setPoundsOfFood(mySupplies.getPoundsOfFood() - 3*3*numPlayerAlive());
            }
            else if(intInput == 3){
                cout << "You continue on..." << endl;   //print Statement
                if((rand() % 100) < 70){
                    cout << sickName << " died from " << sicknessName << endl;  //print Statement
                    survives = false;
                    loop = false;
                }
                else{
                    cout << "miraculously " << sickName << " survived" << endl; //print Statement
                    loop = false;
                }
            }
        }
    }
    
    Companions newCompanion;
    if(!survives){
        if(n < 4){
            newCompanion = myPlayer.getCompanion(n);
            newCompanion.setAliveState(false);
            myPlayer.setCompanion(n, newCompanion);
        }
        else{
            myPlayer.setAliveStatus(false);
        }
    }
    myPlayer.setSupplies(mySupplies);
}


//////////////////////////////////////////////////////////////////////////
/*
    misfortunes:
    runs misfortunes functions
    
    random number between 1 and 3 
    if random is 1
        runs sickness method
    if random is 2
        removes 1 oxen
    if random is 3
        breaks the wagon
        takes 1 wagon part if the user has any remaining
*/
//////////////////////////////////////////////////////////////////////////
void Game :: misfortunes(){
   int n = rand() % 3 + 1;      //random number between 1 and 3
   Supplies mySupplies = myPlayer.getSupplies();
   switch(n){
       case 1:
       {
           sickness();      //runs sickness method
           break;
       }
       case 2:
       {
           int numOxen = mySupplies.getNumOxen() -1;    //sets numOxen to numOxen -1`
           cout << "Oh No! One of your oxen has died! You have " << numOxen << " oxen left" << endl;    //print Statement
           mySupplies.setNumOxen(numOxen);  //sets numOxen
           break;
       }
       case 3:
       {
           int wagonParts = mySupplies.getNumWagonParts();
           cout << "Oh No! One of your wheels has broken" << endl;  //print Statement
           if (wagonParts < 1){
               mySupplies.setWagonStatus(false);    //sets wagonStatus to false
           }
           else{
               mySupplies.setNumWagonParts(wagonParts -1);  //subtracts 1 from wagonParts
           }
           break;
       }
   }
   myPlayer.setSupplies(mySupplies);
}
//////////////////////////////////////////////////////////////////////////
/*
    raiderAttack:
    runs the raider attack functionality
    
    presents user options to do 
        if the choose to run
            subtracts items lost
        
*/
//////////////////////////////////////////////////////////////////////////
void Game :: raiderAttack(){
    string input;
    bool loop = true;       //init loop to true
    int balance = myPlayer.getBalance();    //get player balance
    Supplies mySupplies = myPlayer.getSupplies();   //get playerSupplies
    while(loop){
        Util().raiderAttackUI();
        getline(cin, input);
        if(Util().everyCharIsInt(input)){       //if userinput is valid
            Util().printSep();
            int intInput = stoi(input);
            if(intInput == 1){
                cout << "You escape from the raiders but have left behind:" << endl;    //print Statement
                cout << "1 oxen" << endl;   //print Statement
                cout << "10lbs of food" << endl;    //print Statement
                cout << "1 wagon part" << endl; //print Statement
                mySupplies.setNumOxen(mySupplies.getNumOxen() - 1);
                mySupplies.setPoundsOfFood(mySupplies.getPoundsOfFood() - 10);  //loose 10 pounds
                mySupplies.setNumWagonParts(mySupplies.getNumWagonParts() - 1); //loose 1 wagon part
                loop = false;
            }
            else if(intInput == 2){
                if(puzzle()){   //if puzzle returns true
                    cout << "You have taken 50 lbs of food and 50 bullets from the raiders" << endl;    //print Statement
                    mySupplies.setNumBullets(mySupplies.getNumBullets() + 50);  //add 50 bullets
                    mySupplies.setPoundsOfFood(mySupplies.getPoundsOfFood() + 50);  //add 50 pounds of food
                }
                else{
                    cout << "The raiders have taken 25 percent of your cash" << endl;   //print Statement
                    cout << "You have also lost 50 bullets" << endl;        //print Statement
                    mySupplies.setNumBullets(mySupplies.getNumBullets() - 50);
                    balance = balance - .25*balance;    //lost 25% of balance
                }
                loop = false;
            }
            else if(intInput == 3){ 
                cout << "You have given 25 percent of your cash to the raiders" << endl;    //print Statement
                balance = balance - .25*balance;    //loose 25% of balance   
                loop = false;   //set loop to false
            }
            else{
                cout << "Invalid input" << endl;    //print Statement
            }
        }
        else{
            cout << "Invalid input" << endl;    //print Statement
        }
    }
    if(mySupplies.getNumOxen() < 0){    //checks if a value is negative
        mySupplies.setNumOxen(0);       //sets it to zero
    }
    if(mySupplies.getPoundsOfFood() < 0){   //checks if a value is negative
        mySupplies.setPoundsOfFood(0);      //sets it to zero
    }
    if(mySupplies.getNumWagonParts() < 0){  //checks if a value is negative
        mySupplies.setNumWagonParts(0);     //sets it to zero
    }
    if(mySupplies.getNumBullets() < 0){ //checks if a value is negative
        mySupplies.setNumBullets(0);    //sets it to zero
    }
    
    myPlayer.setSupplies(mySupplies);
    myPlayer.setBalance(balance);   //sets the players balance to the new values
}
//////////////////////////////////////////////////////////////////////////
/*
    Score:
    calculates the score of a given game
    
    gets important user info
    sets score to milestravelled
    if milesTravelled is greater than 1000
        affects the score with an assortment of values with diffrent score values
*/
//////////////////////////////////////////////////////////////////////////
int Game :: score(){
    int score = 0;
    score += milesTravelled;
    if(milesTravelled > 1000){      //if the player travelled over a 1000 miles
        score += 0.5 * myPlayer.getBalance();   //add 1/2 of the players balance to their score
        score += numPlayerAlive() * 10;     //add amount of players remaining * 10 to there score
        score += myPlayer.getSupplies().getNumOxen() * 2;   //add 2 times the amount of oxen remaing to there score
    }
    return score;
}
//////////////////////////////////////////////////////////////////////////
/*
    endGame:
    runs end of game functions
    
    gets important user info
    runs endGameUI method with given param
    runs leaderBoard Method with given param
*/
//////////////////////////////////////////////////////////////////////////
void Game :: endGame(){
    string playerName = myPlayer.getName();     //gets player name and sets it too playerName
    int poundsOfFood = myPlayer.getSupplies().getPoundsOfFood();    //gets food remaining and sets it to poundsOfFood
    int balance = myPlayer.getBalance();    //gets player balance and stores it in balance
    int playerScore = score();  //sets score to the result of the score method
    Util().endGameUI(playerName, milesTravelled, poundsOfFood, balance, playerScore);   //runs endGameUI method
    Util().leaderBoard(playerName,milesTravelled, poundsOfFood, balance, playerScore);  //runs leaderBoard util method
}