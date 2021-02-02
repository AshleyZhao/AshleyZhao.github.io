#include <iostream>
using namespace std;

#include "myComplex.h"

int main() {

	MyComplex one;
	MyComplex two(2);
	MyComplex three(3.5);
	MyComplex four(3, 4);
	MyComplex five(4.0, 5.0);

	cout << "one: " << one << endl;
	cout << "two: " << two << endl;
	cout << "three: " << three << endl;
	cout << "four: " << four << endl;
	cout << "five: " << five << endl;

	cout << "\nOperations:" << endl;
	cout << one + two << endl;
	cout << four + five << endl;
	cout << four.abs() << endl;
	cout << 10 + four << endl;
	cout << four + 20 << endl;

	// Tests for ++ and += operators
	cout << "\nNew operations:" << endl;
	MyComplex six(6, 6);
	MyComplex seven(7, 7);

	seven += six;
	cout << seven << endl;

	seven += 7;
	cout << seven << endl;

	MyComplex uno(1, 1);
	MyComplex duo(2, 2);
	cout << "\nPre-increment:" << endl;
	cout << uno + ++duo << endl;
	cout << duo << endl;
	MyComplex duoAgain(2, 2);
	cout << "\nPost-increment:" << endl;
	cout << uno + duoAgain++ << endl;
	cout << duoAgain << endl;

	return 0;

} // end main
