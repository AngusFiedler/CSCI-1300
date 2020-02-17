#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int solarCharge (int minOfSunlight){
    int batteryChargePercentage = 0;
    while(minOfSunlight >= 2 && batteryChargePercentage < 100){
        batteryChargePercentage = batteryChargePercentage + 1;
        minOfSunlight= minOfSunlight -2;
    }
    return batteryChargePercentage;
}

string mileage(int flightDistance){
    string mileage = "INVALID";
    if(flightDistance > 0 && flightDistance <= 10000){
        mileage = "Bronze";
    }
    else if(flightDistance > 10001 && flightDistance <= 15000){
        mileage = "Silver";
    }
    else if(flightDistance > 15001 && flightDistance <= 30000){
        mileage = "Gold";
    }
    else if(flightDistance > 30000){
        mileage = "Platinum";
    }
    return mileage;
}

void ordinalText(int num){
    switch (num){
        case 1:
            cout << num << "st" << endl;
            break;
        case 2:
            cout << num << "nd" << endl;
            break;
        case 3:
            cout << num << "rd" << endl;
            break;
        default:
            cout << num << "th" << endl;
            break;
        
    }
}

double largestNumber(double a, double b, double c){
    double num = a;
    if(a < b){
        num = b;
    }
    if(num < c){
        num = c;
    }
    return num;
}
int main(){
    cout << mileage(100) << endl;
    //cout << solarCharge(230) <<endl;
}
