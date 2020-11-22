#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]){

  //Error-checking
  if (argc != 4){
    fprintf(stderr, "Error: this program accepts only 3 arguments\n");
    return 1;
  }
  //Error checking

  char* inputFile = argv[1];
  FILE* fpInput = fopen(inputFile, "r");

  //Error checking
  if (fpInput == NULL) {
    fprintf(stderr, "Error message from strerror: %s\n", strerror(errno));
    printf("----------\n");
    return 2;
  }

  char* outputFile = argv[2];

  FILE* fpOutput = fopen(outputFile, "w");

  //Error checking
  if (fpOutput == NULL) {
    fprintf(stderr, "Error message from strerror: %s\n", strerror(errno));
    printf("----------\n");
    return 3;
  }
 
  char** tail;
  int maxLength = strtol(argv[3],tail,10);

  //Error checking
  int i=0;
  while (argv[3][i] != '\0') {
    if (argv[3][i] == '-') {
      fprintf(stderr,"Error: line length must be positive\n");
      return 4;
    }
    if (argv[3][i] < '0' || argv[3][i] > '9') {
      fprintf(stderr,"Error: line length must be a number\n");
      return 4;
    }
    i++;
  }
  //Error checking

  //testing
  printf("inputfile: %s, outputfile: %s, maxlength: %d\n", inputFile, outputFile, maxLength);
  
  int count = 0; //this is the count of how many characters were printed in this particular line
  int done = 0;
  int success = 0;
  while(!done){
    int c = getc(fpInput);
    if (c != EOF){
      if (count != maxLength && c!='\n'){ //if the line hasn't already reached the character limit and c is not the newline character
	success = putc(c, fpOutput);
	count++;
      }
      else if (c == '\n'){
	success = putc('\n',fpOutput);
	count = 0; //restarts the character count after printing a newline character
      }
    }
    if (success ==EOF) {
	fprintf(stderr,"There was an error writing output");
	return 5;
    }
    if (c == EOF) {
	if (errno != 0) {
	  fprintf(stderr,"There was an error reading input");
	  return 5;
	}
      done = 1;
    }
  }
  fclose(fpInput);
  fclose(fpOutput);
  return 0;
}
