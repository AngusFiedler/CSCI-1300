// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Homework 2 - Problems #1,2,3,4

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/*
*This function takes a given int value which is named seconds and computes the time in hours min and seconds
*It does this by:
    1. Calculates the hours by dividing the input(seconds) by the amount of seconds in an hour(60*60)
    2. Calculats the time in min by diving the input(seconds) by the amount of seconds in a min (60) then subtracts the amount already found in hours
    3. Calculates the remaining seconds by taking the inital input and subtracting the minutes found * 60 and the hours found*60*60
    4. Outputs the values of hours, min, and seconds.
    
*Input parameters: seconds(int type)
*Output: diffrent string based on the hours, min, and seconds calculated
   x hour(s) y minute(s) z second(s)
*Returns: Nothing
*/

void convertSeconds(int seconds){
    int hours = seconds/(60*60); //calculates the amount of hours in the given number of seconds
    int min = seconds/60 - hours*60; //calculates the amount of min in the given seconds subtracting the amount calculated in hours
    int secondsfinal = seconds - min*60 - hours*60*60;//find the remaining number of seconds not included in hours or min
    cout << hours << " hour(s) " << min << " minute(s) " << secondsfinal << " second(s)";//outputs result
}

/*
*This function takes a given temp in celsius and converts it into fahrenheit 
*Algorithm does this by:
    1. Multiplies the input(int celsius) by 9/5ths and adds 32
    2. Prints the output to the screen
*Input parameters: temputure in celsius(int type)
*Output: String based on inputed temp in celsius and its converted temp in fahrenheit
    The temperature of x in fahrenheit is y
*Returns: Nothing

*/

void celsiusToFahrenheit(int celsiusTemp){
    double fahrenheit = (celsiusTemp)*(9.0/5.0) + 32.0; //calculates the temp in fahrenheit given the temp in celsius
    cout << fixed << setprecision (2) << "The temperature of " << celsiusTemp << " in fahrenheit is " << fahrenheit; //print the result, restricts result to 2 points after the decimal through setting precision
}

/*
*This function calculates the future population of the US given the current population as well as birth rate, death rate, and immigration rate
*Algorithm does this by:
    1.sets the values for birth rate, death rate, and immigration rate
    2. sets an int of minutes in a year to 365*24*60 
    3. calculates the new population by taking (60/birthrate)*the minutes in a year and doing the same with immigration rate and adding the current population then subtracting (60.0/DR)*MinInYear
    4. returns the new population 
*Input parameters: currentPop(int type)
*Output: None
*Returns: The newPopulation(int type)

*/

int population (int currentPop){
    int bR = 8; //birthrate, 1 birth every 8 seconds
    int dR = 12; //deathrate, 1 death every 12 seconds
    int iR = 27; //immigration rate, 1 new immigrant every 27 seconds
    int minInYear = 365*24*60; //calculates the number of min in a year
    int newPop = currentPop + ((60.0/bR)*minInYear) + ((60.0/iR)*minInYear) - ((60.0/dR)*minInYear); //calculates the population 1 year later by taking the current population and adding the amount of births and deaths in a min * the total min in a year and subtracting the deaths in a min * the total min in a year
    return newPop; //returns the new population as an int value 
}

/*
*This function calculates the luminosity of an astronomical object given its distance and brightness
*Algorithm does this by:
    1. Setting the value of pi to the double, pi
    2. Calculates the value of luminosity by the given formula
    3. Casts the value obtained in previous step from a double into an int
    4. returns the luminosity(int type)
*Input parameters: brightness(double), distance(double)
*Output: None
*Returns: The luminosity as an int

*/
int luminosity(double b, double d){
    double pi = 3.14159; //set the value of pi 
    double lumin = 4*b*pi*pow(d,2); //calculates the luminosity 
    int luminosity = (int) lumin; //casts the double lumin into a int
    return luminosity; //returns the value of luminosity as an int
}

int main(){
    convertSeconds(3671); //test case 1 for convertSeconds
    convertSeconds(1200); //test case 2 for convertSeconds
    
    celsiusToFahrenheit(38); //test case 1 for celsiusToFahrenheit
    celsiusToFahrenheit(10); //test case 2 for celsiusToFahrenheit
    
    cout << population(0) << endl; //test case 1 for population 
    cout << population(1000000) << endl; //test case 2 for population
    
    cout << luminosity(1.5,17.8) << endl; //test case 1 for luminosity
    cout << luminosity(0.254,1.97) << endl; //test case 2 for luminosity
}