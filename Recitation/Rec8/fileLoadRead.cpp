// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 8 Problem 3


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

/*
    init a int varible called lineCounter to zero
    create a tempstring
    create an ifstream called file and assign in to to the var filename
    if the file opens
        while each line in the file
            Add one to lineCounter
    else
        set lineCounter to -1
    return the value of lineCounter
*/

int fileLoadRead(string fileName){
    int lineCounter = 0;    //init lineCounter to 0
    string tempString;  //create a new string called tempString
    
    ifstream file;  //create new ifstream called file
    file.open(fileName);    //open the given file
    
    if(file.is_open()){ //if the file has opened
        while(getline(file, tempString)){   //for each line in the file
            lineCounter++;  //Add one to lineCounter
        }
    }
    else{
        lineCounter = -1;   //set the value of linecounter to -1
    }
    
    
    return lineCounter; //return the value of lineCounter
}

int main(){
    cout << fileLoadRead("myFile.txt") << endl; //test case 1, should return 10
    cout << fileLoadRead("incorrectFile.txt") << endl; //test case 2, should return -1 as the files dne
}