// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 3 - Problem #2

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: Calculates weekly pay given payrate and number of hours worked 
*   1. Checks if both hours worked and pay rate is positive
        2.if hours worked is less than 40, calculates hours worked times pay rate and returns the value
        3.if hours worked is over 40 calculates the pay for the first 40 hours and stores it as pay
        4.changes pay equal to pay + (hoursworked - 40)*payrate*1.5 to find the overtime pay added to base pay
        5.returns the total pay
    2.returns -1 if either payrate or hours worked is negative
* Parameters:  hoursWorked (type double), payrate(type double)
* Output: None
* Returns: the total pay (type double)
*/

double calcPay (double hoursWorked, double payRate){
    if(hoursWorked >= 0 && payRate >= 0){     //checks that both hours worked and payRate is positive
        if (hoursWorked <= 40){             //checks if hours worked is less than 40
            return hoursWorked * payRate;   //if it is it simply returns the pay, hours worked * payrate
        }
        else{                               //if more than 40 hours were worked
            double pay = 40*payRate;        //sets pay equal to 40*payrate
            pay = pay + (hoursWorked - 40)*(payRate * 1.5); //resets the value of pay to pay + pay made in overtime 
            return pay;     //returns the calculated pay
        }
    }
    else
        return -1;      //if hours worked or payrate is negative returns -1
}

int main(){
    cout << calcPay(41,10) << endl; //test case 1 for calcPay
    cout << calcPay(-41,10) << endl; //test case 2 for calcPay
    cout << calcPay(30,10) << endl; //test case 3 for calcPay
}
