#include "Book.h"
#include "User.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

string User :: getUsername(){
    return username;
}

void User :: setUsername(string username_){
    username = username_;
}

int User :: getRatingAt(int index){
    if(index < size){
       return ratings[index]; 
    }
    else{
        return -1;
    }
}

bool User :: setRatingAt(int index, int val){
    if(val >=0 && val <=5 && index < size){
        ratings[index] = val;
        return true;
    }
    else{
        return false;
    }
}

int User :: getNumRatings(){
    return numRatings;
}

void User :: setNumRatings(int numRatings_){
    numRatings = numRatings_;
}

int User :: getSize(){
    return size;
}

/*
int main(){
    User ng = User();
    std::cout << "Size of array: " << ng.getSize() << endl;
    ng.setUsername("Bob");
    string test = ng.getUsername();
    std::cout << "Current User: " << test << endl;
}
*/