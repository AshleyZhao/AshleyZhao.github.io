#include <iostream>
using namespace std;

#include "myComplex.h"

int main() {

	MyComplex one;
	MyComplex two(2);
	MyComplex three(3.5);
	MyComplex four(3, 4);
	MyComplex five(4.0, 5.0);
	MyComplex six(0, 7);

	cout << "one: " << one << endl;
	cout << "two: " << two << endl;
	cout << "three: " << three << endl;
	cout << "four: " << four << endl;
	cout << "five: " << five << endl;
	cout << "six: " << six << endl;

	cout << "\nOperations:" << endl;
	// Normal overloading of +
	cout << "one + two: " << one + two << endl;
	cout << "four + five: " << four + five << endl;
	// An accessor
	cout << "four.abs(): " << four.abs() << endl;
	// Overloading with mixed types, using the conversion constructor
	cout << "10 + four: " << 10 + four << endl;
	cout << "four + 20: " << fmour + 20 << endl;
	cout << "four + 5.5: " << four + 5.5 << endl;

	return 0;

}
