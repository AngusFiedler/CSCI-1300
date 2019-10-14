// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Homework 3 - Problems #2

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: Counts the number of digits in a given number
*   1. Checks if n is less than zero, if it is it multiplies by -1 to become a positive
    2. Checks if n is equal to zero, if it is it returns 1;
    2. initializes the digits varible with the value 0
    3. While loop that continues until n is less than 0
        1.sets n = n/10
        2. adds 1 to digits 
    4. returns the number of digits
* Parameters:  a random number, stored as n(int type)
* Output: None
* Returns: the number of digits in the given number(int type)
*/

int countDigits(int n){
    if (n < 0){     //checks if n is negative
        n = n*(-1); //if n is negative multiplies n by -1 to change n to a positive
    }
    if(n==0){       //checks if n is equal to zero
        return 1;   //if n is equal to zero, returns 1
    }
    
    int digits = 0; //initializes digits with the value 0
    while(n > 0){   //while loop while n is positive
        n = n/10;   //changes n = n/10
        digits++;   //adds 1 to the digits counter
    }
    return digits; //returns the number of digits
}

int main(){
    cout << countDigits(3) << endl; //test case 1 for countDigits
    cout << countDigits(75) << endl; //test case 2 for countDigits
    cout << countDigits(-200) << endl; //test case 3 for countDigits
}