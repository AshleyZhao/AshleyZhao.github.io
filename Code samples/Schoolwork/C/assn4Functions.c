#include <stdio.h>
#include <stdlib.h>

int main () {
  //countSpaces("  I am a cat  ");
}

int countSpaces (char strArr[]) {
  int space = 0;
  int i;
  while (strArr[i] != '\0') {
    if (strArr[i] == ' ') {
      space++;
    }
    i++;
  }
  return space;
}

char** splitString(char String[], int *numWords) {
  
  //This gets the number of words in a string
  int getSpace=countSpaces(String)+1;
  numWords = &getSpace;

  //This makes an array of pointers, each pointer will point to a word, AKA a char*
  char **wordsArr = malloc(numWords*sizeof(char*));

  //Here I started making an int array that holds the length of each word in the string, should end up looking somewhat like [3,4,5]
  int lengths[numWords];
  int i; //position of letter
  int wordNum = 0;
  int length=0;
  for(i=0;i<strlen(String);i++){
    while(String[i]!='\0'){
      if(String[i]!=' '){
	length++;
      }
      else {
	lengths[wordNum]=length;
	length=0;
      }
      i++;
    }
  }

  //Now for every pointer in **wordsArr, AKA **wordsArr[0], **wordsArr[1] etc., we need to assign enough space to it using malloc, so it contains
  //enough space for a word. Fetch the lengths from previous int array, and add 1 to each length because we need to account
  //for the null character. Then do something like **wordsArr[0] = malloc((lengths[0]+1)*sizeof(char)), except in a loop for all the words.

  //Now we need to make a copy of each letter from the original string and stick them in the different words. E.g. *wordsArr[0]=String[0], except in a loop
  //to make sure all words are in

  //yay! done! return **wordsArr ;A;
