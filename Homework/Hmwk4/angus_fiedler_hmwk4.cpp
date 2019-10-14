// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Project 1 







///////////////////////////////////////////////////////////////////////////////////////////////////
// Step1: Steps to solve this problem
// write an algorithm in pseudocode explaining on how you are approaching the problem, step by step 
///////////////////////////////////////////////////////////////////////////////////////////////////

/*


///////////////////////////////////////////////////////////////////////////////////////////////////
main method

print "Welcome to Jeopardy Dice!" 
humanScore = 0
computerScore = 0
yesNo;
while(humanScore < 100 and computerScore < 100)
	Print "It is now human's turn" 
	print "Do you want to roll a dice (Y/N)?:"
	input yesNo;
	if(yesNo is 'y' or if yesNo is 'Y')
		humanScore = humanScore + human(0)
	
	if(humanScore < 100)
		currentscores(computerScore,humanScore);
		Print  "It is now computer's turn"
		computerScore =computerScore + computer(0)
	currentscores(computerScore, humanScore)


if (humanScore > 100)
	winner("human")
else
	winner("computer")
///////////////////////////////////////////////////////////////////////////////////////////////////
winner method takes a string of the winner

Print  "Congratulations! "  winner " won this round of jeopardy dice!"
///////////////////////////////////////////////////////////////////////////////////////////////////
turnOutpot method takes the turnTotal and the current diceroll

Print "You rolled a "  diceRoll  
Print "Your turn total is "  turnTotal
///////////////////////////////////////////////////////////////////////////////////////////////////
turnOutpotComputer method takes the turnTotal and the current diceroll, same as turnoutput but for the computer

Print "Computer rolled a "  diceRoll  
Print "Computer turn total is "  turnTotal
///////////////////////////////////////////////////////////////////////////////////////////////////
currentscores method takes the current scores of the computer and the human and outputs them

print  "computer: "  computerScore  
print  "human: "  humanScore 
///////////////////////////////////////////////////////////////////////////////////////////////////
human method takes the turn total and returns the final turnscore

int diceRoll = rollDice()
	if(diceRoll is equal to 1 or diceRoll is equal to6)
		turnOutput(0,diceRoll)
		return 0
	
	else if(diceRoll is equal to 3)
		turnOutput(15,diceRoll)
		return 15
	
	else
		turnTotal = turnTotal + diceRoll
		turnOutput(turnTotal, diceRoll)
		Print  "Do you want to roll again (Y/N)?:"  
		cin>>yesNo
		if(yesNo is equal to 'y' or yesNo is equal to 'Y')
			human(turnTotal)
		
		else
			return turnTotal
///////////////////////////////////////////////////////////////////////////////////////////////////
computer method takes the turntotal as a parameter and returns the final turnScore, almost identical to human

while(turnTotal < 10)
	diceRoll = rollDice()
	if(diceRoll is equal to 1 or diceRoll is equal to 6)
		turnOutputComputer(0,diceRoll)
		return 0
		
	else if(diceRoll is equal to 3)
		turnOutputComputer(15,diceRoll)
		return 15
	
	else
	turnTotal = turnTotal + diceRoll;
	turnOutputComputer(turnTotal,diceRoll)
	
return turnTotal
///////////////////////////////////////////////////////////////////////////////////////////////////

*/

///////////////////////////////////////////////////////////////////////////////////////////////////
// Step2: Code it up! 
// After finishing up your pseudocode, translate them into c++ 
// IMPORTANT: rollDice() and main() are already written for you.
// You need to complete game function as well as at least 3 other additional functions
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 

/**
 * rollDice 
 * returns a random integer between 1 and 6, works as rolling a dice.
 * return value, int number (1-6)
 */

int rollDice()
{
	return random() % 6 + 1; 
}

// your 3 + functions go in here

void winner(string winner){
    cout<< "Congratulations! " << winner <<" won this round of jeopardy dice!";	//prints the winner of the game based on the given string
}

void turnOutput(int turnTotal, int diceRoll){		//method to print the turn given the turn total and diceroll
	cout<<"You rolled a " << diceRoll << endl;		//prints the users current roll
	cout<<"Your turn total is " << turnTotal <<endl;	//prints the users turntotal
}

void turnOutputComputer(int turnTotal, int diceRoll){	//method to print the computers turn given the turn total and diceroll
	cout<<"Computer rolled a " << diceRoll << endl;	//prints the computers roll
	cout<<"Computer turn total is " << turnTotal <<endl;	//prints the computer's turntotal
}

void currentscores(int computerScore, int humanScore){	//method to show the current scores
	cout << "computer: " << computerScore << endl;		//prints the computers score
	cout << "human: " << humanScore << endl << endl;	//prints the human's score
}

int human(int turnTotal){	//method that returns the turn total of the human
	char yesNo;	//init yesNo
	int diceRoll = rollDice();	//init diceRoll to the return of the rollDice method
	if(diceRoll == 1 || diceRoll ==6){	//if the diceroll was 1 or 6
		turnOutput(0,diceRoll);	//runs the output method with zero and the diceroll
		return 0;	//returns 0
	}
	else if(diceRoll == 3){ //else if the diceRoll was 3
		turnOutput(15,diceRoll);	//runs the output method with 15 and the diceroll as param
		return 15;	//returns 15
	}
	else{	//else in all other cases
		turnTotal = turnTotal + diceRoll; //set the turnTotal equal to the turntotal plus the diceroll
		turnOutput(turnTotal, diceRoll);	//runs the output method with the turnTotal and diceRoll as param
		cout<< "Do you want to roll again (Y/N)?:" << endl;	//asks the user if the would like to roll again
		cin>>yesNo;	//takes the input and assigns it to yesNo
		if(yesNo == 'y' || yesNo == 'Y'){//if the input was y or Y
			human(turnTotal);	//rerun the same human method with the turntoal as a param
		}
		else{//in all other cases, when the user does not want to reroll
			return turnTotal;//return the turntotal
		}
	} 
}

int computer(int turnTotal){	//method that returns the turntotal for the computer, takes the turn total as a param
	while(turnTotal < 10){	//loop while the turnTotal is less than 10
		int diceRoll = rollDice();	//init diceRoll equal to the return from the rollDice method
		if(diceRoll == 1 || diceRoll == 6){	//if the roll is equal to 1 or 6
			turnOutputComputer(0,diceRoll);	//runs the output method with zero and the diceroll
			return 0;	//returns 0
		}
		else if(diceRoll == 3){	//if the diceroll is 3
			turnOutputComputer(15,diceRoll);	//runs the output method with 15 and the diceroll as param
			return 15;	//returns 15
		}
		else{	//in all other cases...
			turnTotal = turnTotal + diceRoll;	//sets the turn total equal to the turnTotal + the diceroll
			turnOutputComputer(turnTotal,diceRoll);	//runs the output method with the turn total and diceroll's as param
		} 
	}
	return turnTotal;	//returns the turntotal
	
}

/**
 * game 
 * driver function to play the game
 * the function does not return any value
 */

void game(){
	cout << "Welcome to Jeopardy Dice!" << endl << endl;	//prints "Welcome to Jeopary Dice!""	
	int humanScore = 0;	//init humanScore to zero
	int computerScore = 0;	//init computerScore to zero
	char yesNo;	//init the character yesNo
	while(humanScore < 100 && computerScore < 100){		//continous loop while both the computer's and the human's score is under 100
		cout << "It is now human's turn" <<endl<<endl;		//prints that it is the humans turn
		cout<< "Do you want to roll a dice (Y/N)?:" << endl;	//Asks the user if they would like to roll a dice
		cin>>yesNo; //takes the input into the yesNo character
		if(yesNo == 'y' || yesNo == 'Y'){	//checks if the inputed character was a y
			humanScore = humanScore + human(0);	//sets the human score equal to the humanScore plus the return of the human method
		}
		
		if(humanScore < 100){	//checks to make sure human's score hasn't gone over 100
			currentscores(computerScore,humanScore);	//runs the current score method, given the computerScore and humanScore as parameters
			cout << "It is now computer's turn" << endl << endl; //Prints that it is the computers turn
			computerScore = computerScore + computer(0); //changes the computer score to its current score plus the return of the computer method
		}
		
		currentscores(computerScore, humanScore); //runs the current score method, given the computerScore and humanScore as parameters
	}
	if (humanScore > 100){	//if the human has a winning score, over 100
		winner("human"); //runs the winner method on the string human
	}
	else{
		winner("computer");	//runs the winner method on the string computer
	}
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// don't change the main. 
// Once you finished please paste your code above this line 
///////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	// start the game! 
	game();
	return 0;
}