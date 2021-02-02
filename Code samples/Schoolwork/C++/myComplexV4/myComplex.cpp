#include <iostream>
#include <cmath>
using namespace std;

#include "myComplex.h"

MyComplex::MyComplex() : real(0), imag(0) { }
MyComplex::MyComplex(double r) : real(r), imag(0) { }
MyComplex::MyComplex(double r, double im) : real(r), imag(im) { }

double MyComplex::abs() const {
	return sqrt(real * real + imag * imag);
}

MyComplex& MyComplex::operator+=(const MyComplex& right) {
	real = real + right.real;
	imag = imag + right.imag;
	return *this;
}

// Pre-increment
MyComplex& MyComplex::operator++() {
	real++;
	return *this;
}

// Post-increment
MyComplex MyComplex::operator++(int unused) {
	MyComplex clone(real, imag);
	real++;
	return clone;
}

MyComplex operator+(const MyComplex& left, const MyComplex& right) {
	return MyComplex(left.real + right.real, left.imag + right.imag);
}

ostream& operator<<(ostream& out, const MyComplex& value) {
   out << value.real << " + " << value.imag << "i";
   return out;
}
