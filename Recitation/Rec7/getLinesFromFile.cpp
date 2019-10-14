// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 7 #4


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int getLinesFromFile(string fileName, int array[], int arrayLength){
    int numAdded = 0;   //init numAdded to zero
    string tempLine;    //init string called tempLine
    
    ifstream file;  //create an ifstream called file
    file.open(fileName);    //open the file with the var fileName
    
    if(file.is_open()){ //if the file has opened
        while(getline(file, tempLine)){ //for each line on the file
            if (tempLine == "") continue;   //if the current line is empty, skip to the next line
            if(numAdded < arrayLength){ //if the num added is less than the array length
                array[numAdded] = stoi(tempLine);   //set the value of array at numAdded to the int value at the current line
                numAdded++; //add 1 to numAdded
            }
            else    //if the num added has filled the array
                break;  //break from the loop
        }
    }
    else{   //if the file cannot be opened
        numAdded = -1;  //set numAdded to -1
    }
    return numAdded;    //return the val of numAdded
}

int main(){
    int arr[4];
    cout << getLinesFromFile("fileName.txt", arr, 4) << endl;
    cout << arr[3];
    
}