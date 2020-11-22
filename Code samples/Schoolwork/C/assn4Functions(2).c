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

 char splitString(char String[], int *numWords) {
  
  //This finds the size of the string array
  int size=findSize(String);

  //This instantiates the array based on the size of string
  char *wordsArr = malloc((countSpaces(String)+2)*size*sizeof(char));
  char wordArr[countSpaces(String)+1];  

  //This instantiates counter variables
  int i;
  int j=0;
  int k=0;
  
  //This finds each word of the array
  for (i=0; i<size; i++){
    if (String[i] != ' ') {
        //put assignment of wordArr[k] here
	j++;
    }
    else {
      j=0;
      k++;
    }
  }
return 'p';
}


//This is an optional helper function that finds the total size of the array containing string.
int findSize(char String[]) {
  int i=0;
  int size;
  while (String[i] != '\0') {
    i++;
  }
  size=i;
  return size;
}
