#pragma once
#include <iostream>

void demo_pointer()
{
	int i = 100;
	char c = '1';
	std::cout << "i (int) == " << i << std::endl;
	std::cout << "c (char) == " << c << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "(char) i == " << (char)i << std::endl;
	std::cout << "(int) c == " << (int)c << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "toupper(i) == " << toupper(i) << std::endl;
	std::cout << "toupper(c) == " << toupper(c) << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "(char) toupper(i) == " << (char)toupper(i) << std::endl;
	std::cout << "(char) toupper(c) == " << (char)toupper(c) << std::endl;
	std::cout << std::endl << std::endl;
}