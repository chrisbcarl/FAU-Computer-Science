//
//  main.cpp
//  IntroToC
//
//  Created by Christopher Carl on 7/29/16.
//  Copyright © 2016 Christopher Carl. All rights reserved.
//


/*

 Solutions to problems presented in class;
	1D array, write function find minimum, find summation, find average
	HW6 task 1, pass two arrays to a function
	2D arrays, ask cout the first column, or column i, or diagonal, product diagonal, all positive

*/
#include <iostream>

using namespace std;

void print_array(int *A, int n);
int array_minimum(int *A, int n);
int array_maximum(int *A, int n);
int array_summation(int *A, int n);
int array_average(int *A, int n);
int array_mode(int *A, int n);
int array_median(int *A, int n);
void array_bubble_sort(int *A, int n);
void print_twoD(int **A, int n, int m);
void print_twoD_column(int **A, int n, int m);
void print_twoD_diagonalA(int **A, int n, int m);
void print_twoD_diagonalB(int **A, int n, int m);


//A - defines where an integer array starts in memory
//n - size of integer array
//returns nothing
void print_array(int *A, int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "]" << endl;
}



//A - defines where an integer array starts in memory
//n - size of integer array
//returns the minimum value in the array
int array_minimum(int *A, int n)
{
    int minimum = A[0];
    for (int i = 0; i < n; i++) {
        if (A[i] < minimum) minimum = A[i];
    }
    return minimum;
}



//A - defines where an integer array starts in memory
//n - size of integer array
//returns the maximum value in the array
int array_maximum(int *A, int n)
{
    int maximum = A[0];
    for (int i = 0; i < n; i++) {
        if (A[i] > maximum) maximum = A[i];
    }
    return maximum;
}



//A - defines where an integer array starts in memory
//n - size of integer array
//returns the total of all its elements
int array_summation(int *A, int n)
{
    int summation = 0;
    for (int i = 0; i < n; i++) {
        summation = summation + A[i];
    }
    return summation;
}



//A - defines where an integer array starts in memory
//n - size of integer array
//returns the average value in the array
int array_average(int *A, int n)
{
    int summation = 0;
    for (int i = 0; i < n; i++) {
        summation = summation + A[i];
    }
    int average = summation / n;
    return average;
}




//A - defines where an integer array starts in memory
//n - size of integer array
//returns the middle value in the array
int array_median(int *A, int n)
{
    //check if sorted.
    
    int median = 0;
    if (n%2 == 0) median = (A[n/2 - 1] + A[n/2]) / 2;
    if (n%2 == 1) median = A[n/2];
    return median;
}


//A - defines where an array of integer arrays starts in memory
//n - # of rows
//m - # of columns
//returns nothing
void print_twoD(int **A, int n, int m)
{
    for (int i = 0; i < n; i ++) {
        cout << "[ ";
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "]" << endl;
    }
}



//A - defines where an array of integer arrays starts in memory
//n - # of rows
//m - specifies which column to print
//returns nothing
void print_twoD_column(int **A, int n, int m)
{
    cout << "[ ";
    for (int i = 0; i < n; i ++) {
        cout << A[i][m-1] << " ";
    }
    cout << " ]" << endl;
}



//A - defines where an array of integer arrays starts in memory
//n - # of rows
//m - # of columns
//returns nothing
void print_twoD_diagonalA(int **A, int n, int m)
{
    if (n == m)
    {
        cout << "[ ";
        for (int i = 0; i < n; i ++) {
            cout << A[i][i] << " ";
        }
        cout << "]" << endl;
    }
    else cout << "Diagonal is impossible." << endl;
}



//A - defines where an array of integer arrays starts in memory
//n - # of rows
//m - # of columns
//returns nothing
void print_twoD_diagonalB(int **A, int n, int m)
{
    if (n == m)
    {
        cout << "[ ";
        int j = n - 1;
        for (int i = 0; i < n; i++, j--) {
            cout << A[i][j] << " ";
        }
        cout << "]" << endl;
    }
    else cout << "Diagonal is impossible." << endl;
}



int main(int argc, const char * argv[]) {
    
    int size = 6;
    
    int temp[6] = {6, 123, 45, 69, 3, 17};

    int temp2[6][6] = { {0, 1, 2, 3, 4, 5},
                        {5, 6, 7, 8, 9, 10},
                        {8, 7, 6, 5, 4, 6},
                        {3, 2, 1, 0, 1, -1},
                        {2, 3, 4, 5, 6, -3},
                        {-1, -2, -3, -4, -5, -6}};
    
    int *oneD = new int[size];
    int **twoD = new int*[size];
    
    for (int i = 0; i < size; i++) {
        oneD[i] = temp[i];
    }
    
    for (int i = 0; i < size; i++) {
        twoD[i] = new int[size];
        for (int j = 0; j < size; j++) {
            twoD[i][j] = temp2[i][j];
        }
    }
    
    cout << "1D Array:" << endl;
    print_array(oneD, size);
    array_bubble_sort(oneD, size);
    print_array(oneD, size);
    cout << "\t" << "minimum = " << array_minimum(oneD, size) << endl;
    cout << "\t" << "maximimum = " << array_maximum(oneD, size) << endl;
    cout << "\t" << "summation = " << array_summation(oneD, size) << endl;
    cout << "\t" << "average = " << array_average(oneD, size) << endl;
    cout << "\t" << "median = " << array_median(oneD, size) << endl;
    
    cout << endl << endl;
    
    cout << "2D Array:" << endl;
    print_twoD(twoD, size, size);
    cout << "\t" << "column " << size << " = "; print_twoD_column(twoD, size, size);
    cout << "\t" << "diagonal A = "; print_twoD_diagonalA(twoD, size, size);
    cout << "\t" << "diagonal B = "; print_twoD_diagonalB(twoD, size, size);
    
    return 0;
}
