#include "Book.h"
#include "User.h"

#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

//////////////////////////////////////////////////////////////////////////
/*
    split:
    initilize counter, count and start to zero
    for each time the delim is found at the beginning of the string
        add one to the starting point
    for each char in the split string
        if the delim is found at split[i]
            store(counter) = the substring from start to current pos
            counter +1
            while split[i+1] is equal to delim
                i++
            set start to i + 1
            set count equal to the counter, this is not the most efficient way of doing this
        else 
            count = -1
    return count
*/
//////////////////////////////////////////////////////////////////////////
int split(string split, char delim, string store[], int length){
    if(split.length() < 1){ //checks if the string is empty
        return 0;   //returns 0
    }
    else {
    int counter = 0;    //init counter, int type, to zero
    int count;  //init count, int type,
    int start = 0;  //init start, int type, to zero
    for(int i = 0; split[i] == delim; i++){ //for loop that checks if the string starts with the delim,
        start = i+1;    //if it does, sets the start equal to i + 1
    }
    for (int i = start; i < split.length() + 1; i++){   //for each char in the array, i++
        if ((split[i] == delim || i == split.length()) && counter < length){  //checks if split at i is equal to delim and that the counter is not longer than the length
            if(i < split.length() + 1 && split[i - 1] != delim){    //checks to make sure the last char is not the delim and 
                store[counter] = split.substr(start,i-start);   //stores the substring in the store array at the counter index
                counter++;  //counter + 1
            }
            while (split[i+1] == delim){    //while the next char in the string is equal to the delim
                i++;    //i + 1
            }
            start = i+1;    //sets start to i + 1
            count = counter;    //sets count equal to the counter
        }
        else {  //if there is an error, aka if the string is cut into more pieces than the size of the array
            count = -1; //sets count to -1
        }
    }
    return count;   //returns the value of count
    }
}
//////////////////////////////////////////////////////////////////////////
/*
    readBooks:
    if the filename is empty
        set fileName to books.txt
    create ifstream called file
    open filename on file
    if the file opens
        declare string tempString
        declare a tempArray with length 2
        while loop for everyline of the file
            split the current line with a comma as delim, sets the title to a temp array
            create book object called tempBook set to the constructor Book(tempArray[1], tempArray[0])
            set bookData at numOfBooks to the tempBook;
            add one to numOfBooks
        }
    else
        set numOfBooks to -1
    return val of numOfBooks
*/
//////////////////////////////////////////////////////////////////////////
int readBooks(string fileName, Book bookData[], int numOfBooks, int capacity){
    if (fileName.length() < 1){ //if the fileName is null
        fileName = "books.txt"; //set file name to a default books.txt
    }
    
    ifstream file;  //create an ifstream called file
    file.open(fileName);    //open the file with the var fileName
    
    if(file.is_open()){ //if the file has opened
        string tempString;  //init tempString
        string tempArray[2];    //init tempArray with length 2
        while(getline(file, tempString)){   //while loop for everyline of the file
            split(tempString, ',', tempArray, 2);   //split the current line with a comma as delim, sets the title to a temp array
            Book tempBook = Book(tempArray[1], tempArray[0]);   //create a new book object called tempBook using the book constructor
            bookData[numOfBooks] = tempBook;    //set bookData at numOfBooks to tempBook
            numOfBooks++;    //add one to the counter
        }
    }
    else{
        numOfBooks = -1;    //set numOfBooks to -1
    }
    return numOfBooks;  //return the val of numOfBooks
}
//////////////////////////////////////////////////////////////////////////
/*
    ReadRatings
    if the filename is empty
        set fileName to ratings.txt
    create ifstream call file and open fileName
    
    if the file opens
        init a bunch of varibles
        set i to zero
        while loop for everyline of the file
            int numOfRatings = 0;
            split the current line with a comma as delim, sets the title to a temp array
            set username at pos i to the value of tempArray at zero
            
            set ratingString to the the value at tempArray at pos 1
            run split function on ratings string into arraytwo and set result to int x
            init ratings array with length x
            for loop from zero to x J++
                set tempInt to the int value of tempArrayTwo at j
                if tempInt is between 0 and 5
                    set the value of ratings at i j to the int of array2
                    add one to numOfRatings
                else
                    set ratings at j to -1
            set tempUser to a user constructor given username ratings and the number of ratings
            print current username...
            set users array at numOfUsers+1 to the tempUser
            add one to the counter
    else
        set numOfUsers to -1
    return the val numOfUsers
*/
//////////////////////////////////////////////////////////////////////////
int readRatings(string fileName, User users[], int numOfUsers, int capacity){
    if (fileName.length() < 1){ //if the fileName is null
        fileName = "ratings.txt"; //set file name to a default books.txt
    }
    
    ifstream file;  //create an ifstream called file
    file.open(fileName);    //open the file with the var fileName
    
    if(file.is_open()){ //if the file has opened
        string tempString;  //init tempString
        string tempArray[2];    //init tempArray with length 2
        string username;    //init username
        string tempArrayTwo[capacity];  //init tempArrayTwo at size capacity
        User tempUser;  //init user called tempUser
        int i = 0;  //init i, a counter, to zero
        while(getline(file, tempString)){   //while loop for everyline of the file
            int numOfRatings = 0;
            split(tempString, ',', tempArray, 2);   //split the current line with a comma as delim, sets the title to a temp array
            username = tempArray[0];    //set username at pos i to the value of tempArray at zero
            
            string ratingString = tempArray[1]; //set ratingString to the the value at tempArray at pos 1
            int x = split(ratingString, ' ', tempArrayTwo, capacity);    //run split function and set result to int x
            int ratings[x]; //init ratings array with length x
            for(int j = 0; j < x; j++){    //for each item in the column part of the array
                int tempInt = stoi(tempArrayTwo[j]);    //set tempInt to the int value of tempArrayTwo at j
                if(0 <= tempInt && tempInt <= 5){   //if tempInt is between 0 and 5
                    ratings[j] = stoi(tempArrayTwo[j]);    //set the value of ratings at i j to the int of array2
                    numOfRatings++; //add one to numOfRatings
                }
                else{
                    ratings[j] = -1;    //set ratings at j to -1
                }
            }
            tempUser = User(username, ratings, x);  //set tempUser to a user constructor given username ratings and the number of ratings
            cout << username << "..." << endl;  //print current username...
            users[numOfUsers+i] = tempUser; //set users array at numOfUsers+1 to the tempUser
            i++;    //add one to the counter
        }
        numOfUsers = i + numOfUsers;    //set numOfUsers +i
    }
    else{
        numOfUsers = -1;    //set numOfUsers to -1
    }
    return numOfUsers;  //return the val of numOfUsers
}
//////////////////////////////////////////////////////////////////////////
/*
    printAllBooks:
    if numOfBooks is zero
        print "No books are stored"
    else
        print here is a list of books
        for loop from 0 to the numOFBooks, adding 1 to i each iteration
            print bookData at i getTitle function and bookData at i's getAuthor function
*/
//////////////////////////////////////////////////////////////////////////
void printAllBooks(Book bookData[], int numOfBooks){
    if(numOfBooks == 0){    //if the numOfBooks is zero
        cout << "No books are stored" << endl;  //print no books are stored
    }
    else{
        cout << "Here is a list of books" << endl;  //print here is a list of books
        for(int i = 0; i < numOfBooks; i++){    //for each book, i++
            cout << bookData[i].getTitle() << " by " << bookData[i].getAuthor() << endl;    //print bookData at i get title and bookdata at i getAuthor
        }
    }
}

//////////////////////////////////////////////////////////////////////////



/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
  cout << "Select a numerical option:" << endl;
  cout << "======Main Menu=====" << endl;
  cout << "1. Read book file" << endl;
  cout << "2. Read user file" << endl;
  cout << "3. Print book list" << endl;
  cout << "4. Find number of books user rated" << endl;
  cout << "5. Get average rating" << endl;
  cout << "6. Quit" << endl;
}

int main(int argc, char const *argv[]) {
    string choice;
    string fileName;
    int numBooks = 0;
    int numUsers = 0;
    Book bookData[200];
    User users[200];
    int capacity = 200;
    

    while (choice != "6") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    getline( cin, fileName);    //get the userinput and set it to fileName
                    numBooks = readBooks(fileName, bookData, numBooks, capacity);
                    if (numBooks > 0){  //if numBooks is positive
                        cout << "Total books in the database: " << numBooks << endl;    //print the num of books in  the database
                    }
                    else{
                        cout << "No books saved to the database" << endl;   //print no books saved
                    }
                    cout << endl;   //go to a new line
                    break;

                case 2:
                    // read user file
                    cout << "Enter a rating file name:" << endl;
                    getline(cin, fileName); //get the user input and set it to filename
                    numUsers = readRatings(fileName, users, numUsers, capacity);   //set numUsers to the result of readRatings
                    if(numUsers > 0){
                        cout << "Total users in the database: " << numUsers << endl;    //print total users in database + numUsers
                    }
                    else{
                        cout << "No users saved to database" << endl;   //print no users saved to database
                    }
                    cout << endl;   //go to a new line
                    break;

                case 3:
                    printAllBooks(bookData, numBooks);   //run the printAllBooks function
                    cout << endl;   //go to a new line
                    break;
/*
                case 4:
                    // find the number of books user read
                    cout << "Enter username:" << endl;  //print enter username:
                    getline(cin, username); //get input and set the data to username
                    
                    booksRead = getUserReadCount(username, usernames, ratings, numUsers, numBooks); //set booksRead to the result of getUserReadCount
                    if(booksRead >= 0){ //if books read is positive
                        cout << username << " rated " << booksRead << " books" << endl; //print that username rated numofbooks read
                    }
                    cout << endl;   //go to a new line
                    break;

                case 5:
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;    //print Enter book title: 
                    getline(cin, bookName); //get userinput and set it to the bookname
                    averageRating = calAvgRating(bookName, titles, ratings, 100, 50);   //set averageRating from the calAvgRating function
                    if(averageRating >= 0){ //if the average rating is positive
                        cout << "The average rating for " << bookName << " is " << fixed << setprecision(2) << averageRating << endl;   //print out the average rating for bookName is AverageRating
                    }
                    
                    cout << endl;   //go to a new line
                    break;
                    */
                case 6:
                    // quit
                    cout << "good bye!" << endl;
                    break;

                default:
                    cout << "invalid input" << endl;
                    cout << endl;
            }
    }

    return 0;
}