#pragma once

#include <string>

using namespace std;


#ifndef JUMBLE_H_
#define JUMBLE_H_

typedef char* charArrayPtr; //defines the pointer to pointers (char **) required to store on heap

//Jumble puzzle class
class JumblePuzzle {
	charArrayPtr* jp; //Jumble array stored on heap using pointers (char**)

	//user input
	string toHide; //Takes word user inputs 'to hide' in puzzle
	string difficulty; //Takes easy medium, hard

	//attributes
	int size; //Puzzle size
	int indexX; //x (row) coordinate of word
	int indexY; //y (column) coordinate of word
	char direction; //Direction to write word

	//generates random puzzle
	void generatePuzzle();

public:
	// ====================================================
	//Constructors as assignment required
	// ====================================================
	JumblePuzzle(const string& toHide, const string& difficulty); //constructor
	JumblePuzzle(const JumblePuzzle&); //copy constructor
	~JumblePuzzle(); //destructor
	JumblePuzzle& operator=(const JumblePuzzle& right); //assignment overloading

	// ====================================================
	//Accessors of puzzle, size, row, column and direction
	// ====================================================
	charArrayPtr* getJumble();
	const int getSize();
	const int getRowPos();
	const int getColPos();
	const char getDirection();

};


// Bad jumble exception
class BadJumbleException {
	string message;
public:
	BadJumbleException(const string& message);
	string& what();
};

#endif /* JUMBLE_H_ */
