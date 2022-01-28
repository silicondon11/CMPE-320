/*
 * JumblePuzzle.h
 *
 *  Created on: Nov. 11, 2021
 *      Author: arifialkov
 */

#ifndef JUMBLEPUZZLE_H_
#define JUMBLEPUZZLE_H_

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cmath>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>

using namespace std;

typedef char* charArrayPtr;

class BadJumbleException {//file exception class
public:
    BadJumbleException(const string&);//calls itself with the desired error to be printed
    string what();
private:
    string error;
};

class JumblePuzzle {//Jumble puzzle members
public:
    JumblePuzzle(const string& word, const string& difficulty);
    JumblePuzzle(const JumblePuzzle& puzz);
    ~JumblePuzzle();
    JumblePuzzle& operator=(const JumblePuzzle& right);
    charArrayPtr* getJumble() const;
    int getSize() const;
    int getRowPos() const;
    int getColPos() const;
    char getDirection() const;

private:
    charArrayPtr* buffer;
    int size;
    int row;
    int column;
    char direction;
};


#endif /* JUMBLEPUZZLE_H_ */
