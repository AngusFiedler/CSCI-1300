#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(){
    string fortDataFile = "fort-milestones.txt";
    vector<string> fortNames;
    vector<string> riverNames;
    
    vector<string> fortDistances;
    vector<string> riverDistances;
            
    string tempString;  //create a new string called tempString
            
    ifstream fortFile;  //create new ifstream called fortFile
    ifstream riverFile;
            
    fortFile.open(fortDataFile);    //open the given file
    //riverFile.open(riverDataFile);
    
    if(fortFile.is_open()){ //if both files have opened
        int i = 0;
        while(getline(fortFile, tempString)){   //for each line in the file
            if(i % 2 == 0){
                //cout << "fort names: " << tempString << endl;
                fortNames.push_back(tempString);
            }
            else{
                //cout << "distances: " << tempString << endl;
                fortDistances.push_back(tempString);
            }
            i++;
        }
    }
    else{
        cout << "Fort file could not be found" << endl;
    }
    if(riverFile.is_open()){
        int i = 0;
        while(getline(riverFile, tempString)){   //for each line in the file
            if(i % 2 == 0){
                //cout << "fort names: " << tempString << endl;
                riverNames.push_back(tempString);
            }
            else{
                //cout << "distances: " << tempString << endl;
                riverDistances.push_back(tempString);
            }
            i++;
        }
    }
    
    
}