// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Project 1 extra credit


/*

Your algorithm goes into here 


*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;

string whoIsFirst(bool firstTurn){
    if(firstTurn == true){
        return "Computer";
    }
    else{
        return "Human";
    }
}

string isComputerSmart(bool computerMode){
    if(computerMode == true){
        return "Yes";
    }
    else{
        return "No";
    }
}

int player(int num){
    int marblesTaken;
    cout << "Your move. Marbles remaining: " << num << endl;
    cin >> marblesTaken;
    if(marblesTaken <= num/2 && marblesTaken >= 1){
        return marblesTaken;
    }
    else{
        int max = num/2;
        cout << "Wrong Move. You can only choose between 1 to " << max << endl;
        player(num);
    }
}

int smartComputer(int num){
    int marblesTaken;
    if(num > 64){
        marblesTaken = num - 63;
    }
    else if(num > 31){
        marblesTaken = num - 31;
    }
    else if(num > 15){
        marblesTaken = num - 15;
    }
    else if(num > 7){
        marblesTaken = num - 7;
    }
    else if(num > 3){
        marblesTaken = num - 3;
    }
    else{
        marblesTaken = 1 + rand() % (( (num/2) + 1 ) - 1);
    }
    cout << "Computer took " << marblesTaken << endl;
    return marblesTaken;
}

int stupidComputer(int num){
    int marblesTaken = 1 + rand() % (( (num/2) + 1 ) - 1);
    cout << "Computer took " << marblesTaken << endl;
    return marblesTaken;
}

int computer(int num,bool computerMode){
    cout << "Computer is playing.." << endl;
    if(computerMode == false){
        return stupidComputer(num);
    }
    else{
        return smartComputer(num);
    }
}

void marbleRun(int initialSize, bool computerMode, bool firstTurn){
    cout << "Lets start the game!" << endl;
    cout << "Initial size is: " << initialSize << endl;
    cout << "First player to play: " << whoIsFirst(firstTurn) << endl;
    cout << "Is computer in smart mode? " << isComputerSmart(computerMode) << endl;
    
    
    int num = initialSize;
    bool winner = false;
    if(firstTurn == false){
        while(num > 1){
            winner = true;
            num = num - player(num);
            cout << "Remaining marbles: " << num << endl;
            if(num > 1){
            num = num - computer(num, computerMode);
            cout << "Remaining marbles: " << num << endl;
            }
            else{
                winner = false;
            }
        }
    }
    else{
        while(num > 1){
            num = num - computer(num, computerMode);
            cout << "Remaining marbles: " << num << endl;
            if(num > 1){
                num = num - player(num);
                cout << "Remaining marbles: " << num << endl;
            }
            else{
                winner = true;
            }
        }
    }
    if(winner == true){
        cout << "You lose. Computer won";
    }
    else{
        cout << "You Win. Computer loses";
    }
    
}

int main(){
    marbleRun(100, false, false);
    return 0;
}