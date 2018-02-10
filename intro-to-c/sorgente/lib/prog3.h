#ifndef SORGENTE_PROG3
#define SORGENTE_PROG3

#include <stdio.h>

#define PI 3.141592

int prog3() {
  double radius, length, squareArea, squarePerimeter, circleArea, circleCir;
  
  printf("Hello!\n\n");

  printf("Radius? ");
  scanf(" %lf", &radius);
  
  circleArea = PI * radius * radius;
  printf("Circle area: %0.3lf\n", circleArea);

  circleCir = 2 * PI * radius;
  printf("Circle circumference: %0.3lf\n\n", circleCir);

  printf("Length of a square? ");
  scanf(" %lf", &length);

  squareArea = length * length;
  printf("Square area: %0.3lf\n", squareArea);

  squarePerimeter = length * 4;
  printf("Square perimeter: %0.3lf\n", squarePerimeter);

  return 0;
}

#endif // !SORGENTE_PROG2
