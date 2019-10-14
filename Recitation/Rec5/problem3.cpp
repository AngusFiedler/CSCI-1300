// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 5 - Problems #3

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;

/*
    1. init num to zero
    2. if either the substring or string is less than zero set num to -1
    3. if the substring is longer than the string set num to negative 2
    4. else
        1. for each character in the string
            1. if the substring of a from i to the length of the substring is equal to the substring
                1. num +1
    5. return the vale of num
*/


int getMatchCount(string sub, string a){
    int num = 0;    //init num and sets it equal to 0
    if(sub.length() < 1 || a.length() < 1){ //if either length is zero
        num = -1;   //sets num to -1
    }
    else if(sub.length() > a.length()){  //if the substring is longer than the string
        num = -2;   //sets num to -2
    }
    else{
        for(int i = 0; i < a.length(); i++){    //for each char in the string, i++
            if(a.substr(i, sub.length()) == sub){   //if the substring starting at i is eqaul to the substring
                num++;//num +1
            }
        }
    }
    return num; //return the value of num
}

int main(){
    cout << getMatchCount("si","mississippi"); //test case 1 for getMatchCount, 2
    cout << getMatchCount("ipp","mississippi"); //test case 1 for getMatchCount, 1
}