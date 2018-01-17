//define/include section
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

//function prototypes section

int main()
{


	return 0;
}
//function definitions section
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