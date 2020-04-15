#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 

int CountLower(string input){
    int counter = 0;
    if(input.length()<1){
        counter = -1;
    }
    else{
        for(int i = 0; i < input.length(); i++){
            if(islower(input[i])){
                counter++;
            }
        }
        if (counter == 0){
            counter = -2;
        }
    }
    return counter;
}

void PrintZeros(string str){
    for(int i = 0; i < str.length(); i++) {
        if (str[i] == '0') {
            cout << str[i];
        }
    }
}

void dotsAndDashes(int n){
    for (int i = 1; i <= n; i++){
        for(int j=0; j < i; j++){
            if(i%2==0){
                cout << "-";
            }   
            else{
                cout<<".";
            }
        }
        cout << endl;
  }
}

string removeDigits(string str){
    int count = 0;
    string finalString;
    string array[str.size()];
    for(int i = 0; i < str.size(); i++){
        if (!((str[i] >= 'a' && str[i]<='z') || (str[i] >= 'A' && str[i]<='Z') || (str[i] == ' '))){
        }
        else{
            str[count] = str[i];
            array[count] = str[i];
            count++;
        }
        
    }
    if (count == 0){
        str = "";
    }
    else if(count < str.length()){
        for(int i = count; i < str.size(); i++){
            str[i] = '\0';
        }
    }
    string test = "";
    for(int i = 0; i < count; i++){
        test = test + array[i];
    }
    return test;
}

int main(){
   //cout << CountLower("Test") << endl;
   //PrintZeros()
   //dotsAndDashes(3);
   //cout << removeDigits("123132Hello Computer Science World21324") << endl;
   cout << removeDigits("H2e5l6l8oWorld");
}

/*
string removeDigits(string str){
    int count = 0;
    for(int i = 0; i < str.size(); i++){
        if (!((str[i] >= 'a' && str[i]<='z') || (str[i] >= 'A' && str[i]<='Z') || (str[i] == ' '))){
            str[i] = '\0';
        }
        else{
            count++;
        }
    }
    if (count == 0){
        str = "";
    }
    return str;
}
*/
