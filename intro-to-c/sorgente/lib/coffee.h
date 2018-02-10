#ifndef SORGENTE_COFFEE
#define SORGENTE_COFFEE

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int coffee() {
  double cup1, cup2, cup3;
  double sum = 0;
  double avg = 0;

  printf("Average coffee cup thingy.\n");
  printf("\tAmount of coffee in first coffee cup: ");
  scanf(" %lf", cup1);

  printf("\tAmount of coffee in second coffee cup: ");
  scanf(" %lf", &cup2);


  printf("\tAmount of coffee in third coffee cup: ");
  scanf(" %lf", &cup3);

  sum = cup1 + cup2 + cup3;
  //avg = sum / 3;

  printf("\nAverage of the three cups: %lf\n\n", sum);

  return 0;
}

#endif // !SORGENTE_COFFEE
