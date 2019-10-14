// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 3 - Problem #3

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: Calculates if a year is a leap year 
*   1. Initilizes bool leapYear to false
    2. if year is less than 1582 and has no remainder if divded by 4 changes leapYear to true
    3. Else if the year is divisible by 4 with no remainder and it has a remainder or the year divided by 400 has no remainder
        changes leap year to true;
    4.Returns the value of leapYear
* Parameters:  year(int type)
* Output: None
* Returns: leapYear (bool type) 1 if it is a leap year, 0 if it is not
*/

bool checkLeapYear(int year){
    bool leapYear = false;          //initializes leapYear and sets it to false
    if (year < 1582 && year%4==0){  //checks if the year is less than 1582 and has no remainder if divided by 4
        leapYear = true;            //changes leapYear to true
    }
    else if(year%4 == 0 && (year%100 != 0 || year%400 == 0 )){ //else if year is divisible by 4 with no remainder and is either not divisible by 0 with no remainder or is divisible by 400 with no remainder
            leapYear = true;        //sets leapYear to True
    }
    return leapYear;                //returns the value of leap year
}

int main(){
    cout << checkLeapYear(1900) << endl; //test case 1 for leapYear
    cout << checkLeapYear(2000) << endl; //test case 2 for leapYear
    cout << checkLeapYear(1300) << endl; //test case 3 for leapYear
}
