#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//Jake Cardo 03/27/16
int main()
{
	// vars
	int bob;
	FILE * file2 = fopen("doubleOutput.txt", "w");
	FILE * file1 = fopen("doubleInput.txt", "r");
	int i;



	//-Declare an array of doubles of size 25.
	double decimals[25];

	//	- Ask the user how many doubles to get from the file(<= 25).
	printf("Enter a number less than 25");
	scanf(" %d", &bob);

	//	- Use a loop  from zero to bob to read the doubles into the array from the input file(fscanf).
	for (i = 0; i <bob; i++)
	{
		fscanf(file1, " %lf", &decimals[i]);
	}



	//	- Use a loop to print the doubles in the array onto the screen in a row, with a space between each
	for (i = 0; i <bob; i++)
	{
		printf("%lf \n", decimals[i]);
	}


	//	- Use a loop to add 2.64 to each number in the array
	for (i = 0; i <bob; i++)
	{
		decimals[i] = decimals[i] + 2.64;
	}

	//	- Use a loop to print the new values of the doubles in the array onto the screen in a row, with a space between each
	for (i = 0; i <bob; i++)
	{
		printf("%lf \n", decimals[i]);
	}



	//	Open a file called doubleOutput.txt - Use a loop and fprint the new values of the doubles in the array into the output file
	for (i = 0; i <bob; i++)
	{
		fprintf(file2, "%lf\n", decimals[i]);
	}


	//	Use fclose to close both file pointer
	fclose(file2);
	fclose(file1);

	return 0;
}