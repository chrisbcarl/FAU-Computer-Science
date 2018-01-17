///*******************************************************************************
//
//Name: Christopher Carl
//Z#: Z23146703
//Course: Foundations of Computer Science (COP3014)
//Professor: Dr. Lofton Bullard
//Due Date: 16.07.13
//Due Time: 23:59
//Total Points: 100
//Assignment 5:
//
//Description:
//In this assignment, you are going to turn in a single cpp file. Your goal is to compute modular
//exponentiation as we will explain below. Then you are going to practice how to design a function
//that needs to output \two" things.
//Task 1: You need to design a function that takes in inputs three integers a, e, and n. The function
//returns an integer which is supposed to be (a^e mod n). Basically, ae is a to the power of e, and
//\mod" means the modulo operation. Recall in the midterm exam, the operation is %, i.e. a mod b
//can be written as a%b in C/C++ code. The outcome is the remainder of a divided by b.
//One nice property about modulo computation is the following:
//(a + b) mod n = (a mod n) + (b mod n) = ((a mod n) + (b mod n)) mod n;
//(a * b) mod n = ((a mod n) * (b mod n)) mod n:
//This property allows you to compute a^e mod n precisely without worrying about over
//ow. You
//should note that if you first compute ae directly as an integer, then it is very likely that the result
//will be larger than what an int can represent. This is typically called as the problem of over
//ow.
//On the other hand, if you always apply mod n after one multiplication, then you can bring the
//number back to the range of [0; n]. This avoids the problem of over
//ow.
//Task 2: We want to design a function that takes inputs of 5 integers, a, x, b, y, n, and the
//function computes a^x mod n and by mod n. However, as we discussed in the class, a function
//cannot return two integers. To achieve the same effect, we need to apply the technique of pointers
//we learned in the class.
//So the task becomes: design a function a function that takes inputs of 5 integers, a, x, b, y, n,
//and two integer pointers out1 and out2. The function returns void, but needs to write ax to the
//place that out1 points to and similarly by to the place that out2 points to. This has the same eect
//as returning two outputs.
//Task 3: In the main function, the program asks the user to cin 5 numbers a, x, b, y, n. Then
//the program calls the function in Task2 to gure out the answer of ax and by. Then it prints the
//answers. You can design whatever interface you like as long as it gets the spirit! A sample interface
//looks like the following.
//*Give me 5 numbers for a, x, b, y, n.
//*2 2 3 3 5 (This line is input by the user.)
//*The answers are 4 and 2.
//
//
//
//LOG:
//16.07.06, 16:25 - START
//16.07.06, 16:35 - pseudocode phinished
//16.07.06, 16:53 - 1st compile
//16.07.06, 18:15 - going down the recursive rabbit hole
//16.07.06, 19:42 - trying to be clever but really just wasting time
//16.07.06, 20:25 - STOP
//
//16.07.06, 15:46 - START
//16.07.06, 16:12 - documentation added
//16.07.06, 16:12 - formatting for readability/80char rule
//
//
//16.07.06, 16:12 - final edits
//
//
//
//
//BUG:	FOUND:			FIXED:			DESCIRPTION:
//B0001	16.07.06,16:54  -               BUG: All I get are 0's for the outs.
//|       16.07.06,16:59                  Nothing wrong with inputs, I just put a
//|       16.07.06,16:59                  0 for n, causing there to be no remainders.
//|       16.07.06,17:21                  Stuck on the math of it all
//|       16.07.06,20:25                  The math is unreliable. I need to be more 
//|                                       careful and plan it out better before 
//|                                       tackling this again.
//
//
//
//
//|                       16.07.06,17:23  FIXED: 
//|                                       a
//*******************************************************************************/
//
//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <istream>
//#include <string>
//#include <cmath>
//
//int task1(int a, int e, int n);
//void task2(int a, int x, int b, int y, int n, int &out1, int &out2);
//void task2(int a, int x, int b, int y, int n, int* out1, int* out2);
//int mult(int x, int n);
//int exp(int x, int n);
//int hard_exp(int x, int n);
//void simple(int a, int x, int b, int y, int n, int* out1, int* out2);
//
//struct mod {
//	int a, b, x, y, n, out1, out2;
//	int* ptr_out1 = &out1;
//	int* ptr_out2 = &out2;
//};
//
//int main(int args, char* argv[])
//{
//	int ex = 5;
//	std::cout << ex << std::endl << std::endl;
//	std::cout << ex/2 << std::endl << std::endl;
//	std::cout << ex / 2 + (ex / 2 + 1) << std::endl << std::endl;
//
//	int f = 3; 
//	int g = 4;
//	int h = exp(f, g);
//	std::cout << h << std::endl << std::endl;
//
//	f = 3;
//	g = 4;
//	h = mult(f, g);
//	std::cout << h << std::endl << std::endl;
//
//	f = 3;
//	g = 4;
//	h = hard_exp(f, g);
//	std::cout << h << std::endl << std::endl;
//
//
//	std::string user_response = "y";
//	std::string input_filename = "C:\\Users\\ccarl2\\data.txt";
//	std::ifstream in_stream;
//	in_stream.open(input_filename);
//
//	if (in_stream.fail())
//	{
//		std::cout << "Abort motherfucker" << std::endl;
//		std::exit(1);
//	}
//
//	while (user_response == "y" || user_response == "Y")
//	{
//		while (user_response == "y" || user_response == "Y")
//		{
//				
//			
//			mod array_mod[10];
//			unsigned int i = 0;
//			int alpha = 0;
//			int bravo = 0;
//			int* ptr_alpha = &alpha;
//			int* ptr_bravo = &bravo;
//
//			int a, x, b, y, n, out1, out2;
//			int* ptr_out1 = &out1;
//			int* ptr_out2 = &out2;
//
//			std::cout << "Give me 5 numbers for a, x, b, y, n:";
//			while (!in_stream.eof())
//			{
//				in_stream >> a >> x >> b >> y >> n;
//
//				simple(a, x, b, y, n, ptr_alpha, ptr_bravo);
//				std::cout << "Simple answer is " << *ptr_alpha << " " << *ptr_bravo << "." << std::endl << std::endl;
//
//				task2(a, x, b, y, n, out1, out2);
//				//task2(array_mod[i].a, array_mod[i].x, array_mod[i].b, array_mod[i].y, array_mod[i].n, array_mod[i].ptr_out1, array_mod[i].ptr_out2);
//
//				std::cout << "The answers calculated by reference are " << out1 << " " << out2 << "." << std::endl << std::endl;
//				//std::cout << "The answers calculated by pointer are " << *array_mod[i].ptr_out1 << " " << *array_mod[i].ptr_out2 << "." << std::endl << std::endl;
//
//				i++;
//			}
//			
//			
//
//
//			//printf("Give me 5 numbers for a, x, b, y, n:");
//			//scanf("%d%d%d%d%d", &a, &x, &b, &y, &n);
//			//
//			//task2(a, b, x, y, n, out1, out2);
//			//task2(a, b, x, y, n, ptr_out1, ptr_out2);
//
//			//printf("\n\nThe answers calculated by reference are %d %d.\n", out1, out2);
//			//printf("\n\nThe answers calculated by pointer are %d %d.\n", *ptr_out1, *ptr_out2);
//
//			std::cout << "Again? (Y or N): ";
//			std::getline(std::cin, user_response);
//			std::cout << std::endl << std::endl;
//		}
//
//		std::cout << "Operation completed." << std::endl << std::endl;
//		std::cout << "Would you like to do another calculation? (Y or N): ";
//		std::getline(std::cin, user_response);
//		std::cout << std::endl << std::endl;
//	} 
//
//	return 0;
//}
//
//
////pseudocode:
///*
//
//int func a()
//	return a^e mod n
//	//a^e mod n == for all e total += (a mod n)
//
//
//void func b(int a, x, b, y, n,)
//	and two integer pointers out1 and out2.
//	return two int pointers a^x mod n b^y mod n
//	uses func a()
//
//
//func main()
//	uses only func b()
//	Give me 5 numbers for a, x, b, y, n.
//	2 2 3 3 5 (This line is input by the user.)
//	The answers are 4 and 2.
//
//*/
//
//
//
//int mult(int x, int n)
//{
//	int total = x;
//	if (n == 0) return 0;
//	if (n == 1) return x;
//	else total += mult(total, n - 1);
//	return total;
//}
//
//int exp(int x, int n)
//{
//	int total = x;
//	if (n == 0) return 1;
//	if (n == 1) return x;
//	else total *= exp(total, n - 1);
//	return total;
//}
//
//int hard_exp(int x, int n)
//{
//	int total = x;
//	if (n == 0) return 1;
//	if (n == 1) return x;
//	else total = mult(exp(total, n - 1), n - 1);
//	return total;
//}
//
//
//void simple(int a, int x, int b, int y, int n, int* out1, int* out2)
//{
//	//* is the dereference operator, meaning "modify the value"
//	//since the pointers pointers have values of addresses, the values 
//	//are reached through dereferencing to modify the value.
//	
//	*out1 = static_cast<int>(pow(a, x)) % n;
//	*out2 = static_cast<int>(pow(b, y)) % n;
//}
//
//
//int add_mod(int a, int b, int n)
//{
//	return (a % n) + (b % n);
//}
//
//int mult_mod(int a, int b, int n)
//{
//	return ((a % n) * (b % n)) % n;
//}
//
////implement fermat little theorum
//
//int task1(int a, int x, int n)
//{
//	int a1 = a;
//	int a2 = a;
//	if (x % 2 == 0)
//	{
//		a1 = pow(a, x / 2);
//		a2 = a1;
//	}
//	else
//	{
//		a1 = pow(a, x / 2);
//		a2 = pow(a, x / 2 + 1);
//	}
//	return mult_mod(a1, a2, n);
//}
//
//void task2(int a, int x, int b, int y, int n, int &out1, int &out2)
//{
//	//& is the address operator, meaning "modify the value"
//	//since the addresses were passed formally, the values are modified
//	out1 = task1(a, x, n);
//	out2 = task1(b, y, n);
//}
//
//void task2(int a, int x, int b, int y, int n, int* out1, int* out2)
//{
//	//* is the dereference operator, meaning "modify the value"
//	//since the pointers pointers have values of addresses, the values 
//	//are reached through dereferencing to modify the value.
//	*out1 = task1(a, x, n);
//	*out2 = task1(b, y, n);
//}
