// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 6 - Problem #3

/*
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

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <iterator>
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

int main(){
    string words[6];
    cout << split("one small step",' ',words,6) << endl; //test case 1, should return 3
    cout << words[0] << endl;   //should print one
    
    cout << split("unintentionally",'n',words,6) << endl;   //test case 2, should return 5
    cout << words[1] << endl;   //test case 2, should print i
}