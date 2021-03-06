/*******************************************************************************

Name: Christopher Carl
Z#: Z23146703
Course: Introduction to C (COP2200)
Professor: Dr. Feng-Hao Liu
Due Date: 16.08.03
Due Time: 23:59
Total Points: 100
Assignment 7: Recursion

DESCRIPTION:
In this assignment, you are going to turn in a single cpp le. Your goal is to whether an array
is symmetric in the following two ways.
An array is symmetric if the array has the same values either reading from the top or from
the end. For example, [1; 2; 3; 2; 1] is symmetric, [1; 2; 2; 1] is symmetric, but [1; 3; 2] is not. In the
following, your goal is to determine whether an array is symmetric using two dierent methods.
Task 1: In this task, you are going to use the recursive method. More specically, you are going
to write a boolean function that takes inputs a pointer int p, int a, b. Here p points to an array.
The function returns true if the sub-array fp[a]; p[a + 1]; : : : ; p[b]g is symmetric. Use the recursive
method to complete the code. Here are some observations for hints:
 What is the base case, or what are the base cases? If a == b, then the sub-array p[a] is
symmetric for sure. If b == a + 1, then it is easy to determine whether fp[a]; p[a + 1]g is
symmetric.
 For the recursion relation, consider whether p[a] ?=
p[b]. If they are not equal, then the array
is denitely not symmetric. Otherwise, you only need to consider whether the remaining sub
array is symmetric. This is basically the recursive method.
Task 2: In this task, you are going to design another boolean function that takes inputs a pointer
int p, int n, where n is the size of the array p points to. The function determines whether the
array is symmetric or not, but this time, you don't use the recursive method. (Notice that the
functions in Tasks 1 and 2 take in dierent inputs.) Here you are going to use one loop (ei-
ther for or while). Recall that the way how we dene whether an array is symmetric: the values
are the same, whether you read from the top or from the end. Use a for loop to implement the idea.
Task 3: In the main function, you are going to write your main function. In the main function, you
are going to declare an array of arbitrary values of your own choice. Then call the two functions
to determine whether the array is symmetric. The style isexible.

LOG:

16.07.27.11:45 - START
16.07.27.11:55 - pseudo done, debugging iterative
16.07.27.12:05 - just reduced iterative code in half
16.07.27.12:15 - debugging recursive
16.07.27.12:30 - coding
16.07.27.12:42 - STOP


16.07.28.19:32 - START
16.07.28.19:48 - DONE
16.07.28.20:19 - supplemental functions and testing.


16.07.28.20:19 - straight up started building this into a oop procedural automated thing.
16.07.28.22:50 - satisfied with the results.


BUG:	FOUND:			FIXED:			DESCIRPTION:
-       -               -               -


PSEUDOCODE:
<template><class type_a>
bool symetric_r (type_a *p, int a, int b)


//p points to an array
//a = start of array, or starting element
//b = ending element



if a == b return true

else
{
if a > b, a = temp, a = b, b = temp;
if b = a + 1 return (p[a] == p[b])
return (p[a]==p[b]) && symetric(p, a+1, b-1)
}

6
012345
abccba

7
0123456
abcdcba

n = 6
call stack:
symetric_r(p, 0, 5)
↵return (p[0]==p[5]) && symetric_r(p, 1, 4)
↵return (p[1]==p[4]) && symetric_r(p, 2, 3)
↵return (p[2]==p[3])

resolved call stack:
symetric_r(p, 0, 5)
↵return (p[0]==p[5]) && symetric_r(p, 1, 4)
↵return (p[1]==p[4]) && symetric_r(p, 2, 3)
↵return true


symetric_r(p, 0, 5)
↵return (p[0]==p[5]) && symetric_r(p, 1, 4)
↵return true && true

symetric_r(p, 0, 5)
↵return true && true

true


6
012345
abccba

7
0123456
abcdcba

bool symetric_i (type_a *p, int n)
bool isSymetric;

if n%2 == 0
for i = 0; i < n/2 + 0, i++
isSymetric = (p[i] == p[(n-1)-i]);

n = 6
n/2 = 3
i = 0       pi = 0  p(n-1)-i = 5
i = 1       pi = 1  p(n-1)-i = 4
i = 2       pi = 2  p(n-1)-i = 3


if n%2 == 1
for i = 0; i < n/2 + 1, i++
isSymetric = (p[i] == p[(n-1)-i]);
return isSymetric

n = 7
n/2 + 1 = 4
i = 0       pi = 0  p(n-1)-i = 7
i = 1       pi = 1  p(n-1)-i = 6
i = 2       pi = 2  p(n-1)-i = 5
i = 3       pi = 3  p(n-1)-i = 4



bool symetric_i (type_a *p, int n)
bool isSymetric;
for i = 0; i < n/2 + n%2, i++
isSymetric = (p[i] == p[(n-1)-i]);

*******************************************************************************/

#include <iostream>
#include <time.h>

template<class type_a>
struct Arr
{
	type_a* p;
	int size;
};

//p points to an array
//a = start of array, or starting element
//b = ending element
template<class type_a>
bool symetric_r(const Arr<type_a>& arr, int a, int b)
{
	if (a == b) return true;

	else
	{
		if (a > b)
		{
			int temp = 0;
			a = temp;
			a = b;
			b = temp;
		}
		if (b == a + 1) return (arr.p[a] == arr.p[b]);
		return (arr.p[a] == arr.p[b]) && symetric_r(arr, a + 1, b - 1);
	}
}


//p points to an array
//n is the size
template<class type_a>
bool symetric_i(const Arr<type_a>& arr)
{
	for (int i = 0; i < (arr.size / 2 + arr.size % 2); i++)
		if (arr.p[i] != arr.p[(arr.size - 1) - i]) return false;
	return true;
}

void initialize(Arr<char>& arr)
{
	arr.size = rand() % 5 + 3;
	arr.p = new char[arr.size];
	for (int i = 0; i < arr.size; i++) {
		arr.p[i] = static_cast<char>(rand() % 126 + 33);
	}
}


void initialize(Arr<int>& arr)
{
	arr.size = rand() % 5 + 3;
	arr.p = new int[arr.size];
	for (int i = 0; i < arr.size; i++) {
		arr.p[i] = rand() % 3 + 1;
	}
}


template<class type_a>
void initialize(Arr<type_a>& arr)
{
	arr.size = rand() % 3 + 1;
	arr.p = new type_a[arr.size];
	for (int i = 0; i < arr.size; i++) {
		arr.p[i] == rand() % 3 + 1;
	}
}


void initialize(Arr<int>& arr, int n)
{
	arr.size = n;
	arr.p = new int[arr.size];
	std::cout << "Please insert " << arr.size << " ints into this array." << std::endl;
	for (int i = 0; i < arr.size; i++) {
		std::cin >> arr.p[i];
	}
}


void initialize(Arr<char>& arr, int n)
{
	arr.size = n;
	arr.p = new char[arr.size];
	std::cout << "Please insert " << arr.size << " chars into this array." << std::endl;
	for (int i = 0; i < arr.size; i++) {
		std::cin >> arr.p[i];
	}
}

template<class type_a>
void initialize(Arr<type_a>& arr, int n)
{
	arr.size = n;
	arr.p = new type_a[arr.size];
	std::cout << "Please insert " << arr.size << " elements into this array." << std::endl;
	for (int i = 0; i < arr.size; i++) {
		std::cin >> arr.p[i];
	}
}


template<class type_a>
void print(const Arr<type_a>& arr)
{
	std::cout << "[ ";
	for (int i = 0; i < arr.size; i++)
		std::cout << arr.p[i] << " ";
	std::cout << "]";
}


template<class type_a>
void process(const Arr<type_a>& arr)
{
	std::cout << arr.size << " elements array: ";
	print(arr); std::cout << std::endl;
	std::cout << " is " << symetric_r(arr, 0, arr.size - 1)
		<< " recursively symmetrical, and "
		<< symetric_i(arr) << " iteratively symmetrical." << std::endl;

}

template<>
void process(const Arr<int>& arr)
{
	std::cout << arr.size << " ints array: ";
	print(arr); std::cout << std::endl;
	std::cout << " is " << symetric_r(arr, 0, arr.size - 1)
		<< " recursively symmetrical, and "
		<< symetric_i(arr) << " iteratively symmetrical." << std::endl;

}

template<>
void process(const Arr<char>& arr)
{
	std::cout << arr.size << " chars array: ";
	print(arr); std::cout << std::endl;
	std::cout << " is " << symetric_r(arr, 0, arr.size - 1)
		<< " recursively symmetrical, and "
		<< symetric_i(arr) << " iteratively symmetrical." << std::endl;

}


int main(int argc, const char * argv[]) {

	srand(unsigned(time(NULL)));

	int even = 6;
	int odd = 7;
	
	Arr<char> chars_even; 
	Arr<char> chars_odd; 
	Arr<char> chars_rand;
	
	Arr<int> ints_even;
	Arr<int> ints_odd;
	Arr<int> ints_rand;

	initialize(chars_even, even); initialize(chars_odd, odd); initialize(chars_rand);
	initialize(ints_even, even); initialize(ints_odd, odd); initialize(ints_rand);
	

	process(chars_even); process(chars_odd); process(chars_rand); 
	process(ints_even); process(ints_odd); process(ints_rand);


	delete[] chars_even.p, chars_odd.p, chars_rand.p, ints_even.p, ints_odd.p, ints_rand.p;


	return 0;
}
