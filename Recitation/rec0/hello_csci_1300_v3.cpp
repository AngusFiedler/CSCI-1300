#include <iostream>
using namespace std;

int main() {
    //cout << "Hello World! Hello CSCi 1300" << endl;
    int Num;
    cout << "Enter a Number between 1 and 10:";
    cin >> Num;
    while ( Num < 1 || Num > 10){
        cout << "That number is not between 1 and 10";
	    cin >> Num;
    }
    cout << Num;

}
