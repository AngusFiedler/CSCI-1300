#include <iostream>
#include "Util.h"
#include <fstream>
#include <vector>
using namespace std;

Util :: Util(){
}

//////////////////////////////////////////////////////////////////////////
/*
    SicknessUI:
    prints ui elements
*/
//////////////////////////////////////////////////////////////////////////
void Util :: sicknessUI(){
    cout << "How would you like to proceed?" << endl;
    cout << "1) Use medical Kit" << endl;
    cout << "2) Rest for three days" << endl;
    cout << "3) Press on!" << endl;
}
//////////////////////////////////////////////////////////////////////////
/*
    turnMenu:
    prints ui elements
*/
//////////////////////////////////////////////////////////////////////////
void Util :: turnMenu(){
    cout << "1) Stop and rest" << endl;
    cout << "2) Continue on your journey" << endl;
    cout << "3) Hunt" << endl;
    cout << "4) Quit" << endl;
}
//////////////////////////////////////////////////////////////////////////
/*
    raiderAttackUI:
    prints ui elements
*/
//////////////////////////////////////////////////////////////////////////
void Util :: raiderAttackUI(){
    cout << "Riders ahead! They look hostile!" << endl;
    cout << "How would you like to respond?" << endl;
    cout << "1) RUN!" << endl;
    cout << "2) ATTACK!" << endl;
    cout << "3) Surrender..." << endl;
}
//////////////////////////////////////////////////////////////////////////
/*
    printStoreOptions:
    prints ui elements
*/
//////////////////////////////////////////////////////////////////////////
void Util :: printStoreOptions(){
    cout << "1) Oxen" << endl;
    cout << "2) Food" << endl;
    cout << "3) Ammunition" << endl;
    cout << "4) Miscellaneous Supplies" << endl;
    cout << "5) Exit Store" << endl;
}
//////////////////////////////////////////////////////////////////////////
/*
    endGameUI:
    prints end of game ui elements
*/
//////////////////////////////////////////////////////////////////////////
void Util :: endGameUI(string playerName, int milesTravelled, int poundsOfFood, int balance, int score){
    cout << endl;
    Util().printSep();
    cout << "Final Stats:" << endl;
    cout << "Party Leader: " << playerName << endl;
    cout << "Miles Travelled: " << milesTravelled << endl;
    cout << "Food Remaining: " << poundsOfFood << "lbs" << endl;
    cout << "Money Remaining: $" << balance << endl;
    cout << "Total Score: " << score << endl;
    Util().printSep();
    cout << endl;
}

//////////////////////////////////////////////////////////////////////////
/*
    split:
    initilize counter, count and start to zero
    for each time the delim is found at the beginning of the string
        add one to the starting point
    for each char in the split string
        if the delim is found at split[i]
            store(counter) = the substring from start to current pos
            counter +1
            while split[i+1] is equal to delim
                i++
            set start to i + 1
            set count equal to the counter, this is not the most efficient way of doing this
        else 
            count = -1
    return count
*/
//////////////////////////////////////////////////////////////////////////
int Util :: split(string split, char delim, string store[], int length){
    if(split.length() < 1){ //checks if the string is empty
        return 0;   //returns 0
    }
    else {
    int counter = 0;    //init counter, int type, to zero
    int count;  //init count, int type,
    int start = 0;  //init start, int type, to zero
    for(int i = 0; split[i] == delim; i++){ //for loop that checks if the string starts with the delim,
        start = i+1;    //if it does, sets the start equal to i + 1
    }
    for (int i = start; i < split.length() + 1; i++){   //for each char in the array, i++
        if ((split[i] == delim || i == split.length()) && counter < length){  //checks if split at i is equal to delim and that the counter is not longer than the length
            if(i < split.length() + 1 && split[i - 1] != delim){    //checks to make sure the last char is not the delim and 
                store[counter] = split.substr(start,i-start);   //stores the substring in the store array at the counter index
                counter++;  //counter + 1
            }
            while (split[i+1] == delim){    //while the next char in the string is equal to the delim
                i++;    //i + 1
            }
            start = i+1;    //sets start to i + 1
            count = counter;    //sets count equal to the counter
        }
        else {  //if there is an error, aka if the string is cut into more pieces than the size of the array
            count = -1; //sets count to -1
        }
    }
    return count;   //returns the value of count
    }
}

//////////////////////////////////////////////////////////////////////////
/*
    printSep:
    prints a set number of dashes to seperate ui elements
    loop from zero to 75
        print a dash
    go to a new line
*/
//////////////////////////////////////////////////////////////////////////
void Util :: printSep(){
    for(int i = 0; i < 75; i++){    //loop from zero to 75
        cout << "-";    //print a dash
    }
    cout << endl;   //go to a new line
}


//////////////////////////////////////////////////////////////////////////
/*
    everyCharIsInt:
    checks if every char in a given string is a digit

    if the length of the string is zero
        set result to false
    loop from zero to temp length
        if temp at pos i is not a digit
            set result to false
    return result
*/
//////////////////////////////////////////////////////////////////////////
bool Util :: everyCharIsInt(string temp){
    bool result = true;     //init result to true
    if(temp.length() <= 0){ //if temp is empty
        result = false;     //set result to false
    }
    for(int i = 0; i < temp.length(); i++){     //loop from zero to temp length, i++
        if(!isdigit(temp[i])){  //if temp at pos i is not a digit
            result = false;     //set result to false
        }
    }
    return result;  //return the val of result
}


//////////////////////////////////////////////////////////////////////////
/*
    isValidInitChoice:
    checks if a given string is a digit with the given param

    set result to the result of the everychar is int function
    if result is true
        set tempInt to the int value of temp
        if tempInt is less than min or greater than max
            set result to false
    if result is false
        print invalid input...
    return result
*/
//////////////////////////////////////////////////////////////////////////
bool Util :: isValidIntChoice(string temp, int min, int max){
    bool result = everyCharIsInt(temp);     //init result to the result of the everCharIsInt function
    if(result){     //if result is true
        int tempInt = stoi(temp);   //set tempInt to the int value of temp
        if(tempInt < min || tempInt > max){     //if tempInt is outside of the given bounds
            result = false;     //st result to false
        }
    }
    if(!result){    //if result is false
        cout << "invalid input!" << endl;   //print invalid...
    }
    return result;  //return result
}


//////////////////////////////////////////////////////////////////////////
/*
    isValidChoice:
    checks if given string has the char y or n

    if choice at first pos is n
        return true
    else if choice at pos 1 is y
        return true
    else
        print invalid value
        return false
*/
//////////////////////////////////////////////////////////////////////////
bool Util :: isValidChoice(string choice){
    if(tolower(choice[0]) == 'n'){  //if choice at pos 0 is n
        return true;    //return true
    }
    else if(tolower(choice[0]) == 'y'){     //if choice at pos 1 is y
        return true;    //return true
    }
    else{
        cout << "incorrect value" << endl;  //print incorrect value
        return false;   //return false
    }
}


//////////////////////////////////////////////////////////////////////////
/*
    printTextFromFile:
    prints all text from a given file

    create ifstream called file 
    open the given filename
    if the file opens
        while loop through each line of the file
            print the current line
*/
//////////////////////////////////////////////////////////////////////////
void Util :: printTextFromFile(string fileName){
    string tempString;  //create tempString
    ifstream file;  //create an ifstream called file
    file.open(fileName);    //open the file with the var fileName
    
    if(file.is_open()){ //if the file has opened
        while(getline(file,tempString)){    //loop through each line of the file
            cout << tempString << endl;     //print the current line
        }
    }
}

//////////////////////////////////////////////////////////////////////////
/*
    leaderBoard:
    adds current player score to leaderboard

    init all needed varibles
    open the leaderboard file
        loop through each line of the file
            run split function to remove the current pos
            run split function to get to each catagory
            set scoreTemp to the int value of the score pos
            if scoreTemp is greater than score
                add the current line to the vector
            else if the score has not been added
                add the playerText to the vector
                add currentline to vecoter
                set scoreAdded to true
            else
                add current line to vector
    else
        print file could not be found
    if the player was not added
        add playerText to the vector
    
    loop through each item in the vector
        add the vector at i to the file

*/
//////////////////////////////////////////////////////////////////////////
void Util :: leaderBoard(string playerName, int milesTravelled, int poundsOfFood, int balance, int score){
    vector<string> result;      //create a vector called result
    string playerText = playerName + " || Score: " + to_string(score) + " || " + to_string(milesTravelled) + " miles || " + to_string(poundsOfFood) + "lbs || $" + to_string(balance);

    ifstream file;  //create an ifstream called file
    file.open("leaderBoard.txt");   //open leaderBoard.txt

    string tempString;  //init tempString
    int tempMilesTravelled, scoreTemp;     //init tempMilesTravelled and scoreTemp
    string removeCurrentPos[2];     //create removeCurrentPos array of size 2
    string tempScore[4];        //create tempScore array with size 4
    bool playerScoreAdded = false;      //init playerScoreAdded to false

    if(file.is_open()){     //if the file opens
        while(getline(file, tempString)){       //loop through each line of the file
            Util().split(tempString,'.', removeCurrentPos,2);   //run split function on tempstring
            Util().split(removeCurrentPos[1], ' ', tempScore,4);    //run split on removeCurrentPos at 1
            scoreTemp = stoi(tempScore[3]); //set scoreTemp to int value of tempScore at 3
            if(scoreTemp > score){  //if scoreTemp is greater than score
                result.push_back(removeCurrentPos[1]);  //add the current line to the vector
            }
            else if(!playerScoreAdded){     //else if playerScoreAdded is false
                result.push_back(playerText);   //add the currentplayer to the vector
                result.push_back(removeCurrentPos[1]);  //add the current line to the vecotor
                playerScoreAdded = true;    //set playerScoreAdded to true
            }
            else{
                result.push_back(removeCurrentPos[1]);      //add the currentline to the vector
            }
        }
    }
    else{
        cout << "Leaderboard file could not be found and will be created" << endl;  //print statement
    }

    if(!playerScoreAdded){  //if the playerScore was not added
        result.push_back(playerText);   //add the player score to the vector
    }
    ofstream newFile;   //create a of stream called newFile
    newFile.open("leaderBoard.txt");    //open leaderBoard.txt with newFile
    for(int i = 0; i < result.size(); i++){     //loop from zero to the size of the vector
        tempString = to_string(i+1) + '.' + result.at(i);   //set tempString the the result line text
        newFile << tempString << endl;  //add the tempString to the file
    }
}