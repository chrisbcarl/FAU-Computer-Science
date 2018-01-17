//
//  main.cpp
//  HW7_first
//
//  Created by Christopher Carl on 7/27/16.
//  Copyright © 2016 Christopher Carl. All rights reserved.
//

#include <iostream>
#include <time.h>

using namespace std;

//p points to an array
//a = start of array, or starting element
//b = ending element
bool recursive(int *p, int a, int b)
{
    if (a == b) return true;        //base case 1, where the array is only one element
    if (b == a + 1)
        return (p[a] == p[b]);      //base case 2, where the array is only two elements
    else
        /*
         
         YOUR CODE HERE:
         
         return (is the end of the array 'p' at element 'a' equal to the end of the array 'p' at element 'b')
                && (recursive(p, "your n-1 or something here", "your n-1 or something here" ))
         
         */
        return false;                //get rid of this once you're done writing your own code.
}


//p points to an array
//n is the size
bool iterative(int *p, int n)
{
    /*
     
     YOUR CODE HERE:
     
    for (int i = 0; i < "some length of the array"; i++)
        if ("what's at the current element is equal to the mirror element from the other end")
            return false;
        else
            "keep going"
     
    */
    return false;                    //keep, change, or get rid of this line when you're done
     
}


//FIND TOTAL OF A 1D ARRAY
//GIVES INSIGHT HOW TO FIX RECURSIVE
double findtotal(int *p, int a, int b)
{
    if (b < 0) return 0;
    
    int total = 0;
    if (a == b) //base case 1, where the array is only one element
    {
        total = p[a];
        return total;
    }
    else
        //this same idea of addition applies to boolean logic as well
        total = p[a] + findtotal(p, a+1, b);
    return total;
}


//FIND TOTAL OF A 2D ARRAY
//JUST FOR FUNZIES, if a-b is the width of a 1D array, then a-b is the length of a 2D one, and
//c is the width of the 2D one
double findtotal(int **p, int a, int b, int c )
{
    if (b < 0) return 0;
    
    int total = 0;
    if (a == b) //base case 1, where the only element is an array, a [1xj] size
    {
        total = findtotal(p[a], 0, c-1);
        return total;
    }
    else
        //this same idea of addition applies to boolean logic as well
        total = findtotal(p[a], 0, c-1) + findtotal(p, a+1, b, c);
    return total;
}


//PRINTS 1D ARRAYS
void print(int *A, int n)
{
    if (n == 0) cout << "[]";
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "]" << endl;
}


//PRINTS 2D ARRAYS USING THE PREVIOUS FUNCTION
void print(int **A, int n, int m)
{
    cout << endl;
    for (int i = 0; i < n; i++) {
        print(A[i], m);
    }
    cout << endl;
}


//PRINTS 2D ARRAYS USING ITS OWN METHOD
void print2(int **A, int n, int m)
{
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "[ ";
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "]" << endl;
    }
}


int main(int argc, const char * argv[]) {
    
    //SET UP STATIC 1D ARRAYS
    int ints_even1[6] = {0, 1, 2, 2, 1, 0};            //symetric
    int ints_even2[6] = {0, 1, 2, 3, 4, 5};            //asymetric
    int ints_odd1[7]  = {0, 1, 2, 3, 2, 1, 0};          //symetric
    int ints_odd2[7]  = {0, 1, 2, 3, 4, 5, 6};          //asymetric
    
    
    //SET UP/FILL UP DYNAMIC 1D ARRAYS
    int size1;
    int size2;
    
    int *ints_user1;
    int *ints_user2;
    
    cout << "How big for your own array 1? ";
    cin >> size1;
    ints_user1 = new int[size1];
    for (int i = 0; i < size1; i++) {
        cout << "\t" << "Element [" << i << "] = ";
        cin >> ints_user1[i];
    }
    
    
    cout << "How big for your array 2? ";  cin >> size2;
    ints_user2 = new int[size2];
    for (int i = 0; i < size2; i++) {
        cout << "\t" << "Element [" << i << "] = ";
        cin >> ints_user2[i];
    }

    
    
    
    //SET UP STATIC 2D ARRAYS, CAN'T BE PASSED TO FUNCTIONS
    int two_d_ints1[6][6] = {{0, 1, 2, 2, 1, 0},
                            { 1, 1, 2, 2, 1, 1},
                            { 0, 1, 0, 0, 1, 0},
                            { 0, 3, 2, 2, 3, 0},
                            { 1, 1, 1, 1, 1, 1},
                            { 0, 0, 0, 0, 0, 0}};
    
    
    
    int two_d_ints2[7][4] = {{0, 4, 2, 2 },
                            { 1, 1, 2, 7 },
                            { 0, 1, 0, 0 },
                            { 0, 3, 2, 2 },
                            { 1, 1, 1, 9 },
                            { 0, 0, 0, 0 },
                            { 1, 1, 1, 1 }};
    
    
    int test[1][4] = {0, 4, 2, 2 };
    
    //SET UP DYNAMIC 2D ARRAYS SO THAT WE CAN USE PASS THEM TO FUNCTIONS AT ALL
    int **two_d_ints3 = new int*[6];
    for (int i = 0; i < 6; i++) {
        two_d_ints3[i] = new int[6];
        for (int j = 0; j < 6; j++) {
            two_d_ints3[i][j] = two_d_ints1[i][j];
        }
    }
    
    
    int **two_d_ints4 = new int*[7];        
    for (int i = 0; i < 7; i++) {
        two_d_ints4[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            two_d_ints4[i][j] = two_d_ints2[i][j];
        }
    }
    
    
    int **two_d_ints5 = new int*[1];
    for (int i = 0; i < 1; i++) {
        two_d_ints5[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            two_d_ints5[i][j] = test[i][j];
        }
    }
    
    
    //PRINT AND DO MATH ON EACH ARRAY
    cout << "ints_even1 = "; print(ints_even1, 6);
    cout << "\t" << "siz = " << 6 << endl;
    cout << "\t" << "tot = " << findtotal(ints_even1, 0, 6-1) << endl;
    cout << "\t" << "avg = " << findtotal(ints_even1, 0, 6-1) / ((6-1) - 0) << endl;
    cout << "\t" << "sym (r) = " << recursive(ints_even1, 0, 6-1) << endl;
    cout << "\t" << "sym (i) = " << iterative(ints_even1, 6) << endl;
    
    cout << "ints_even2 = "; print(ints_even2, 6);
    cout << "\t" << "siz = " << 6 << endl;
    cout << "\t" << "tot = " << findtotal(ints_even2, 0, 6-1) << endl;
    cout << "\t" << "avg = " << findtotal(ints_even2, 0, 6-1) / ((6-1) - 0) << endl;
    cout << "\t" << "sym (r) = " << recursive(ints_even1, 0, 6-1) << endl;
    cout << "\t" << "sym (i) = " << iterative(ints_even1, 6) << endl;
    
    cout << "ints_odd1  = "; print(ints_odd1, 7);
    cout << "\t" << "siz = " << 7 << endl;
    cout << "\t" << "tot = " << findtotal(ints_odd1, 0, 7-1) << endl;
    cout << "\t" << "avg = " << findtotal(ints_odd1, 0, 7-1) / ((7-1) - 0) << endl;
    cout << "\t" << "sym (r) = " << recursive(ints_even1, 0, 7-1) << endl;
    cout << "\t" << "sym (i) = " << iterative(ints_even1, 7) << endl;
    
    cout << "ints_odd2  = "; print(ints_odd2, 7);
    cout << "\t" << "siz = " << 7 << endl;
    cout << "\t" << "tot = " << findtotal(ints_odd2, 0, 7-1) << endl;
    cout << "\t" << "avg = " << findtotal(ints_odd2, 0, 7-1) / ((7-1) - 0) << endl;
    cout << "\t" << "sym (r) = " << recursive(ints_even1, 0, 7-1) << endl;
    cout << "\t" << "sym (i) = " << iterative(ints_even1, 7) << endl;
    
    cout << "ints_user1 = "; print(ints_user1, size1);
    cout << "\t" << "siz = " << size1 << endl;
    cout << "\t" << "tot = " << findtotal(ints_user1, 0, size1-1) << endl;
    cout << "\t" << "avg = " << findtotal(ints_user1, 0, size1-1) / ((size1-1) - 0) << endl;
    cout << "\t" << "sym (r) = " << recursive(ints_even1, 0, size1-1) << endl;
    cout << "\t" << "sym (i) = " << iterative(ints_even1, size1) << endl;
    
    cout << "ints_user2 = "; print(ints_user2, size2);
    cout << "\t" << "siz = " << size2 << endl;
    cout << "\t" << "tot = " << findtotal(ints_user2, 0, size2-1) << endl;
    cout << "\t" << "avg = " << findtotal(ints_even2, 0, size2-1) / ((size2-1) - 0) << endl;
    cout << "\t" << "sym (r) = " << recursive(ints_even1, 0, size2-1) << endl;
    cout << "\t" << "sym (i) = " << iterative(ints_even1, size2) << endl;
    
    
    
    //2D ARRAY PRINTING
    cout << "two_d_ints1 = "; print(two_d_ints3, 6, 6);
    cout << "\t" << "siz = " << 6*6 << endl;
    
    cout << "two_d_ints1 = "; print(two_d_ints5, 1, 4);
    cout << "\t" << "siz = " << 1*4 << endl;
    
    cout << "two_d_ints2 = "; print2(two_d_ints4, 7, 4);
    cout << "\t" << "siz = " << 7*4 << endl;
    
    return 0;
}
