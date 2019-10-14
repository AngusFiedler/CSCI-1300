// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Homework 6


#include <iostream>
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
        if (split[i] == delim || i == split.length() && counter < length){  //checks if split at i is equal to delim and that the counter is not longer than the length
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
    findUserIndex:
    Create and set index to -1
    Create and set  i to 0
    While i is less than the numberOfBooks
        If usernames at pos i equals username
            Set index to i
            Break from the loop
        Add 1 to i
    return the value of index

*/
//////////////////////////////////////////////////////////////////////////
int findUserIndex(string username, string usernames[], int numOfUsers){
    int index = -1; //init index to -1
    int i = 0;  //init i to zero
    while(i < numOfUsers){  //while i is less than the number of users
        if(usernames[i] == username){   //if usernames at i is equal to username
            index = i;  //set index to i
            break;  //break from the loop
        }
        i++;    //add one to i
    }
    return index;   //return the value of index
}
//////////////////////////////////////////////////////////////////////////
/*
    findBookIndex:
    Create and set index to -1
    Create and set i to 0
    Loop while i is less than the number of books
        If titles array at i is equal to bookName
            Set index to i+1
            Break from the loop
        Add 1 to i

*/
//////////////////////////////////////////////////////////////////////////
int findBookIndex(string bookName, string titles[], int numOfBooks){
    int index = -1; //init index to -1
    int i = 0;  //init i to zero
    while(i < numOfBooks){  //while i is less than the numOfBooks
        if(titles[i] == bookName){  //if the value of titles at pos i is equal to the bookname
           index = i+1; //set index to i+1
           break;   //break from the while loop
        }
        i++;    //add one to i
    }
}
//////////////////////////////////////////////////////////////////////////
/* readBooks function
    init numOfBooks to 0
    init tempString to blank
    init a tempArray with length of 2
    
    if the fileName is null
        set file name to a default books.txt
    
    
    create an ifstream called file
    open the file with the var fileName
    
    if the file has opened
        init i, a counter, to zero
        while loop for everyline of the file, setting the currentline to the tempstring
            split the current line with a comma as delim, sets the title to a temp array
            Authors array at i equal to tempArray at zero
            Set  titles at pos i equal to  tempArray pos 1
            add one to the counter, i
        
        Set numOfBooks equal to  i, the counter    
    If the file cannot be opened
        Set numOfBooks equal to  -1
   returns the numOfBooks
 */

//////////////////////////////////////////////////////////////////////////
// ToDo: implement readBooksfunction
int readBooks(string fileName, string titles[], string authors[], int numBooksStored, int capacity){
    int numOfBooks = 0; //init numOfBooks to zero
    string tempString = ""; //init tempString to blank
    string tempArray[2];    //init a tempArray with length of 2
    
    if (fileName.length() < 1){ //if the fileName is null
        fileName = "books.txt"; //set file name to a default books.txt
    }
    
    ifstream file;  //create an ifstream called file
    file.open(fileName);    //open the file with the var fileName
    
    if(file.is_open()){ //if the file has opened
        int i = 0;  //init i, a counter, to zero
        while(getline(file, tempString)){   //while loop for everyline of the file
            split(tempString, ',', tempArray, 2);   //split the current line with a comma as delim, sets the title to a temp array
            authors[i] = tempArray[0];  //set authors at i equal to tempArray at 0
            titles[i] =  tempArray[1];  //set titles at i equal to tempArray pos 1
            i++;    //add one to the counter
        }
        numOfBooks = i; //set the num of books to the val of the counter
    }
    else{   //If the file cannot be opened
        numOfBooks = -1;    //sets numOfBooks to -1
    }
    return numOfBooks;  //returns the numOfBooks
}
//////////////////////////////////////////////////////////////////////////


/* 
    readRatings function
    init numOfUsers to 0
   init tempString  
   create string array TempArray with length of 2 
   create string array call tempArrayTwo with length of 50
     
    if fileName length  is less than 1
        set file name to a default books.txt
    
    create an ifstream called file
    open the file with the var fileName
    
    if the file has opened
        init i to 0
        While there is another line in the file, set current line to tempstring
            split the current line with a comma as delim, sets the title to a temp array
            Set usernames at i = tempArray at zero    
            print usernames at i ....
            Set ratings at [i][0] to the value of i;  
            set ratingString to the the value at tempArray at pos 1
            Run the split method on the second part of the first array using a space as a delim
          	for each item in the column part of the array
                set the value of ratings at i j to the int of array2
           add one to the counter, i
        
        set the num of books to the val of the counter, i
    
    If the file cannot be opened
        Set numOfUsers to -1
    return the numOfUsers

 */

 //////////////////////////////////////////////////////////////////////////
 int readRatings(string fileName, string usernames[], int ratings[][50], int numCurrentUsers, int rowCapacity, int columnCapacity){
    int numOfUsers = 0; //init number of users to zero
    string tempString;  //creat tempString
    string tempArray[2];    //create string array TempArray with length of 2 
    string tempArrayTwo[50];    //create string array call tempArrayTwo with length of 50
     
    if (fileName.length() < 1){ //if the fileName is null
        fileName = "ratings.txt"; //set file name to a default books.txt
    }
     
    ifstream file;  //create an ifstream called file
    file.open(fileName);    //open the file with the var fileName
    
    if(file.is_open()){ //if the file has opened
        int i = 0;  //init i, a counter, to zero
        while(getline(file, tempString)){
            split(tempString, ',', tempArray, 2);   //split the current line with a comma as delim, sets the title to a temp array
            usernames[i] = tempArray[0];    //set username at pos i to the value of tempArray at zero
            cout << usernames[i] << "..." << endl;  //print out the current username and ...
            
            ratings[i][0] = i;  //set the first index for the ratings array to i, the index of the user
            string ratingString = tempArray[1]; //set ratingString to the the value at tempArray at pos 1
            split(ratingString, ' ', tempArrayTwo, 50);    //check later
            for(int j = 1; j < columnCapacity; j++){    //for each item in the column part of the array
                ratings[i][j] = stoi(tempArrayTwo[j-1]);    //set the value of ratings at i j to the int of array2
            }
            i++;    //add one to the counter
        }
        numOfUsers = i; //set the num of books to the val of the counter
    }
    else{   //If the file cannot be opened
        numOfUsers = -1;    //sets numOfBooks to -1
    }
    return numOfUsers;  //return the numOfUsers
 }
//////////////////////////////////////////////////////////////////////////
/*
    printAllBooks:
    If the numberOfBooks is less than or equal to zero
        Print no books are stored
    else   
        Print here is a list of books  
        For each book, add 1 to i   
            Print titles array at i and authors array at i

*/
//////////////////////////////////////////////////////////////////////////
 void printAllBooks(string titles[], string authors[], int numOfBooks){
    if(numOfBooks <= 0){    //if the number of books is less than 1
        cout << "No books are stored" << endl;  //print No books are stored
    }
    else{   //if there are books
        cout << "Here is a list of books" << endl;  //print here is a list of books
        for(int i = 0; i < numOfBooks; i++){    //for every book, i++
            cout << titles[i] << " by " << authors[i] << endl;  //print bookname by author
        }
    }
 }
//////////////////////////////////////////////////////////////////////////
/*
    getUserReadCount:
    Create and set  index to the return of the findUserIndex function
    Create and set numRead to 0
    If the index is positive
        Loop through the number of books
            If ratings at index,i does not equal zero
                numRead + 1
    Else
        Print that username does not exist in the database
        Set numRead equal to -1
    return numRead

*/
//////////////////////////////////////////////////////////////////////////
int getUserReadCount(string username, string usernames[], int ratings[][50], int numOfUsers, int numOfBooks){
    int index = findUserIndex(username, usernames, numOfUsers); //int and set index to the value found by the findUserIndex
    int numRead = 0;    //init numRead to zero
    if(index > 0){  //if the index if positive
        for(int i = 0; i < numOfBooks; i++){    //loopthrough each numOfBooks, i++
            if(ratings[index][i] != 0){ //if the value of ratings at index,i does not equal 0
                numRead++;  //add one to numRead
            }
        } 
    }
    else{   //else.. if the index is neg
        cout << username << " does not exist in the database" << endl;  //print that the user does not exist in database
        numRead = -1;   //set numRead to -1
    }
    return numRead; //return the value of numRead
}
//////////////////////////////////////////////////////////////////////////
/*
    CalAvgRating:
    Create an index equal to the return of the findBookIndex function 
    Create and set average equal to 0
    Create and set timesRated equal to 0
    Create and set sum equal to 0
    if the value of index is positive
        Loop through the number of users
            If ratings at i,index does not equal 0 and ratings at i,index is less than 5
                timesRated + 1
                sum equals sum + ratings at i,index
        average equals the sum divided by timesRated
    else
	    Print that the book does not exist in the database
        Set average equal to -1.0
    Return the value of average

    
*/
//////////////////////////////////////////////////////////////////////////
double calAvgRating(string bookTitle, string titles[],int ratings[][50], int numOfUsers, int numOfBooks){
    int index = findBookIndex(bookTitle, titles, numOfBooks);   //init index to the value returned by the findBookIndex Function
    double average = 0; //init average to zero
    int timesRated = 0; //init timesRated to zero
    int sum = 0;    //init sum to zero
    if (index > 0 && index < numOfBooks){ //if the index is positive
        for(int i = 0; i < numOfUsers; i++){    //for loop, through everyuser, i++
            if(ratings[i][index] > 0 && ratings[i][index] <= 5){   //if the value of rating at i,index does not equal zero and is less than or equal to 5
                timesRated++;   //add one to timesRated
                sum = sum + ratings[i][index];  //set sum equal to sum + the value found of ratings at i,index
            }
            cout << "i: " << i << endl;
            cout << "Temp: " << ratings[i][index] << endl;
        }
        average = (double)sum/timesRated;   //calculate the average by dividing the sum by timesRated
    }
    else{   //else.. if the index is negative
        cout << bookTitle << " does not exist in our database" << endl; //print that the book title does not exist 
        average = -1.0; //set average to -1
    }
    return average; //return the value of average
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
    int numBooks = 0;
    int numUsers = 0;
    int booksRead = 0;
    double averageRating = 0;
    string fileName;
    string username;
    string bookName;
    string titles[50]; 
    string authors[50];
    string usernames[100];
    int ratings[100][50];

    while (choice != "6") {
            displayMenu();
            getline(cin, choice);
            switch (stoi(choice)) {
                case 1:
                    // read book file
                    cout << "Enter a book file name:" << endl;
                    getline( cin, fileName);    //get the userinput and set it to fileName
                    numBooks = readBooks(fileName, titles, authors, 0, 50); //set numBooks to the return of readBooks
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
                    numUsers = readRatings(fileName, usernames, ratings, 0, 100, 50);   //set numUsers to the result of readRatings
                    if(numUsers > 0){
                        cout << "Total users in the database: " << numUsers << endl;    //print total users in database + numUsers
                    }
                    else{
                        cout << "No users saved to database" << endl;   //print no users saved to database
                    }
                    cout << endl;   //go to a new line
                    break;

                case 3:
                    printAllBooks(titles, authors, numBooks);   //run the printAllBooks function
                    cout << endl;   //go to a new line
                    break;

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
