
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <ctime>
#include "Jumble.h"

using namespace std;



//Bad Jumble Exception
BadJumbleException::BadJumbleException(const string & message) :message(message) {}
string & BadJumbleException::what() { return message; }


void JumblePuzzle::generateRandomPuzzle()
{
	bool complete = true; //Bool variable to be used for placing target word
	int randSize = this->size - 1; //Random number for the range of where to put the word.

	string directions = "news";    //North East West South
	string alphabet = "abcdefghijklmnopqrstuvwxyz"; //Alphabet

	srand(time(NULL));

	int direction = rand() % 3;  //Random number between 0 and 3 ...indexes for the directions string
	char move = directions[direction]; //pick a random direction

	//Pick a random start row and start column
	int row = rand() % randSize;
	int column = rand() % randSize;

	//Set private column and row attributes
	this->rowPos = row;
	this->colPos = column;

	//Create new charArrayPtr*
	charArrayPtr* jumbl = new charArrayPtr[this->size];
	for (int i = 0; i < this->size; i++) {
		jumbl[i] = new char[this->size + 1]; //Set each array in the charArrayPtr* to size+1 to compensate for the final NULL value
	}

	//Set each value to the null char
	for (int i = 0; i < this->size; i++) {
		for (int x = 0; x < this->size; x++) {
			jumbl[i][x] = (char)0;
		}
		jumbl[i][this->size] = '\0';
	}

	//Length of the hidden word
	int hiddenWordLength = this->toHide.size();

	//Placing the characters for the target word;
	//This algorithm works by placing the characters from the starting position and starting to place in a certain direction
	//if the next index is out of bounds then choose a different direction and break from the for loop.
	//else if all the words are placed then set the complete variable to false so the while loop terminates.
	while (complete) { //While true

		int y = row; //start row
		int x = column;// start column

		switch (move) { //recall: move was the direction you are placing the words
		case 'n':
			//Try to place all the characters in the upper direction
			for (int j = 0; j < hiddenWordLength ; j++) {
				if (y - j < 0) {                        //If y - j is out of bounds
					move = directions[rand() % 3];      //Pick a new random direction
					break; //Exit for loop
				}
				else
					jumbl[y - j][x] = this->toHide[j];  //Add current char to position
				if (j == hiddenWordLength - 1)          //If able to add all characters
					complete = !complete;               //Set complete to false in order to terminate loop
			}
			break;
		case 'e':
			for (int j = 0; j < hiddenWordLength ; j++) {
				if (x + j >= this->size) {
					move = directions[rand() % 3];
					break;
				}
				else
					jumbl[y][x + j] = this->toHide[j];
				if (j == hiddenWordLength - 1)
					complete = !complete;

			}
			break;
		case 'w':
			for (int j = 0; j < hiddenWordLength ; j++) {
				if (x - j < 0) {
					move = directions[rand() % 3];
					break;
				}
				else
					jumbl[y][x - j] = this->toHide[j];
				if (j == hiddenWordLength - 1)
					complete = !complete;
			}
			break;
		case 's':
			for (int j = 0; j < hiddenWordLength ; j++) {
				if (y + j >= this->size) {
					move = directions[rand() % 3];
					break;
				}
				else
					jumbl[y + j][x] = this->toHide[j];
				if (j == hiddenWordLength - 1)
					complete = !complete;
			}
			break;
		}
	}

	//set direction private attribute
	this->direction = move;

	//fill up array with random letters from the indexes that have null values
	for (int y = 0; y < this->size; y++) {
		for (int x = 0; x < this->size; x++) {
			if (jumbl[y][x] == (char)0)
				jumbl[y][x] = alphabet[rand() % 25];
		}
	}

	//set jumble private attribute
	this->jumble = jumbl;
}

JumblePuzzle::JumblePuzzle(const string & toHide, const string & difficulty):toHide(toHide)
{
	int size = toHide.size(); //size of word
	if (size < 3 || size > 10)
		throw BadJumbleException("Size of the word to hide must be between 3 and 10!"); //Size of word must be between 3 and 10

	if (difficulty != "easy" && difficulty != "medium" && difficulty != "hard")
		throw BadJumbleException("This is not a valid difficulty!must choose from difficulties : \"easy\", \"medium\" or \"hard\" ");
	else
		this->difficulty = difficulty; //set difficulty

	//Pick size
	if (this->difficulty == "easy") {
		this->size = 2 * size;
	}
	else if (this->difficulty == "medium") {
		this->size = 3 * size;
	}
	else if (this->difficulty == "hard") {
		this->size = 4 * size;
	}

	//generateRandomPuzzle!
	generateRandomPuzzle();

}

JumblePuzzle::JumblePuzzle(const JumblePuzzle & right)
{
	this->toHide = right.toHide;
	this->difficulty = right.difficulty;
	this->size = right.size;
	this->rowPos = right.rowPos;
	this->colPos = right.colPos;
	this->direction = right.direction;
	charArrayPtr* newJumble = new charArrayPtr[this->size];
	for (int j = 0; j < this->size; j++) {
		newJumble[j] = new char[this->size + 1];
	}
	for (int y = 0; y < this->size; y++) {
		for (int x = 0; x < this->size + 1; x++) {
			newJumble[y][x] = right.jumble[y][x];
		}
	}
	this->jumble = newJumble;
}

JumblePuzzle::~JumblePuzzle()
{
	for (int y = 0; y < this->size; y++) {
		delete jumble[y];
		jumble[y] = nullptr; //Destroy each pointer in the outer array
	}
	delete jumble;
	jumble = nullptr;
}

JumblePuzzle & JumblePuzzle::operator=(const JumblePuzzle & right)
{
	if (this != &right) {
		for (int y = 0; y < this->size; y++) {
			delete this->jumble[y];
			this->jumble[y] = nullptr;
		}
		delete this->jumble;
		jumble = nullptr;

		this->toHide = right.toHide;
		this->difficulty = right.difficulty;
		this->size = right.size;
		this->rowPos = right.rowPos;
		this->colPos = right.colPos;
		this->direction = right.direction;

		jumble = new charArrayPtr[right.size];
		for (int j = 0; j < right.size; j++)
			jumble[j] = new char[right.size + 1];
		for (int y = 0; y < this->size; y++) {
			for (int x = 0; x < this->size + 1; x++) {
				jumble[y][x] = right.jumble[y][x];
			}
		}
	}
	return *this;
}

//GETTERS

charArrayPtr * JumblePuzzle::getJumble()
{
	return this->jumble;
}

const int JumblePuzzle::getSize()
{
	return this->size;
}

const int JumblePuzzle::getRowPos()
{
	return this->rowPos;
}

const int JumblePuzzle::getColPos()
{
	return this->colPos;
}

const char JumblePuzzle::getDirection()
{
	return this->direction;
}
