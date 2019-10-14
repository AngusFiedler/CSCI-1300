#ifndef Date_H
#define Date_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Date{
    private:
        int month;  //int var month
        int day;    //int var day
        int year;   //init var year
    public:
    Date(){     //default constructor
        month = 03;     //sets month to 3
        day = 28;       //sets day to 28
        year = 1847;    //sets year to 1847
    }
    Date(int month_, int day_){ //param constructor
        month = month_; //sets month to given month
        day = day_;     //sets day to given day
        year = 1847;    //sets year to 1847
    }
    int getMonth(); //returns the current month
    int getDay();   //returns the current day
    int getYear();  //returns the current year
    
    bool addDays(int daysToAdd);    //adds the amount of days, changing the month correctly
    bool isValidStartDate(int month, int day);  //checks if a given date is valid
};
#endif