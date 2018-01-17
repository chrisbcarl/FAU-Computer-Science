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