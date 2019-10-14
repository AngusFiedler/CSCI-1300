// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 8 Problem 1


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

/*
    init result to false
    create an ifstream called file
    open the filename on file
    check if the file opens
        set result to true;
    return result
*/

bool checkFile(string fileName){
    bool result = false;    //init bool result to false
    ifstream file;  //create an ifstream called file
    file.open(fileName);    //open the file with the var fileName
    
    if(file.is_open()){ //if the file has opened
        result = true;  //set result to false
    }
    return result;  //return the value of result
}

int main(){
    cout << checkFile("wrongfile.txt") << endl; //should return false
    cout << checkFile("correctfile.txt") << endl; //should return true
}