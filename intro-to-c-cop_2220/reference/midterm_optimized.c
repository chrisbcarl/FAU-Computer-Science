/*
Copyright 2017, Christopher Carl
FAU COP 2200, 2017S
Dr. Woodworth, Joy
*/

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

//2. 
char GetGrade(double arg1, double arg2);						//Write a function call for a function called GetGrade which has two type double arguments/parameters. The function returns a character. 

//4. 
void ReadMe(char a, char b);									//Write the function prototype / declaration for a function called ReadMe that takes two character arguments and returns nothing.

//5. 
double SalesTax();												//Write user-defined function definition for a function called SalesTax that has no parameter/argument. 


int main()
{
	//2.
	double lower_score = 79.5;									//Declare and initialize the three necessary datavariables and assign values needed to make it eexecutable 
	double upper_score = 84.5;									//Declare and initialize the three necessary datavariables and assign values needed to make it eexecutable 
	char grade = GetGrade(lower_score, upper_score);			//Declare and initialize the three necessary datavariables and assign values needed to make it eexecutable, Do NOT use literal values in the call.

	//3.
	FILE * file = fopen("numbers.txt", "r");						//Open a file called "numbers.txt" for input(read only)
	int var;													//Declare all necessary variables
	fscanf(file, " %d", &var);									//Read a single integer from the file and store it in your declared variable.
	printf("var = %d, var-15 = %d\n", var, var-15);				//Subtract 15 from the integer, Display the original value and the new value
	fclose(file);													//Close the file

	//6. 
	int awards = 9;
	int students = 3;
	if (awards % students != 0)									//if the value of the integer variable awards is not evenly divisible (with no remainder) by the integer variabel students 
		printf("Buy more awards...\n");							//Write a statement that displays the phrase "Buy More" 
	else														//otherwise 
		printf("Everyone student gets an award!\n");			//displays the phrase "Everyone wins!" (Assume that students is not zero.)

	//8. 
	int wealthy = 99999999;										//Declare and initialize these two integer variables to any values, wealthy 
	int poor = 9;												//Declare and initialize these two integer variables to any values, poor
	int prince_pauper = wealthy;								//Declare only one additional variable to assist with the swap., write some code that swaps their values.
	wealthy = poor;
	poor = prince_pauper;


	//9.
	int checkNum = 0;
	switch (checkNum)											//Write a switch statement that tests the value of the variable checkNum
	{
	case 10:													//if checkNum is 10, the message "Speed lane" is printed.
		printf("Speed lane\n");
		break;
	case 11:													//if checkNum is 11, the message "Pick any lane" is printed.
		printf("Pick any lane\n");
		break;
	case 12:													//if checkNum is 12, the message "Special assistance required" is printed.
		printf("Special assistance required\n");
		break;
	default:													//for any other value of checkNum, the message "See the manager" is printed
		printf("See the manager\n");
		break;
	}

	return 0;
}

//1. 

double IncreasePrice(double arg)								//Write the function definition for a function caled increaseprice which has one type double parameter/argument. 
{
	printf("What's the amount? ");								//The function prompts the user for an amount, 
	double amount;
	scanf(" %lf", &amount);
	return amount * arg;										//multiplies the input by the argument value, and returns the new value.
}

//5. continued
double SalesTax()
{
	
	printf("What's the value? ");								//The function prompts the user for an integer value, reads the value from the keyboard, 
	int value;
	scanf(" %d", &value);

	if (value < 100)											//if the input is less than 100 
		return value + value * 0.10;								//adds 10% 
	else if (100 <= value && value <= 499)						//if it is 100-499 
		return value + value * 0.08;								//8% 
	else														//otherwise 
		return value + value * 0.05;								//it ad 5% to the input value 
}

//7. 
int GotIt(int answer, int guess)								//Write a function definition for a user-defined function called GotIt. The function takes two integer arguments, answer and guess.
{
	if (guess > answer)											//if guess is greater than answer
		printf("too high\n");									//	display "too high" on the monitor
	else if (guess < answer)									//if guess is less than answer :
		printf("too low\n");									//	display "too low" on the monitor
	else														//if answer and guess are the same
		printf("they match, you win!\n");						//	display "you win" on the monitor

	return guess;												//	return the guess, return the answer
}

//2. (prototype and defninition is necessary to run in this example code)
char GetGrade(double arg1, double arg2) { return '_'; }

//4. (prototype and defninition is necessary to run in this example code)
void ReadMe(char a, char b) {}