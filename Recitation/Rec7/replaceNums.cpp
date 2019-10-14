// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 7 #1


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void replaceNums(int array[], int arrayLength){
    int tempArray[arrayLength];
    for(int i = 1; i < arrayLength -1; i++){    //for loop, for every element but the first and last
        if(array[i-1] > array[i+1] && array[i-1] > array[i]){    //if the num at the pos before i is greater than the pos i+1
            tempArray[i] = array[i-1];  //set tempArray at i equal to the num at i-1
        }
        else if(array[i+1] > array[i-1] && array[i+1] > array[i]){    //if i+1 is greater then i-1 and i
            tempArray[i] = array[i+1];  //set tempArray at i equal to the num at i+1
        }
        else
            tempArray[i] = array[i];    //set temp array at i equal to array at i
    }
    for(int i = 1; i < arrayLength -1; i++){    //for each element in the array
        array[i] = tempArray[i];    //set the values of the array with the temp values
    }
}

int main(){
    int myArray[5] = {5, 4, 3, 2, 1};
    int arrayLength = 5;
    replaceNums(myArray, arrayLength);
    for(int i = 0; i < arrayLength; i++){
        cout << myArray[i] << endl;
    }
}