/*
 * This is the equivalent program to that in the TestBadShapes.cpp file.  However, this
 * code is much nicer because it is able to use polymorphism with the Shape hierarchy.
 * You will also notice that the Shape constructors now contain the colours and text,
 * where applicable.
 *
 * This program will produce the same output as shown in the TestBadShapes.cpp file.
 *
 * for CISC/CMPE 320 by Prof. Alan McLeod
 */
#include <iostream>
#include <string>
#include <vector>

#include "ShapesGood.h"

using namespace std;

int main() {

	int count(0);
	vector<Shape*> shapes;
	shapes.push_back(new Square(10, 10, "orange"));
	shapes.push_back(new FilledSquare(10, 10, "purple", "red"));
	shapes.push_back(new FilledTextSquare(10, 10, "green", "gray", "Hello"));
	shapes.push_back(new Circle(10, 10, "blue"));
	shapes.push_back(new FilledCircle(10, 10, "yellow", "green"));
	shapes.push_back(new Arc(10, 10, "puce"));

	// Isn't this much nicer!
	for (Shape* shp : shapes) {
		cout << "\nShape " << count++ << ":";
		shp->draw();
	} // end for

	//works
	for (Shape* shp : shapes) {
		delete shp;
	}

} // end main
