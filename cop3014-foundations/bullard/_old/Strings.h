#pragma once

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*
"String" - as an abstract data type(ADT), strings hold language words.

C++ Strings vs. C-Strings
	C++ (a real Class):
		String s = "word1";
		ACTUAL CONTENTS: 'w', 'o', 'r', 'd', '1'

	C (a primitive char array):
		char s[30] = "a string with less chars then 30"
		ACTUAL CONTENTS: 'w', 'o', 'r', 'd', '1', '\0'

\0 - null terminator, it is character just like new line '\n', '\t', and others.

Some operations that you can do include:
Basic:
	Declaration
	Size vs. Length
	Assigning
	Concatonation - "one" + ", two" == "one, two";
	indexing - "Where is character 'x'?"
	Substringing - "one plus two is three" can be broken up into smaller strings like "one plus" and " two is three"
	Compare - "abc" comes before "xyz"
	Reversing - "one" becomes "eno"
	
	C-String to String

*/

int cpp_strings()
{
	//C++ STRINGS
	cout << "//C++ STRINGS" << endl;

	//Declaration
	cout << "//Declaration" << endl;
	string cpp_string = "one plus two equals three";
	cout << "cpp_string == " << cpp_string << endl;
	cout << endl << endl;

	//Size vs. Length
	cout << "//Size vs. Length" << endl;
	cout << "cpp_string's size == " << cpp_string.size() << " bytes" << endl;
	cout << "cpp_string's length == " << cpp_string.length() << " characters" << endl;
	cout << endl << endl;

	//Assigning
	cout << "//Assigning" << endl;
	string cpp_string_new1 = cpp_string;
	string cpp_string_new2 = "two minus one equals two";
	cout << "cpp_string_new1 == " << cpp_string_new1 << endl;
	cout << "cpp_string_new2 == " << cpp_string_new2 << endl;
	cout << endl << endl;

	//Concatonation
	cout << "//Concatonation" << endl;
	string cpp_string_concat = cpp_string_new1 + ", or " + cpp_string_new2;
	cout << "cpp_string_concat == " << cpp_string_concat << endl;
	cout << endl << endl;

	//Indexing
	cout << "//Indexing" << endl;
	cout << "char 'e' in \"" << cpp_string << "\" is at elements: " << endl;
	for (unsigned int i = 0; i < cpp_string.length(); i++)
	{
		if (cpp_string[i] == 'e')	cout << i << " " << endl;
	}
	cout << endl << endl;

	//Substrings
	cout << "//Substrings" << endl;
	string one = cpp_string.substr(0, 3);
	string plus = cpp_string.substr(4, 4);
	cout << "The substring of \"" << cpp_string << "\" between 0 and 3 is: " << one  << endl;
	cout << "The substring of \"" << cpp_string << "\" between 5 and 9 is: " << plus << endl;
	cout << endl << endl;

	//Compare
	cout << "//Compare" << endl;
	string abc = "abc";
	string xyz = "xyz";
	cout << "\"" << abc << "\" compared to \"" << xyz << "\" equals " << abc.compare(xyz) << endl;
	cout << "\"" << xyz << "\" compared to \"" << xyz << "\" equals " << xyz.compare(xyz) << endl;
	cout << "\"" << xyz << "\" compared to \"" << abc << "\" equals " << xyz.compare(abc) << endl;
	cout << endl << endl;

	//Reversing
	cout << "//Reversing" << endl;
	string cba;
	for (unsigned int i = abc.length(); i > 0; i--)
	{
		cba += abc[i - 1];
	}
	cout << "\"" << abc << "\"" << " reverse is " << cba << endl;
	cout << endl << endl;
	
	//String to C-String
	cout << "//String to C-String" << endl;
	char c_string[100];
	unsigned int i = 0;
	for (i = 0; i < cpp_string.length(); i++)
	{
		c_string[i] = cpp_string[i];
	}
	c_string[i] = '\0';			//VITALLY IMPORTANT;
	cout << "The C++ String of \"" << cpp_string << "\" has been converted to C-String \"" << c_string << "\""<< endl;
	cout << endl << endl;
	return 0;
}

int c_strings()
{
	//C STRINGS
	cout << "//C STRINGS" << endl;

	//Declaration
	cout << "//Declaration" << endl;
	char c_string[255] = "one plus two equals three";
	cout << "c_string == " << c_string << endl;
	cout << endl << endl;

	//Size vs. Length
	cout << "//Size vs. Length" << endl;
	int size = 0;
	int length = 0;
	for (int i = 0; i < 255; i++)
	{
		if (c_string[i] == '\0')
		{
			break;
		}
		else
		{
			size += sizeof (char);
			length++;
		}
	}
	cout << "c_string's size == " << size << " bytes" << endl;
	cout << "c_string's length == " << length << " characters" << endl;
	cout << endl << endl;

	//Assigning
	cout << "//Assigning" << endl;
	char c_string_new1[255];		strcpy(c_string_new1, c_string);
	char c_string_new2[255] = "two minus one equals two";
	cout << "c_string_new1 == " << c_string_new1 << endl;
	cout << "c_string_new2 == " << c_string_new2 << endl;
	cout << endl << endl;

	//Concatonation
	cout << "//Concatonation" << endl;
	char c_string_concat[255];		strcpy(c_string_concat, c_string);
	strcat(c_string_concat, c_string_new1);
	strcat(c_string_concat, ", or, "); 
	strcat(c_string_concat, c_string_new2);
	cout << "c_string_concat == " << c_string_concat << endl;
	cout << endl << endl;

	//Indexing
	cout << "//Indexing" << endl;
	cout << "char 'e' in \"" << c_string << "\" is at elements: " << endl;
	for (unsigned int i = 0; i < 255; i++)
	{
		if (c_string[i] == 'e')	cout << i << " " << endl;
	}
	cout << endl << endl;

	//Substrings
	cout << "//Substrings" << endl;
	char * ptr;
	char one[255];
	ptr = strstr(c_string, "one");
	strcpy(one, ptr);
	char plus[255];
	ptr = strstr(c_string, "plus");
	strcpy(plus, ptr);
	cout << "The substring of \"" << c_string << "\" between 0 and 3 is: " << one << endl;
	cout << "The substring of \"" << c_string << "\" between 5 and 9 is: " << plus << endl;
	cout << endl << endl;

	//Compare
	cout << "//Compare" << endl;
	char abc[255] = "abc";
	char xyz[255] = "xyz";
	cout << "\"" << abc << "\" compared to \"" << xyz << "\" equals " << strcmp(abc, xyz) << endl;
	cout << "\"" << xyz << "\" compared to \"" << xyz << "\" equals " << strcmp(xyz, xyz) << endl;
	cout << "\"" << xyz << "\" compared to \"" << abc << "\" equals " << strcmp(xyz, abc) << endl;
	cout << endl << endl;

	//Reversing
	cout << "//Reversing" << endl;
	int x;
	for (x = 0; x < 255; x++)
	{
		if (abc[x] == '\0') break;
	}

	char cba[255];
	int j = 0;
	for (unsigned int i = x; i > 0; i--, j++)
	{
		cba[j] += abc[i - 1];
	}
	cba[x] = '\0';				//VITALLY IMPORTANT
	cout << "\"" << abc << "\"" << " reverse is " << cba << endl;
	cout << endl << endl;

	//C-String to String
	cout << "//C-String to String" << endl;
	string cpp_string;
	unsigned int i = 0;
	for (i = 0; i < 255; i++)
	{
		if (c_string[i] == '\0') break;			//VITALLY IMPORTANT
		else { cpp_string += c_string[i]; }
	}
	cout << "The C-String of \"" << c_string << "\" has been converted to C++ String \"" << cpp_string << "\"" << endl;
	cout << endl << endl;
	return 0;
}