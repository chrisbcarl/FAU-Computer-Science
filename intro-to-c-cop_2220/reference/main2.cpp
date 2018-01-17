//
//  main.cpp
//  IntroToC
//
//  Created by Christopher Carl on 7/26/16.
//  Copyright © 2016 Christopher Carl. All rights reserved.
//

/*
 
 Intro to C:
 
 Data Types - int, double, char
 
 Operations - unary, binary ops
 
 Control Statements - if/else, for, while, switch, break
 
 Output and Input - stdin, stdout
 
 Data Structures - arrays, dynamic arrays, structs, classes
 
 Functions - return, pass by value, reference, pointer
 
 Recursive functions - simple
 
 Solutions to problems presented in class;
	1D array, write function find minimum, find summation, find average
	HW6 task 1, pass two arrays to a function
	2D arrays, ask cout the first column, or column i, or diagonal, product diagonal, all positive
 
	recursive tracing, rather than doing.
 
 
 int f (int n, int i)
 {
 cout << "n = " << n << "\t" << "i = "i << endl;
 if (n==1) return i
 return f(n-1, i+1);
 }
 
 
 generating dynamic arrays
 
 
 minimum value of an array
 store the first element as a sentinel
 for each element in the array, compare it to the sentinel. if smaller/larger, store that as the sentinel
 
 
 k < n computes jth column of B
 cij += aik bkj
 
 
 

 
 */


#include <iostream>


#include "datatypes.hpp"
#include "operations.hpp"

using namespace std;

int main2(int argc, const char * argv[]) {
    
    datatypes1();
    
    int *ArrayTwo = new int[10];
    int ArrayOne[10] = {6, 123, 45, 69, 3, 17};
    cout << "ArrayOne = " << ArrayOne << endl;
    cout << "\t" << "ELEMENT:" << "\t" << "ADDRESS:" << "\t\t\t" << "VALUE:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "\t" << i << "\t\t" << ArrayOne + i << "\t\t" << ArrayOne[i] << endl;
    }
    
    ArrayTwo = ArrayOne;
    
    int size = 10;
    int *ArrayThree;
    ArrayTwo = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Element " << i << " of ArrayTwo = "; cin >> ArrayTwo[i];
    }
    
    cout << "ArrayTwo = " << ArrayTwo << endl;
    for (int i = 0; i < size; i++) {
        cout << "\t" << "ArrayTwo + i = " << ArrayTwo + i << "\t" << " value = " << ArrayTwo[i] << endl;
    }
    
    
    int TwoDArrayOne[5][5] = {  {0, 1, 2, 3, 4},
                                {5, 6, 7, 8, 9},
                                {8, 7, 6, 5, 4},
                                {3, 2, 1, 0, 1},
                                {2, 3, 4, 5, 6} };
    cout << "TwoDArrayOne = " << TwoDArrayOne << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\t" << "TwoDArrayOne row[" << i << "] = " << TwoDArrayOne[i] << endl;
        for (int j = 0; j < 5; j++) {
            cout << "\t" << "TwoDArrayOne[" << i << "][" << j << "] = " << TwoDArrayOne[i] + j << "\t" << " = " << TwoDArrayOne[i][j] << endl;
        }
    }
    
    return 0;
}
