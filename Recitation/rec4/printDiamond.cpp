// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 4 - Problems #3

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: Prints a diamond patern with the side lengths given
*   1. set space counter to length -1
*   2. First print the first half of the diamond
*       1. While my innerCounter is less than my space counter add a space, add 1 to innercounter
*       2. Subtract 1 from the space counter
*       3. Another While loop, while the innerCounter is less than or equal to 2 times the counter -1
*           1.print a "*"
*           2. add 1 to the inner counter
*       4. Go to the next line
    3. Print the second half of the diamond, same steps just more and more spaces instead of less
* Parameters:  a side length (int type)
* Output: a diamond patern based on given side length
* Returns: Nothing
*/

void printDiamond(int length){
    int spaceCounter = length -1;   //initializes the space counter and sets it to the length -1
    int counter = 1;                //initializes the counter to 1
    while(counter <= length){       //continues while the counter is less than or equal to the length
        int innerCounter = 1;       //initializes and sets innerCounter to 1 
        while(innerCounter <=spaceCounter){ //continues while the innerCounter is less than or equal to the space counter
            cout<<" ";              //prints a space
            innerCounter++; //adds 1 to the innercounter
        }
        spaceCounter--; //subtracts 1 from the spaceCounter
        
        innerCounter = 1;   //resets the value of the inner counter to 1 
        while(innerCounter<=2*counter-1){   //while the innerCounter is less than or equal to 2 times the counter -1 
            cout<<"*";      //prints a *
            innerCounter++; //innner counter plus 1 
        }
        cout<<endl; //goes to the next line
        counter++;  //counter +1
    }
    
    spaceCounter = 1;   //resets spacecounter to 1
    counter = 1;        //resets the main counter to 1
    while(counter <= length -1){    //continues while the counter is less than or equal to the length -1
        int innerCounter = 1;       //initializes the inner counter to 1 
        while (innerCounter <= spaceCounter){   //while the innercounter is less than or equal to the space counter
            cout<<" ";                          //prints a space
            innerCounter++;                     //adds 1 to the inner counter 
        }
        
        
        spaceCounter++;     //adds 1 to the spacecounter
        innerCounter = 1;   //resets inner counter to 1
        while (innerCounter <= 2*(length-counter)-1){   //while the inner counter is less than or equal to 2 times (the length - the counter) -1 
            cout<<"*";          //prints a star
            innerCounter++;     //adds 1 to the innercounter
        }
    
    cout<<endl;     //ends the current line / goes to the next line
    counter++;  //adds 1 to the counter
    }
}


int main(){
    printDiamond(4); //test case 1 for print diamond
    printDiamond(3); //test case 2 for print diamond
    printDiamond(10); //test case 3 for print diamond
}