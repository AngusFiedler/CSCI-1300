// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 7 #3


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void floodMap(double array[][4], int numOfRows, double currentWaterLevel){
    int columns = 4;    //init columns to 4
    for(int i = 0; i < numOfRows; i++){ //for each row in the array, i++
        for(int j = 0; j < columns; j++){   //for each column in the array
            if(array[i][j] <= currentWaterLevel){   //if the value of the array at i j is less than or eqaul to the current water level
                cout << '*';    //print *
            }
            else    //else...
                cout << '_';    //print _
        }
        cout << endl;   //go to the next line
    }
}

int main(){
    double map[2][4] = {{0.2, 0.8, 0.8, 0.2},{0.2, 0.2, 0.8, 0.5}};
    floodMap(map, 2, 0.0);
}