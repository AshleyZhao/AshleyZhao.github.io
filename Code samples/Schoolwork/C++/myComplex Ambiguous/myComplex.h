/*
 * This version of the MyComplex class uses non-member overloading of the + operator
 * and accessors.
 */
#pragma once

#include <iostream>
using namespace std;

class MyComplex {
public:
	MyComplex();
	MyComplex(double);				// Conversion constructor
//	explicit MyComplex(double);		// A Constructor, only
	MyComplex(double, double);
	double getReal() const;
	double getImag() const;
	double abs() const;
	operator int() const;			// Overload cast to int
private:
	double real;
	double imag;
};

MyComplex operator+(const MyComplex& left, const MyComplex& right);
ostream& operator<<(ostream& out, const MyComplex& value);
