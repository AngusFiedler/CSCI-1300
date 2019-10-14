#ifndef Game_H
#define Game_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Player.h"
#include "Date.h"
#include "Companions.h"
#include "Supplies.h"
#include "Milestones.h"
#include "Store.h"
using namespace std;

class Game{
    private:
        Player myPlayer;    //player object
        Date myDate;        //date object
        Milestones myMilestones;    //milestone object
        Store myStore;      //store object
        int milesToGo;      //int milesToGo
        int milesTravelled; //int that stores milesTravelled
        int milestoneIndex; //the index of the next mileStone
    public:
    Game(){     //default constructor
        myPlayer = Player();    //sets myPlayer to the default player constructor
        myDate = Date();        //sets date to the default date constructor
        milesToGo = 2040;       //sets miles to go to 2040
        milesTravelled = 0;     //sets milesTravelled to zero
        milestoneIndex = 0;     //sets milestone index to zero
        myStore = Store();
    }
    Game(Player myPlayer_, Date myDate_,Milestones myMilestones_, int milesToGo_, int milesTravelled_, int milestoneIndex_){   //param constructor
        myPlayer = myPlayer_;   //sets myPlayer to the given player object
        myDate = myDate_;       //sets the date object to the given date object
        myMilestones = myMilestones_;
        milesToGo = milesToGo_; //sets milesToGo to the given val
        milesTravelled = milesTravelled_;   //sets milesTravelled to the given val
        milestoneIndex = milestoneIndex_;   //sets milestoneIndex to the given val
        myStore = Store();  //sets myStore to a new store object
    }
    int numPlayerAlive();   //returns the number of players still alive
    
    Player getPlayer(); //returns the player object
    void setPlayer(Player myPlayer_);   //set the player object
    
    Date getDate();     //gets the date object
    void setDate(Date myDate_);     //set the date object
    
    int getMilesToGo(); //return milesToGO as an int
    void setMilesToGo(int milesToGo_);  //set milesToGo
    int getMilesTravelled();
    void addMiles(int milesToAdd);  //add a certain amount of miles effects both miles to go and miles travelled
    
    void statusUpdate(); //prints the users current status
    void turnMenu(); //shows turn menu options
    
    bool puzzle();  //puzzle, returns true if the puzzle is solved
    bool successfulHunt(string animal, int bullets);    //successfulHunt, returns true if the hunt is successful
    
    bool checkForGameEnd(); //checks if game end conditions have been met
    
    void rest();    //run the rest function
    void continueOn();  //run the continue on journey function
    bool animalHunt(string animalName, int& poundsOfFood, int& bullets,int percentage,int foodChange, int bulletChange); //runs a hunt for a specified animal
    void hunt();        //hunt
    void quit();        //quit the game 
    
    void sickness();    //gives a random player a random sickness
    void misfortunes(); //gives a random misfortune to the player
    void raiderAttack();    //causes a raiderAttack 
    
    void reachedMilestone();    //checks what milestone has been reached and prompts the user 

    int score();        //calculates the score of the current Game 
    void endGame();     //runs the methods for the end of game
};
#endif