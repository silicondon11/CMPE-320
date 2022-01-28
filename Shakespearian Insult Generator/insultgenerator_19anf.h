/*
 * insultgenerator_19anf.h
 *
 *  Created on: Oct. 3, 2021
 *      Author: arifialkov
 */

#include <string>
#include <vector>
using namespace std;

class FileException {//file exception class
public:
    FileException(const string&);//calls itself with the desired error to be printed
    string what() const;
private:
    string error;
};

class NumInsultsOutOfBounds {//invalid number of insults
public:
    NumInsultsOutOfBounds(const string&);
    string what() const;
private:
    string error;
};

class InsultGenerator{//InsultGenerator()
public:
    void initialize();//calls method to initialize generator and read InsultsSource.txt
    string talkToMe();//calls method to build insult
    vector<string> generate(const int insultNumber);//calls method that puts the crafted insult into a vector string
    void generateAndSave(const string ResultingInsults, const int insultNumber);//calls method that creates a file and saves the vector strings to it in order

private:
    vector<string> insult1;//creating vector string variables for each part of the insult
    vector<string> insult2;
    vector<string> insult3;
};



