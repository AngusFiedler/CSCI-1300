// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 5 - Problems #1

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 
/*
    1. init wordCount and sets it equal to 1
    2. checks if the length is zero, if it is sets wordCount to 0
    3. for each char in the string 
        1.If the char at given position i = ' '
            1.Adds 1 to length
    4. returns the word count

*/


int getWordCount(string sentence){
    int wordCount = 1; //sets length to 1 by default
    if (sentence.length() <= 0){    //if the string is empty
        wordCount = 0; //sets wordCount to zero if there are no characters
    }
    for(int i = 0; i < sentence.length(); i++){ //for each char i  the string, i++
        if (sentence[i] == ' '){    //if the char at point = ' '
            wordCount++;   //wordCount + 1
        }
    }
    return wordCount;  //return the value of wordCount
}

int main(){
    cout << getWordCount("");   //test case 1 for word count, should return zero
    cout << getWordCount("Go");   //test case 2 for word count, should return 1
    cout << getWordCount("I went");   //test case 3 for word count, should return 2
}