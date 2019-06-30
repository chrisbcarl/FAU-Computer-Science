/*******************************************************************************

Name: Christopher Carl
Z#: Z23146703
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 16.06.28
Due Time: 23:59
Total Points: 100
Assignment 7: Character Frequency in a File

Description:
1. Read the contents of a data file(mytext.dat);
2. Process the frequency of characters(a - z) that appear in the data file
3. Print the frequency of characters in the file to the screen;
4. Be able to use an ifstream object;
In this assignment you will implement a program called "charword_freq.cpp" 
to determine the number of words and the number of occurrences of each letter 
in a block of text stored in a data file called “mytext.dat”.Define a word to 
be any string of letters that is delimited at each end by either whitespace, 
a period, a comma, or the beginning or end of a line.You can assume that the 
input consists entirely of letters, whitespace, commas and periods.When 
outputting the number of words and letters that occur in a line, be sure to 
count upper - and lowercase versions of a letter as the same letter.Output t
he letters in alphabetical order and list only those letters that do occur 
in the input data file.Consider the following example :
Block of text in the data file :
hello world ALL is great.HELLO WORLD ALL IS GREAT.hellO worlD alL iS great.
Output of your program to the screen :
15 words
6   a
3   d
6   e
3   g
3   h
3   i
15 l
6  o
6  r
3  s
3  t
3 w
Your program should be modular, meaning that you should break it up into smaller 
function(s).Your main program should be as small as possible and well documented.
Handing in your program
Electronically submit the source file "charword_freq.cpp" in the Assignments 
area of blackboard before the due date and time.Remember, no late assignments 
will be accepted.

LOG:
16.06.24, 12:03 - start
16.06.24, 13:15 - spent about an hour working on a c-style implementation...
					never again godamnit.
16.06.24, 13:15 - start over from scratch, epiphany. need only 1D array
16.06.24, 14:03 - logic completed, 1st compile, no errors, but no output
16.06.24, 14:09 - ~10th compile, about right output
16.06.24, 14:26 - ~20th compile, correct
16.06.24, 14:27 - potty break
16.06.24, 14:52 - documentation added
16.06.24, 14:53 - formatting for readability/80char rule
16.06.24, 15:00 - ~30th compile, final edits

16.06.29, 10:45 - start on accurate word counting
16.06.29, 11:17 - DONE


BUG:	FOUND:			FIXED:			DESCIRPTION:
B0001	16.06.24,14:55	-				Doesn't work on multi-lined text files
						16.06.24,14:59	Added a temp variable and would 
										continually add to the string being 
										eventually analyzed.
B0002a	16.06.24,17:00	-				Missing features: case-less counting
						16.06.24,17:41	DONE
B0002b	16.06.24,17:00	-				Missing features: accurate word counting.
						16.06.29,11:17	DONE, non-greedy
*******************************************************************************/

//used to supress Microsoft compiler errors for using scanf
//they insist on using scanf_s which requires buffer sizes
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>
#include <ios>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;


/*
Name:  initializeArray
Parameters:			int arr[], 
					int size
Returns:			void
Precondition:		Parameters initializes in higher function
					int size must accurately reflect how many
						elements occur in arr[]
Postcondition:		P arr[] 0->n elements initialized with 0
Description:		Iniitializes all elements in an int array
					from zero to size with the value of 0.
*/
void initializeArray(int arr[], int size)
{
	for (int i = 0; i < size; i++) arr[i] = 0;
}


/*
Name:  ingest
Parameters:			ifstream & in_stream, 
					string & s
Returns:			void
Precondition:		ifstream & in_stream must successfully open a file
Postcondition:		string s contains all chars of the file
						opened by in_stream
Description:		Takes in string data from a text file and
					stores it as a string
*/
void ingest(ifstream & in_stream, string & s)
{
	string temp;
	while (!in_stream.eof())
	{
		getline(in_stream, temp);
		s += temp;
	}
}


/*
Name:  isASCII_char
Parameters:			int i
Returns:			bool
Precondition:		int i must be initialized in higher function
Postcondition:
Description:		Returns true if int i corresponds to a letter
					character on the ASCII table
*/
bool isASCII_char(int i)
{
	return ((65 <= i) && (i <= 90)) || ((97 <= i) && (i <= 122));
}


/*
Name:  isENG_char
Parameters:			int i
Returns:			bool
Precondition:		int i must be initialized in higher function
Postcondition:
Description:		Returns true if int i corresponds to an English 
					character on the ASCII table, including whitespace
*/
bool isENG_char(int i)
{
	return ((0 <= i) && (i <= 34)) || 
		((39 <= i) && (i <= 41)) || (44 == i) || (46 == i) ||
		(58 == i) || (59 == i) || (63 == i) ||
		((65 <= i) && (i <= 90)) || ((97 <= i) && (i <= 122)) ||
		(91 == i) || (93 == i) || (96 == i) || 
		(123 == i) || (125 == i);
}

bool iseng_char_backup(int i)
{
	return ((0 <= i) && (i <= 3)) || ((i > 10) && (i < 16)) ||
		((i > 64) && (91 > i)) || ((i > 96) && (123 > i)) ||
		((i > 32) && (35 > i)) || ((i > 38) && (42 > i)) ||
		((i > 144) && (149 > i)) || (i == 46) || (i == 58) ||
		(i == 59) || (i == 63);
}


/*
Name:  wordCount
Parameters:			string s, 
					int & words
Returns:			void
Precondition:		VARS must be initialized
Postcondition:		VAR words contains how many words are in string s
Description:		Accurately describes how many English words are
					in string s, regardless of correct spelling or
					length. Hyperprimitive. Works on lorem ipsum
					ERRORS (still count as words):
						B0002
						~10th
*/
void wordCount (string s, int & words)
{
	unsigned int i = 0;
	/*string s;
	string::iterator iterS = s.begin();*/
	while (i < s.length())
	{
		while (!isASCII_char(static_cast<int>(s[i]))) i++;
		while (isASCII_char(static_cast<int>(s[i]))) i++;
		words++;
		i++;
	}
}

/*
Name:  categorize
Parameters:			string & s, 
					int arr[]
Returns:			void
Precondition:		int arr[] must have enough elements to cover
						the required sections of the ASCII table
Postcondition:		VAR arr[] contains frequency data of string s
Description:		For every char in string s, the frequency of
					its occurance in the string s is recorded
					int args:
						0 -- case sensitive categorization
						1 -- case insensitive
*/
void categorize(int args, string & s, int arr[], int & word_count)
{
	int n;
	unsigned int i;
	switch (args)
	{
	case 0:
		for (i = 0; i < s.length(); i++)
		{
			n = static_cast<int>(s[i]);
			arr[n]++;
		}
		break;
	case 1:
		for (i = 0; i < s.length(); i++)
		{
			n = static_cast<int>(s[i]);
			if ((n > 64) && (91 > n)) n += 32;
			arr[n]++;
		}
		break;
	default:
		break;
	}
}


/*
Name:  expel
Parameters:			int args, 
					ofstream & out_stream, 
					int arr[], 
					int size
Returns:			void
Precondition:		int args < 4 && args > -1
					ofstream & out_stream must be valid
Postcondition:		ofstream & out_stream now points to a written
						textfile
Description:		Prints out the frequency of character occurances
					in a corresponding integer ascii frequency table
					array.
					int args:
						0 -- ASCII table frequency printed
						1 -- ASCII with nonzero frequency printed
						2 -- ASCII leters printed 
						3 -- ASCII leters with nonzero frequency printed 
*/
void expel(int args, ofstream & out_stream, int & word_count, int arr[], int size)
{
	out_stream << word_count << " words" << endl;

	int i = 0;
	switch (args)
	{
		//expell everything
	case 0:
		while (i < size)
		{
			out_stream << arr[i] << "\t" << static_cast<char>(i) << endl;
			i++;
		};
		break;
		//expell what had frequency
	case 1:
		while (i < size)
		{
			if (arr[i] != 0)
			{
				out_stream << arr[i] << "\t" << static_cast<char>(i) << endl;
			}
			i++;
		}
		break;
		//expell only letters
	case 2:
		while (i < size)
		{
			if (isASCII_char(i))
			{
				out_stream << arr[i] << "\t" << static_cast<char>(i) << endl;
			}
			i++;
		}
		break;
		//expell only letters that occured.
	case 3:
		while (i < size)
		{
			if ((arr[i] != 0) && (isASCII_char(i)))
			{
				out_stream << arr[i] << "\t" << static_cast<char>(i) << endl;
			}
			i++;
		}
		break;
	default:
		break;
	}
}




int main(int argc, const char * argv[])
{
	ifstream in_stream;		//declaring an input file stream
	ofstream out_stream;	//declaring an output file stream
	string input_filename = "mytext.dat";
	string output_filename = "myresults.dat";
	
	string user_response = "y";

	do
	{
		cout << "Default file name (Y or N): ";
		getline(cin, user_response);

		if ((user_response != "Y") && (user_response != "y"))
		{
			cout << "Enter the file name to parse: ";
			getline(cin, input_filename);
			cout << endl << endl;
		}

		in_stream.open(input_filename);
		out_stream.open(output_filename);


		//meat and potatoes, begin

		string s = "";			//that space is actually important for the word count
		int word_count = 0;

		ingest(in_stream, s);
		wordCount(s, word_count);
		int ascii[256];
		initializeArray(ascii, 256);
		categorize(1, s, ascii, word_count);
		expel(3, out_stream, word_count, ascii, 256);
		out_stream.close();

		out_stream.open("array_results.dat");
		initializeArray(ascii, 256);
		categorize(0, s, ascii, word_count);
		expel(0, out_stream, word_count, ascii, 256);

		//meat and potatoes, end
		in_stream.close();
		out_stream.close();

		cout << "Repeat calculation (Y or N): ";
		getline(cin, user_response);
		cout << endl << endl;


	} while (user_response == "y" || user_response == "Y");

	return 0;
}