/*
 * ShapesGood.cpp
 *
 *  Created on: Nov. 24, 2021
 *      Author: arifialkov
 */
#include <iostream>
#include <string>
#include "ShapesGood.h"

using namespace std;

//main constructors
Shape::Shape(int len, int wid, string outClr) : length(len), width(wid), outlineColour(outClr) {}
Shape::~Shape() {}
int Shape::getLength() { return length; }
int Shape::getWidth() { return width; }

Fillable::Fillable(string fillCol) : fillColour(fillCol) {}
Fillable::~Fillable() {}

Labelled::Labelled(string txt) : text(txt) {}
Labelled::~Labelled() {}

Square::Square(int length, int width, string outlineColour) : Shape(length, width, outlineColour) {}
void Square::draw() {//every shape implements different methods when draw() is called, based on if it is fillable and/or labelled
	drawOutside();
}
void Square::drawOutside() {
	cout << "\nDrawing a " + outlineColour + " square.";
}

FilledSquare::FilledSquare(int length, int width, string outlineColour, string fillColour) : Square(length, width, outlineColour), Fillable(fillColour) {}
void FilledSquare::draw() {
	drawOutside();
	fill();
}
void FilledSquare::fill() {
	cout << " With " + fillColour + " fill.";
}

FilledTextSquare::FilledTextSquare(int length, int width, string outlineColour, string fillColour, string text) : FilledSquare(length, width, outlineColour, fillColour), Labelled(text) {}
void FilledTextSquare::draw() {
	drawOutside();
	fill();
	drawText();
}
void FilledTextSquare::drawText() {
	cout << " Containing the text: \"" << text << "\".";
}


Circle::Circle(int length, int width, string outlineColour) : Shape(length, width, outlineColour) {}
void Circle::draw() {
	drawOutside();
}
void Circle::drawOutside() {
	cout << "\nDrawing a " + outlineColour + " circle.";
}

FilledCircle::FilledCircle(int length, int width, string outlineColour, string fillColour) : Circle(length, width, outlineColour), Fillable(fillColour) {}
void FilledCircle::draw() {
	drawOutside();
	fill();
}
void FilledCircle::fill() {
	cout << " With " + fillColour + " fill.";
}


Arc::Arc(int length, int width, string outlineColour) : Shape(length, width, outlineColour) {}
void Arc::draw() {
	drawOutside();
}
void Arc::drawOutside() {
	cout << "\nDrawing a " + outlineColour + " arc.";
}
