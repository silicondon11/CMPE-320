/*
 * fraction_19anf.h
 *
 *  Created on: Oct. 14, 2021
 *      Author: arifialkov
 */

#ifndef FRACTION_19ANF_H_
#define FRACTION_19ANF_H_

#include <string>

class FractionException {//file exception class
public:
    FractionException(const string&);//calls itself with the desired error to be printed
    string what();
private:
    string error;
};

class Fraction {
public:
    Fraction();
    Fraction(const int& inumerator);
    Fraction(const int& inumerator, const int& idenominator);
    Fraction& operator++();
    Fraction operator++(int unused);
    Fraction& operator-();
    Fraction& operator+=(const Fraction& right);
    int numerator();
    int denominator();
    void normalize();
    int onumerator;
    int odenominator;
private:
    int gcd(int n, int m);

};

Fraction operator+=(const Fraction& left, const Fraction& right);
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
bool operator<(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);
ostream& operator<<(ostream& out, const Fraction& value);
istream& operator>>(istream& in, Fraction& value);


#endif /* FRACTION_19ANF_H_ */
