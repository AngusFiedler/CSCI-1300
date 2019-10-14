// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 8 Problem 2


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

/*
    init result to -1
    init a int varible called square
    create an ofstream called file
    open file with the fileName as a param
    if the file opens successfully
        set result to 0
        for loop between 1 and 10, i++
            set square to i times i
            place the square into the file then go to a new line
    return the result
*/

int fileLoadWrite(string fileName){
    int result = -1;    //init result to -1
    int square; //init a int variable called square
    
    ofstream file;  //create an outstream called file
    file.open(fileName);    //open the file given the fileName
    
    if(file.is_open()){ //if the file has opened
        result = 0; //set result to 0
        for(int i = 1; i < 11; i++){    //for each num betweeen 1 and 10
            square = i*i;   //set square to i times i
            file << square << endl;
        }
    }
    
    
    return result;
}

int main(){
    fileLoadWrite("myFile.txt");    //should print the squares of all numbers between 1 and 10, each on a new line
}