/*
 * This version of the MyComplex class uses non-member overloading of the + operator
 * and accessors.  It also contains an overloading of the pre and post-increment operator
 * and the += assignment operator.
 */
#pragma once

#include <iostream>
using namespace std;

class MyComplex {
public:
	MyComplex();
	MyComplex(double);
	MyComplex(double, double);
	double abs() const;

	MyComplex& operator+=(const MyComplex& right);

	MyComplex& operator++();	// Pre-increment
	MyComplex  operator++(int);	// Post-increment

private:
	double real;
	double imag;

friend MyComplex operator+(const MyComplex& left, const MyComplex& right);
friend ostream& operator<<(ostream& out, const MyComplex& value);
};

