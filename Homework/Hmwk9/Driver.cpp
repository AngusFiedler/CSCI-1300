// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Homework 9 / Project 3
#include <iostream>
#include "Player.h"
#include "Date.h"
#include "Companions.h"
#include "Supplies.h"
#include "Util.h"
#include "Game.h"
#include "Store.h"
#include "Milestones.h"
#include <cmath>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////
/*
    loadFromSave:
    not implemented
*/
////////////////////////////////////////////////////////////////
void loadFromSave(){
    string fileName;
    cout << "Enter the savegame fileName:" << endl;
    getline(cin, fileName);
    cout << "Still Under Construction..." << endl;
}


////////////////////////////////////////////////////////////////
/*
    inputPlayerName:
    loop while playerName is zero
        print what is the name of your character
        read the userinout into playername

        if the playername is zero
            print you did not enter a name
    return the playerName
*/
////////////////////////////////////////////////////////////////
string inputPlayerName(){
    string playerName = ""; //setplayerName to empty char
    while(playerName.length() == 0){    //loop while playname length is zero
        cout << "What is the name of your character?" << endl;  //print what is the name of...
        getline(cin, playerName);   //get userinput, store into playerName
        
        if(playerName.length() == 0){   //if the playername length is zero
            cout << "You did not enter a name!" << endl;    //print you did not enter...
        }
    }
    return playerName;  //return the playerName
}


////////////////////////////////////////////////////////////////
/*
    createCompanionArray:
    loop equal to true
    while loop
        print enter the name of your first companion
        getuser input save as companionOne
        print enter the name of your second companion
        getuser input save as companionTwo
        print enter third..
        getuser input save as companionThree
        print enter fourth..
        getuser input save as companionFour
    
        if the lenth of all are greater than zero
            set loop to false
        else 
            print it looks like you forgot to enter a companion name


    set each playercompanion given the name and true for them being alive
*/
////////////////////////////////////////////////////////////////
void createCompanionArray(string playerName, Companions playerCompanions[]){
    string companionOne,companionTwo,companionThree,companionFour;  //create strings for all companion names
    bool loop = true;   //init loop to true
    cout << "Welcome " << playerName << ", and what are the names of your companions?" << endl; //print statement
    while(loop){    //loop while loop is true
        cout << "Enter the name of your first companion:" << endl;  //ask for name of companion
        getline(cin, companionOne);     //get userinput and store into CompanionOne
        cout << "Enter the name of your second companion:" << endl; //ask for name of companion
        getline(cin, companionTwo);     //get userinput and store into CompanionTwo
        cout << "Enter the name of your third companion:" << endl;  //ask for name of companion
        getline(cin, companionThree);   //get userinput and store into CompanionThree
        cout << "Enter the name of your fourth companion:" << endl; //ask for name of companion
        getline(cin, companionFour);    ////get userinput and store into CompanionFourt
        if(companionOne.length() > 0 && companionTwo.length() > 0 && companionThree.length() > 0 && companionFour.length() > 0){    //if all companion names are not empty
            loop = false; //set loop to false
        }
        else{
            cout << "It looks like you forgot to enter one of you companion's names!" << endl;  //print that at least companion name was not inputed
        }
    }
    playerCompanions[0] = Companions(companionOne, true);   //set playerCompanions at pos zero to a new companion given the companion name
    playerCompanions[1] = Companions(companionTwo, true);   //set playerCompanions at pos one to a new companion given the companion name
    playerCompanions[2] = Companions(companionThree, true); //set playerCompanions at pos two to a new companion given the companion name
    playerCompanions[3] = Companions(companionFour, true);  //set playerCompanions at pos three to a new companion given the companion name
}


////////////////////////////////////////////////////////////////
/*
    startDate:
    loop while validChoice is false
        print do you want to...
        getUser input into choice
        set valid choice to the result of the isvalidchoice method
    if userinput is n
        print you must choose...
        loop while validchoice is false
            print enter the month..
            getUser input and store as month
            printe enter the day
            getUser input and store to day
            if both day and month are digits
                if the date would be valid
                    set validchoice to true
                else
                    print invalid choice
            else
                print invalid input
        set myDate to the date constrcutor given the month and day
    return myDate
*/
////////////////////////////////////////////////////////////////
Date startDate(){
    Date myDate = Date();   //create a new Date object called myDate
    bool validChoice = false;   //init validChoice to false
    string choice = ""; //create an empty string called choice
    cout << "Your original thoughts were to depart on 03/28/1847" << endl;      //print statement
    while(!validChoice){    //loop while validChoice is false
        cout << "Do you want to stick with this date? (Y/N)" << endl;   //print statement
        getline(cin, choice);   //get user input and store as choice
        validChoice = Util().isValidChoice(choice);     //set valid choice to the result of isValidChoice method
    }
    if(tolower(choice[0]) == 'n'){  //if the first char of choice is the char n
        string month;   //init month 
        string day;     //init day
        validChoice = false;    //init validChoice to false
        cout << "You must choose a date between 03/01/1847 and 05/01/1847" << endl;     //print statement
        while(!validChoice){    //loop while validChoice is false
            Util().printSep();
            cout << "Please enter the month:" << endl;  //print statement
            getline(cin, month);    //get user input and store as month
            cout << "Please enter the day:" << endl;    //print statement
            getline(cin, day);  //get user input and store as day
            if(Util().everyCharIsInt(month) && Util().everyCharIsInt(day) && month.length() > 0 && day.length() > 0){   //if day and month are both digits and have a length longer than 0
                if(myDate.isValidStartDate(stoi(month),stoi(day))){ //if the result of the validStartDate method is true
                    validChoice = true; //set validChoice to true
                }
                else{   //if validStartDate returns false...
                    cout << "invalid date!" << endl;    //print statement
                }
            }
            else{   //in all other cases
                cout << "invalid input, please try again..." << endl << endl;   //print statement
            }
        }
        myDate = Date(stoi(month),stoi(day));   //set date using the param date construtor
    }
    return myDate;  //return myDate
}


////////////////////////////////////////////////////////////////
/*
    getInitSupplies:
    create a string called input
    create a bool called loop and set it to true

    use printTextFromFile given initialStoreText.txt
    loop while loop is true
        print would you like to visit the store?
        get userinput and store as input
        if isValidChoice given input returns true
            if userinput at pos 0 is y
                set myPlayer to the result of the storeMenu function
                set loop to false
            break from the loop
        run printSep method
    return myPlayer
*/
////////////////////////////////////////////////////////////////
Player getInitSupplies(Player myPlayer, Store myStore){
    string input;   //create string called input
    bool loop = true;   //init loop to true

    Util().printTextFromFile("InitialStoreText.txt");   //run printTextFromFile given InitialStoreText.tx
    while(loop){    //loop while loop is true
        cout << endl << "Would you like to visit the store? (Y/N):" << endl;    //print statement
        getline(cin, input);    //get userinput and store as input
        if(Util().isValidChoice(input)){    //if isvalidChoice returns true given the user input
            if(tolower(input[0]) == 'y'){   //if input at pos 0 is the char y
                myPlayer = myStore.storeMenu(myPlayer); //set myPlayer to the result of the storeMenu function given myPlayer
                loop = false;   //set loop to false
            }
            break;  //break from the loop
        }
        Util().printSep();  //print a sep
    }
    return myPlayer;    //return myPlayer
}

////////////////////////////////////////////////////////////////
/*
    gameLoop:
    initialize some varibles

    loop while the result for checkForGame end is false and loop is true
        print a status update
        loop
            turn menu
            if userinput is valid
                break from loop
        switch statement on userInput
            if 1
                run rest method
            if 2 
                run continue method
            if 3
                run hunt method
            if 4
                break from game
        if milesTravelled is > 2040
            print congratz on making it to oregon
        missfortune
        raiderAttack
    endGame function
*/
////////////////////////////////////////////////////////////////
void gameLoop(Game currentGame){
    bool loop = true;   //init loop to true
    bool innerLoop; //create bool innerloop
    string input;   //create string input
    int intInput;   //create int intInput
    
    while(!currentGame.checkForGameEnd() && loop){  //loop while not game end and loop
        innerLoop = true;   //set loop to true
        currentGame.statusUpdate();     //run statusUpdate method
        while(innerLoop){   //loop while innerLoop is true
            Util().printSep();  //printSep method
            Util().turnMenu();  //turnMenu method
            getline(cin, input);    //get user input
            if(Util().isValidIntChoice(input,1,4)){ //if user input is valid
                intInput = stoi(input); //set intInput to userInput
                innerLoop = false;      //set inner loop to false
            }
        }
        switch(intInput){   //run a switch on intInput
            case 1:
            {
                Util().printSep();  //printSep Method
                currentGame.rest(); //run rest method
                break; 
            }
            case 2:
            {
                Util().printSep();  //printSep method
                currentGame.continueOn();   //run continueOn method
                break;
            }
            case 3:
            {
                Util().printSep();  //printSep method
                currentGame.hunt(); //run hunt method
                break;
            }
            case 4:
            {
                loop = false;   //set loop to false
                break;
            }
        }
        if(currentGame.getMilesToGo() == 0){    //if miles to go = zero
            cout << "Congratulations on reaching Oregon!" << endl;  //print statement
            break;  //break from the loop
        }
        Util().printSep();  //printsep method
        if((rand() % 100) < 40){    //40% chance
            currentGame.misfortunes();  //run misfotune method
            Util().printSep();
        }
        int milesTravelled = currentGame.getMilesTravelled();   //init milesTravellled to currentGame.getMileTavelled
        int raiderProbability = 100*(1.0/10.0*((pow(milesTravelled/100-4,2)+72)/(pow(milesTravelled/100-4,2)+12)-1));;  //calculate the probability of raiders
        if((rand() % 100) < raiderProbability){     //run probability
            currentGame.raiderAttack(); //run raiderAttack method
            Util().printSep();
        }
    }
    currentGame.endGame();  //run end of game method
}


////////////////////////////////////////////////////////////////
/*
    newGame:
    printSep method

    create playerName from the inputPlayerName method
    printSep method

    create a companions array
    run createCompanionArray given the companions array
    printSep method 

    create a date called myDate from the result of the startDate function
    printSep method 

    create a new store object called myStore
    create a new Supplies object called mySupplies
    create a new player called myPlayer from the get InitSupplies function with the given params
    create a new milestone called myMilestones from the result of the milestones param constructor
    create a new game called myGame using the given params
    rum the gameLoop function on myGame

*/
////////////////////////////////////////////////////////////////
void newGame(){
    cout << "Starting a new game..." << endl;   //print starting a new game...

    Util().printSep();  //print sep method
    string playerName = inputPlayerName();  //create a string called playerName as the result of the inputPlayerName function
    
    Util().printSep();  //print sep method
    Companions playerCompanions[4];     //create a companions array called playerCompanions with size 4
    createCompanionArray(playerName, playerCompanions);     //run the createCompanionArray given the playerName and the playerComanions array
    
    Util().printSep();  //print sep method
    Date myDate = startDate();  //create a date called myDate from the startDate function
    
    Util().printSep();  //print sep method
    Store myStore = Store();    //create a store called myStore
    Supplies mySupplies = Supplies();   //create a supplies object called mySupplies
    Player myPlayer = Player(playerName,1000, playerCompanions,mySupplies); //create a new player called myPlayer with given param
    myPlayer = getInitSupplies(myPlayer, myStore);  //set myPlayer to the result of the getInitSupplies function
    Milestones myMilestones = Milestones("fort-milestones.txt","river-milestones.txt");  //create a new milestone called myMilestones with the given fileNames
    Game myGame(myPlayer, myDate, myMilestones, 2040, 0,0); //create a new game with the given params
    gameLoop(myGame);   //run the gameLoop function with myGame as a param
}


////////////////////////////////////////////////////////////////
/*
    initialDisplayMenu
    prints intro text
    get userinput
    if userinput is y
        run loadFromSave function
    else if user input is n
        run newGame function
    else
        print invalid user input
        run initialDisplayMenu function
*/
////////////////////////////////////////////////////////////////
void initialDisplayMenu(){
    string choice;  //create a string called choice
    Util().printSep();  //run printSep method from util class
    cout << "Welcome to Oregon Trail!" << endl;     //print Welcome...
    newGame();
    /*
    cout << "Would you like to continue from a last save? (Y/N)" << endl;   //print message
    getline(cin, choice);   //get userinput 
    Util().printSep();  //printSep method from util class
    if(tolower(choice[0]) == 'y'){  //if userinput at first char is y
        loadFromSave();     //run the loadFromSaveOption
    }
    else if(tolower(choice[0]) == 'n'){ //if input at first char is n
        newGame();  //run the newGame function
    }
    else{
        cout << "invalid input" << endl << endl;    //print invalid input
        initialDisplayMenu();   //run this function again
    }
    */

}


////////////////////////////////////////////////////////////////
/*
    main function:
    creates srand
    runs the initial display menu
*/
////////////////////////////////////////////////////////////////
int main(){
    srand (time(NULL));
    initialDisplayMenu();   //run the inital display menu
}