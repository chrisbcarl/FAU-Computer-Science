#pragma once
#include <sstream>

void exit()
{
	std::cout << "Input a string and the return key to exit the program." << std::endl;
	std::string s = "";
	
	do
	{
		std::cin >> s;
	} while (s == "");
}

void print_string(string s)
{
	cout << s << endl;
}