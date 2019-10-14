// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 4 - Problems #3

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: 
*   1. initilizes height counter to zero
    2. While width is less than the height counter
        3.Initilizes widthcounter to 0
        4.While width counter is less tha width
            5. Print *
            6. width counter +1
        7. cout " "
        8. width counter to zero
        9. while width counter is less than width
            10. if checks if the height is zero or the width or if widthcounter is zero or the max num
                11. prints "*"
            12. else 
                13. prints " "
            14. widthcounter +1
        15. goes to next line, endl
        16. height counter +1
* Parameters:  
* Output: 
* Returns: 
*/

void printSquares (int width){
    int heightCounter = 0;      //initializes heightcounter to 0
    while (width > heightCounter){  //while width is less than heightcounter
        int widthCounter = 0;       //initilizes widthCounter to zero
        while(widthCounter < width){    //while widthCounter is less than the width
            cout << "*";        //prints "*"
            widthCounter++;     //adds 1 to width counter
        }
        cout << " ";            //prints a space
        widthCounter = 0;       //resets widthcounter to zero
        while(widthCounter < width){ //while widthcounter is less than the width  
            if(widthCounter == 0 || (widthCounter == width-1) || heightCounter == 0 || heightCounter == width-1){   //checks if there should be a *
                cout << "*";    //prints "*"
            }
            else{       //else
                cout << " ";    //prints " "
            }
            widthCounter++;     //widthcounter +1
        }
        cout << endl;       //goes to the next line
        heightCounter++;    //heightCounter +1
    }
}

int main(){
    printSquares(5);    //test case 1 for printSquares
    printSquares(10);   //test case 2 for printSquares
    printSquares(3);    //test case 3 for printSquares
}