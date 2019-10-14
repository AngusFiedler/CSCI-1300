// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 3 - Problems #1

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: Checks if a given number is positive, negative, or zero!
*   1. Checks if n is less than 0, if it is prints "negative"
    2. Checks if n is greater than 0, if it is prints "positive"
    3. Checks if n is equal to zero, if it is returns "zero"
* Parameters:  a random number, stored as n(int type)
* Output: "negative" , "positive" , or "zero" depending on what is found
* Returns: None
*/

void numberSign (int n){
    if (n < 0){             //checks if n is negative
        cout << "negative"; //prints "negative" if n is negative
    }
    else if (n > 0){        //checks if n is positive
        cout << "positive"; //prints "positive" if n is positive
    }
    else if (n == 0){       //checks if n is equal to 0
        cout << "zero";     //returns "zero" if n is equal to 0
    }
}

int main(){
    numberSign(4);  //test case 1 for numberSign
    numberSign(-4); //test case 2 for numberSign
    numberSign(0);  //test case 3 for numberSign
}