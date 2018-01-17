//define/include section
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

//7. THIS QUESTION HAS 3 PARTS: 
//1. A main function with the function calls to GetL and GetD. Declare any variables and assign values as needed. 
//2. Include the function definitions described below. Declare any variables and assign values as needed. 
//3. Add the function prototypes You do not need to include comments or preprocessor directives Function 
//1. Write a function definition called GetL that takes no arguments and returns a character. The function will prompt the user to enter a character, get a character, and return it. Function 
//2. Write a function definition called GetD that takes no arguments and returns a double. The function will prompt the user to enter a double, get a double, and return it.

//function prototypes
char GetL();
double GetD();

int main()
{
	GetL();
	GetD();
	return 0;
}

//function defintions
char GetL()
{
	printf("Enter a letter: ");
	char letter;
	scanf(" %c", &letter);
	return letter;
}
double GetD()
{
	printf("Enter a decimal: ");
	double decimal;
	scanf(" %lf", &decimal);
	return decimal;
}

#endif // !MIDTERM_REVIEW_H