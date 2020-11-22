/* Program prompts user for difficulty level of dive and 9 judge scores and computes total score

This program was submitted by:

Ashley Zhao - 10139334
Katie Yang - 10193698*/

#include <stdio.h>
#include <stdlib.h>

#define NUMJUDGES 9
#define MULTIPLIER 0.6

float genScore(float difficulty, float sortedScores[]){
  float middleScores=0;
  int i;
  for(i=2;i<NUMJUDGES-2;i++){ /*for everything other than the first two and last two elements in the array*/
    middleScores += sortedScores[i];
  }
  return difficulty*MULTIPLIER*middleScores;
}

void inputScores(float scores[]){
  int i;
  for (i=0; i<NUMJUDGES; i++){
    printf("enter score %d: ",i+1);
    scanf("%f",&scores[i]);
  }
}

/*Selection sort scores*/
void sortScores(float scores[]){
  int i;
  int j;
  float min;
  for(i=0;i<NUMJUDGES;i++){
    for(j=i+1;j<NUMJUDGES;j++){
      if(scores[j]<scores[i]){
	min = scores[j]; /* storing value of scores[j] to enable swap */
	scores[j]=scores[i];
	scores[i]=min;
      }
    }
  }
}

int main(){
  float scores[NUMJUDGES];
  float difficulty;
  printf("Degree of difficulty: ");
  scanf("%f",&difficulty);
  inputScores(scores);
  sortScores(scores);
  float totalScore = genScore(difficulty, scores);
  #ifdef DEBUG
  printf("low scores are %0.1f and %0.1f, high scores are %0.1f and %0.1f\n", scores[0], scores[1], scores[NUMJUDGES-1],scores[NUMJUDGES-2]);
  #endif
  printf("Score for this dive is: %0.1f\n", totalScore);
  return 0;  
}
