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
    username = username_;   //set username to the given username
}

int User :: getRatingAt(int index){
    if(index < size){   //as long as the index is less than the size
       return ratings[index];   //return the rating at that index
    }
    else{
        return -1;  //return -1
    }
}

bool User :: setRatingAt(int index, int val){
    if(val >=0 && val <=5 && index < size){ //as long as the rating and index is valid 
        ratings[index] = val;   //set ratings at index to the given val 
        return true;    //return true
    }
    else{
        return false;   //return false
    }
}

int User :: getNumRatings(){
    return numRatings;  //return the val of numRatings
}

void User :: setNumRatings(int numRatings_){
    numRatings = numRatings_;   //set numRatings to the given val
}

int User :: getSize(){
    return size;    //return the val of size
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