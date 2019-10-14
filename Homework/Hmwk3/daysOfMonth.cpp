// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Homework 3 - Problems #3

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: Returns the number of days in a given month
*   1. Checks if n is 1,3,5,7,8,10,12
        prints Month n has 31 days
    2. Checks if n is 2
        prints month 2 has 28 or 29 days
    3.Checks if n is 4,6,9,11
        prints month n has 30 days
    4. if n has not been found
        prints Invalid month number
* Parameters:  a given month stored as n(int type)
* Output: Month x has y days
* Returns: None
*/

void daysOfMonth (int n){
    switch (n){     //switch statement given n
        case 1:     //if case 1
        case 3:     //or case 3
        case 5:     //or case 5
        case 7:     //or case 7
        case 8:     //or case 8
        case 10:    //or case 10
        case 12:    //or case 12
            cout << "Month " << n << " has 31 days" << endl;    //prints Month n has 31 days
            break;
        case 2:     // if case 2
            cout << "Month 2 has 28 or 29 days" << endl;    //prints Month 2 has 28 or 29 days
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "Month " << n << " has 30 days" << endl;
            break;
        default:    //default, aka if n cannot be found 
            cout << "Invalid month number"; //prints invalid month number
            break;
    }
    
}

int main(){
    daysOfMonth(3); //test case 1 for daysOfMonth
    daysOfMonth(2); //test case 2 for daysOfMonth
    daysOfMonth(22);//test case 3 for daysOfMonth
}