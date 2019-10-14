// CSCI1300 Fall 2018
// Author: Angus Fiedler
// Recitation: 104 – Richard Tillquist
// Cloud9 Workspace Editor Link: https://ide.c9.io/anfi9237/csci1300-anfi9237
// Homework 5


/*

simScore:
score = 0
if the seq are the same length and are not empty
    for each char in the string, i+1
        if firstSeq at i and secondSeq at i do not equal each other
            score + 1
    set score equal to firstSeq length - score divided by firstSeq length
return score


///////////////////////////////////////////////
realAnalyzer:
init largestnum and set it equal to the first value in genome
init arraylength and set it to 3
for each item in the array starting at the second item, i++
    if the genome at i is larger than the current largest num
        set largestnum to the value of genome at i
for each item in the array, i++
    if genome at i is equal to the largestnum
        print genome i is the best match
///////////////////////////////////////////////
analyzer:
if any of the lengths are zero
        print "Genome and sequence cannot be empty."
else if the lengths are not equal 
    print "Genome length does not match."
else if the length of unknown bacteria is longer than the genome's
    print "Sequence length must be smaller than genome length."
else{
    int length to genomeOne's length
    init testOne
    init testTwo
    init testThree
    for each item in the array, i++
        init test equal to the substring of genomeOne from i to unknownBacteria's length
        init score = simScore(test, unknownBacteria)
        if score is greater than testOne
            int testOne to the value of score
    for each item in the array, i++
        init test equal to the substring of genomeTwo from i to unknownBacteria's length
        init score to the result of simScore(test, unknownBacteria)
        if score is greater than testTwo
            set testTwo to to the value of score
    for each item in the array, i++
            string test equal to the substring of genomeThree from i to unknownBacteria's length
            set score to the result of simScore(test, unknownBacteria)
            if score is greater than testThree
                set testThree to score
    create array genome and give it the three scores 
    run realAnalyzer on the genome array 
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std;


double simScore(string firstSeq, string secondSeq){
    double score = 0;   //init double score to zero
    if(firstSeq.length() == secondSeq.length() && firstSeq.length() !=0){   //if both seq are the same length and have a length longer than 0
        for(int i = 0; i < firstSeq.length(); i++){ //for each char in the firstSeq, i++
            if(firstSeq[i] != secondSeq[i]){    //if the firstSeq char at i is not equal to the secondSeq char at i
                score++;    //score + 1
            }
        }
        score = (firstSeq.length()-score)/firstSeq.length();    //set score equal to the length of the firstSeq - score divided by the length of firstSeq
    }
    return score;   //return the value of score
}

void realAnalyzer(double genome[]){
    double largestnum = genome[0];  //init largestnum and set it equal to first value in genom
    int arraylength = 3;    //init array length and set it equal to 3
    for(int i = 1; i < arraylength; i++){   //for each item in the array, starting at the second item, i++
        if(genome[i] > largestnum){ //if the value of genome at i is larger than the largestnum
            largestnum = genome[i]; //set largest num to the value of genome at i
        }
    }
    for(int i = 0; i < arraylength; i++){   //for each item in the array
        if(genome[i] == largestnum){        //if the value of genome at i is equal to the largestnum
        cout << "Genome " << i+1 <<" is the best match." << endl;   //print "genome" i+1 " is the the best match"
        }
    }
}

void analyzer(string genomeOne, string genomeTwo, string genomeThree, string unknownBacteria){
    if(genomeOne.length() == 0 || genomeTwo.length() == 0 || genomeThree.length() == 0 || unknownBacteria.length() == 0){   //checks if any of the lengths are zero
        cout << "Genome and sequence cannot be empty."; //print that the genome's length's cannot be empty  
    }
    else if(genomeOne.length() != genomeTwo.length() || genomeOne.length() != genomeThree.length()){    //checks if the length's are all the same
        cout << "Genome length does not match.";    //print that the length's do not match
    }
    else if(unknownBacteria.length() > genomeOne.length()){ //if the unknown bacteria is longer than the Genome's 
        cout << "Sequence length must be smaller than genome length.";  //print that the sequence must be shorter than the genome length
    }
    else{
        int length = genomeOne.length();    //set int length to the value of genomeOne's length
        double testOne = 0; //init testOne, double, for the high score of genomeOne
        double testTwo = 0; //init testTwo, double, for the high score of genomeTwo
        double testThree = 0;   //init testThree, double, for the high score of genomeThree
        for(int i = 0; i < length; i++){    //for each char in the array 
            string test = genomeOne.substr(i, unknownBacteria.length());    //create a string using the substring from i with a length of the unknown bacteria
            double score = simScore(test, unknownBacteria); //calculate the score  using simscore given the string that was just found and the unknown bacteria
            if(score > testOne){    //if the calculated score is greater than the current highest score
                testOne = score;    //set testOne to score
            }
        }
        for(int i = 0; i < length; i++){    //for each char in the array 
            string test = genomeTwo.substr(i, unknownBacteria.length());    //create a string using the substring from i with a length of the unknown bacteria
            double score = simScore(test, unknownBacteria); //calculate the score  using simscore given the string that was just found and the unknown bacteria
            if(score > testTwo){    //if the calculated score is greater than the current highest score
                testTwo = score;    //set testTwo to score
            }
        }
        for(int i = 0; i < length; i++){    //for each char in the array 
            string test = genomeThree.substr(i, unknownBacteria.length());  //create a string using the substring from i with a length of the unknown bacteria
            double score = simScore(test, unknownBacteria); //calculate the score  using simscore given the string that was just found and the unknown bacteria
            if(score > testThree){  //if the calculated score is greater than the current highest score
                testThree = score;  //set test three to score
            }
        }
        double genome[] = {testOne, testTwo, testThree};    //create an array given the three scores found
        realAnalyzer(genome);   //run realAnalyzer given the genome array
    }
}

int main(){
    /*
    cout << simScore("ATGC","ATGA") << endl;    //test case 1 for simScore, print 0.75
    cout << simScore("ATGC","ATGC") << endl;    //test case 2 for simScore, print 1
    cout << simScore("ATG","GTA") << endl;    //test case 3 for simScore, print 0.3
    cout << simScore("AAA","TTT") << endl;    //test case 4 for simScore, print 0.0
    cout << simScore("ATGC","ATCG") << endl;    //test case 5 for simScore, print 0.5
    cout << simScore("ATC","ATG") << endl;    //test case 6 for simScore, print 0.666
    */
    /*
    analyzer("AAG","TGC","GATTACA","TAC");  //test case 1, should print that the length's do not match
    analyzer("AAG","TGC","TAC","CCCCCATAG");    //test case 2, should print that the sequence must be smaller
    analyzer("","TGC","","TTA");    //test case 3, should print that the genome and sequence connot be empty
    analyzer("AC","AC","AC","AC");  //test case 4, should print that all three work 
    analyzer("TAAGGCA","TACCTAC","AGCCAGA","TCT");  //test case 5, should print that genome 2 is the best match
    analyzer("AACT","AACT","AATG","AACT")  //test case 6, should return genome 1 and genome 2 are the best match
    */
    
    
    //two of the genomes are best match
    //two of the genomes are best match
    string g1 = "CATCATAATTAGCACGTTGTTGGTACCTAGAGACCAACTTAC";
    string g2 = "TGGAGACCCACCCGTTACTTCTGACAGACAGAAGTGAGCGAT";
    string g3 = "CCTAACGTGTGGCCACGCGGGAGAAGAGGTTTACCATTCTGC";
    string seq = "TCTTTTA";
    analyzer(g1,g2,g3,seq);
}