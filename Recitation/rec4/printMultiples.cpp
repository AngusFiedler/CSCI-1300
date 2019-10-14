// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 4 - Problems #2

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: Prints all multiples of a given number up to a given max value
*   1. Checks if n is positive
*   2. initializes counter to the value of n
    3. while counter is less than or equal to max value
        4. Print the current value of counter
        5. change value of counter equal to counter +n
* Parameters:  a given num(int type) and a given max(int type)
* Output: all multiples of a number up to the max value
* Returns: None
*/

void printMultiples(int n, int max){
    if (n > 0){             //checks if n is positive
        int counter = n;    //initializes counter to the given value n
        while(counter <= max){  //while counter is less than or equal to the max
            cout << counter << endl;    //print the current value of counter
            counter = counter + n;      //changes counter equal to counter + n
        }
    }
}

int main(){
    printMultiples(5,10); //test case 1 for printMultiples
    printMultiples(-1,10); //test case 1 for printMultiples
    printMultiples(7,100); //test case 1 for printMultiples
}