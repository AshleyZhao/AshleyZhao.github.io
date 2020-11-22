#pragma once
#include <string>
using namespace std;

#ifndef jumble_13eio_H
#define jumble_13eio_H

typedef char* charArrayPtr;

class BadJumbleException {
	string message;
public:
	BadJumbleException(const string& message);
	string& what();
};


class JumblePuzzle {
	charArrayPtr* jumble; //Jumble array stored on the heap
	string toHide; //Storing users word that is to be hidden
	string difficulty; //the difficulty
	int size; //Size of the jumble puzzle based on word * difficulty
	int rowPos; //Row start position of the word
	int colPos; //Column start position of the word
	char direction; //Direction the word is written in
	void generateRandomPuzzle(); //helper function to create a random jumble puzzle

public:
	JumblePuzzle(const string& toHide, const string& difficulty); //default constructor
	JumblePuzzle(const JumblePuzzle&); //Copy constructor
	~JumblePuzzle(); //Destructor
	JumblePuzzle& operator=(const JumblePuzzle& right); //Assignment operator


	//Getters
	charArrayPtr* getJumble(); //Get Jumble
	const int getSize();
	const int getRowPos();
	const int getColPos();
	const char getDirection();


};

//testJumble.cpp
void showJumble(const charArrayPtr* jumble, const int size);
void playGame();
void testJumble();

#endif
