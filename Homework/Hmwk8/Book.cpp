#include "Book.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

string Book :: getTitle(){
    return title;   //return val of title
}
void Book :: setTitle(string title_){
    title = title_; //set title to the input title_
}
string Book :: getAuthor(){
    return author;  //return val of author
}
void Book :: setAuthor(string author_){
    author = author_;   //set the val of author to the given author_
}

/*
int main(){
    Book ng = Book("Test Title", "Test Author");
    std::cout << "Current Author: " << ng.getAuthor() << endl;
    ng.setAuthor("WHIZZ");
    string test = ng.getAuthor();
    std::cout << "Current Author: " << test << endl;
}
*/