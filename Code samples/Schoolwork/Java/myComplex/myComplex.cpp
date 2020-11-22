#include <iostream>
#include <cmath>
using namespace std;

#include "myComplex.h"

MyComplex::MyComplex() : real(0), imag(0) { }
MyComplex::MyComplex(double r) : real(r), imag(0) { }
MyComplex::MyComplex(double r, double im) : real(r), imag(im) { }

double MyComplex::getReal() const { return real; }
double MyComplex::getImag() const { return imag; }

double MyComplex::abs() const {
	return sqrt(real * real + imag * imag);
}

MyComplex operator+(const MyComplex& left, const MyComplex& right) {
	// Can you get at left.real here?
	//double aVal = left.real;
	return MyComplex(left.getReal() + right.getReal(), left.getImag() + right.getImag());
}

ostream& operator<<(ostream& out, const MyComplex& value) {
   out << value.getReal() << " + " << value.getImag() << "i";
   return out;
}
