// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Homework 3 - Problems #1

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: calculates the next number in the Collatz sequence based off a given input
*   1. Checks if n is negative, if it is returns 0
    2. then checks if n is even, if it is it divides n by 2 and returns the new value
    3. if the number is not filled by either above statement n is multiplied by 3 then +1, and returns the new value
* Parameters:  a random number, stored as n(int type)
* Output: None
* Returns: the calculated number, n (int type)
*/

int collatzStep (int n){
    if(n < 0){      //checks if n is less than 0
        return 0;   //if n is less than 0 returns 0
    }
    else if (n%2 == 0){ //else checks if n is even
        n = n/2;        //changes n to n/2
        return n;       //returns the new value of n
    }
    else{               //if n was not found in the first 2 cases executes this code
        n = 3*n+1;      //changes n = 3 times n plus 1
        return n;       //returns the new value of n
    }
}

int main(){
    cout << collatzStep(4) << endl; //test case 1 for collatzStep
    cout << collatzStep(7) << endl; //test case 2 for collatzStep
    cout << collatzStep(-5) << endl;//test case 3 for collatzStep
}