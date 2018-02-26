#ifndef SORGENTE_GUESSING
#define SORGENTE_GUESSING

//HEADER
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
//FUNCTION PROTOTYPE AREA
void DisplayInstructions();
int GetNumberOfGames();
char GetLetter(FILE * filepointer);
int SingleGame(char c);
int WinLose(int r);

//MAIN SECTION
int guessing()
{
	DisplayInstructions();

	//open file
	FILE * filepointer = fopen("data/lettersin.txt", "r");

    if (filepointer != NULL) {
      //get number of games
      int playgames = GetNumberOfGames();
      for (int i = 0; i < playgames; i++)
      {
        //get a letter from ffile
        char letter = GetLetter(filepointer);

        //play one game
        int result = SingleGame(letter);

        //check for win or lose
        WinLose(result);

      }
    }
	//close file
    fclose(filepointer);


	return 0;
}

void DisplayInstructions() {
  printf("Hello! Welcome to the guessing game based on the letters in a textfile!\n\n");
}

int GetNumberOfGames() {
  int games = 0;
  printf("How many games would you like to play? ");
  scanf(" %d", &games);
  while (games < 0) {
    printf("Something went wrong. How many games would you like to play? ");
    scanf(" %d", &games);
  }
  return games;
}

char GetLetter(FILE * filepointer)
{
  char c;
  fscanf(filepointer, " %c", &c);
  return c;
}

int SingleGame(char answer)
{
  char guess;
  printf("Guess a letter? ");
  scanf(" %c", &guess);
  if (guess != answer) {
    return 0;
  }
  else {
    return 1;
  }
}

int WinLose(int r)
{
  if (r == 1) {
    printf("You guessed correctly!\n");
  } else {
    printf("Better luck next time...\n");
  }
  return 0;
}

#endif