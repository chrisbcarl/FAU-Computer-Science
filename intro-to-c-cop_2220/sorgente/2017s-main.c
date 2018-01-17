//define/include section
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

//my own libraries
//#include "loops.h"
//#include "control.h"
//#include "midterm_review.h"

//function prototype section
void function(double parameter1, int parameter2);

int main()
{
	printf("Hello, world!\n");
	//question6();


	return 0;
}

//other function definitions
void function(double parameter1, int parameter2)
{
	printf("%lf %d", parameter1, parameter2);
}