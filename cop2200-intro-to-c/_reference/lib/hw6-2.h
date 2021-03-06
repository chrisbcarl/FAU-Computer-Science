/*******************************************************************************

Name: Christopher Carl
Z#: Z23146703
Course: Introduction to C (COP2200)
Professor: Dr. Feng-Hao Liu
Due Date: 16.07.26
Due Time: 23:59
Total Points: 100
Assignment 6: Matrix Calculator

DESCRIPTION:
In this assignment, you are going to turn in a single cpp ?le. Your goal is to compute the following two basic operations in linear algebra: (1) inner products, and (2) matrix multiplications.
Task 1: In this task, you are going to write a function that computes inner product of two vectors (represented by arrays). In particular, the function takes four inputs: int * a, int n, int * b, int m, and the function returns an integer which is supposed to be their inner product. Here a is a pointer to the ?rst array (vector), and n is its dimension; b is another pointer to the second array (vector), and m is its dimension. Here you need to consider the case where n and m do not match. In this case, the inner product is not well-de?ned. For those who don�t know inner products, look at �http://en.wikipedia.org/wiki/Dot_ product�.
Task 2: In this task, you are going to write a function that computes matrix multiplications. In particular, the function takes in inputs int ** A, int n1, int m1, int ** B, int n2, int m2, where A is a pointer to a 2D array with dimension n1�m1, and B is a pointer to a 2D array with dimension n2 � m2. Your goal is to compute the matrix C = A � B. You need to consider a case if the dimensions do not match, i.e. m1 6= n2. In this case, the matrix multiplication is not well-de?ned. The function needs to return the matrix C and its dimension. However, it cannot return three things per time. So we need to use our trick of pointers. That means, the function takes in additional input int ** C, int * n3, int * m3. You should write the output matrix to C (the place where C points to), and the dimension to n3 and m3 (i.e. the places where they point to). For those who don�t know matrix multiplications, look at �http://www.mathsisfun.com/ algebra/matrix-multiplying.html�, or �http://en.wikipedia.org/wiki/Matrix_multiplication�.
Task 3: In this task, you are going to write things in your main function. You need to declare two vectors (e.g. 1-D arrays) and two matrices (e.g. 2-D arrays) of arbitrary dimensions and values of your choice. You can either let the user cin the values or just initialize them in the code. Then you need to call the functions in Tasks 1 and 2, and cout the outcomes. The format and style are ?exible


LOG:
16.07.19, 04:19 - START
16.07.19, 04:57 - pseudocode done
16.07.19, 05:40 - ~5th compile, implemented printing vectors
16.07.19, 06:17 - ~20th compile, every function returns something without crashing
16.07.19, 07:07 - STOP

16.07.25, 19:37 - START
16.07.25, 21:17 - DONE


BUG:	FOUND:			FIXED:			DESCIRPTION:
B0001	16.07.19,06:17  -               BUG: dot product produces only zeros
|                       16.07.19,06:27  FIX: Copy/Paste causes me to overlook
|                                            little things like what I'm 
|                                            incrementing or not.
B0002   16.07.19,06:17  -               BUG: dot product produces only zeros
|                                            in matrix calculations.
|       16.07.19,06:17  -               The first dot product calculates correctly
|                                            while the others are still 
|                                            uninitialized.
|       16.07.25,19:07  -               Now the dot products approach infinity
|                       16.07.25,20:42  FIX: My parameter call to task1 was switched.
B0003   16.07.25,20:45  -               BUG: UI doesn't print any results
|                       16.07.25,21:00  FIX: I never updated i3 or j3.


PSEUDOCODE:
int task1(int* a, int n, int* b, int m) // returns inner product
a - pointer to vector, n dimensions,
b - pointer to another vector, m dimensions
//don't consider case where n!=m. In that case, wrong.
//dot product = a1b1 + a2b2 + ... + anbn


void task2(int** A, int n1, int m1, int** B, int n2, int m2, int** C, int n3, int m3)
A - 2d array with dimension n1xm1,
B - 2d array with dimension n2xm2
//consider n/m1!=n/m2. defined only if the number of columns in A is equal to the number of rows in B,
return Matrix C
//matrix multiplication (AB)ij= sum(to m, from k = 1, Aik,Bkj)

int main
two vectors (1D) matricies
two matricies (2D) arrays
cout the results


//dot product
it seems:
for every single item in a row, multiply that BY every single item in a column, and store that
so, if A = {a,b,c}, and B = {d, e, f}
A.B = {ad + be + cf}
for each element e in A
for each element n in B
sum += A[n]*B[n]
return sum


//multiplication
A has i rows, j columns.
B has i2 rows, j2 columns.
j === i2

A is an i*j matrix
B is an n*m matrix
if j==n, declare new array C as an i*m matrix.
for every row i in C
for every column m in C
C[i, m] = A[i].B[m]

C there therefore

C has NxA
D has AxM
E will have NxM

ex) 2*3 * 3*2 == 2*2
ex) 1*2 * 3*2 == CANT DO


ex)

A =
[a00, a01, a02]
[a10, a11, a12]

B =
[b00, b01]
[b10, b11]
[b20, b21]

AB =
[ai0.bj0, ai0.bj1]
[ai1.bj0, ai1.bj1]
*******************************************************************************/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <ios>


using namespace std;

//n is the size of a, m is the size of B
int task1(int* a, int n, int* b, int m) // returns inner product
{
	if (n != m) return -1;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[i];
	}
	return sum;
}

void task2(int** A, int i1, int j1, int** B, int i2, int j2, int** &C, int &i3, int &j3)
{
	
	//for each element x in matrix C, row i, column j
	//	element x = A row i.B column j

	//matrix C has rows = A
	//matrix B has columns = B

	//for each row of C

	if (j1 != i2)
	{
		i3 = 0;
		j3 = 0;
		return;
	}

	else
	{
		i3 = i1;
		j3 = j2;


		C = new int*[i1];

		for (int x = 0; x < i1; x++)
		{
			int* Celement = new int[j2];

			//for each row, column of C
			for (int y = 0; y < j2; y++)
			{
				int* Bcolumn = new int[i2];

				//create a temp array composed of all of B's column
				for (int n = 0; n < i2; n++)
				{
					Bcolumn[n] = B[n][y];
				}
				Celement[y] = task1(A[x], j1, Bcolumn, i2);
			}
			C[x] = Celement;
		}
	}
}


void initialize(int* A, int j)
{
	for (int i = 0; i < j; i++)
	{
		A[i] = rand() % 10 + 1; // between 1 and 10
	}
}

void initialize(int** A, int i, int j)
{
	for (int x = 0; x < i; x++)
	{
		int* column;
		column = new int[j];
		for (int y = 0; y < j; y++)
		{
			column[y] = rand() % 10 + 1; // between 1 and 10
		}
		A[x] = column;
	}
}

void print(int* A, int j)
{
	cout << "[";
	for (int i = 0; i < j; i++)
	{
		if( i < j-1) cout << A[i] << " ";
		else cout << A[i];;
	}
	cout << "]" << endl;
}


void print(int** A, int i, int j)
{
	for (int x = 0; x < i; x++)
	{
		print(A[x], j);
	}
}


int main3()
{
	string user_response = "y";
	srand(static_cast<unsigned int>(time(NULL)));
	do
	{
		//INITIALIZE 2 VECTORS, 3 MATRICIES
		int vector1Size = rand() % 4 + 1; // between 1 and 4;
		int vector2Size = rand() % 4 + 1; // between 1 and 4;

		int matrix1rows = rand() % 4 + 1; // between 2 and 5;
		int matrix1columns = rand() % 3 + 2; // between 3 and 4;
		int matrix2rows = rand() % 3 + 2; // between 3 and 4;
		int matrix2columns = rand() % 4 + 1; // between 2 and 5;
		int matrix3rows;
		int matrix3columns;

		int* vector1; vector1 = new int[vector1Size];
		int* vector2; vector2 = new int[vector2Size];

		int** matrix1; matrix1 = new int*[matrix1rows];
		int** matrix2; matrix2 = new int*[matrix2rows];
		int** matrix3 = 0;

		cout << "VECTOR:" << endl;
		initialize(vector1, vector1Size);
		initialize(vector2, vector2Size);
		cout << "vector1: " << 1 << "x" << vector1Size << endl;
		print(vector1, vector1Size);
		cout << "vector2: " << 1 << "x" << vector2Size << endl;
		print(vector2, vector2Size);

		cout << endl;

		int dot = task1(vector1, vector1Size, vector2, vector2Size);
		cout << "Dot product scalar is: ";
		if (dot != -1) cout << dot <<endl;
		else cout << "UNDEFINED" << endl;

		cout << endl << "---------------" << endl;

		cout << "MATRIX:" << endl;
		initialize(matrix1, matrix1rows, matrix1columns);
		initialize(matrix2, matrix2rows, matrix2columns);
		cout << "matrix1: " << matrix1rows << "x" << matrix1columns << endl;
		print(matrix1, matrix1rows, matrix1columns);

		cout << "matrix1: " << matrix2rows << "x" << matrix2columns << endl;
		print(matrix2, matrix2rows, matrix2columns);

		cout << endl;

		task2(matrix1, matrix1rows, matrix1columns, matrix2, matrix2rows, matrix2columns, matrix3, matrix3rows, matrix3columns);

		cout << "Matrix product is: ";
		if (matrix3)
		{
			cout << "matrix3: " << matrix3rows << "x" << matrix3columns << endl;
			print(matrix3, matrix3rows, matrix3columns);
		}
		else
		{
			cout << "UNDEFINED" << endl;
		}
		
		cout << "Would you like to do another calculation (Y or N): ";
		getline(cin, user_response);
		cout << endl << endl;
	} while (user_response == "y" || user_response == "Y");

	return 0;
}
