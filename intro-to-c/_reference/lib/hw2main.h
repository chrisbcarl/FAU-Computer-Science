/*
********************************************************************************

NAME: Christopher Carl
Z#: Z23146703
COURSE: Intro to C (COP2200 - Summer 2016)
PROFESSOR: Dr. Feng-Hao Liu
DUE DATE: 16.07.08
DUE TIME: 23:59
TOTAL POINTS: 100
HOMEWORK 2

DESCRIPTION:
In this assignment, you are going to turn in a single cpp file. Your goal is
to (1) design a function that calculates distances between two points, and
(2) run the function to the following scenario.

We break down things into the following tasks:
	Task 1: write a function that takes inputs 4 integers x1; y1; x2; y2 and
returns a double. The function calculates the distance between the
points (x1; y1) and (x2; y2). In the following, you are going to
write codes in the main function. You need to produce the following
results.
Task 2: in the first line, print "Enter two integers as the coordinates
for the first point", and then let the user input two integers.
Task 3: in the next line, print "Enter two integers as the coordinates
for the second point", and then let the user input two integers.
Task 4: in the next line, "Enter two integers as the coordinates for
the third point", and then let the user input two integers.
Task 5: in the next line, print
"The distance between Points 1 and 2 is: ",
followed by the distance (double).
Task 6: in the next line, print
"The distance between Points 1 and 3 is: ",
followed by the distance (double).
Task 7: in the next line, print
"The distance between Points 2 and 3 is: ",
followed by the distance (double).

To achieve the tasks 5,6,7, you must call the function in Task 1.
Also, pay attention to the input/output data types specied in Task 1.

LOG:
16.07.07, 02:30 - start
16.07.07, 02:45 - logic completed, 1st compile
16.07.07, 03:11 - 4th compile, control flow works as intended
16.07.07, 03:16 - formatting for readability/80char rule
16.07.07, 03:20 - documentation added



BUG:	FOUND:			FIXED:			DESCIRPTION:
********************************************************************************
B001	16.07.07,02:45	-				For some reason the program skips
prompting the user for whether they want
to repeat
16.07.07,03:11	scanf("%c", &var) is tricky. Basically
all of the scanf's above were ignoring
whitespace because they were looking for
%lf stuff, but when it gets to the
%c, \n counts as a single character,
so it was reading that first and counted
it, but it wasn't a 'y' or 'Y',
so it exited. SOL: scanf("\n%c", &var)

*/

/*
RESPONSE:

*/

//used to supress Microsoft compiler errors for using scanf
//they insist on using scanf_s which requires buffer sizes
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2);

int main(int argc, const char * argv[]) {

  //part of a ui control flow that allows the user to repeat the program
  char user_response = 'y';

  do
  {
    //declare all vars at once
    double x1, y1, x2, y2, x3, y3;

    //user is prompted for input
    //C++ uses cout, C uses printf
    printf("Enter two integers as the coordinates for the first point.\n");
    //user input begins
    //C++ uses cin, C uses scanf
    scanf("%lf", &x1); scanf("%lf", &y1);
    printf("Enter two integers as the coordinates for the second point.\n");
    scanf("%lf", &x2); scanf("%lf", &y2);
    printf("Enter two integers as the coordinates for the third point.\n");
    scanf("%lf", &x3); scanf("%lf", &y3);

    //user is displayed the calculations which take place within the print
    printf("The distance between Points 1 and 2 is: %lf\n",
      distance(x1, y1, x2, y2));
    printf("The distance between Points 1 and 3 is: %lf\n",
      distance(x1, y1, x3, y3));
    printf("The distance between Points 2 and 3 is: %lf\n",
      distance(x2, y2, x3, y3));

    //ui control flow starts here
    printf("\n\n");
    printf("Would you like to do another calculation? (Y or N): ");
    scanf("\n%c", &user_response);
    printf("\n\n");

  } while (user_response == 'y' || user_response == 'Y');

  return 0;
}

//distance function returns a double, no need for abs(), since a square 
//will always be positive
double distance(double x1, double y1, double x2, double y2)
{
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}