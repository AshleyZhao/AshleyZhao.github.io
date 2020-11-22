/*
 * This version of the MyComplex class uses non-member overloading of the + operator
 * and accessors.
 */
#pragma once

#include <iostream>
using namespace std;

class MyComplex {
public:
	MyComplex();				// Default Constructor
	MyComplex(double);			// Constructor, Conversion Constructor
	MyComplex(double, double);	// Constructor
	double getReal() const;		// Accessor
	double getImag() const;		// Accessor
	double abs() const;			// Accessor
private:
	double real;
	double imag;
};

// Non-Member overloading of + operator
MyComplex operator+(const MyComplex& left, const MyComplex& right);

// Get a bit ahead of ourselves so it is easy to display a MyComplex object.
ostream& operator<<(ostream& out, const MyComplex& value);

