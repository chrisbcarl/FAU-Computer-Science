#include <iostream>
#include <vector>
#include <time.h>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;


int Step1()
{
	srand(static_cast<unsigned>(time(NULL)));

	vector<char> line; cout << line.size() << endl;
	vector<int> Ages; 
	for (int i = 0; i < 20; i++)
	{
		Ages.push_back(20);
		cout << Ages[i] << endl;
	}

	vector<char> sentence;
	for (int i = 0; i < 60; i++)
	{
		sentence.push_back(rand() % 256 + 33);
		cout << sentence[i];
	}
	cout << sentence.size() << endl;

	vector<vector<char>> page;
	for (int i = 0; i < 50; i++)
	{			
		for (int j  = 0; j < 60; j++)
		{
			cout << sentence[j];
		}
		page.push_back(sentence);
	}

	cout << page.size() << endl;

	vector<vector<vector<char>>> book;

	vector<char>::iterator sent2It = sentence.begin();

	return 0;
}