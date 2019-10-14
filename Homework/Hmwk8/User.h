#ifndef User_H
#define User_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class User{
    private:        //a bunch of private varibles
        string username;
        int ratings[200];   //create a ratings array with a size of 200
        int numRatings;
        int size;
    public:
        User(){ //default constructor
            username = "";  //set username to blank
            numRatings = 0; //set numRatings to zero
            size = 200;     //set size to 200
            ratings[size];  //create ratings array with given size
            for(int i = 0; i < size; i++){  //for loop through the size of the array
                ratings[i] = -1;    //set val of ratings at index i to -1
            }
        }
        User(string username_, int ratings_[], int numRatings_){    //param constructor
            username = username_;   //set username to the given username
            numRatings = numRatings_;   //set numRatings to the given numRatings
            size = 200; //set size to 200
            ratings[numRatings];    //create ratings array
            for(int i = 0; i< size; i++){   //loop through all index's of the array
                ratings[i] = -1;    //set ratings at index i to -1
            }
            for(int i = 0; i < numRatings_; i++){   //loop through the numOfRatings
                ratings[i] = ratings_[i];   //set the val of ratings to the given ratings at index i
            }
        }
        string getUsername();
        void setUsername(string username_);
        int getRatingAt(int index);
        bool setRatingAt(int index, int val);
        int getNumRatings();
        void setNumRatings(int numRatings_);
        int getSize();
};
#endif