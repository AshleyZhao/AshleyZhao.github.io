/*
 * This version of the MyComplex class uses non-member overloading of the
 * +, -, /, *, +=, ++, negate, boolean comparisons, <<, >>
 */
#pragma once

#include <iostream>
using namespace std;

class Fraction {
public:
	Fraction();				// Default Constructor
	Fraction(int);			// Constructor for numerator input only
	Fraction(int, int);	// Constructor for numerator/denominator
	int numerator() const;		// Accessor
	int denominator() const;		// Accessor

	Fraction& operator+=(const Fraction& right); //addition assignment

	Fraction& operator++();	// Pre-increment
	Fraction  operator++(int);	// Post-increment

	double abs() const;

private:
	int num;
	int denom;

	// Binary operations
	friend Fraction operator+(const Fraction& left, const Fraction& right);
	friend Fraction operator-(const Fraction& left, const Fraction& right);
	friend Fraction operator*(const Fraction& left, const Fraction& right);
	friend Fraction operator/(const Fraction& left, const Fraction& right);

	//negation
	friend Fraction operator-(const Fraction& value);

	//boolean comparisons
	friend bool operator<(const Fraction& left, const Fraction& right);
	friend bool operator<=(const Fraction& left, const Fraction& right);
	friend bool operator==(const Fraction& left, const Fraction& right);
	friend bool operator!=(const Fraction& left, const Fraction& right);
	friend bool operator>=(const Fraction& left, const Fraction& right);
	friend bool operator>(const Fraction& left, const Fraction& right);

	//input/output
	friend ostream& operator<<(ostream& out, const Fraction& value);
	friend istream& operator>>(istream& in, Fraction& value);

};



class FractionException { //throws an exception when illegal fraction is inputted
public:
	FractionException(const string& message);
	string& what();
private:
	string message;
};

int gcd(int m, int n); //finds greatest common divisor

void reduce(int num, int denom);
