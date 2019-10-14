// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Rec 10 Problem 1


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

void modifyVector(vector<int>& v){
    while(true){
        int value = 0;
        cout << "Please enter an integer value:" << endl;
        cin >> value;
        if(value > 0){
            if(v.size() == 0){
                v.push_back(value);
            }
            else{
                if(value%5 == 0){
                    v.erase(v.begin() + 0);
                }
                else{
                    if(value % 3 == 0){
                        v.pop_back();
                    }
                    else{
                        v.push_back(value);
                     }
                }
            }
        }
        else{
            break;
        }
    }
}