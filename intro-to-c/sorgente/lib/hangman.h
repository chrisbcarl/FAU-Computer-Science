#ifndef SORGENTE_HANGMAN
#define SORGENTE_HANGMAN

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <ctype.h> 
#include <string.h> //strcmp, //strlen
#define WSIZE 30

//game-style
void Rules();
int PlayOneRound(char solution[], char blanks[], char guess_history[]);
void WonLost(int win);
int FillBlanks(char solution[], char blanks[], char target);
void DrawHangman(int num);
void GuessWholeWord(char solution[], char blanks[]);			//opportunity to fill in the blanks
void StoreGuesses(char guess_history[], char new_guess);						//save each and every guess.


//utility
void Quit(char *again);
void MakeBlanks(char blanks[], int size);
void GetLetter2(char *letter);
int CompareArrays( char word_a[], char word_b[]);
void ChangeCase(char word[]);

int hangman()
{
	char again;
	char solution[WSIZE] = "something";
	char blanks[WSIZE] = "something else";
	char guess_history[WSIZE];
	int outcome;
	FILE * the_file = fopen("data/hangman.txt", "r");
    if (the_file) {
      do
      {
        guess_history[0] = '\0';				//resets guess history
        fscanf(the_file, " %s", solution);
        ChangeCase(solution);
        outcome = PlayOneRound(solution, blanks, guess_history);
        WonLost(outcome);
        Quit(&again);
      } while (again == 'Y');
    }
    else {
      printf("File not found!\n\n");
    }

	return 0;
}

//GAME FUNCTIONS

//just print the rulese
void Rules() 
{
	printf("//just print the rulese\n\n\n");
}

//PLAY THE WHOLE GAME
//The thing is, you already know the solution,
//	so use it. then make the blanks for the player
//	to use
int PlayOneRound(char solution[], char blanks[], char guess_history[])
{
	char guess;
	int correct;
	int got_the_word;

	int length = strlen(solution);
	MakeBlanks(blanks, length);

	int chance = 1;
	
	do
	{
		GetLetter2(&guess);
		StoreGuesses(guess_history, guess);				//save each and every guess.

		correct = FillBlanks(solution, blanks, guess);

		if (correct)
		{
			//don't draw, don't increment
			printf("Aye fam, good guess.\n");
			//opportunity to fill in the blanks
			GuessWholeWord(solution, blanks);
		}
		else if (!correct)
		{
			DrawHangman(chance);
			chance++;
		}

		printf("Guesses include: %s\n", guess_history);
		printf("blanks include: %s\n\n\n", blanks);

		got_the_word = CompareArrays(solution, blanks);
	} while (chance < 6 && !got_the_word);

	return got_the_word;
}

//1 if they won
//0 if they lost
void WonLost(int win)
{
	if (win == 1)
	{
		printf("You WIN!\n\n");
	}

	if (win == 0)
	{
		printf("You LOST!\n\n");
	}
}

//it fills in the blanks
//how?
//it looks through the entire solution,
//	if the current character it's sitting on is the target
//	fill in the blanks word at the same spot
//	if one of the blanks gets filled, return 1
//	if none of the blanks gets filled, return 0
int FillBlanks(char solution[], char blanks[], char target)
{
	int length = strlen(solution);
	int a_blank_was_filled = 0;			//assume that the user didn't guess right

	int i;
	for (i = 0; i < length; i++)
	{
		//each character of the solution is called solution[i]
		//each character of the blanks is called blanks[i]
		if (solution[i] == target)	//if solution letter is the target
		{
			blanks[i] = target;		//fill in the blanks
			a_blank_was_filled = 1;			//the user guessed something right
		}

	}

	return a_blank_was_filled;
}

//draw hangman, there are only 6 states.
void DrawHangman(int num)
{
	if (num == 1)
	{
		printf("---head---\n");
	}
	else if (num == 2)
	{
		printf("---neck---\n");
	}
	else if (num == 3)
	{
		printf("---left arm---\n");
	}
	else if (num == 4)
	{
		printf("---right arm---\n");
	}
	else if (num == 5)
	{
		printf("---left leg---\n");
	}
	else if (num == 6)
	{
		printf("---right leg---\n");
	}
}


void GuessWholeWord(char solution[], char blanks[])
{
	char guess_from_user[WSIZE];
	printf("Congrats, guess the whole word: ");
	scanf(" %s", guess_from_user);
	ChangeCase(guess_from_user);

	//option 1
	int the_same = CompareArrays(solution, guess_from_user);

	//option 2
	int comparison = strcmp(solution, guess_from_user);

	if (the_same)
	{
		strcpy(blanks, guess_from_user);
	}
	else
	{
		//they're not the same, no need to do anything
	}
}


//WE're gonna treat this as a string. THAT MEANS that at the end of it is a '\0'
//all we have to do is move teh null character over by 1.
void StoreGuesses(char guess_history[], char new_guess)
{
	//[a, e, i, o, \0]
	//[a, e, i, o, u]		[a, e, i, o, u, \0];

	int length = strlen(guess_history);
	guess_history[length] = new_guess;
	guess_history[length + 1] = '\0';
}



//UTILITY FUNCTIONS
void Quit(char *again)
{
	printf("Again? ");
	scanf(" %c", again);
	*again = toupper(*again);		//"not necessary"
}

void MakeBlanks(char blanks[], int length) 
{
	int i;
	for (i = 0; i < length; i++)
	{
		//each character of the blanks word is called blanks[i]
		blanks[i] = '_';
	}

	//to make this a string, add a null terminator '\0'
	blanks[length] = '\0';


}
void GetLetter2(char *letter)
{
	printf("Letter? ");
	scanf(" %c", letter);
	*letter = toupper(*letter);		//"not necessary"
}
int CompareArrays(char word_a[], char word_b[])
{
	//if they're the same, return 1, meaning TRUE
	//if they're not the same, return 0, meaning FALSE
	int length = strlen(word_a);

	int they_are_the_same = 1;		//assume they're the same
	
	int i;
	for (i = 0; i < length; i++)
	{
		//each character of the word_a is called word_a[i]
		//each character of the word_b is called word_b[i]
		if (word_a[i] != word_b[i])
		{
			they_are_the_same = 0;		//we found out that they're not the same
		}
	}

	return they_are_the_same;
}
void ChangeCase(char word[]) 
{
	int length = strlen(word);

	int i;
	for (i = 0; i < length; i++)
	{
		//each character of the word is called word[i]
		word[i] = toupper(word[i]);
	}
}

#endif