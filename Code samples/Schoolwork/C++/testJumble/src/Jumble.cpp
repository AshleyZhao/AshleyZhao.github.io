
#include "Jumble.h"

#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <ctime>
#include "Jumble.h"

using namespace std;

//==========
//Accessors
//==========
//gets the actual puzzle
charArrayPtr * JumblePuzzle::getJumble(){ return this->jp; }

//gets the size attribute
const int JumblePuzzle::getSize(){return this->size;}

//gets the x coordinate of the word
const int JumblePuzzle::getRowPos() {return this->indexX;}
//gets the y coordinate of the word
const int JumblePuzzle::getColPos() {return this->indexY;}

//gets the direction of the word
const char JumblePuzzle::getDirection(){return this->direction;}


//Bad jumble exception
BadJumbleException::BadJumbleException(const string & message) :message(message) {}
string & BadJumbleException::what() { return message; }

void JumblePuzzle::generatePuzzle()
{

	int puzzleSize = this->size; //make a constant for storing the size attribute

	//=======================================
	// Creates random direction and position
	//=======================================

	char dir;

	int randDir = rand() % 3;

	if (randDir == 0) { dir = 'n'; }
	else if (randDir == 1) { dir = 'e'; }
	else if (randDir == 2) { dir = 'w'; }
	else if (randDir == 3) { dir = 's'; }

	int row = rand() % (puzzleSize -1); //generate row position 0-(size of puzzle -1)
	int column = rand() % (puzzleSize -1); //generate column position 0-(size of puzzle -1)

	//Set the row and column attributes
	this->indexX = row;
	this->indexY = column;

	//Initializes puzzle
	charArrayPtr* jumbleThis = new charArrayPtr[puzzleSize];
	for (int i = 0; i < puzzleSize; i++) {
		jumbleThis[i] = new char[puzzleSize + 1];
	}

	for (int i = 0; i < puzzleSize; i++) {
		for (int j = 0; j < puzzleSize; j++) {
			jumbleThis[i][j] = (char)0;
		}
		jumbleThis[i][puzzleSize] = '\0';
	}

	//word size and boolean switch to use in loop
	int wordSize = this->toHide.size();
	bool done = true;

	while (done) {
		bool outOfBounds = false;

		if (dir == 'n') {

			//This first loop checks if the word is out of bounds.
			//If yes, it breaks out of the loop and sets outOfBounds to true.
			//If outOfBounds is true, process restarts.
			//If not, then the loop is repeated, adding the word in for real, and sets
			//the while loop checker to false.
			//This ensures that a single word is inserted into the array only when
			//it is valid to do so.
			for (int i = 0; i < wordSize; i++) {
				if (row - i < 0) {
					//If row is out of bounds, picks new dir
					int randDir = rand() % 3;
					//cout << "Was north, now" << randDir << endl;

					if (randDir == 0) { dir = 'n'; }
					else if (randDir == 1) { dir = 'e'; }
					else if (randDir == 2) { dir = 'w'; }
					else if (randDir == 3) { dir = 's'; }
					outOfBounds = true;
					break;
				}
			}
			if (outOfBounds == false) {
				for (int i = 0; i < wordSize; i++) {
					jumbleThis[row - i][column] = this->toHide[i];  //Add current char to position
				}
				done = false;
			}
		}


		else if (dir == 'w') {
			for (int i = 0; i < wordSize; i++) {
				if (column - i < 0) {
					//If column is out of bounds, picks new dir
					int randDir = rand() % 3;
					//cout << "Was west, now" << randDir << endl;

					if (randDir == 0) { dir = 'n'; }
					else if (randDir == 1) { dir = 'e'; }
					else if (randDir == 2) { dir = 'w'; }
					else if (randDir == 3) { dir = 's'; }
					outOfBounds = true;
					break;
				}
			}
			if (outOfBounds == false) {
				for (int i = 0; i < wordSize; i++) {
					jumbleThis[row][column-i] = this->toHide[i]; //Add current char to position
				}
				done = false;
			}
		}
		else if (dir == 's') {
			for (int i = 0; i < wordSize; i++) {
				if (row + i >= puzzleSize) {
					//If column is out of bounds, picks new dir
					int randDir = rand() % 3;
					//cout << "Was south, now" << randDir << endl;

					if (randDir == 0) { dir = 'n'; }
					else if (randDir == 1) { dir = 'e'; }
					else if (randDir == 2) { dir = 'w'; }
					else if (randDir == 3) { dir = 's'; }
					outOfBounds = true;
					break;
				}
			}
			if (outOfBounds == false) {
				for (int i = 0; i < wordSize; i++) {
					jumbleThis[row+i][column] = this->toHide[i];
				}
				done = false;
			}
		}
		else if (dir == 'e') {
			for (int i = 0; i < wordSize; i++) {
				if (column + i >= puzzleSize) {
					//If column is out of bounds, picks new dir
					int randDir = rand() % 3;
					//cout << "Was east, now" << randDir << endl;

					if (randDir == 0) { dir = 'n'; }
					else if (randDir == 1) { dir = 'e'; }
					else if (randDir == 2) { dir = 'w'; }
					else if (randDir == 3) { dir = 's'; }
					outOfBounds = true;
					break;
				}
			else
				jumbleThis[row][column+i] = this->toHide[i];
			if (i == wordSize - 1)
				done = false;
			}
			if (outOfBounds == false) {
				for (int i = 0; i < wordSize; i++) {
					jumbleThis[row][column+i] = this->toHide[i];
				}
				done = false;
			}
		}
	}

	this->direction = dir;


	string alphabet = "abcdefghijklmnopqrstuvwxyz"; //Alphabet

	for (int i = 0; i < puzzleSize; i++) {
		for (int j = 0; j < puzzleSize; j++) {
			if (jumbleThis[i][j] == (char)0)
				jumbleThis[i][j] = alphabet[rand() % 25];
		}
	}

	//set jumble private attribute
	this->jp = jumbleThis;
}

//Gets the user input needed from testJumble.cpp
JumblePuzzle::JumblePuzzle(const string& toHide, const string& difficulty):toHide(toHide)
{
	int wordSize = toHide.size(); //gets size of word

	//Checks size of word
	if (wordSize < 3 || wordSize > 10)
		throw BadJumbleException("Please enter a string between 3-10 characters.");

	this->difficulty = difficulty; //sets difficulty

	//Generate int size of the puzzle
	if (this->difficulty == "easy") {
		this->size = 2 * wordSize;
	}
	else if (this->difficulty == "medium") {
		this->size = 3 * wordSize;
	}
	else if (this->difficulty == "hard") {
		this->size = 4 * wordSize;
	}
	else {
		throw BadJumbleException("Please enter either easy, medium, or hard with exact wording.");
	}

	generatePuzzle();

	srand(time(NULL));

}

JumblePuzzle::JumblePuzzle(const JumblePuzzle& jumble)
{
	this->toHide = jumble.toHide;
	this->difficulty = jumble.difficulty;
	this->size = jumble.size;
	this->indexX = jumble.indexX;
	this->indexY = jumble.indexY;
	this->direction = jumble.direction;

	int puzzleSize = this->size; //local variable for optimization

	charArrayPtr* newJumble = new charArrayPtr[puzzleSize];
	for (int i = 0; i < puzzleSize; i++) {
		newJumble[i] = new char[puzzleSize + 1];
	}
	for (int i = 0; i < puzzleSize; i++) {
		for (int j = 0; j < puzzleSize + 1; j++) {
			newJumble[i][j] = jumble.jp[i][j];
		}
	}

	this->jp = newJumble;
}

//destructor
JumblePuzzle::~JumblePuzzle()
{
	int puzzleSize = this->size;
	for (int i = 0; i < puzzleSize; i++) {
		delete jp[i];
		jp[i] = nullptr;
	}
	delete jp;
	jp = nullptr;
}

//assignment
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& jumble)
{
	if (this != &jumble) {
		int puzzleSize = this -> size;
		for (int i = 0; i < puzzleSize; i++) {
			delete this->jp[i];
			this->jp[i] = nullptr;
		}
		delete this->jp;
		jp = nullptr;

		this->toHide = jumble.toHide;
		this->difficulty = jumble.difficulty;
		this->size = jumble.size;
		this->indexX = jumble.indexX;
		this->indexY = jumble.indexY;
		this->direction = jumble.direction;

		jp = new charArrayPtr[jumble.size];
		for (int i = 0; i < jumble.size; i++)
			jp[i] = new char[jumble.size + 1];
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size + 1; j++) {
				jp[i][j] = jumble.jp[i][j];
			}
		}
	}
	return *this;
}


