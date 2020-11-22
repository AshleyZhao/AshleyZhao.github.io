//============================================================================
// Name        : ShapesGood.cpp
// Author      : 15jz4
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;
#include "ShapesGood.h"

//abstract class constructors
Shape::Shape() : length(0), width(0) {}
Shape::Shape(int &len, int &wid, string &col) : length(len), width(wid), colour(col) {}
FilledShape::FilledShape(string &fil) : fillCol(fil) {}
FilledTextShape::FilledTextShape(string &msg) : text(msg) {}

//destructors
Shape::~Shape() {}
FilledShape::~FilledShape() {}
FilledTextShape::~FilledTextShape() {}
Square::~Square() {}
FilledSquare::~FilledSquare() {}
FilledTextSquare::~FilledTextSquare() {}
Circle::~Circle() {}
FilledCircle::~FilledCircle() {}
Arc::~Arc() {}

//accessors
int Shape::getLength() const { return length; }
int Shape::getWidth() const { return width; }
string Shape::getColour() const { return colour; }
string FilledShape::getFill() const { return fillCol; }
string FilledTextShape::getText() const { return text; }

//draw method is inherited from base class
void Shape::draw() const {};

//Initialize simple shapes inherited from base (Shape) class
Square::Square(int len, int wid, string col) : Shape(len, wid, col) {};
Circle::Circle(int len, int wid, string col) : Shape(len, wid, col) {};
Arc::Arc(int len, int wid, string col) : Shape(len, wid, col) {};

//Initialize intermediate shapes inherited fron intermediate (FilledShape) class
FilledSquare::FilledSquare(int len, int wid, string col, string fil) : Square(len, wid, col), FilledShape(fil) {};
FilledCircle::FilledCircle(int len, int wid, string col, string fil) : Circle(len, wid, col), FilledShape(fil) {};

//Initialize complex shapes inherited fron derived (FilledTextShape) class
FilledTextSquare::FilledTextSquare(int len, int wid, string col, string fil, string msg) : FilledSquare(len, wid, col, fil), FilledTextShape(msg) {};
