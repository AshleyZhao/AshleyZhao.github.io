#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

//Catcher code start//////////////////////////////////////////////////////////////////////////////////////
#define outputFile //for deleting the outputfile in 1
#define lineCount 0 //for keeping track of line count in 3
#define MAX_INT 2 //for 4
int signalCount=0; //for 4

void catchINT(int signo){
  signalCount++;
  remove (outputFile);
  printf("exiting early after deleting outputfile \n");

  signal(SIGINT, SIG_DFL);
  exit(0);
}

void catchUSR1(int signo){
  
  if (signalCount>MAX_INT){
  printf("signals received exceeds two, signal ignored");
  }
  else{
  signalcount++;
  printf("name of input file is: %s\n", inputFile);
  signal(SIGUSR1,catchUSR1);
  }

}

void catchUSR2(int signo){
  if (signalCount>MAX_INT){
  printf("signals received exceeds two, signal ignored");
  }
  else{  
  signalCount++;
  printf("The number of lines read so far is: %d\n",lineCount);
  signal(SIGUSR2,catchUSR2);
  }
}
//Catcher code end//////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]){
  char* inputFile = argv[1];
  FILE* fpInput = fopen(inputFile, "r");
  char* outputFile = argv[2];
  FILE* fpOutput = fopen(outputFile, "w");
  char** tail;
  int maxLength = strtol(argv[3],tail,10);
  //testing
  printf("inputfile: %s, outputfile: %s, maxlength: %d\n", inputFile, outputFile, maxLength);
  
  //Catcher code start
  signal(SIGINT,catchINT);
  signal(SIGUSR1,catchUSR1);
  signal(SIGUSR2,catchUSR1);
  //Catcher code end 


  int lineCount = 0; //this is the count of how many characters were printed in this particular line
  int done = 0;
  while(!done){
    int c = getc(fpInput);
    if (c != EOF){
      if (lineCount != maxLength && c!='\n'){ //if the line hasn't already reached the character limit and c is not the newline character
	putc(c,fpOutput);
	lineCount++;
      }
      else if (c == '\n'){
	putc('\n',fpOutput);
	lineCount = 0; //restarts the character count after printing a newline character
      }
    }
    if (c == EOF) {
      done = 1;
    }
  }
  fclose(fpInput);
  fclose(fpOutput);


  //temporary code for testing, delete before submission!
  for (;;) {
    printf("signal4 program is running....\n");
    sleep(1);
  } /* end for */
  printf("signal4 program is done\n");
  //temporary code end
  

  return 0;
}


