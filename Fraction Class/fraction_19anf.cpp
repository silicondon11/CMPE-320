/*
 * fraction_19anf.cpp
 *
 *  Created on: Oct. 14, 2021
 *      Author: arifialkov
 */

#include <iostream>
#include <string>
using namespace std;
#include "fraction_19anf.h"


FractionException::FractionException(const string &err) : error(err) {};//fraction exception class

string FractionException::what() {
    return error;
}

Fraction::Fraction() {//no input
    onumerator = 0;
    odenominator = 1;
}

Fraction::Fraction(const int& inumerator) {//integer inputted
    onumerator = inumerator;
    odenominator = 1;
}

Fraction::Fraction(const int& inumerator, const int& idenominator) {//numerator and denominator inputted
    if(idenominator == 0) {
        throw FractionException("ERROR: INVALID DENOMINATOR");
    }
    else {
        onumerator = inumerator;
        odenominator = idenominator;
        normalize();
    }
}

int Fraction::numerator() {//numerator accessor
    return onumerator;
}

int Fraction::denominator() {//denominator accessor
    return odenominator;
}

void Fraction::normalize() {//normalize method
	int sign = 1;
	   if (onumerator < 0) {
	      sign = -1;
	      onumerator = -onumerator;
	   }
	   if (odenominator < 0) {
	      sign = -sign;
	      odenominator = -odenominator;
	   }
	   int g = 1;
	   if (onumerator > 0)
		   g = gcd(onumerator, odenominator);
	   onumerator = sign * (onumerator / g);
	   odenominator = odenominator / g;
}

int Fraction::gcd(int n, int m) {//method to find greatest common factor
    int g;
    if(m <= n && n%m == 0) {
        return g = m;
    }
    else if(n < m) {
        return g = gcd(m,n);
    }
    else {
        return g = gcd(m,n%m);
    }
}



//Overloading
Fraction& Fraction::operator++() {
    onumerator += odenominator;
    return *this;
}

Fraction  Fraction::operator++(int unused) {
    Fraction clone(onumerator, odenominator);
    onumerator += odenominator;
    return clone;
}

Fraction& Fraction::operator-() {
    onumerator = -1*onumerator;
    return *this;
};

Fraction operator+(const Fraction& left, const Fraction& right) {
    return Fraction((left.onumerator * right.odenominator) + (right.onumerator * left.odenominator), left.odenominator * right.odenominator);
}

Fraction operator-(const Fraction& left, const Fraction& right) {
    return Fraction((left.onumerator * right.odenominator) - (right.onumerator * left.odenominator), left.odenominator * right.odenominator);
}

Fraction operator*(const Fraction& left, const Fraction& right) {
    return Fraction((left.onumerator * right.onumerator), (left.odenominator * right.odenominator));
}

Fraction operator/(const Fraction& left, const Fraction& right) {
    return Fraction((left.onumerator * right.odenominator), (left.odenominator * right.onumerator));
}

Fraction& Fraction::operator+=(const Fraction& right) {
    onumerator = ((onumerator * right.odenominator) + (right.onumerator * odenominator));
    odenominator = odenominator * right.odenominator;
    normalize();
    return *this;
}

bool operator<(const Fraction& left, const Fraction& right) {
    if((left.onumerator * right.odenominator) < (right.onumerator * left.odenominator)) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<=(const Fraction& left, const Fraction& right) {
    if((left.onumerator * right.odenominator) <= (right.onumerator * left.odenominator)) {
        return true;
    }
    else {
        return false;
    }
}

bool operator==(const Fraction& left, const Fraction& right) {
    if((left.onumerator * right.odenominator) == (right.onumerator * left.odenominator)) {
        return true;
    }
    else {
        return false;
    }
}

bool operator!=(const Fraction& left, const Fraction& right) {
    if((left.onumerator * right.odenominator) != (right.onumerator * left.odenominator)) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>=(const Fraction& left, const Fraction& right) {
    if((left.onumerator * right.odenominator) >= (right.onumerator * left.odenominator)) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>(const Fraction& left, const Fraction& right) {
    if((left.onumerator * right.odenominator) > (right.onumerator * left.odenominator)) {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<<(ostream& out, const Fraction& value) {
    out << value.onumerator << "/" << value.odenominator;
    return out;
}

istream& operator>>(istream& in, Fraction& value) {
	   int inumerator;
	   int idenominator;
	   char slashCheck;
	   in >> inumerator;
	   if(inumerator == 0) {
	        value = Fraction();
	        return in;
	   }

	   slashCheck = in.peek();
	   if(slashCheck == '/'){
	        in.get();
	        in >> idenominator;
	        value = Fraction(inumerator, idenominator);
	   }
	   else {
		   value = Fraction(inumerator);
	   }
	   return in;
}

