#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Dice.h"
#include "Player.h"

using namespace std;

int main()
{  
      // creating Player p1 with 5 dices
      Player p1(5);

      p1.playerRoll();  //run playerRoll on p1
      
      for (int i = 0; i < 5; i++){  //loop through from zero to 5, i++
            cout << p1.getDiceValueAtIndex(i) << " "; //print the value at index i
      }
      cout << endl;
      return 0;
}