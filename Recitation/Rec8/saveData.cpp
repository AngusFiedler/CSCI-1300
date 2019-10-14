// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 8 Problem 4

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

/*
    init average
    init sum to zero
    init counter to zero
    
    create ofstream called file
    open file given the fileName
    
    if the file opens
        for loop through from zero to n, i++
            set sum equal to sum + the double stored at data[i]
            add one to counter
        set average to sum divided by counter
        add the name plus data at n to line one of file
        add the average to the second line of the file
    else
        print file open failed

*/

void saveData(string fileName, string data[], int n, int arraySize){
    double average; //init average 
    double sum = 0; //init sum to zero
    int counter = 0;    //init counter to zero
    
    ofstream file;  //init ofstream called file
    file.open(fileName);    //open fileName on file
    
    if(file.is_open()){
        if (data[0] != ""){ //if the array is empty
            for(int i = 0; i < n; i++) {    // for loop from 0 to n, i++
                sum = sum + stod(data[i]);  //set sum to sum + the double value of data at i
                counter++;
            }
            average = sum/counter;  //set average to sum divided by counter
            file << "Name: " << data[n] << endl;    //inset name + data[n] to the file and go to a new line
            file << "Avg: " << average; //place avg: + average to the file
        }
    }
    else{
        cout << "file open failed"; //print file open failed 
    }
}

int main(){
    string data[4] = {"2.3", "-1.5", "0.8", "Garth"};   //test case data
    saveData("my_data.txt", data, 3, 4);    //run save data
}