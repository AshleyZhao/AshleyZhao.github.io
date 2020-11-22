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
	cout << one + two << endl;
	cout << four + five << endl;
	cout << four.abs() << endl;
// Are the results correct?
	cout << 10 + four << endl;
	cout << four + 20 << endl;
	cout << four + 20.0 << endl;

	return 0;

}
