/*
COP 3530 Data Structure and Algorithm Analysis
Homework 1

Feng-Hao Liu
In this assignment, you are going to write a program for the following tasks in a single cpp .le:
•
Task 1: write a function that takes input an integer int n, and returns void. 
The function should print the binary representation of n starting from the most signi.cant bit. 
For example, if the input is 26, then the function should print 11010 on the screen. 
Here you do not need to worry about the problem of over.ow.

•
Task 2: write a function that converts a binary number into a decimal number. 
In particular, the function takes inputs an array int* p and int n, where p[n - 1],p[n - 2],...,p[1],p[0] 
represent the binary digits from the most signi.cant bit. 
Your function returns an integer that is equal to the number p represents. 
You can assume that n = 31 so that there is no over.ow. (Most signi.cant bit means the left most bit.)

•
Task 3: In your main function, you should write some test cases to test your Tasks 1 and 2. The format is .exible.


In the class, we have discussed about the algorithms. Here is a quick recap. Given a decimal number n, we can represent n into the following way:
n = ak2k + ak-12k-1 + ··· + a12+ a0,
where k is roughly log2(n) and all ai’s are binary digits, i.e., either 0 or 1. The binary representation of n should be akak-1 ...a0. If you are given a binary string akak-1 ...a0 (represented by an array), then you can compute n from the above formula directly.
The slightly more non-trivial part is to to compute the binary digits from n. Here we can .rst determine the a0 by using mod 2. (Think about how and why). Then we know:
n/2= ak2k-1 + ak-12k-2 + ··· + a1.
So we can use the same idea to .nd out a1. Proceeding in this way, we can .nd out all the ai’s.
For more information about binary numbers, you can .nd more details from Wikipedia (http: //en.wikipedia.org/wiki/Binary_number).
1
*/


/*
Chris Carl
LOG:
16.11.18, 20:20 - start
16.11.18, 21:08 - task 1 done as I want it, array based
16.11.18, 21:35 - task 2 done as I want it, array based
*/

/*
strategy: keep modding and dividing per step until you hit 0 in the divisor.
fill array left to right.
*/
#pragma once

#include "std_libraries.h"

static int* int_to_base2(const int& n, int& power)
{
	power = 0;
	int* temp = 0;
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
		int i = 0;
		while (i < power)
		{
			temp[i] = x % 2;
			x = x / 2;
			i++;
		}
	}
	return temp;
}

static int* int_to_base10(const int& n, int& power)
{
	power = 0;
	int* temp = 0;
	if (n == 0)
	{
		power++;
		temp = new int[power];
		temp[power] = 0;
	}
	else
	{
		int x = n;
		while (x / 10 != 0)
		{
			power++;
			x = x / 10;
		}
		power++;
		temp = new int[power];

		x = n;
		int i = 0;
		while (i < power)
		{
			temp[i] = x % 10;
			x = x / 10;
			i++;
		}
	}
	return temp;
}

/*
strategy: keep multiplying by power and adding, left to right
*/
static int base2_to_int(int*& a, int& power)
{
	int base10 = 0;
	for (int i = 0; i < power; i++)
	{
		base10 += (int)pow(a[i]* 2, i);
	}
	return base10;
}


static stringstream* print_base(int n[], const int& power)
{
	stringstream* out = new stringstream();

	for (int i = 0; i < power; i++)
	{
		*out << std::to_string(n[power - 1 - i]);
	}
	return out;
}

static stringstream* base_to_stream(int*& base, const int& power, const int& digits)
{
	stringstream* out = new stringstream();
	*out << " " << print_base(base, power);
	if (digits % 2 == 1)
		*out << " ";
	else
		*out << "  ";

	return out;
}

int baseTest()
{
	int size = 10;
	int number = 117;
	int* a = int_to_base2(number, size);
	std::cout << print_base(a, size)->str() << std::endl;
	std::cout << base2_to_int(a, size) << std::endl;
	
	return 0;
}