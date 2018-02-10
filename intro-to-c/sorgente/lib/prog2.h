#ifndef SORGENTE_PROG2
#define SORGENTE_PROG2

#include <stdio.h>
#include <ctype.h>

int prog2() {
  int number, sum;
  char letter, upper;

  printf("Hello my name is Chris!\n\n");

  printf("Ask the user for a number: ");
  scanf(" %d", &number);

  sum = number + 435;
  printf("original number: %d, sum: %d\n", number, sum);

  printf("Ask the user for a letter: ");
  scanf(" %c", &letter);

  upper = toupper(letter);
  printf("original letter: %c, uppercase: %c\n", letter, upper);

  printf("Have a nice day!\n");

  return 0;
}

#endif // !SORGENTE_PROG2
