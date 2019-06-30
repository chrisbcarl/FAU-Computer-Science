//Tevyn Campbell
//11/20/16
//Program 3


#define SIZE 20
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"


void greeter(char * c);
void getWord(char word[]);
int SearchforlastCharacter_and_ChangeToLower(char word[], char lowerword[]);
void changeToLowerCase(char word[], char lowerword[]);
void Changeto_ies(char word[], int i);
void Changeto_es(char word[], int i);
void Changeto_s(char word[], int i);
void displayWord(char word[]);
void saveWords(FILE * fptr, char word1[], char word2[]);

int main()
{
	char choice;
	char lowerword[20];
	char word[20];
	char plural[20];

	FILE * fptr = fopen("pluralWords.txt", "a+");
	if (fptr == NULL)
	{
		return -1;
	}
	else
	{
		greeter(&choice);
		while (choice == 'y')
		{
			getWord(word);
			int i = SearchforlastCharacter_and_ChangeToLower(word, lowerword);
			strcpy(plural, lowerword);
			if (word[i] == 'y')
				Changeto_ies(plural, i);
			else if ((word[i-1] == 's') && (word[i] == 'h'))
				Changeto_es(plural, i);
			else if ((word[i-1] == 'c') && (word[i] == 'h'))
				Changeto_es(plural, i);
			else if (word[i] == 's')
				Changeto_es(plural, i);
			else
				Changeto_s(plural, i);
			displayWord(plural);
			greeter(&choice);
		} 
		fclose(fptr);
	}
	return 0;
}


void greeter(char * c)
{
	printf("Hello, Welcome user would you like to continue?\n");
	printf("Eneter Y for yes and N for no\n ");
	scanf(" %c", c);

}

void getWord(char word[])
{
	printf("Enter a word\n");
	scanf("%s",word);
}

int SearchforlastCharacter_and_ChangeToLower(char word[], char lowerword[])
{
	strcpy(lowerword, word);
	int i = 0;
	while (lowerword[i] != '\0')
	{
		lowerword[i] = (char)tolower(lowerword[i]);
		i++;
	} 
	return i - 1;

}
void changeToLowerCase(char word[], char lowerword[])

	{
		strcpy(lowerword, word);
		int i = 0;
		while (lowerword[i] != '\0')
		{
			lowerword[i] = (char)tolower(lowerword[i]);
			i++;
		}

}

//A function for each rule that converts a single word(3 functions)
//1. If the word ends in ‘y’, remove the ‘y’ and add “ies” to the end.   Examples: cherry becomes cherries
void Changeto_ies(char word[], int i)
{

	word[i] = 'i';
	word[i + 1] = 'e';
	word[i + 2] = 's';
	word[i + 3] = '\0';

	
}

//2. If the word ends with the letters ‘s’, “ch”, or “sh” then simply add the letters “es” to the end    Examples : bus becomes buses
void Changeto_es(char word[], int i)
{
	word[i+1] = 'e';
	word[i + 2] = 's';
	word[i+3] = '\0';
}

//3. If the above rules above do not apply then just add the letter‘s’ to the end of the word.
void Changeto_s(char word[], int i)
{
	
	word[i + 1] = 's';
	word[i + 2] = '\0';

}

void displayWord(char word[])
{
	printf("%s\n", word);

}

//A function that saves both words to the output file
//bonus WORTH 5 POINTS- IMPLEMENT THE ASSIGNMENT WITH NO STRING MEMBER FUNCTIONS
//FOR THE BONUS YOU MAY ONLY USE %s ONE TIME WHEN SCANNING IN THE WORD
//void saveWords(FILE * fptr, char word1[], char word2[]);

