/*
 * JumblePuzzle.cpp
 *
 *  Created on: Nov. 11, 2021
 *      Author: arifialkov
 */

#include "JumblePuzzle.h"


using namespace std;

BadJumbleException::BadJumbleException(const string &err) : error(err) {};//Bad Jumble exception class

string BadJumbleException::what() {
    return error;
}

JumblePuzzle::JumblePuzzle(const string& word, const string& difficulty) {//main constructor

    int wordSize = word.length();

    if((difficulty != "easy") && (difficulty != "medium") && (difficulty != "hard")){//throws exception if invalid difficulty is entered
        throw BadJumbleException("INVALID DIFFICULTY ENTERED. PLEASE ENTER 'easy', 'medium', or 'hard'.");
    }

    if((wordSize > 10) || (wordSize < 3)){//throws exception if word length is invalid
        throw BadJumbleException("INVALID WORD ENTERED. PLEASE ENTER A WORD CONTAINING 3-10 LETTERS.");
    }

    if(difficulty == "easy") {//set the size of the puzzle based on difficulty
        size = wordSize * 2;
    }
    else if(difficulty == "medium") {
        size = wordSize * 3;
    }

    else if(difficulty == "hard") {
        size = wordSize * 4;
    }


    srand(time(NULL));//initialize random
    buffer = new charArrayPtr[size];

    for(int i = 0; i < size; i++) {//fill the puzzle
        buffer[i] = new char[size];
        for(int j = 0; j < size; j++) {
            buffer[i][j] = 'a' + rand()%26;
        }
    }

    int invalid = 1;
    while(invalid == 1) {//while loop that restarts placing the hidden word if the word will exceed any border of the puzzle.
        row = rand()%size;
        column = rand()%size;
        char directions[] = "nesw";
        direction = directions[rand()%4];
        invalid = 0;
        if((row > (size - wordSize)) && (direction == 's')){
            invalid = 1;
        }
        if((row < (wordSize - 1)) && (direction == 'n')){
            invalid = 1;
        }
        if((column > (size - wordSize)) && (direction == 'e')){
            invalid = 1;
        }
        if((column < (wordSize - 1)) && (direction == 'w')){
            invalid = 1;
        }

    }

    for(int i = 0; i < wordSize; i++) {//inserting the word into the puzzle
        if(direction == 's') {
            buffer[row + i][column] = word[i];
        }
        else if(direction == 'n') {
            buffer[row - i][column] = word[i];
        }
        else if(direction == 'e') {
            buffer[row][column + i] = word[i];
        }
        else if(direction == 'w') {
            buffer[row][column - i] = word[i];
        }
    }
}

JumblePuzzle::JumblePuzzle(const JumblePuzzle& puzz) {//copy constructor
    size = puzz.getSize();
    row = puzz.getRowPos();
    column = puzz.getColPos();
    direction = puzz.getDirection();
    //may have to make getSize()
    buffer = new charArrayPtr[size];

    for(int i = 0; i < size; i++) {
        buffer[i] = new char[size];
        for(int j = 0; j < size; j++) {
            buffer[i][j] = puzz.buffer[i][j];
        }
    }
}

JumblePuzzle::~JumblePuzzle() {//destructor
    for(int i = 0; i < size; i++) {
        delete[] buffer[i];
    }
    delete[] buffer;
}

JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& right) {//overload assignment operator
    if(this != &right) {
        right.~JumblePuzzle();
        size = right.size;//may have to make getSize()
        buffer = new charArrayPtr[size + 1];
        for(int i = 0; i < size; i++) {//allocating memory to buffer
            buffer[i] = new char[size];
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; i++) {
                buffer[i][j] = right.buffer[i][j];
            }
        }
    }
    return *this;
}

//accessors
charArrayPtr* JumblePuzzle::getJumble() const {
    return buffer;
}

int JumblePuzzle::getSize() const {
    return size;
}

int JumblePuzzle::getRowPos() const {
    return row;
}

int JumblePuzzle::getColPos() const {
    return column;
}

char JumblePuzzle::getDirection() const {
    return direction;
}

