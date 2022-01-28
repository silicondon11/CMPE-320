/*
 * ShapesGood.h
 *
 *  Created on: Nov. 24, 2021
 *      Author: arifialkov
 */

#ifndef SHAPESGOOD_H_
#define SHAPESGOOD_H_

#pragma once

#include <string>
using namespace std;

//note: every instance I tried used const where it made sense ended up giving
//me an error or made the program less efficient for some reason so I didnt
//use any const variables

class Shape {//remake shape class
public:
	Shape();
	Shape(int, int, string);
	virtual ~Shape();
	int getLength();
	int getWidth();
	virtual void draw() = 0;
protected:
	string outlineColour;
private:
	int length, width;
};

class Fillable {//make fillable class
public:
	Fillable(string);
	virtual ~Fillable();
protected:
	virtual void fill() = 0;
	string fillColour;
};

class Labelled {//make labelled class
public:
	Labelled(string);
	virtual ~Labelled();
protected:
	virtual void drawText() = 0;
	string text;
};

class Square : public Shape {//make square extend shape
public:
	Square(int, int, string);
	virtual void draw();
protected:
	virtual void drawOutside();
};

class FilledSquare : public Square, Fillable {//make filled square extend shape and fillable
public:
	FilledSquare(int, int , string, string);
	virtual void draw();
protected:
	virtual void fill();
};

class FilledTextSquare : public FilledSquare, Labelled {//make filled text square extend filled square and labelled
public:
	FilledTextSquare(int, int, string, string, string);
	virtual void draw();
protected:
	virtual void drawText();
};


class Circle : public Shape {//make circle extend shape
public:
	Circle(int, int, string);
	virtual void draw();
protected:
	virtual void drawOutside();
};

class FilledCircle : public Circle, Fillable {//make filled circle extend circle and fillable
public:
	FilledCircle(int, int, string, string);
	virtual void draw();
protected:
	virtual void fill();
};

class Arc : public Shape {//make arc extend shape
public:
	Arc(int, int, string);
	virtual void draw();
protected:
	virtual void drawOutside();
};



#endif /* SHAPESGOOD_H_ */
