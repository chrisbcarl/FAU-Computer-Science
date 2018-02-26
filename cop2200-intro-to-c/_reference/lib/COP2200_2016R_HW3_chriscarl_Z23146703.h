/*******************************************************************************

NAME: Christopher Carl
Z#: Z23146703
COURSE: Intro to C (COP 2200)
PROFESSOR: Dr. Feng-Hao Liu
DUE DATE: 16.07.16
DUE TIME: 23:59
TOTAL POINTS: 100
ASSIGNMENT 3: hw3.cpp

DESCRIPTION:
Homework 3

In this assignment, you are going to turn in a single cpp file. Your goal is to 
determine the final grade given certain threshold values and the score. For 
example, here is an example for threshold values: 90 up for A, 80 - below 90 
for B, 70 - below 80 for C, and below 70 for F. Here we can think of 90, 80, 
70 as the threshold values. Under these values, if your grade is 86, then your 
final grade is B.
In this assignment, we consider the case where there are only 4 possible grades:
A, B, C, and F, so we need 3 integers to specify the threshold. Next we describe 
your tasks:
• Task 1: write a function to determine whether the input threshold values are 
valid. The function takes inputs 3 integers a, b, c and returns a boolean value 
(true/false). In particular, it checks whether 100 > a > b > c > 0. If the 
condition is true, then return true. Otherwise, return false.
• Task 2: write a function that takes input a threshold and a score, and then 
returns the grade. (Think about what output data type you should use). In 
particular, the function takes inputs 4 integers a, b, c and g. The first three 
numbers represent the threshold, and the last represents the score. Then the 
function first checks whether the input threshold values are valid. If not, 
return a character ’N’; if valid, then return the final grade.
• Task 3: Inside the main function, you print “Enter the values of threshold 
for A,B,C, and F” on the first line, and then the user inputs 3 integers. Then 
print “What is your grade?” on the next line, followed by a user input (for an 
integers). On the next line, print either “The threshold is not valid.” or 
“Your final grade is X.”, where X depends on the threshold and your grade.
Task 2 should use Task 1 (do not re-write codes!)

LOG:
16.07.13, 17:30 - start
16.07.13, 18:02- logic completed, 1st compile
16.07.13, 18:11 - 2nd compile, fixed bugs
16.07.13, 18:15 - formatting for readability/80char rule
16.07.13, 18:16 - documentation added
16.07.13, 18:18 - 3rd compile, fully tested


BUG:	FOUND:			FIXED:			DESCIRPTION:
B0001	16.07.13,18:02	-				annother new line problem where scanf 
										gets confused
						16.07.13,18:11	fixing has to be done on a case by case
										basis.
*******************************************************************************/


//used to supress Microsoft compiler errors for using scanf
//they insist on using scanf_s which requires buffer sizes
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

/*
Name:  task1
Precondition:		VARS all initialized in higher function

VARS:				int a, 
					int b, 
					int c

Postcondition:		VARS all unmodified
					return boolean
Description:		determines if 100 > a > b > c > 0. Returns
					true if true, returns false if false.
*/
bool task1(int a, int b, int c)
{
	if ((100 > a) && (a > b) && (b > c) && (c > 0)) return true;
	else return false;
}


/*
Name:  task2
Precondition:		VARS all initialized in higher function

VARS:				int a,
					int b,
					int c,
					int g

Postcondition:		VARS all unmodified
return boolean
Description:		Returns a character corresponding to the
					input thresholds. If the grade is invalid
					or the threshold is invalid, the returned
					grade is 'N'.
*/
const char task2(int a, int b, int c, int g)
{
	if (task1(a, b, c))
	{
		if (g > 100) return 'N';
		else if (g > a) return 'A';
		else if (g > b) return 'B';
		else if (g > c) return 'C';
		else if (g < g) return 'F';
		else if (g < g) return 'N';
	}
	return 'N';
}


int main(int argc, const char * argv[])
{
	char user_selection = '0';
	char user_response = 'n';

	int thresh1, thresh2, thresh3, grade;

	do
	{
		printf("Enter the values of threshold for A, B, C: ");
		scanf("%d", &thresh1); scanf("%d", &thresh2); scanf("%d", &thresh3);
		printf("What is your grade? ");
		scanf("%d", &grade);

		/*
		OPTIONAL CONTROL FLOW (replaces if/else structure):

		while (!task1(thresh1, thresh2, thresh3))
		{
		printf("The threshold is not valid.\n");
		printf("Enter the values of threshold for A, B, C: ");
		scanf("%d", &thresh1); scanf("%d", &thresh2); scanf("%d", &thresh3);
		};
		*/
		if (!task1(thresh1, thresh2, thresh3))
		{
			printf("The threshold is not valid.\n");
		}
		else
		{
			printf("Your final grade is %c.\n", task2(thresh1, thresh2, thresh3, grade));
		} 

		printf("\n\n");
		printf("Would you like to repeat? (Y or N): ");
		scanf("\n%c", &user_response);
		printf("\n\n");

	} while (user_response == 'y' || user_response == 'Y');

	return 0;
}

