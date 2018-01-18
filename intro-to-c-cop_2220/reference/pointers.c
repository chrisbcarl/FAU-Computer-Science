//#define _CRT_SECURE_NO_WARNINGS
//#include "stdio.h"
//
////function prototypes
//void add_two_numbers(int a, int b);
//void pointerfunc(int* a, int* b);
//void printarray(int arr[], int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("one example at %d == %d\n", i, arr[i]);
//	}
//}
//printarray(arr, size);	//put inside main
//
//#define GLOBAL_SIZE 10000
//
//int main()
//{
//	//declare
//	char some_name[12] = { '1', 'b', '!' };
//	int another[] = { 6, 3, 2,7,3,3,256, 8 };
//	double numbers[GLOBAL_SIZE];
//
//	//n-th number		   1, 2, 3, 4, 5
//	int one_example[5] = { 8, 3, 7, 2, 6 };
//	//i-th element         0, 1, 2, 3, 4
//
//	//what is the 5th nuimber? 6
//	//what is the number at index
//	//	3? 2
//	//what is the number at index -1? undef
//
//	
//	one_example[3] = 69;
//
//	printf("\n\n");
//	printarray(one_example, 5);
//
//	return 0;
//
//
//
//
//
//	int variable = 6;
//	int container = 9;
//	int* pointer = &variable;
//	int* arrow = &container;
//
//	//values
//	printf("value of variable = %d\n", variable);
//	printf("value of variable = %d\n", *pointer);
//
//	printf("\n\n");
//
//	//addresses
//	printf("address of variable = %X\n", &variable);
//	printf("address of variable = %X\n", pointer);
//	
//
//	//regular functions without pointers
//	add_two_numbers(variable, container);
//	add_two_numbers(*pointer, *arrow);
//	printf("\n\n");
//	//pointer functions
//	pointerfunc(&variable, &container);
//	pointerfunc(pointer, arrow);
//
//
//
//
//}
//
////function definitions
//
//void add_two_numbers(int a, int b)
//{
//	int c = a + b;
//	printf("add_two_numbers without pointers == %d\n", c);
//}
//void pointerfunc(int* a, int* b) 
//{
//	int c = *a + *b;
//	printf("add_two_numbers WITH    pointers == %d\n", c);
//}