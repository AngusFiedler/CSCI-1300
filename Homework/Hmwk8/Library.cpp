#include "Book.h"
#include "Library.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>
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
    findUserIndex:
    init index to -1
    init i to zero
    init found to false
    while i is less than the numOfUsers
        create a tempstring with the value of username at i
        loop through every char in the given username, j++
            if the lowercase of the character in the tempstring at j does not equal the lowecase char of username at j
                set found to false
                break from the loop
            set found to true
        if found is true
            set index to the val of i
            break from the loop
        add one to i
    return the value of index

*/
//////////////////////////////////////////////////////////////////////////
int findUserIndex(string username, User usernames[], int numOfUsers){
    int index = -1; //init index to -1
    int i = 0;  //init i to zero
    bool found = false;
    while(i < numOfUsers){  //while i is less than the number of users
        string tempString = usernames[i].getUsername();
        for(int j = 0; j < username.length(); j++){     //loop through each char in the username, j++
            if(tolower(tempString[j]) != tolower(username[j])){ //if the lowercase char at j for tempstring does not equal the lowercase char at username
                found = false;  //set found to false
                break;  //break from the j loop
            }
            found = true;   //set found to true
        }
        if(found){  //if found is equal to true
            index = i;  //set index to the val of i
            break;  //break from the loop
        }
        i++;    //add one to i
    }
    return index;   //return the value of index
}
//////////////////////////////////////////////////////////////////////////
/*
    findBookIndex:
    set index to -1
    set i equal to zero
    while i is less than the number of books
        if books at i has a title equal to the bookname
            set index to the val of i
            break from the loop
        add one to i
    return the val of index
*/
//////////////////////////////////////////////////////////////////////////
int findBookIndex(string bookName,Book books[],int numOfBooks){
    int index = -1;
    int i = 0;  //init i to zero
    while(i < numOfBooks){  //while i is less than the numOfBooks
        if(books[i].getTitle() == bookName){  //if the value of titles at pos i is equal to the bookname
           index = i; //set index to i+1
           break;   //break from the while loop
        }
        i++;    //add one to i
    }
    return index;
}
//////////////////////////////////////////////////////////////////////////
/*
    setRatingArray: 
    //just adds ratings to an array//
    loop through from i to 50, i++
        set array at i to the val of tempUser's rating at i
*/
//////////////////////////////////////////////////////////////////////////
void setRatingArray(User tempUser, int array[]){
    for(int i = 0; i < 50; i++){    //for loop from zero to 50, i++
        if(tempUser.getRatingAt(i) > 5 || tempUser.getRatingAt(i) < 0){
            array[i] = -1;
        }
        else{
            array[i] = tempUser.getRatingAt(i); //set array at i to the val of tempUser's ratings at pos i
        }
    }
}
//////////////////////////////////////////////////////////////////////////
/*
    findUserSSD:
    int sum to zero
    loop from zero 50, i++
        if the rating is valid
            set valid ratings to true
    if the user does not have valid ratings
        set sum to 999
    loop through from i to 50, i++
        set sum to sum + userRatings at i - testratings at i squared
    return the val of sum
*/
//////////////////////////////////////////////////////////////////////////
int findUserSSD(int userRatings[], int testRatings[]){
    int sum = 0;    //init sum to zero
    bool validUserRatings = false;  //init validUserRatings to false
    for (int i = 0; i < 50; i++){   //loop through from zero to 50
        if(testRatings[i] > 0 && testRatings[i] <= 5){  //if the rating is inbetween 0 and 5
            validUserRatings = true;    //set validUserRatings to true
        }
    }
    if(!validUserRatings){  //if validUserRatings true
        sum = 999;  //set sum to 999
    }
    for(int i = 0; i < 50; i++){    //loop through from zero to 50, i++
        sum = sum + pow(userRatings[i] - testRatings[i],2); //set sum equal to sum + (userRatings at i - testRatings at i)^2
    }
    return sum; //return the sum 
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
            if there is more books than spaces in the arary
                break from the array
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
int Library :: readBooks(string fileName){
    if (fileName.length() < 1){ //if the fileName is null
        fileName = "books.txt"; //set file name to a default books.txt
    }
    
    ifstream file;  //create an ifstream called file
    file.open(fileName);    //open the file with the var fileName
    
    if(file.is_open()){ //if the file has opened
        string tempString;  //init tempString
        string tempArray[2];    //init tempArray with length 2
        while(getline(file, tempString)){   //while loop for everyline of the file
            if (numBooks >= sizeBook){   //if there is more books than spaces in the array
                break;
            }
            split(tempString, ',', tempArray, 2);   //split the current line with a comma as delim, sets the title to a temp array
            Book tempBook = Book(tempArray[1], tempArray[0]);   //create a new book object called tempBook using the book constructor
            books[numBooks] = tempBook;    //set bookData at numBooks to tempBook
            numBooks++;    //add one to the counter
        }
    }
    else{
        numBooks = -1;    //set numBooks to -1
    }
    return numBooks;  //return the val of numBooks
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
            split the current line with a comma as delim, sets the title to a temp array
            set username at pos i to the value of tempArray at zero
            
            set ratingString to the the value at tempArray at pos 1
            run split function on ratings string into arraytwo and set result to int x
            init ratings array with length x
            for loop from zero to x J++
                set tempInt to the int value of tempArrayTwo at j
                if tempInt is between 0 and 5
                    set the value of ratings at i j to the int of array2
                else
                    set ratings at j to -1
            set tempUser to a user constructor given username ratings and the number of ratings
            print current username...
            set users array at numUsers+1 to the tempUser
            add one to the counter
    else
        set numUsers to -1
    return the val numUsers
*/
//////////////////////////////////////////////////////////////////////////
int Library :: readRatings(string fileName){
    if (fileName.length() < 1){ //if the fileName is null
        fileName = "ratings.txt"; //set file name to a default books.txt
    }
    
    ifstream file;  //create an ifstream called file
    file.open(fileName);    //open the file with the var fileName
    
    if(file.is_open()){ //if the file has opened
        string tempString;  //init tempString
        string tempArray[2];    //init tempArray with length 2
        string username;    //init username
        string tempArrayTwo[sizeUser];  //init tempArrayTwo at size capacity
        User tempUser;  //init user called tempUser
        int i = 0;  //init i, a counter, to zero
        while(getline(file, tempString)){   //while loop for everyline of the file
            if (i + numUsers >= sizeUser){  //if there is more users than the cap of the array
                break;  //break from the loop
            }
            split(tempString, ',', tempArray, 2);   //split the current line with a comma as delim, sets the title to a temp array
            username = tempArray[0];    //set username at pos i to the value of tempArray at zero
            
            string ratingString = tempArray[1]; //set ratingString to the the value at tempArray at pos 1
            int x = split(ratingString, ' ', tempArrayTwo, sizeUser);    //run split function and set result to int x
            int ratings[x]; //init ratings array with length x
            for(int j = 0; j < x; j++){    //for each item in the column part of the array
                int tempInt = stoi(tempArrayTwo[j]);    //set tempInt to the int value of tempArrayTwo at j
                if(0 <= tempInt && tempInt <= 5){   //if tempInt is between 0 and 5
                    ratings[j] = stoi(tempArrayTwo[j]);    //set the value of ratings at i j to the int of array2
                }
                else{
                    ratings[j] = -1;    //set ratings at j to -1
                }
            }
            tempUser = User(username, ratings, x);  //set tempUser to a user constructor given username ratings and the number of ratings
            cout << username << "..." << endl;  //print current username...
            users[numUsers+i] = tempUser; //set users array at numUsers+1 to the tempUser
            i++;    //add one to the counter
        }
        numUsers = i + numUsers;    //set numUsers +i
    }
    else{
        numUsers = -1;    //set numUsers to -1
    }
    return numUsers;  //return the val of numUsers
}
//////////////////////////////////////////////////////////////////////////
/*
    printAllBooks:
    if the number of books or number of users is zero
        print the datbase has not been fully init...
    else
        print here is a list of books
        loop from zero to numBooks, i++
            print books at i get title function plus books at i getAuthor function
*/
//////////////////////////////////////////////////////////////////////////
void Library :: printAllBooks(){
    if(numBooks == 0 /*|| numUsers == 0*/){ //if there is no books or no users
        cout << "Database has not been fully initialized" << endl;  //print databse not init...
    }
    else{   //else
        cout << "Here is a list of books" << endl;  //print here is a list of...
        for(int i = 0; i < numBooks; i++){  //loop through each book, i++
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;  //print book title at i and book author at i
        }
    }
}
//////////////////////////////////////////////////////////////////////////
/*
    getCountReadBooks:
    if either the number of books or number of users is zero
        print Database has not been...
        return -1
    set index to the result of the findUserIndex
    if the value of index is equal to -1
        print username does not exist...
        return -2
    init numOfRatings to zero
    loop through all of the users ratings, i++
        set tempRating equal to users at index getrating at fucntion given i
        if the rating is between 0 and 5
            add one to numOfRatings
    print username rated...
    return the numOfRatings
*/
//////////////////////////////////////////////////////////////////////////
int Library :: getCountReadBooks(string username){
    if(numBooks <= 0 || numUsers <= 0){     //if numBookls or numUsers is zero
        cout << "Database has not been fully initialized" << endl;  //print databse has no been...
        return -1;  //return the val -1
    }
    else{
        int index = findUserIndex(username, users, numUsers);   //set index to the result of the findUserIndex function
        if (index == -1){   //if the val of index is -1
            cout << username << " does not exist in the database" << endl;  //print username does not...
            return -2;  //return the val -2
        }
        int numOfRatings = 0;   //init numRatings to zero
        for(int i = 0; i < users[index].getNumRatings(); i++){  //loop through each rating of a user, i++
            int tempRating = users[index].getRatingAt(i);   //set tempRating to the result of the getRating function at i from the user at index
            if (tempRating > 0 && tempRating <= 5){ //if the tempRating is inbetween zero and 5
                numOfRatings++; //add one to numRatings
            }
        }
        return numOfRatings;    //return the val of numOfRatings
    }
}
//////////////////////////////////////////////////////////////////////////
/*
    calcAvgRating:
    If numBooks is equal to 0 or numUsers is equal to 0
        Print Database has not been fully initialized
        return the val -1
    
    init bookIndex to the result of the findBookIndex function
    if bookIndex is equal to -1
        Print title does not exist in the database
        return the val -2
    
    init timesRated to 0
    init sum to 0
    Loop through from zero to numUsers, i++
        init temp to users at i getRatingAt function given the index
        If temp > 0 and temp <= 5
            Set sum equal to sum + temp
            Add one to timesRated
        
    init average to sum/timesRated passed as a double
    print out the average rating for bookName is AverageRating
    return the val of average
*/
//////////////////////////////////////////////////////////////////////////
double Library :: calcAvgRating (string title){
    if(numBooks == 0 || numUsers == 0){ //if numUsers or numUsers is zero
        cout << "Database has not been fully initialized" << endl;  //print database has not been...
        return -1;  //return the val -1
    }
    int bookIndex = findBookIndex(title, books, numBooks);  //set bookIndex to the result of the findBookIndex function
    if (bookIndex == -1){   //if bookIndex is -1
        cout << title << " does not exist in the database" << endl; //print title does not...
        return -2;  //return the val -2
    }
    int timesRated = 0; //init timesRated to zero
    int sum = 0;    //init sum to zero
    for(int i = 0; i < numUsers; i++){  //loop through each users, zero to numUsers, i++
        int temp = users[i].getRatingAt(bookIndex); //set temp to users at i getRatingfunction at bookIndex
        if(temp > 0 && temp <= 5){  //if the temp rating is inbetween zero and 5
            sum = sum + temp;   //set sum to sum + temp
            timesRated++;   //add one to timesRated
        }
    }
    double average = (double)sum/timesRated;    //set avg to the sum divided by timesRated passed as a double
    return average; //return the val of average
}
//////////////////////////////////////////////////////////////////////////
/*
    addUser:
    If the result of the findUserIndex does not equal -1
        print username  already exists in the database" 
        return false
    
    If numUsers is less than sizeUser
        Create a User called tempUser
        Use setUsername on tempUser using the given username as a param
        Set users at numUsers to tempUser
        Add one to numUsers
        return true
    else
        print Database full
        return false

*/
//////////////////////////////////////////////////////////////////////////
bool Library :: addUser(string username){
    if(findUserIndex(username, users, numUsers) != -1){ //if the result of the findUserIndex does not equal -1,aka the user exists
        cout << username << " already exists in the database" << endl;  //print username already exists..
        return false;   //return false
    }
    if(numUsers < sizeUser){    //if the numUsers is less than sizeUser
        User tempUser = User(); //set tempUser to a new user using the default constructor
        tempUser.setUsername(username); //use the setUsername function on tempUser
        users[numUsers] = tempUser; //add tempUser to the users array at numUsers
        numUsers++; //add one to numUsers
        return true;    //return the val true
    }
    else{
        cout << "Database full" << endl;    //print databse full
        return false;   //return false 
    }
}
//////////////////////////////////////////////////////////////////////////
/*
    checkOutBook: 
    init result to true
    if(numBooks is equal to 0 or numUsers is equal to 0)
        cout << "Database has not been fully initialized" << endl
        return false
    
    init userIndex to the result of the findUserIndex function
    init bookIndex to the result of the findBookIndex function
    If userIndex is equal to -1
        Print username does not exist in the database
        Set result to false
    
    If bookIndex is equal to -1
        print title does not exist in the database
        result to false
    
    If rating > 5 or rating < 0
        print rating is not valid
        result to false
    
    If result is true
        Use the  set ratingatindex on users at userindex    
    return result
*/
//////////////////////////////////////////////////////////////////////////
bool Library :: checkOutBook(string username, string title, int rating){
    bool result = true; //set result to true
    if(numBooks == 0 || numUsers == 0){     //if there is no books or no ratings currently stored
        cout << "Database has not been fully initialized" << endl;  //print Database has not been fully...
        return false;   //return false
    }
    int userIndex = findUserIndex(username, users,numUsers);    //set userIndex to the result of the findUserIndex function
    int bookIndex = findBookIndex(title, books, numBooks);      //set bookIndex to the result of the findBookIndex function
    if(userIndex == -1){    //if userIndex is -1
        cout << username << " does not exist in the database" << endl;  //print username does not...
        result = false; //set result to false
    }
    if(bookIndex == -1){    //if the bookIndex is -1
        cout << title << " does not exist in the database" << endl; //print title does not...
        result = false; //set result to false
    }
    if(rating > 5 || rating < 0){   //if rating is outofbounds, aka greater than 5 or less than zero
        cout << rating << " is not valid" << endl;  //print rating is not valid
        result = false; //set result to false
    }
    if(result){     //if result is still true
        users[userIndex].setRatingAt(bookIndex, rating);    //call the setRating at function on the user in the users array at user index
    }
    return result;  //return the val of result
}
//////////////////////////////////////////////////////////////////////////
/*
    viewRatings:
    if either numUsers to numUsers is zero
        print Database has not been...
    else
        init userIndex to the result of findUserIndex function
        if userIndex is -1
            print username does not...
        else if the user has not rated any books
            print username has not rated any books
        else
            print Here are the books that user has rated
            init i to zero
            /init j to zero
            init numRatings to the result of the getNumRatings function
            while j is less than numRatings
                if the rating at i is a valid rating, between 0 and 5
                    print the book title
                    print the rating
                    add one to j
                if the rating is zero, aka book has not been read but has a valid rating
                    add one to j
                add one to i

*/
//////////////////////////////////////////////////////////////////////////
void Library :: viewRatings(string username){
    if(numBooks == 0 || numUsers == 0){ //if either numUsers to numUsers is zero
        cout << "Database has not been fully initialized" << endl;  //print Databse has not been...
    }
    else{
        int userIndex = findUserIndex(username, users,numUsers);    //init userIndex to the result of findUserIndex function
        if(userIndex == -1){    //if userIndex is -1
            cout << username << " does not exist in the database" << endl;  //print username does not...
        }
        else if(users[userIndex].getNumRatings() == 0){ //if the user has not rated any books
            cout << username << " has not rated any books yet" << endl; //print username has not rated...
        }
        else{
            cout << "Here are the books that " << username << " rated" << endl; //print Here are the books that...
            int i = 0;  //init i to zero
            int j = 0;  //init j to zero
            int numRating = users[userIndex].getNumRatings();   //init numRatings to the result of the getNumRatings function
            while(j < numRating){   //while j is less than numRatings
                if(users[userIndex].getRatingAt(i) > 0 && users[userIndex].getRatingAt(i) <= 5){    //if the rating at i is a valid rating 
                    cout << "Title : " << books[i].getTitle() << endl;  //rpint the book title
                    cout << "Rating : " << users[userIndex].getRatingAt(i) << endl; //print the rating
                    cout << "-----" << endl;        //print some more stuff
                    j++;    //add one to j
                }
                else if(users[userIndex].getRatingAt(i) == 0){  //if the rating is zero, aka book has not been read but has a valid rating
                    j++;    //add one to j
                }
                i++;    //add one to i
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////
/*
    getRecommendations:
    int userIndex = findUserIndex(username, users,numUsers)
    If numBooks or numUsers is zero
        print Database has not been fully initialized  
    else if(userIndex == -1)
        print username does not exist in the database  
    else
        init currentSSD
        init minSSD to 999
        init minSSDIndex
        intt userRatings array with size 50
        Use setRatingArray function on the given user and userRatings array
        loop through from zero to the num of users, i++
            init newUserRatings array with size 50
            Use setRatingArray function on user with index i
            Set currentSSD to the result of the findUserSSD function given the two arrays
            If the currentSSD is less than the minSSD and i does not equal the userIndex
                Set minSSD to the currentSSD
                Set minSSDIndex to the val of i
        init foundMatch to false
        init numMatches to 0
        init matchedUserRatings array with size 50
        Use setRatingArray on the index of the user with the lowest ssd to the matchedUser 
        Loop from zero up while i is less than numBooks, i++                    
            if matchedUserRatings at i is greater than 3 and userRatings at i is 0
                Set foundMatch = true
                Break from the loop
        If foundMatch is true
            print Here are the list of recommendations:  
            Loop from zero up while i is less than numBooks and numMatches is 4 or less
                If matchedRating at i is >= 3 and userRatings at i is zero
                    Print title at i plus author at i 
                    Add one to numMatches
        else
            print There are no recommendations for  username at the present
*/
//////////////////////////////////////////////////////////////////////////
void Library :: getRecommendations(string username){
    int userIndex = findUserIndex(username, users,numUsers);    //create userIndex using the find userIndex function
    if(numBooks == 0 || numUsers == 0){     //if either numBooks or numUsers is zero
        cout << "Database has not been fully initialized" << endl;  //print Database has not been...
    }
    else if(userIndex == -1){   //if the userindex is -1
        cout << username << " does not exist in the database" << endl;  //print username does not exist in database
    }
    else{
        int currentSSD; //init a currentSSD
        int minSSD = 999;   //init minSSD to 999
        int minSSDIndex = -1;   //init minSSDIndex to -1
        int userRatings[50];    //init a userRatings array with size 50
        setRatingArray(users[userIndex], userRatings);  //use setRatingArray given the user and userRatings array
        for(int i = 0; i < numUsers; i++){  //loop through from zero to numUsers, i++
            int newUserRatings[50];     //create numUserRatings array with size 50
            setRatingArray(users[i], newUserRatings);   //pass the numUserRatings array and the current user to the setRatingArray function
            currentSSD = findUserSSD(userRatings, newUserRatings);  //set currentSSD to the result of the findUser SSD given the userratings and newUserRatings
            if(currentSSD < minSSD && i != userIndex){  //if the currentSSD is less than the min SSD and i does not equal to the userIndex 
                minSSD = currentSSD;    //set minSSD to the current SSD
                minSSDIndex = i;    //set minSSD index to i
            }
        }
        if(minSSDIndex != -1){  //as long as minSSDIndex does not equal -1
            bool foundMatch = false;    //init foundMatch to false
            int numMatches = 0;     //init numMatches to zero 
            int matchedUserRatings[50]; //init matchedUserRatings to size 50
            setRatingArray(users[minSSDIndex], matchedUserRatings); //use setRatingArray on the user and minSSDIndex and the matchedUserRatings array
            for(int i = 0; i < 50; i++){  //loop through from zero to numBooks, i++
                if(matchedUserRatings[i] >= 3 && matchedUserRatings[i] <= 5 && userRatings[i] <= 0){    //if matchedUser ratings at i is inbetween 3 and 5 and userRatings at i is zero or less
                    foundMatch = true;  //set found match to true
                    break;  //break from the loop
                }
            }
            if(foundMatch){ //if foundMatch is true
                cout << "Here are the list of recommendations:" << endl;    //print here is a list of rec...
                for(int i = 0; i < 50 && numMatches < 5; i++){    //loop through from zero to numBooks and while numMatches is less than 5
                    if(matchedUserRatings[i] >= 3 && matchedUserRatings[i] <= 5 && userRatings[i] <= 0){    //if matchedUser at i is greater than 3 and less than 5, at userRatings at i is less than or equal to zero
                        cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;  //print title by author at index i
                        numMatches++;   //add one to numMatches
                    }
                } 
            }
            else{
                cout << "There are no recommendations for " << username << " at the present" << endl;   //print there are no recommendations
            }
        }
    }
}



/*
int main(){
    cout << "It runs!" << endl;
}
*/