// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 5 - Problems #2

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;

/*
    1. sets numOfDigits to zero
    2. For each char in the given string, i++
        1.if the char at i is digit
            1.numOFDigits + 1
    3. return numOfDigits
*/

int getDigitCount(string a){
    int numOfDigits = 0;
    for(int i = 0; i < a.length(); i++){
        if (isdigit(a[i]) == 1){
            numOfDigits++;
        }
    }
    return numOfDigits;
}

int main(){
    cout << getDigitCount("a blue house"); //test case 1 for getDigitCount, result should be zero
    cout << getDigitCount("12345"); //test case 1 for getDigitCount, result should be 5
}
