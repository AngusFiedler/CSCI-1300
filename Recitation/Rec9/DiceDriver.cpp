#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Dice.h" 
using namespace std;

// driver code to run and verify dice class is working
int main(){

      Dice d1;    //init Dice d1
      Dice d2;    //init Dice d2
      srand(time(0));
      for (int i = 1; i <= 10; i++){  
            d1.roll();  //roll d1
            d2.roll();  //roll d2
            cout << d1.getFaceValue() << " " << d2.getFaceValue() << endl;    //print the value of d1 and then d2
      }

      return 0;   //return 0
}