∑//
//  main.cpp
//  HW7_first
//
//  Created by Christopher Carl on 7/27/16.
//  Copyright © 2016 Christopher Carl. All rights reserved.
//

//16.07.27.11:45 - START
//16.07.27.11:55 - pseudo done, debugging iterative
//16.07.27.12:05 - just reduced iterative code in half
//16.07.27.12:15 - debugging recursive

//16.07.27.12:30 - coding
//16.07.27.12:42 - STOP



//16.07.28.19:32 - START
//16.07.28.19:48 - DONE
//16.07.28.20:19 - supplemental functions and testing.

/*
 Pseudo
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
 
 */

#include <iostream>
#include <time.h>




//p points to an array
//a = start of array, or starting element
//b = ending element
template<class type_a>
bool symetric_r (type_a *p, int a, int b)
{
    if (a == b) return true;
        
    else
    {
        if (a > b)
        {
            int temp;
            a = temp;
            a = b;
            b = temp;
        }
        if (b == a + 1) return (p[a] == p[b]);
        return (p[a]==p[b]) && symetric_r(p, a+1, b-1);
    }
}


//p points to an array
//n is the size
template<class type_a>
bool symetric_i (type_a *p, int n)
{
    for (int i = 0; i < (n/2 + n%2); i++)
        if (p[i] != p[(n-1)-i]) return false;
    return true;
}


template<class type_a>
void print (type_a *p, int n)
{
    std::cout << "[ ";
    for (int i = 0; i < (n); i++)
        std::cout<< p[i] << " ";
    std::cout << "]";
}


int main2(int argc, const char * argv[]) {
    
    srand (unsigned(time(NULL)));
    
    int even = 6;
    int odd = 7;
    int size1 = 0;
    int size2 = 0;
    int i;
    
    
    //EVEN SIZED CHARACTER ARRAY
    char *chars_even;
    chars_even = new char[even];
    std::cout << "Please insert " << even << " characters into this array." << std::endl;
    for (i = 0; i < even; i++) {
        std::cin >> chars_even[i];
    }
    
    
    //ODD SIZED CHARACTER ARRAY
    char *chars_odd;
    chars_odd = new char[odd];
    std::cout << "Please insert " << odd << " characters into this array." << std::endl;
    for (i = 0; i < odd; i++) {
        std::cin >> chars_odd[i];
    }
    
    
    //EVEN SIZED INTEGER ARRAY
    int *ints_even;
    ints_even = new int[even];
    std::cout << "Please insert " << even << " integers into this array." << std::endl;
    for (i = 0; i < even; i++) {
        std::cin >> ints_even[i];
    }
    
    
    //ODD SIZED INTEGER ARRAY
    int *ints_odd;
    ints_odd = new int[odd];
    std::cout << "Please insert " << odd << " integers into this array." << std::endl;
    for (i = 0; i < odd; i++) {
        std::cin >> ints_odd[i];
    }
    
    
    //RANDOM SIZED CHARACTER ARRAY
    size1 = rand()% 10 + 3;
    char *chars_rand;
    chars_rand = new char[size1];
    for (i = 0; i < size1; i++) {
        chars_rand[i] = rand() % 99 + 97;
    }
    
    
    //RANDOM SIZED INTEGER ARRAY
    size2 = rand()% 10 + 3;
    int *ints_rand;
    ints_rand = new int[size2];
    for (i = 0; i < size2; i++) {
        ints_rand[i] = rand() % 3 + 1;
    }
    
    
    std::cout << "The size " << even << " character array: ";
    print(chars_even, even); std::cout << " symmetry is recursive: "
    << symetric_r(chars_even, 0, even-1) << " and iterative: "
    << symetric_i(chars_even, even) << std::endl;
    
    
    std::cout << "The size " << even << " character array: ";
    print(chars_odd, odd); std::cout << " symmetry is recursive: "
    << symetric_r(chars_odd, 0, odd-1) << " and iterative: "
    << symetric_i(chars_odd, odd) << std::endl;

    
    std::cout << "The size " << even<< " integer array symmetry ";
    print(ints_even, even); std::cout << " is recursive: "
    << symetric_r(ints_even, 0, even-1) << " and iterative: "
    << symetric_i(ints_even, even) << std::endl;

    
    std::cout << "The size " << odd << " integer array symmetry ";
    print(ints_odd, odd); std::cout << " is recursive: "
    << symetric_r(ints_odd, 0, odd-1) << " and iterative: "
    << symetric_i(ints_odd, odd) << std::endl;
    
    
    std::cout << "The size " << size1 << " integer array symmetry ";
    print(chars_rand, size1); std::cout << " is recursive: "
    << symetric_r(chars_rand, 0, size1-1) << " and iterative: "
    << symetric_i(chars_rand, size1) << std::endl;
    
    
    std::cout << "The size " << size2 << " integer array symmetry ";
    print(ints_rand, size2); std::cout<< " is recursive: "
    << symetric_r(ints_rand, 0, size2-1) << " and iterative: "
    << symetric_i(ints_rand, size2) << std::endl;
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
