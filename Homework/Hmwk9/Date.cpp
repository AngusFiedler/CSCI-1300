#include "Date.h"
using namespace std;


int Date :: getMonth(){
    return month;   //returns the month 
}
int Date :: getDay(){
    return day;     //returns the day
}
int Date :: getYear(){
    return year;    //returns the year
}
////////////////////////////////////////////////////////////////
/*
    addDays:
    loop through from zero to the given amount of days

        switch on a given month
            if adding one to the day would over run the amount of days in the month
                add one to month 
                set day to 1
            else
                add one to day
            in all other cases
                set result to false
*/
////////////////////////////////////////////////////////////////
bool Date :: addDays(int daysToAdd){
    bool result = true;     //init result to true
    for(int i = 0; i < daysToAdd; i++){ //loop from zero to daysToAdd, i++
        switch(month){      //switch on the given month
            case 3: case 5: case 7: case 8: case 10:    //in case month has 31 days
            {
                day++;  //add one to day
                if(day > 31){   //if the day is greater than 31
                    day = 1;    //set day to 1
                    month++;    //add one to month
                }
                break;  //break
            }
            case 4: case 6: case 9:     //if the month has 30 days
            {
                day++;  //add one to day
                if(day > 30){   //if the day is greater than 30
                    day = 1;    //set day to 1 
                    month++;    //add one to month
                }
                break;  //break
            }
            case 11:    //if it is the 11th month
            {
                day++;      //add one to day
                if (day > 30){      //if the day is greater than 30
                    result = false;     //set result to false
                }
                break;  //break
            }
            default:    //in all other cases
                result = false;     //set result to false
        }
    }
    return result;      //return the value of result
}

///////////////////////////////////////////////////////////////
/*
    validDate:
    seet result to false
    if day is greater than min and less than max
        set result to true
    return result
*/
///////////////////////////////////////////////////////////////

bool validDate(int day, int min, int max){
    bool result = false;    //init result to false
    if(day > min && day < max){ //if the date is within range
        result = true;  //set result to true
    }
    return result;      //return the value of result
}


///////////////////////////////////////////////////////////////
/*
    isValidStartDate:
    create bool result
    if month is 3
        set result to validDate given day, 0, 32
    if month is 4
        set result to validDate given day, 0, 31
    if month is 5
        set result to validDate given day, 0, 2
    else
        set result to false
    return the value of result
*/
////////////////////////////////////////////////////////////////
bool Date :: isValidStartDate(int month, int day){
    bool result;    //create result 
    if(month == 3){     //if the month is 3
        result = validDate(day,0,32);   //set result to the validDate function
    }
    else if(month == 4){    //if the month is 4
        result = validDate(day,0,31);   //set result to the validDate function
    }
    else if(month == 5){    //if the month is 5
        result = validDate(day,0,2);    //set result to the validDate function
    }
    else{
        result = false;     //set result to false 
    }

    return result;  //return the value of result
}