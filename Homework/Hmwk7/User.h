#ifndef User_H
#define User_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class User{
    private:
        string username;
        int ratings[200];
        int numRatings;
        int size;
    public:
        User(){
            username = "";
            numRatings = 0;
            size = 200;
            ratings[size];
            for(int i = 0; i < size; i++){
                ratings[i] = -1;
            }
        }
        User(string username_, int ratings_[], int numRatings_){
            username = username_;
            numRatings = numRatings_;
            size = 200;
            ratings[numRatings];
            for(int i = 0; i< size; i++){
                ratings[i] = -1;
            }
            for(int i = 0; i < numRatings_; i++){
                ratings[i] = ratings_[i];
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