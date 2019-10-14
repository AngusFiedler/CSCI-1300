#ifndef Book_H
#define Book_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Book{
    private:    //declare some private varibles
        string title;  
        string author;
    public:
        Book(){ //basic constructor
            title = ""; //set title to blank
            author  = "";    //set author to blank
        }
        Book(string title_, string author_){
            title = title_; //set title to title_
            author = author_;   //set author to author_
        }
        string getTitle();  //declare getTitle function
        void setTitle(string title_);   //declare setTitle function
        string getAuthor(); //declare getAuthor function
        void setAuthor(string author_); //declare setAuthor function
};
#endif