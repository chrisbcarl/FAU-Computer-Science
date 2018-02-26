#ifndef LETTERGUESS_SORGENTE
#define LETTERGUESS_SORGENTE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MIN_GUESSES 1
#define MAX_GUESSES 8
#define RANDOM_LETTER_FILE "letters.txt"

void seedLetters(char * filename, int letter_count);
int getGames();
char getLetter(FILE * filepointer);
int compareLetters(char a, char b);
void playGame();
int getRepeat();

void letterGuess() {
  seedLetters(RANDOM_LETTER_FILE, RAND_MAX);
}

void seedLetters(char * filename, int letter_count) {
  srand(time(NULL));   // should only be called once

  FILE * filepointer = fopen(filename, "w");
  if (!filepointer) {
    exit(EXIT_FAILURE);
  }
  else {
    int i, r;

    for (i = 0; i < letter_count; i++) {
      r = rand() % 24 + 0;      // returns a pseudo-random integer between 97 and 122
      fprintf(filepointer, "%c", r);
    }
  }
}

int getGames() {
  int games = 0;
  printf("How many games, 1-8? ");
  scanf(" %d", &games);
  while (0 < games && games < 9) {
    printf("Error in the number of games. How many games, 1-8? ");
    scanf(" %d", &games);
  }
  return games;
}

char getLetter(FILE * filepointer) {
  return 0;
}

int compareLetters(char a, char b) {
  return a == b;
}

void playGame() {
  int i, games = getGames();
  char guess, answer;
  FILE * filepointer = fopen(RANDOM_LETTER_FILE, 'o');
  for (i = 0; i < games; i++) {
    guess = getLetter(filepointer);
  }
}

int getRepeat() {
  return 0;
}

#endif // !LETTERGUESS_SORGENTE
