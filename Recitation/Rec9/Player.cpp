#include "Player.h"
#include "Dice.h"

Player::Player(int nDice){
    for (int i = 0; i < nDice; i++){    //loop through from zero to nDice, i++
        Dice d1;    //create Dice d1
        myDice[i] = d1; //add d1 to the myDice array at pos i
    }
}

void Player::setNumDice(int number){
    nDice = number; //set nDice to the value of number
}

void Player::playerRoll(){
    for(int i = 0;i < nDice; i++){  //for loop from zero to nDice, i++
        myDice[i].roll();   //run the roll function of myDice at pos i
    }
}

int Player::getDiceValueAtIndex(int i) const{
    
    return myDice[i].getFaceValue();    //return the facevalue at i on myDice
}