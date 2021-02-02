#pragma once

#include <string>
using namespace std;

class Shape {
public:
	Shape();
	Shape(int&, int&, string&);
	virtual ~Shape(); //each class has own destructor?
	int getLength() const;
	int getWidth() const;
	string getColour() const;

	virtual void draw()const;

private:
	int length, width;
	string colour;
};

class FilledShape {
public:
	FilledShape(string&);
	string getFill() const;
	virtual ~FilledShape();
private:
	string fillCol;
};

class FilledTextShape {
public:
	FilledTextShape(string&);
	string getText() const;
	virtual ~FilledTextShape();
private:
	string text;
};

class Square : public Shape {
public:
	Square(int, int, string);
	~Square();
	void draw() const {cout << "\nDrawing a " +getColour()+" square\n" <<endl;}; //output in class by itself?
};

class FilledSquare : public Square, public FilledShape {
public:
	FilledSquare(int,int,string,string);
	~FilledSquare();
	void draw() const {cout << "\nDrawing a " +getColour()+" square. With " + getFill() + " fill\n";};
};

class FilledTextSquare : public FilledSquare, public FilledTextShape {
public:
	FilledTextSquare(int,int,string,string,string);
	~FilledTextSquare();
	void draw() const {cout << "\nDrawing a " +getColour()+" square. With " + getFill() + " fill. Containing the text: " + getText() + "\n";};
};

class Circle : public Shape {
public:
	Circle(int, int, string);
	~Circle();
	void draw() const {cout << "\nDrawing a " +getColour()+" circle\n" <<endl;}; //output in class by itself?
};

class FilledCircle : public Circle, public FilledShape {
public:
	FilledCircle(int,int,string,string);
	~FilledCircle();
	void draw() const {cout << "\nDrawing a " +getColour()+" circle. With " + getFill() + " fill\n";};
};

class Arc : public Shape {
public:
	Arc(int, int, string);
	~Arc();
	void draw() const {cout << "\nDrawing a " +getColour()+" arc\n" <<endl;}; //output in class by itself?
};
