#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int NUMSIGNALS = 0;
char* OUTPUT; //global variable in which to store name of output file for SIGINT to delete and for catchUSR1 to print
char* INPUT; //global variable in which to store name of input file for catchUSR1 to print
int LINESREAD = 0; //global variable in which to store lines read for catchUSR2

void catchINT(int signo){
  printf("Program is exiting early.\n");
  remove (OUTPUT);
  signal(SIGINT, catchINT);
  exit(1);
}

void catchUSR1(int signo){
  if (NUMSIGNALS < 2){
    printf("Input file is %s.\n", INPUT);
    printf("Output file is %s.\n", OUTPUT);
    NUMSIGNALS++;
  }
  signal(SIGUSR1, catchUSR1);
}

void catchUSR2(int signo){
  if (NUMSIGNALS < 2){
    printf("Number of lines read: %d\n", LINESREAD);
    NUMSIGNALS++;
  }
  signal(SIGUSR2, catchUSR2);
}

int main(int argc, char* argv[]){
  signal(SIGINT, catchINT);
  signal(SIGUSR1, catchUSR1);
  signal(SIGUSR2, catchUSR2);

  if(argc!=4){
    fprintf(stderr, "Incorrect number of arguments. Usage: shortLines inputFile outputFile maxLength\n");
    exit(1);
  }

  char* inputFile = argv[1];
  INPUT = inputFile;
  FILE* fpInput = fopen(inputFile, "r");
  if (fpInput == NULL){
    perror("There was an error with the input file");
    exit(1);
  }
  char* outputFile = argv[2];
  OUTPUT = outputFile; //set global variable OUTPUT to outputFile so it can be used in signal catcher
  FILE* fpOutput = fopen(outputFile, "w");
  if (fpOutput == NULL){
    perror("There was an errror with the output file");
    exit(1);
  }

  char* tail;
  int maxLength = strtol(argv[3],&tail,10);
  if (*tail != '\0'){
    fprintf(stderr, "Line length not in numerical format.\n");
    exit(1);
  }
  else if (maxLength <= 0){
    fprintf(stderr, "Line length is not greater than 0.\n");
    exit(1);
  }
  
  int count = 0; //this is the count of how many characters were printed in this particular line
  int done = 0; //0 if not done, 1 if done without error
  int success = 0; //used to check for writing output error, will be set to EOF if there is an error writing output
  while(!done){
    int c = getc(fpInput);
    if (c != EOF){
      if (count != maxLength && c!='\n'){ //if the line hasn't already reached the character limit and c is not the newline character
	success = putc(c,fpOutput);
	count++;
      }
      else if (c == '\n'){
	success = putc('\n',fpOutput);
	count = 0; //restarts the character count after printing a newline character
	LINESREAD++; //increments global variable with each newline character
      }
    }
    if (success == EOF){
      perror("There was an error writing output");
      exit(1);
    }
    if (c == EOF) {
      if (errno != 0){
	perror("There was an error reading input");
	exit(1);
      }
      done = 1;
    }
  }
  fclose(fpInput);
  fclose(fpOutput);

  return 0;
}
