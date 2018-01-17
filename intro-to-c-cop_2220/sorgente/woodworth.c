////HEADER
//#define _CRT_SECURE_NO_WARNINGS
//#define MAXGUESSES 5
//#include "stdio.h"
////FUNCTION PROTOTYPE AREA
//int GetNumberOfGamesToPlay();
//
////MAIN SECTION
//int main()
//{
//	//display instructions
//	FILE * filepointer = fopen("lettersin.txt", "r");		//open file
//	int playgames = GetNumberOfGamesToPlay();				//get number of games to play
//	for (int i = 0; i < playgames; i++)
//	{
//		char file_letter;
//		fscanf(filepointer, " %c", &file_letter);
//		printf("%c", file_letter);
//	}
//
//	//	8. Copy the function prototypes from the assignment Word document on BlackBoard into your source code file where the outline instructs you to do so.Do not use copy and paste since Word has invisible formatting that may corrupt your source code.
//	//	Copy the prototypes from the top of your source code and paste them below the main function, EXCEPT THE SingleGame prototype.
//	//	You should have the outline for SingleGame and a second prototype for the other 3 functions below the main function.
//	//	Remove the semicolons from the end of the prototypes below the main function, add{}
//	//	Add return statements inside the definitions where needed(if it returns something)
//	//	9. Build, run and test
//	//	10. Write the function definition and function call for the GameRules function
//	//	11. Build, run and test
//	//	12. Write the function call to SingleGame.Use printf statements in both the main function and inside the SingleGame function to test
//	//	13. Build, run and test
//	//	14. Add the code to the loop in the SingleGame function above numGuesses = numGuesses + 1;
//	//This function will return to an integer variable the you will need to add to the main function
//	//	use printf statements in the main function to test the value of that variable
//	//	15. Build, run and test
//	//	16. Define and call the RetrieveGuess function from inside the while loop of the SingleGame function.
//	//	17. Build, run and test
//	//	18. Call the GuessedIt function, passing it both the answer from the file and the input_letter from the user guess
//	//	It will return to an integer you will need to declare in theSingleGame function
//	//	Use printf statements in both SingleGame and GuessedIt functions to test
//	//	19. Add the conditions in the GuessedIt function
//	//	20. Build, run and test
//	//	21. Add any \n in your printf statments to make everything display on its own line
//	//	22. Make sure you program runs correctly when you guess correctly and that it allows only the specified number of guesses if you keep guessing wrongly.
//	//	23. Make sure you display the answer if the user never guesses it before the number of guesses is depleted.
//	//	24. Before submitting you should delete any printf statements you used just for testing.Make sure you have adequate comments and indentation.
//	//	25. Only submit(upload) the.c file with your code.Do not submit any other files.Be sure you select the correct file!
//
//
//	return 0;
//}
//
////FUNCTION DEFINITION AREA
//int GetNumberOfGamesToPlay()
//{
//	int store;
//	printf("How many games? ");
//	scanf("%d", store);
//	return store;
//}
//
//
//int SingleGame(char file_letter)
//{
//	int numguesses = 0;
//	while (numguesses < MAXGUESSES)
//	{
//		numguesses = numguesses + 1;
//	}
//
//	return -9999;
//}