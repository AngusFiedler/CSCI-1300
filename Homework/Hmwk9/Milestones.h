#ifndef Milestones_H
#define Milestones_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Player.h"
#include "Date.h"
#include "Companions.h"
#include "Supplies.h"
using namespace std;

class Milestones{
    private:
        vector<string> milestoneNames;
        vector<int> milestoneDistances;
        vector<int> milestoneDepths;
    public:
        Milestones(){   //default constructor
            for(int i = 0; i < 10; i++){    //from 0 to 10, i++
                milestoneNames.push_back("null");   //add name null
            }
            for(int i = 0; i < 10; i++){    //from 0 to 10, i++
                milestoneDistances.push_back(0);    //set distance to 0
            }
            for(int i = 0; i < 10; i++){    //from zero to 10, i++
                milestoneDepths.push_back(-1);  //set depth to -1
            }
        }
        Milestones(string fortDataFile, string riverDatasFile); //param constructor

        string getName(int index);  //returns the name of the milestone at a given index

        int getDistance(int index); //returns the distance to to the givenmilestone given the index

        int getDepth(int index);    //returns the depth of a givenmilestone given the index
};
#endif