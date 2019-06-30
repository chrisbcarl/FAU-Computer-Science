#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sum = 0;
	int product = 0;
	for (int i = 1; i < 11; i++)
	{
		printf("Hello, world %d! ", i);
		sum = sum + i;
		printf("Sum = %d ", sum);
		product = 2 * i;
		printf("Product = %d\n", product);
	}


	//print the numbers 1 thru 1000 
	for (int i = 0; i < 1000; i++)
	{
		printf("%d ", i);
	}


	//while loop
	int i = 0;
	while (i < 1000)
	{
		//
		printf("%d ", i);

		i++;
	}

	//use for loop when you know exactly how many times you wanna repeat yourself
	//use a while loop when you're not sure at all, but know when you have to stop.


	int j = 0;
	do {

		printf("%d ", j);
		j++;				//THIS GOES LAST
	} while (j < 1000);


	//the typewriter

	char letter = '_';
	do
	{
		scanf(" %c", &letter);
	} while (letter != '~');


}