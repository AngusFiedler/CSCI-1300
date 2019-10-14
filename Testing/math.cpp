#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
    double rInit = 6;
    double rFinal = 9;
    double pi = atan(1)*4;
    cout << "test " << pi << endl;
    
    double fRFinal = (4/3)*pi*pow(rFinal, 3);
    double fRInit = (4/3)*pi*pow(rInit, 3);
    
    double result = (fRFinal - fRInit)/(rFinal - rInit);
    cout << result << endl;
}