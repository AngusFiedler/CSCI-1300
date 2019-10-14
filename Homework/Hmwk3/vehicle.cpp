// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Homework 3 - Problems #4

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

/**
* Algorithm: Finds what doors, if any, will open inside of a minivan
*   1. initializes a bool for left door and right door and sets them both to false
    2. Checks if the car is in park and if the masterlock is false
        3. checks if the left door would open,
            sets leftdoor to true 
        4.checks if the right door would open
            sets right door to open
    5. checks if left and right door are true
        prints both doors will open
    6. else checks if just right door is true
        prints right door opens
    7. else checks if just left door is true
        prints left door opens
    8. else
        prints both doors remain closed
* Parameters:  bool dashSL, bool dashSR, bool childLock, bool masterLock, bool insideLL, bool outsideLL, bool insideRL, bool outsideRL, char gearShift
* Output: Both doors open, left door opens, right door opens, or both doors stay close 
* Returns: None
*/


void vehicle(bool dashSL, bool dashSR, bool childLock, bool masterLock, bool insideLL, bool outsideLL, bool insideRL, bool outsideRL, char gearShift){
    bool leftDoor = false;      //initializes leftdoor and sets it to false
    bool rightDoor = false;     //initializes rightDoor and sets it to false
    if (gearShift == 'P' && !masterLock){                                       //checks if the car is in park and that the masterlock is off
        if(dashSL || (insideLL && !childLock) || outsideLL){    //checks whether the left door will open, if the dash switch or inside switch is hit without childlock or if the outside latch is opened
            leftDoor = true;    //sets left door to true if it will open
        } 
        if(dashSR || (insideRL && !childLock) || outsideRL){   //checks whether the right door will open, if the dash switch or inside switch is hit without childlock or if the outside latch is opened
            rightDoor = true;   //sets right door to true if it will open
        }
    }
    
    if(rightDoor && leftDoor){          //checks if both left and right doors will open aka both are true
            cout << "Both doors open";  //prints that both doors are open
    }
    
    else if (rightDoor){                //checks if just the right door will open, aka true
        cout << "Right door opens";     //prints that the right door opens
    }
    
    else if (leftDoor){                 //checks if just the left door will open, aka is set to true
        cout << "Left door opens";      //prints that only the left door opens
    }
    
    else{                               //in any other case .....
        cout << "Both doors stay closed";   //prints that both doors stay closed
    }
}



int main(){
    bool dashSL = false;
    bool dashSR = false;
    bool childLock = true;
    bool masterLock = false;
    bool insideLL = false;
    bool outsideLL = true;
    bool insideRL = true;
    bool outsideRL = false;
    char gearShift = 'P';
    vehicle(dashSL, dashSR, childLock, masterLock, insideLL, outsideLL, insideRL, outsideRL, gearShift); //test case 1 for vehicle, just the left door should open
    gearShift = '1';
    vehicle(dashSL, dashSR, childLock, masterLock, insideLL, outsideLL, insideRL, outsideRL, gearShift); //test case 2 for vehicle, neither door should open
    gearShift = 'P';
    outsideRL = true;
    vehicle(dashSL, dashSR, childLock, masterLock, insideLL, outsideLL, insideRL, outsideRL, gearShift); //test case 3 for vehicle, both doors should open
}