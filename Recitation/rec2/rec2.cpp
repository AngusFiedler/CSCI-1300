#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cout << "Enter a radius: " << endl;
    float radius;
    cin >> radius;
    float volume;
    volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume << endl;
    float surface_area = 4 * M_PI * pow(radius, 2);
    cout << "surface area: " << surface_area;
   
}


//Calculates the volume of a sphere given a radius and prints result to screen
void sphereVolume(float radius){
    float volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "volume: " << volume;
}

//calculates the surfacearea of a sphere given a radius and prints the result to the screen
void sphereSurfaceArea(float radius){
    float surface_area = 4 * M_PI * pow(radius, 2);
    cout << "surface area: " << surface_area;
}

//Returns Hello CS ____ World! to the screen given an input of a class num which is unputed after CS
void classGreeting(int classnum){
    cout << "Hello, CS " << classnum << " World!";
}