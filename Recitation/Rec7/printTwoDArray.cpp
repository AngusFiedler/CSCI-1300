// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 7 #2


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void printTwoDArray(int array[][5], int arrayLength){
    int arrayWidth = 5; //set arrayWidth to 5
    if(arrayLength == 0){   //if the array length is 0
        cout << 0;  //print 0
    }
    else if(arrayLength < 0){   //if the array length is negative
        cout << -1; //print -1
    }   
    else
        for(int i = 0; i < arrayLength; i++){   //for each row of the array, i++
            for(int j = 0; j < arrayWidth; j++){    //for each column of the array, j++
                cout << array[i][j];    //print out the value in the array at i j
                if(j != arrayWidth -1){ //as long as j is not at the last term
                    cout << ',';    //print out a comma
                }
            }
            cout << endl;   //go to a new line
        }
}

int main(){
    int myArray[3][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    printTwoDArray(myArray, 3);
}