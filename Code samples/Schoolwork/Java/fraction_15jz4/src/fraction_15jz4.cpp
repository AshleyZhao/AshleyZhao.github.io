//============================================================================
// Name        : fraction_15jz4.cpp
// Author      : 15jz4
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "fraction_15jz4.h"

FractionException::FractionException(const string& message) : message(message) {}
string& FractionException::what() { return message; }

Fraction::Fraction() : num(0), denom(1) { }
Fraction::Fraction(int n) : num(n), denom(1) { }
Fraction::Fraction(int n, int d) {
	if (d == 0) { throw FractionException("Illegal Fraction! Are you trying to divide by zero?"); }
	else {
		int divisor = gcd(d,n);
		num = n/divisor;
		if (num < 0 && denom < 0) {num *= (-1);} //indicates both numerator/denominator is negative
		denom = d/divisor;
		if (denom < 0) {denom *= (-1);} //indicates denominator is negative
	}
}

int Fraction::numerator() const { return num; }
int Fraction::denominator() const { return denom; }

int gcd (int n, int m) {
	int newN = n < 0 ? -n : n;
	int newM = m < 0 ? -m : m;
	if (newM <= newN && newN % newM == 0) { return newM; }
	else if (newN < newM) { return gcd(newM, newN); }
	else { return gcd(newM, newN%newM); }
}

Fraction operator+(const Fraction& left, const Fraction& right) {
	int a = (left.num * right.denom);
	int b = (left.denom * right.num);
	int c = (left.denom * right.denom);
	int d = (a+b);
	Fraction temp(d,c);
	return temp;
}

Fraction operator-(const Fraction& left, const Fraction& right) {
	int a = (left.num * right.denom);
	int b = (left.denom * right.num);
	int c = (left.denom * right.denom);
	int d = (a-b);
	Fraction temp(d,c);
	return temp;
}

Fraction operator*(const Fraction& left, const Fraction& right) {
	int a = (left.num * right.num);
	int c = (left.denom * right.denom);
	Fraction temp(a,c);
	return temp;
}

Fraction operator/(const Fraction& left, const Fraction& right) {
	int a = (left.num * right.denom);
	int c = (left.denom * right.num);
	Fraction temp(a,c);
	return temp;
}

Fraction operator-(const Fraction& value) {
	return Fraction(-value.num, value.denom);
}

// Pre-increment
Fraction& Fraction::operator++() {
	num = num + denom;

	//reduce fraction
	int divisor = gcd(denom,num);
	num = num/divisor;
	denom = denom/divisor;
	if (num < 0 && denom < 0) {num *= (-1);}
	if (denom < 0) {denom *= (-1);}

	return *this;
}

// Post-increment
Fraction Fraction::operator++(int unused) {
	Fraction clone(num, denom);
	num = num + denom;

	//reduce fraction
	int divisor = gcd(denom,num);
	num = num/divisor;
	denom = denom/divisor;
	if (num < 0 && denom < 0) {num *= (-1);}
	if (denom < 0) {denom *= (-1);}

	return clone;
}



Fraction& Fraction::operator+=(const Fraction& right) {
	int a = (num * right.denom);
	int b = (denom * right.num);
	int c = (denom * right.denom);
	int d = (a+b);
	num = d;
	denom = c;

	//reduce fraction
	int divisor = gcd(denom,num);
	num = num/divisor;
	denom = denom/divisor;
	if (num < 0 && denom < 0) {num *= (-1);}
	if (denom < 0) {denom *= (-1);}

	return *this;
}


bool operator<(const Fraction& left, const Fraction& right) {
	return (left.num * (left.denom * right.denom)) < (right.num * (left.denom * right.denom));
}

bool operator<=(const Fraction& left, const Fraction& right) {
	return (left.num * (left.denom * right.denom)) <= (right.num * (left.denom * right.denom));
}

bool operator==(const Fraction& left, const Fraction& right) {
	return (left.num * (left.denom * right.denom)) == (right.num * (left.denom * right.denom));
}

bool operator!=(const Fraction& left, const Fraction& right) {
	return (left.num * (left.denom * right.denom)) != (right.num * (left.denom * right.denom));
}

bool operator>=(const Fraction& left, const Fraction& right) {
	return (left.num * (left.denom * right.denom)) >= (right.num * (left.denom * right.denom));
}

bool operator>(const Fraction& left, const Fraction& right) {
	return (left.num * (left.denom * right.denom)) > (right.num * (left.denom * right.denom));
}


ostream& operator<<(ostream& out, const Fraction& value) {
   out << value.num << "/" << value.denom;
   return out;
}

istream& operator>>(istream& in, Fraction& value) {

	std::string tempAll;

	in >> tempAll; //get input

	int tempNum;
	int tempDenom;
	char slash = '/';

	std::size_t found = tempAll.find(slash);
	if (found!=std::string::npos) { //It is a full fraction
		tempNum = std::stoi(tempAll.substr(0,found), nullptr, 0);
		tempDenom = std::stoi(tempAll.substr(found+1,tempAll.length()), nullptr, 0);
		value.num = tempNum;
		value.denom = tempDenom;

		if (value.denom == 0) { throw FractionException("Illegal Fraction! Are you trying to divide by zero?"); }
	}
	else {
		tempNum = std::stoi(tempAll);
		value.num = tempNum;
		value.denom = 1;
	}
	return in;
}
