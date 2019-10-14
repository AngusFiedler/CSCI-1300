// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Homework 8 / Project 2



#include <iostream>
#include <iomanip>
#include "Library.h"
#include "Book.h"
#include "User.h"
using namespace std;

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
     cout << "6. Add a User" << endl;
     cout << "7. Checkout a book" << endl;
     cout << "8. View Ratings" << endl;
     cout << "9. Get Recommendations" << endl;
     cout << "10. Quit" << endl;
 }



int main(int argc, char const *argv[])
{
	//////////////////////////////////////////////////////////////////////////
	// Your code here. Call the appropriate function(s).
	//////////////////////////////////////////////////////////////////////////
    string fileName;
    string choice;
    string username;
    string bookName;
    string rating;
    int numBooks;
    int numUsers;
    Library mainLibrary = Library();
    while (choice != "10") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                {
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    getline( cin, fileName);    //get the userinput and set it to fileName
                    numBooks = mainLibrary.readBooks(fileName);
                    if (numBooks > 0){  //if numBooks is positive
                        cout << "Total books in the database: " << numBooks << endl;    //print the num of books in  the database
                    }
                    else{
                        cout << "No books saved to the database" << endl;   //print no books saved
                    }
                    cout << endl;   //go to a new line
                    break;
                }
                case 2:
                {
                    // read user file
                    cout << "Enter a rating file name:" << endl;
                    getline(cin, fileName); //get the user input and set it to filename
                    numUsers = mainLibrary.readRatings(fileName);   //set numUsers to the result of readRatings
                    if(numUsers > 0){
                        cout << "Total users in the database: " << numUsers << endl;    //print total users in database + numUsers
                    }
                    else{
                        cout << "No users saved to database" << endl;   //print no users saved to database
                    }
                    cout << endl;   //go to a new line
                    break;
                }
                case 3:
                {
                    mainLibrary.printAllBooks();   //run the printAllBooks function
                    cout << endl;   //go to a new line
                    break;
                }
                case 4:
                {
                    // find the number of books user read
                    cout << "Enter username:" << endl;  //print enter username:
                    getline(cin, username); //get input and set the data to username
                    
                    int numOfRatings = mainLibrary.getCountReadBooks(username);
                    if(numOfRatings >= 0){
                        cout << username << " rated " << numOfRatings << " books" << endl;  //print username ratied numOfRatings...   
                    }
                    cout << endl;   //go to a new line
                    break;
                }
                case 5:
                {
                    // get the average rating of the book
                    cout << "Enter book title:" << endl;    //print Enter book title: 
                    getline(cin, bookName); //get userinput and set it to the bookname
                    double average = mainLibrary.calcAvgRating(bookName);   //run calAvgRating function on mainLibrary given the bookname
                    if (average > 0.0){
                        cout << "The average rating for " << bookName << " is " << fixed << setprecision(2) << average << endl;   //print out the average rating for bookName is AverageRating   
                    }
                    cout << endl;   //go to a new line
                    break;
                }
                case 6:
                {
                    cout << "Enter username:" << endl;    //print Enter username: 
                    getline(cin, username); //get userinput and set it to the username
                    bool resultAddUser = mainLibrary.addUser(username);   //run addUser function on mainLibrary given the username
                    if(resultAddUser){
                        cout << "Welcome to the library " << username << endl;
                    }
                    else{
                        cout << username << " could not be added in the database" << endl;
                    }
                    cout << endl;
                    break;
                }
                case 7:
                {
                    cout << "Enter username:" << endl;
                    getline(cin, username); //get userinput and set it to the username
                    cout << "Enter book title:" << endl;
                    getline(cin, bookName);
                    cout << "Enter rating for the book:" << endl;
                    getline(cin, rating);
                    int ratingInt = stoi(rating);
                    bool result = mainLibrary.checkOutBook(username,bookName,ratingInt);
                    if(result){
                        cout << "We hope you enjoyed your book. The rating has been updated" << endl;
                    }
                    else{
                        cout << username << " could not check out " << bookName << endl;
                    }
                    cout << endl;
                    break;
                }  
                case 8:
                {
                    cout << "Enter username:" << endl;
                    getline(cin, username); //get userinput and set it to the username
                    mainLibrary.viewRatings(username);
                    cout << endl;
                    break;
                }
                case 9:
                {
                    cout << "Enter username:" << endl;
                    getline(cin, username); //get userinput and set it to the username
                    mainLibrary.getRecommendations(username);
                    cout << endl;
                    break;
                }
                case 10:
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
