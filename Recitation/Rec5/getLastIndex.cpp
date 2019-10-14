// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 5 - Problems #4

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;

/*
    1. init and set index to -2
    2. if the string is less than 1
        1. sets index to -1
    3.else
        1. for each char in the string, i++
            1. if the char at point i of the string is equal to the given char
                1. index = to i
    4. return index
        
*/


int getLastIndex(char a, string b){
    int index = -2; //init index and sets it to -2
    if(b.length() < 1){ //if the string is empty
        index = -1; //sets index to -1
    }
    else{   //in all other cases
        for(int i = 0; i < b.length(); i++){    //for each char in the string, i++
            if(b[i] == a){  //if the char at pos i of the string equals the char a 
                index = i;  //sets index to i, aka the current index
            }
        }
    }
    return index;   //returns the index 
}

int main(){
    cout << getLastIndex('o', "lollipop") << endl;  //test case 1 for getLastIndex, return 6
    cout << getLastIndex('p', "mississippi") << endl;  //test case 1 for getLastIndex, return 9
}