// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 6 - Problem #4


/*
    getScores Method
    create a temp string array with a length of the given length
    create a double named total and set it to the result of the split method
    if the array exist, is larger than 0
        for each item in the array
            get the value from the string array at i and set it to digit
            set the value of the int array at i and set it to the int value of digit
    return total
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int split(string split, char delim, string store[], int length){
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
        if (split[i] == delim || i == split.length() && counter < length){  //checks if split at i is equal to delim and that the counter is not longer than the length
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

int getScores(string scores, int stored[], int length){
    string store[length];   //init an array called store with the given length
    double total = split(scores, ' ', store, length);   //set total equal to the result of the split function
    if(total != -1){    //as long as the array does exist
        for(int i = 0; i < total && i < length; i++){   //for each item in the array
            string digit = store[i];    //set digit, string type to the value at store[i]
            stored[i] = stoi(digit);    //set the value of stored at i equal to the int equivlemnt of the string digit
        }
    }
    
    return total;   //return total 
}

int main(){
    int nums[6];
    getScores("15 2007 5",nums,6);
    //cout << nums[0] << endl;
}