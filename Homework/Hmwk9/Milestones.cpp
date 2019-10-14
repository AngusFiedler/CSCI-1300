#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Milestones.h"
#include "Util.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
/*
    loadDataFromFile:
    if the file opens successfully
        get each line from the file and store it in tempstring
            if it is the 1,3,5..etc line 
                add tempstring to milestoneName
            else
                add tempstring to milestoneDistance
            add one to i
    return result
*/
//////////////////////////////////////////////////////////////////////////
bool loadDataFromFile(vector<string>& milestoneName, vector<string>& milestoneDistance, ifstream& file){
    bool result = false;    //init result to false
    string tempString;  //create a string called tempString
    int i = 0;  //init i to zero
    if(file.is_open()){     //if the file opens
        while(getline(file, tempString)){   //for each line in the file
            if(i % 2 == 0){     //if i divided by 2 has a remainder of zero
                milestoneName.push_back(tempString);    //add tempString to the mileStoneName vector 
            }
            else{
                milestoneDistance.push_back(tempString);    //add tempString to milestoneDistance
            }
            i++;    //add one to i
            result = true;      //set result to true
        }
    }
    else{
        cout << "Error opening milestone file" << endl;     //print error opening milestone file
    }
    return result;      //return result
}


//////////////////////////////////////////////////////////////////////////
/*
    Milestones:(sorts through the milestone files)
    load data from both files

    loop through while it has not reached the end of both vectors
        if fortdistance is less than riverDistance
            add the fort data to the vectors
        else
            add the river data to the vectors
*/
//////////////////////////////////////////////////////////////////////////
Milestones :: Milestones(string fortDataFile, string riverDataFile){
    vector<string> fortNames;   //create a string vector to store fortNames
    vector<string> riverNames;  //create a string vector to store riverNames
    vector<string> fortDistances;   //create a string vector to store fortDistances
    vector<string> riverDistances;  //create a string vector to store riverDistances
            
    ifstream fortFile;  //create new ifstream called fortFile
    ifstream riverFile; //create an ifstream call riverFile
    fortFile.open(fortDataFile);   //open fortDataFile
    riverFile.open(riverDataFile);  //open riverDateFile
    
    loadDataFromFile(fortNames,fortDistances,fortFile);     //load in the data from the fort file
    loadDataFromFile(riverNames, riverDistances, riverFile);    //load in data from river file
    
    string tempStringFortDistance;  //create a string varible to store the temp fort distance
    string tempStringRiverDistance; //create a string varible to store the temp river distance
    bool fortEndReached = false;    //init forEndReached to false
    bool riverEndReached = false;   //init riverEndReached to false
    int k = 0;      //fort counter
    int n = 0;      //river counter
    
    while((k < fortNames.size() || n < riverNames.size()) && (!riverEndReached || !fortEndReached)){
        istringstream fortStream(fortDistances.at(k));      //create and stringstream called fortStream given fortDistances at pos k
        istringstream riverStream(riverDistances.at(n));    //create and stringstream called riverStream given RivertDistances at pos n

        getline(fortStream,tempStringFortDistance,'m');     //use getline to get text before the char m
        getline(riverStream,tempStringRiverDistance,'m');   //use getline to get text before the char m
        
        int tempFortDistance = stoi(tempStringFortDistance);    //set tempFortDistance to int value of tempStringFortDistance
        int tempRiverDistance = stoi(tempStringRiverDistance);  //set tempRiverDistance to int value of tempStringRiverDistance
        
        if((tempFortDistance < tempRiverDistance && !fortEndReached) || riverEndReached){   //if fort distance is less than river distances and not fortend reached or if riverend reached
            milestoneNames.push_back(fortNames.at(k));  //add fortnames at k to milestoneNames
            milestoneDistances.push_back(tempFortDistance); //add  tempFortDistance to milestoneDistances
            milestoneDepths.push_back(-1);  //add -1 to milestoneDepths
            if(k+1 < fortNames.size()){     //if k+1 is less than fortnames size 
                k++;    //add one to k
            }
            else{
                fortEndReached = true;  //set fortEndReached to true 
            }
        }
        else if(!riverEndReached){
            string riverDepthArray[2];  //create riverDepth array
            string depthString;     //create depthString
            Util().split(riverDistances.at(n),' ', riverDepthArray,2); //run split function on riverDistances at n, using space as a delim
            istringstream depthStream(riverDepthArray[1]);  //create ifstream called depthStream from riverDepthArray at pos 1
            getline(depthStream,depthString,'f');   //get depthStream till f and set it to depthString 
            
            
            int depth = stoi(depthString);  //set depth to the int val fo depth string
            milestoneNames.push_back(riverNames.at(n)); //add riverNames at n to milestoneNames
            milestoneDistances.push_back(tempRiverDistance);    //add tempRiverDistance to milestoneDistances
            milestoneDepths.push_back(depth);   //add depth to milestoneDepths 
            if(n+1 < riverNames.size()){    //if n+1 is less than riverNames size
                n++;    //add one to n
            }
            else{
                riverEndReached = true;     //set riverEndReached to true
            }
        }
        if(riverEndReached && fortEndReached){  //if both river and fort have reached the end
            break;  //break from the loop
        }
    }
}

string Milestones :: getName(int index){
    return milestoneNames.at(index);    //returns val of milestoneNames at a given index
}

int Milestones :: getDistance(int index){
    return milestoneDistances.at(index);    //returns the distance of a givenmilestone from the index
}

int Milestones :: getDepth(int index){
    return milestoneDepths.at(index);   //returns the milestoneDepth of a given index
}
