// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 6 - Problem #2

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <iterator>
using namespace std;

int main(){
    double temps[10];     //init a float array called temp with a length of 10
    for (int i = 0; i < 10; i++){   //for the total number of positions in the arrray
        temps[i] = -459.67;     //sets the value of temps at position i to -459.67
    }
    string colors[] = {"Red", "Blue", "Green", "Cyan", "Magenta"};  //init string array colors to the given values
    int sequence[100];  //init array sequence to 100 slots
    for (int i = 0; i < 100; i++){  //for each item in the array
        sequence[i] = i+1;      //sets the value of sequance at pos i to i+1       
    }
}