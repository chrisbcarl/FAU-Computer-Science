#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctype.h>

using namespace std;

void input(const string & input_file, string & s)	
{
	ifstream in;
	in.open(input_file);

	if (in.fail())
	{
		cout << "INPUT FILE NOT OPENED" << endl;
		exit(1);
	}

	while (!in.eof())
	{
		getline(in, s);
	}

	in.close();

}

void output(const int & words, int frequency[])
{
	cout << words << " words" << endl;
	char c = 'a';
	for (unsigned int i = 0; i < 26; i++)
	{
		cout << frequency[i] << " " << c << endl;	
		c++;
	}
}

//a is letter 97
//A is letter 65,
//tolower(A) = a
//indexofLetter makes everything correspond to the alphabet exactly
int indexOfLetter(char c)
{
	return tolower(c) - 97;
}

void analyzeFrequency(const string & s, int frequency[])
{
	int index = 0;
	for (unsigned int i = 0; i < s.length(); i++)
	{
		index = indexOfLetter(s[i]);
		frequency[index]++;
	}
}

void analyzeWords(const string s, int & words)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (!isalpha(s[i])) words++;
	}

	// or

	words = 0;
	string field;
	istringstream input;
	input.str(s);

	while (getline(input, field, ' '))
	{
		words++;
	}

	// or
	words = 0;

	istringstream iss;
	iss.str(s);

	int count = 0;
	string sss;

	while (!iss.eof())
	{
		iss >> sss;
		words++;
	}
}

void analyzeWords2(const string & input_file, string & s)
{

}

void charword_freq()
{
	int words = 0;

	int frequency[] = {0,0,0,0,0,
					   0,0,0,0,0,
					   0,0,0,0,0,
					   0,0,0,0,0,
					   0,0,0,0,0,
					   0};
	string file = "mytext.dat";
	string data = "";

	input(file, data);
	analyzeFrequency(data, frequency);
	analyzeWords(data, words);
	output(words, frequency);
	std::cout << data << std::endl;

}