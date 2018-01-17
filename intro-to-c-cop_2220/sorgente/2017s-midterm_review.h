#pragma once

#ifndef MIDTERM_REVIEW_H
#define MIDTERM_REVIEW_H

#include "stdio.h"

//1. Write the function prototype for a function called AverageAge. The function takes 3 arguments of type integer and returns a double, the average of the 3 arguments.
double AverageAge(int a, int b, int anyname);
//2. Write the function definition for a function called LetterGrade that takes two double arguments grade1 and grade2 and returns a character. If the average of the 2 grades is 90.0 or above the function will return a capital E, if the average is between 70.0 and 90.0 the function will return a capital S, if average is 70.0 or below the function will return the capital letter U.

char LetterGrade(double grade1, double grade2)
{
	double average = (grade1 + grade2) / 2;

	//If the average of the 2 grades is 90.0 or above the function will return a capital E, 
	if (average >= 90)
	{
		return 'E';
	}

	//if the average is between 70.0 and 90.0 the function will return a capital S, 
	//if (70 <= average <= 90), NOT LEGAL C
	if (70 <= average && average <= 90)
	{
		return 'S';
	}
		


	//if average is 70.0 or below the function will return the capital letter U.
	if (70 >= average)
	{
		return 'U';
	}
}

//3. Write the definition for a function called Larger that takes two arguments. The function should return the larger of the two values. You should not assume that the variables will contain different values.

int Larger(int arg1, int arg2)
{
	if (arg1 >= arg2)
	{
		return arg1;
	}
	else if(arg2 >= arg1)
	{
		return arg2;
	}
}

//4. Write a set of statements to perform the following steps: When the variable fruit contains the character uppercase P, increase the value in the integer variable papaya by one. When fruit contains the character uppercase G, increase the value in the integer variable guava by one. When fruit contains anything else, increase the value of the integer variable bananas by one.

void question4()
{
	char fruit = '_';
	int guava = 0;
	int papaya = 0;
	int bananas = 0;
	
	if (fruit == 'P')		//When the variable fruit contains the character uppercase P, increase the value in the integer variable papaya by one. 
	{
		papaya++;
	}
	else if (fruit == 'G')	//When fruit contains the character uppercase G, increase the value in the integer variable guava by one. 
	{
		guava = guava + 1;
	}
	else					//When fruit contains anything else, increase the value of the integer variable bananas by one.
	{
		bananas = bananas + 1;
	}
	
}

//5. Write a loop that will add up the squares of the first 100 whole numbers and store the result in the variable called total. Declare and initialize any variables.

void question5_dowhile()
{
	int total = 0;					//initialize any variables
	int square = 0;					//initialize any variables

	//do-while solution
	int counter = 1;				//STEP 1: Initialize the Counter
	do
	{
		square = counter * counter;
		total = total + square;		//STEP 4: Write your code

		counter++;					//STEP 3: Increment the Counter.
	} while (counter <= 100);		//STEP 2: Tell the Counter when to stop

}

//6. Write a function called Product.The function will prompt the user to enter integers one by one and calculate the product of all the numbers entered, until the user enters a zero to stop.The function will return the product of all the numbers entered.Declare and initialize any variables needed.

void question6()
{
	int product = 1;			//initialize any variables needed
	int user_input = 1;			//initialize any variables needed
	do
	{
		printf("Enter a product: ");
		scanf(" %d", &user_input);
		if (user_input != 0)
		{
			product = user_input * product;
		}
		else
		{

		}
	} while (user_input != 0);
	printf("Product = %d", product);
}

//7. THIS QUESTION HAS 3 PARTS: 
//1. A main function with the function calls to GetL and GetD. Declare any variables and assign values as needed. 
//2. Include the function definitions described below. Declare any variables and assign values as needed. 
//3. Add the function prototypes You do not need to include comments or preprocessor directives Function 
//1. Write a function definition called GetL that takes no arguments and returns a character. The function will prompt the user to enter a character, get a character, and return it. Function 
//2. Write a function definition called GetD that takes no arguments and returns a double. The function will prompt the user to enter a double, get a double, and return it.

//function prototypes
char GetL();
double GetD();

//function defintions
void question7()
{
	GetL();
	GetD();
}
char GetL()
{
	printf("Enter a letter: ");
	char letter;
	scanf(" %c", &letter);
	return letter;
}
double GetD()
{
	printf("Enter a decimalPoint: ");
	double num;
	scanf(" %lf", &num);
	return num;
}

#endif // !MIDTERM_REVIEW_H