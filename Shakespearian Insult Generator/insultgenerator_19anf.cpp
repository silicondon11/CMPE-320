/*
* insultgenerator_19anf.cpp
        *
        *  Created on: Oct. 4, 2021
*      Author: arifialkov
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>
using namespace std;
#include "insultgenerator_19anf.h"

FileException::FileException(const string& error) : error(error) {}

string FileException::what() const{
    return error;
}
//FileException()

NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& error) : error(error){}

string NumInsultsOutOfBounds::what() const{
    return error;
}
//NumInsultsOutOfBounds()

void InsultGenerator::initialize(){
    int fileSize = 0;
    string row;


    ifstream getFile("InsultsSource.txt");
    if (getFile.fail()){
        throw FileException("ERROR: FILE NOT FOUND");
    }

    while (!getFile.eof()){
        getFile >> row;
        insult1.push_back(row);

        getFile >> row;
        insult2.push_back(row);

        getFile >> row;
        insult3.push_back(row);
    }
    getFile.close();
}
//initialize()

string InsultGenerator::talkToMe(){
    string fullInsult = ("Thou " + insult1[rand() % 50] + " " + insult2[rand() % 50] + " " + insult3[rand() % 50] + "!");
    return fullInsult;
}
//talkToMe()

vector<string> InsultGenerator::generate(const int insultNumber){
    if (insultNumber < 1 || insultNumber > 10000){
        throw NumInsultsOutOfBounds("ERROR: INSULT AMOUNT INVALID");
    }
    string output;
    set<string> setOfI;

    while (setOfI.size()<insultNumber){
            output = talkToMe();
            setOfI.insert(output);
    }
    vector<string> myVector(setOfI.begin(), setOfI.end());
    return myVector;
}
//generate()

void InsultGenerator::generateAndSave(const string resultFile, const int insultNumber){
    ofstream ResultingInsults;
    ResultingInsults.open(resultFile);

    vector<string> savedInsult = generate(insultNumber);
    if (ResultingInsults.is_open()){
        for(int i = 0; i < insultNumber; i++){
            ResultingInsults << savedInsult[i] << endl;
        }
    }
    else {
        throw FileException("ERROR: RESULTS FILE NOT CREATED");
    }
}
//generateAndSave()
