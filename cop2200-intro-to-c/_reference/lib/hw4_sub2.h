/*******************************************************************************

NAME: Christopher Carl
Z#: Z23146703
COURSE: Intro to C (COP 2200)
PROFESSOR: Dr. Feng-Hao Liu
DUE DATE: 16.07.05
DUE TIME: 23:59
TOTAL POINTS: 100
ASSIGNMENT 4: hw4.cpp

DESCRIPTION:
Homework 4

In this assignment, you are going to turn in a single cpp le. Your goal is to 
design a little number guessing game. The purpose is to practice while and if. 
There will be only one single task, and everything can be written inside the 
main function. 
Task 1: You dene an integer variable int x, and you assign x an arbitrary 
value you like. Then you are going to ask the user to guess what x is. We let 
the user guess up to 10 times.

Your program starts like this:
1. First the program prints \Guess the number:"
2. Then the user enters one number.
3. Then the program prints \This is attempt 1, and the user guesses XXX", 
	where XXX depends on the user's input.
4. Then the program prints one of the three depending on the situation: 
	(1)\Correct!", or (2) "The guess is too small", or 
	(3) \The guess is too large".
5. If the user guesses correctly, end the game. Otherwise, repeat from step 1. 
	Your program should print \This is attempt Y, and the user guesses ZZZ", 
	depending on how many times the user had tried before.
6. If the user fails 10 times, the program prints \Fail the game!", and terminates the game.


LOG:
16.06.21, 20:39 - start
16.06.21, 20:50 - logic completed, 1st compile with constant guess number
16.06.21, 21:19 - logic completed, ~4th compile
16.06.21, 21:31 - ~10th compile, looks better, better UI
16.06.21, 21:44 - ~15th compile, protected
16.06.21, 21:44 - formatting for readability/80char rule
16.06.21, 21:44 - documentation added
16.06.21, 21:44 - ~20th compile, added functionality


BUG:	FOUND:			FIXED:			DESCIRPTION:
B0001	16.06.21,21:07	-				attempts are not accumulating, 
										infinite loop
						16.06.21,21:10	forgot to increment. added accumulator.
B0002	16.06.21,21:15	-				not actually random. Always generating
										a 1 as the magic number.
						16.06.21,21:19	forgot to generate current time-based
										seed. duhhhhhhh
B0003	16.06.21,21:31	-				user can enter anything they please,
										that can definitely mess up the program
						16.06.21,21:42	protected against invalid numerical
										input, stream unprotected from char
										input.


*******************************************************************************/


//used to supress Microsoft compiler errors for using scanf
//they insist on using scanf_s which requires buffer sizes
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task1(void);
void printArray(int arr[], unsigned short int size, int sentinel);
void initializeArray(int arr[], unsigned short int size, int sentinel);


/*
Name:  task1
Precondition:		n/a
Parameters:			void
Return:				void
Postcondition:		n/a

Description:		Plays a simple guessing game that is self contained in the 
					function. The user has 10 attempts to guess a predetermined
					number and displays the previous attempts until the user
					has either succeeded or timed out the attempts.
*/
void task1(void)
{
	const unsigned short int HIGH = 9;
	const unsigned short int LOW = 0;

	//m - the magic number
	//x - trial number
	//u - the user's guess
	srand(unsigned int (time(NULL)));
	unsigned short int m = (rand() % (HIGH - LOW + 1)) + LOW;
	unsigned short int x = 0;
	const unsigned short int size = 10;
	int sentinel = -999;
	int u[size];

	int error;

	initializeArray(u, size, sentinel);
	
	while (x < 10)
	{
		printf("Guess a number between 0-9: ");
		//scanf(%hi, &var) represents hex input converted to a short int
		//unfortunately error = 0 doesn't help me since the buffer still isn't handled.
		error = scanf("%d", &u[x]);
		while ((u[x] < 0) || (u[x] > 9) || error == 0)
		{
			printf("Invalid, try again: ");
			error = scanf("%d", &u[x]);
		};
		printf("Attempt: %hi\nYou Guessed: ", (x+1));
		printArray(u, size, sentinel);

		printf("\n\t\t");

		if (u[x] == m)
		{
			printf("\n\n");
			printf("\tCORRECT! WON THE GAME!\n");
			return;
		}
		else if (u[x] > m)
		{
			printf("Too big!");
		}
		else if (u[x] < m)
		{
			printf("Too small!");
		}

		printf("\n\n\n");
		x++;
	}

	printf("\tWRONG! FAILED THE GAME!\n");
	return;

}


/*
Name:  initializeArray
Precondition:		PARAMS declared in higher function
Parameters:			int arr[], 
					const unsigned short int size, 
					int sentinel
Return:				void
Postcondition:		int arr[] initialized to all sentinel values

Description:		Takes a pointer to the beginning of an array, the size
					of the array, and sets its elements to some integer
					sentinel value.
*/
void initializeArray(int arr[], const unsigned short int size, int sentinel)
{
	unsigned short int i;
	for (i = 0; i < size; i++)
	{
		arr[i] = sentinel;
		
	}
}


/*
Name:  printArray
Precondition:		PARAMS declared in higher function
Parameters:			int arr[],
					const unsigned short int size,
					int sentinel
Return:				void
Postcondition:		n/a

Description:		Takes a pointer to the beginning of an array, the size
					of the array, and prints the contents of the array
					until it either encounters the integer sentinel value
					or the end of the array.
*/
void printArray(int arr[], const unsigned short int size, int sentinel)
{
	unsigned short int i;
	for ( i = 0; i < size; i++)
	{
		if (arr[i] != sentinel)
		{
			printf("%hi ", arr[i]);
		}
		else
			return;
	}
}


int main(int argc, const char * argv[])
{
	char user_response = 'n';

	do
	{
		
		task1();

		printf("\n\n");
		printf("Would you like to repeat? (Y or N): ");
		scanf("\n%c", &user_response);
		printf("\n\n");

	} while (user_response == 'y' || user_response == 'Y');

	return 0;
}

