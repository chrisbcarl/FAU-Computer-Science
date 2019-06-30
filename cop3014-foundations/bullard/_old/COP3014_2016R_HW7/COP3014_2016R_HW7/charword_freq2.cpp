/*
Name:  Input_greedy
Precondition:		VARS all initialized in higher function

VARS:				ifstream in
call_record customer_record

Postcondition:		VAR customer_record contains new data
Description:		Get input (values of cell_number, relays,
and call_length) from a data text file.
Each "line" of this data text file becomes
the same object, customer_record which
becomes processed by void Process()
*/


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
Your program should be modular, meaning that you should break it up into smaller function(s).Your main program should be as small as possible and well documented.
Handing in your program
Electronically submit the source file "charword_freq.cpp" in the Assignments area of blackboard before the due date and time.Remember, no late assignments will be accepted.

LOG:
16.06.24, 12:03 - start
16.06.24, 13:15 - spent about an hour working on a c-style implementation...
never again godamnit.
- logic completed, first compile, works with greedy implementation
- logic completed, first compile, new non-greedy implementation, b0001
- documentation added
- formatting for readability/80char rule
- final edits


BUG:	FOUND:			FIXED:			DESCIRPTION:
b0001	16.06.17,16:34	-				program hangs
16.06.17,16:45	forgot el stupid i++
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

using namespace std;



//prototypes


//globals




/*
pseudocode for hw7

create_array
create a 2d vector, vector of ints, vector of chars.

create_array(overload)
make it a multidimensional hash table that covers the ascii table it's just 2^7

ingest
while not eof, store as a string

ingest(overload)
while not eof, store as a cstring

categorize
while not \0,
find that char inside of the current vector char dimension
if not, push back new char
increment int dimension

categorize

organize
use the sort function on char dimension

main :

call ingest






//pseudocode for hw7
//
//create_array
//create a 2d vector, vector of ints, vector of chars.
void create_vector()
{


}



//ingest
//while not eof, store as a string
void ingest(ifstream & in_stream, string & s)
{
	//optional getline(in_stream, s)
	while (!in_stream.eof()) in_stream >> s;
}


//ingest(overload)
//while not eof, store as a cstring

void ingest(FILE * pFile, char s[])
{
	if (pFile != NULL)
	{
		int i = 0;
		do
		{
			fscanf(pFile, "%c", s[i]);
		} while (s[i] != 0);
	}
}

void expel(ofstream & out_stream, string & s)
{
	out_stream << s;
}

void expel(FILE * pFile, char s[])
{
	if (pFile != NULL)
	{
		int i = 0;
		do
		{
			fprintf(pFile, s);
			i++;
		} while (s[i] != '\0');
	}
}

//initialize
void initialize_vectors(vector<char> & ASCII, vector<vector<char>> & ASCII_FREQ)
{
	vector<char>::iterator ASCII_itr = ASCII.begin();
	vector<vector<char>>::iterator ASCII_FREQ_itr = ASCII_FREQ.begin();

	int i = 0;
	for (i; i < 1; ASCII_FREQ_itr++)
	{
		int j = 0;
		for (j; j < 1; j++)
		{
			ASCII.push_back(static_cast<char>(i));
			i++;
		}
		ASCII_FREQ.push_back(ASCII);
	}
}


void print_vectors(vector<char> & ASCII, vector<vector<char>> & ASCII_FREQ)
{
	vector<char>::iterator ASCII_itr = ASCII.begin();
	vector<char>::iterator ASCII_end = ASCII.end();

	vector<vector<char>>::iterator ASCII_FREQ_itr = ASCII_FREQ.begin();
	vector<vector<char>>::iterator ASCII_FREQ_end = ASCII_FREQ.end();

	for (ASCII_FREQ_itr; ASCII_FREQ_itr != ASCII_FREQ_end; ASCII_FREQ_itr++)
	{
		for (ASCII_itr; ASCII_itr != ASCII_end; ASCII_itr++)
		{
			cout << *ASCII_itr << " ";
		}
		ASCII_FREQ.push_back(ASCII);
		cout << endl;
	}
}




//categorize
//while not \0,
//find that char inside of the current vector char dimension
//if not, push back new char
//increment int dimension
//
//categorize
//
//organize
//use the sort function on char dimension
//
//main :
//
//call ingest


int main(int argc, const char * argv[])
{

	ifstream in_stream;		//declaring an input file stream
	ofstream out_stream;	//declaring an output file stream

	string user_response = "y";
	string input_filename = "mytext.dat";
	string output_filename = "myresults_cpp.dat";
	string cpp_string;


	//FILE * pFile;			//declaring a file pointer for c_strings
	//char c_input_filename[256] = "mytext.dat";
	//char c_output_filename[256] = "myresults_c.dat";
	//int pre_c_string[256];
	//char c_string[256];

	/*pFile = fopen(c_input_filename, "r");
	if (pFile == NULL) perror("Error opening file");*/


/*
	do
	{

		cout << "Use default file name? ";
		getline(cin, user_response);

		if ((user_response != "Y") && (user_response != "y"))
		{
			cout << "Enter the file name to parse: ";
			getline(cin, input_filename);
			cout << endl << endl;
		}



		in_stream.open(input_filename);
		out_stream.open(output_filename);

		vector<char> ASCII;
		vector<vector<char>> ASCII_FREQ;

		initialize_vectors(ASCII, ASCII_FREQ);
		print_vectors(ASCII, ASCII_FREQ);

		ingest(in_stream, cpp_string);
		expel(out_stream, cpp_string);

		//single program function call




		//create_array(overload)
		//make it a multidimensional hash table that covers the ascii table it's just 2^7

		in_stream.close();
		out_stream.close();

		cout << "Would you like to do another calculation (Y or N): ";
		getline(cin, user_response);
		cout << endl << endl;


	} while (user_response == "y" || user_response == "Y");


	
	return 0;
}
*/