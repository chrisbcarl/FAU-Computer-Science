#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <vector>
#include <list>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::istream;
using std::ifstream;
using std::ostream;
using std::ofstream;
using std::stringstream;

using std::string;

using std::vector;
using std::list;


void swap(int& x, int& y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}

int exponent(int x, const int& y)
{
	int c = x;
	if (y == 0)
	{
		return 1;
	}
	else
	{
		int i = 1;
		while (i < y)
		{
			x *= c;
			i++;
		}
		return x;
	}
}

static int* int_to_base2(const int& n, int& power)
{
	power = 0;
	int* temp = new int;
	if (n == 0)
	{
		power++;
		temp = new int[power];
		temp[power] = 0;
	}
	else
	{
		int x = n;
		while (x / 2 != 0)
		{
			power++;
			x = x / 2;
		}
		power++;
		temp = new int[power];

		x = n;
		int i = power - 1;
		while (i > -1)
		{
			temp[i--] = x % 2;
			x = x / 2;
		}
	}
	return temp;
}