#ifndef Util_H
#define Util_H
#include <iostream>
using namespace std;

class Util{
    public:
        Util(); //default constructor
        void printSep();    //prints out a seperation
        void sicknessUI();  //prints the sickness ui
        void turnMenu();    //prints the turnMenu ui
        void raiderAttackUI();  //prints the raiderAttack UI
        void printStoreOptions();    //prints the storeOptions UI
        void endGameUI(string playerName, int milesTravelled, int poundsOfFood, int balance, int score);   //prints the end of gameUI

        int split(string split, char delim, string store[], int length);
        bool everyCharIsInt(string temp);   //checks if every char in a string is a digit
        bool isValidIntChoice(string temp, int min, int max);   //checks if a given string is a int which falls inbetween the given min and max
        bool isValidChoice(string choice);  //checks if a given string contains either a y char on n char in the first pos

        void printTextFromFile(string fileName);    //prints all text from a given file

        void leaderBoard(string playerName, int milesTravelled, int poundsOfFood, int balance, int score);  //prints results to the leaderBoard
};
#endif
