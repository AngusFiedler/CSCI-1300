#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 
//Student id num: 108969832

/*
void printNormalHeartRates(string names[], int heartRates[], int numOfElements){
    for (int i = 0; i < numOfElements; i++){
        if(heartRates[i] >= 70 && heartRates[i] <= 190){
            cout << names[i] << " " << heartRates[i] << endl;
        }
    }
}

int parseScores(string fileName){
    int lineCounter = 0;    //init lineCounter to 0
    string tempString;  //create a new string called tempString
    
    ifstream file;  //create new ifstream called file
    file.open(fileName);    //open the given file
    
    if(file.is_open()){ //if the file has opened
        while(getline(file, tempString)){   //for each line in the file
            if(tempString.length() > 1){
                string tempArray[4];
                Split(tempString, ',', tempArray, 4);
                double averagescore = (stoi(tempArray[0]) +stoi(tempArray[1]) + stoi(tempArray[2]))/3.0;
                cout << tempArray[3] << ": " << averagescore << endl;
                lineCounter++;  //Add one to lineCounter
            }
        }
    }
    else{
        lineCounter = -1;   //set the value of linecounter to -1
    }
    
    
    return lineCounter; //return the value of lineCounter
}

int writeAvg(string fileName; int numArray[], int arrayLength){
    int result = -1;    //init result to -1
    
    ofstream file;  //create an outstream called file
    file.open(fileName);    //open the file given the fileName
    
    if(file.is_open()){ //if the file has opened
        result = 1; //set result to 0
        int total = 0;
        int counter = 0;
        for(int i = 0; i < arrayLength; i++){
            if(numArray[i] >= 0){
                total = total + numArray[i];
                counter++;
            }
        }
        if(counter > 0){
            double average = total/counter;
            file << average;
        }
        else{
            file << 0;
        }
    }
    
    
    return result;
}


*/
int main(){
   int total = 50;
   int table[][3] = {{4,3,5},{0,6,3}, {1,2,2},};
   for (int k = 0; k < 3; k++){
       total = total - table[k][k];
   }
   cout << total;
}


/*
2d array: [rows][columns]
row 1   column 1    column 2
row 2   column 1    column 2

*/