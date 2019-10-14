// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 4 - Problems #1

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: Prints out all even numbers up to a given num
*   1. initializes count to the value 2
    2. while count is less than or equal to num
        3. Print the current value of count
        4. change count equal to count +2
* Parameters:  a random number, stored as num(int type)
* Output: all even nums between zero and given value
* Returns: None
*/

void printEvenNums (int num){
    int count = 2;      //initializes count to the value 2
    while(count <= num){    //countinues while count is less than or euqal to the given num
        cout << count << endl;  //prints the current value of count
        count = count + 2;  //adds two to count
    }
}

int main(){
    pointEvenNums(10); //test case 1 for pointEvenNums
    pointEvenNums(0);   //test case 2 for pointEvenNums
    pointEvenNums(100); //test case 3 for pointEvenNums
}