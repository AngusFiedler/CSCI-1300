#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

int split(string split, char delim, string store[], int length){
    if(split.length() < 1){ //checks if the string is empty
        return 0;   //returns 0
    }
    else {
    int counter = 0;    //init counter, int type, to zero
    int count;  //init count, int type,
    int start = 0;  //init start, int type, to zero
    for(int i = 0; split[i] == delim; i++){ //for loop that checks if the string starts with the delim,
        start = i+1;    //if it does, sets the start equal to i + 1
    }
    for (int i = start; i < split.length() + 1; i++){   //for each char in the array, i++
        if ((split[i] == delim || i == split.length()) && counter < length){  //checks if split at i is equal to delim and that the counter is not longer than the length
            if(i < split.length() + 1 && split[i - 1] != delim){    //checks to make sure the last char is not the delim and 
                store[counter] = split.substr(start,i-start);   //stores the substring in the store array at the counter index
                counter++;  //counter + 1
            }
            while (split[i+1] == delim){    //while the next char in the string is equal to the delim
                i++;    //i + 1
            }
            start = i+1;    //sets start to i + 1
            count = counter;    //sets count equal to the counter
        }
        else {  //if there is an error, aka if the string is cut into more pieces than the size of the array
            count = -1; //sets count to -1
        }
    }
    return count;   //returns the value of count
    }
}
void printCorrectedSpelling(vector<string>& phrase){
    for(int i = 0; i < phrase.size(); i++){
        if(phrase[i].length() > 0){
            cout << phrase[i] << " ";
        }
    }
}

string findCorrectSpelling(string word, vector< vector<string> >& misspellings){
    bool found = false;
    if(word.size() <= 0){
        return "";
    }
    for(int i = 0; i < misspellings.size(); i++){
        for(int k = 0; k < misspellings[i].size(); k++){
            if(misspellings[i][k] == word){
                word = misspellings[i][0];
                found = true;
            }
        }
    }
    if(!found){
        word = "unknown";
    }
    return word;
}

bool allDigits(string word){
    bool result = true;
    for(int i = 0; i < word.length(); i++){
        if(!isdigit(word[i])){
            result = false;
        }
    }
    return result;
}

bool findWord(string word, vector<string>& vocab){
    bool result = false;
    for(int k = 0; k < vocab.size(); k++){
        if(word == vocab.at(k)){
            result = true;
            break;
        }
    }
    if(!result){
        if(allDigits(word)){
            result = true;
        }
    }
    return result;
}

string symbolsFixer(string& word){
    char symbolsArray[21] = {',','.','/','?',';',':','!','@','#','$','%','^','&','*','(',')','_','-','+','=','\''};
    //,./?;’:”!@#$%^&*()_-+=
    bool symbolFound = false;
    bool lettersFound = false;
    string endingSymbols = "";
    for(int i = 0; i < word.length(); i++){
        symbolFound = false;
        for(int k = 0; k < 21; k++){
            if(word[i] == symbolsArray[k]){
                symbolFound = true;
                if(lettersFound){
                    endingSymbols += word[i];
                }
                word.erase(i,1);
                i--;
            }
        }
        if(!symbolFound){
            lettersFound = true;
        }
    }
    return endingSymbols;
}

void wordChecker(vector<string>& phrase, vector<string>& vocab,vector< vector<string> >& misspellings){
    string temp;
    bool found;
    for(int i = 0; i < phrase.size(); i++){
        found = false;
        temp = phrase.at(i);
        string endingSymbols = symbolsFixer(temp);
        if(!findWord(temp,vocab)){
            if(findCorrectSpelling(temp,misspellings).length() > 0){
                phrase[i] = findCorrectSpelling(temp,misspellings) + endingSymbols;
            }
            else{
                phrase[i].erase();
            }
        }
        else{
            phrase[i] = temp + endingSymbols;
        }
    }
}

bool loadDictionaryData(string fileName, vector<string>& vocab){
    bool result = false;
    string tempString;

    ifstream file;
    file.open(fileName);

    if(file.is_open()){
        result = true;
        int i = 0;

        while(getline(file,tempString)){
            vocab.push_back(tempString);
            i++;
        }

        cout << "Read " << i << " words from " << fileName << endl;
    }
    else{
        cout << fileName << " does not exist" << endl;
    }
    return result;
}

bool loadMisspellingsData(string fileName,vector< vector<string> >& misspellings){
    bool result = false;
    string tempstring;
    string innerTemp;

    ifstream file;
    file.open(fileName);

    if (file.is_open()){
        result = true;
        int i = 0;

        while(getline(file,tempstring)){
            string tempArray[2];
            split(tempstring,',',tempArray,2);

            misspellings.push_back(vector<string>());

            istringstream stream(tempArray[1]);
            misspellings[i].push_back(tempArray[0]);

            while(getline(stream, innerTemp, '|')){
                misspellings[i].push_back(innerTemp);
            }
            i++;
        }
        cout << "Read " << i << " words from " << fileName << endl;
    }
    else{
        cout << fileName << " does not exist" << endl;
    }
    return result;
}
string makeLowerCase(string word){
    for(int i = 0; i < word.length(); i++){
        word[i] = tolower(word[i]);
    }
    return word;
}
void spellChecker(){
    vector<string> vocab;
    vector< vector<string> > misspellings;
    if(loadDictionaryData("vocabulary.txt",vocab) && loadMisspellingsData("misspelling.csv", misspellings)){
        string phrase;
        vector<string> phraseVector;
        string tempString;
        cout << "Enter the phrase you would like to correct:" << endl;
        getline(cin,phrase);
        istringstream phraseStream(makeLowerCase(phrase));
        while(getline(phraseStream,tempString,' ')){
            if(tempString != ""){
                phraseVector.push_back(tempString);
            }
        }
        wordChecker(phraseVector,vocab,misspellings);
        printCorrectedSpelling(phraseVector);
    }
}

int main(){
    spellChecker();
}