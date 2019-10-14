#ifndef Library_H
#define Library_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "User.h"
#include "Book.h"
using namespace std;

class Library{
    private:    //declare some private varibles
        Book books[200];
        User users[200];
        int numBooks;
        int numUsers;
        const int sizeBook = 200;
        const int sizeUser = 200;
        
    public:
        Library(){
            numBooks = 0;
            numUsers = 0;
        }
        int readBooks(string fileName);
        int readRatings(string fileName);
        void printAllBooks();
        int getCountReadBooks(string username);
        double calcAvgRating (string title);
        bool addUser(string username);
        bool checkOutBook(string username, string title, int rating);
        void viewRatings(string username);
        void getRecommendations(string username);
};
#endif