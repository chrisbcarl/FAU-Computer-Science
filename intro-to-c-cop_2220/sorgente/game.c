////HEADER
//#define _CRT_SECURE_NO_WARNINGS
//#include "stdio.h"
////FUNCTION PROTOTYPE AREA
//void DisplayInstructions();
//int GetNumberOfGames();
//char GetLetter(char c);
//int SingleGame();
//void WinLose(int r);
//
////MAIN SECTION
//int main()
//{
//	//	4. Insert a printf statement that outputs "hello" inside the loop in the main function 
//	//		and set the number of games to 4(PlayGames = 4), 
//	//		build run and test(you should see "Hello" 4 times and "Press any key...").
//	//		This lets you know that the loop will repeat correctly.
//	//	5. Go to BlackBoard and save lettersin.txt into the same directory as LetterGame.c.
//	//	6. Back in your program declare a file pointer variable and use it to open the input file.
//	//	Replace the printf with "Hello" with an fscanf to read the letters one by one from the file and a printf to print the letters onto the screen(should read from the file and print the first 4 letters from the file)
//	//	7. Build, run and test You should see the first 4 lettes from your input file displayed(GET HELP HERE IF YOU CANNOT CONNECT, READ AND PRINT THE LETTERS FROM THE FILE).
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
//
//	DisplayInstructions();
//
//	//open file
//	FILE * filepointer = fopen("lettersin.txt", "r");
//
//	//get number of games
//	int playgames = GetNumberOfGames();
//	for (int i = 0; i < playgames; i++)
//	{
//		//get a letter from ffile
//		char letter = GetLetterFromFile();
//
//		//play one game
//		int result = PlayOneGame();
//
//		//check for win or lose
//		int check = WinLose(result);
//
//	}
//	//close file
//
//
//	return 0;
//}
//
//void DisplayInstructions();
//int GetNumberOfGames();
//char GetLetterFromFile();
//char PlayOneGame();
//int WinLose(char l, char g);