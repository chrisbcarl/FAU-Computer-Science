//
//  smallprog4.h
//  IntroC
//
//  Created by Chris Carl on 3/14/17.
//  Copyright © 2017 Chris Carl. All rights reserved.
//

#ifndef SORGENTE_SMALLPROG4
#define SORGENTE_SMALLPROG4

/*
 PART 1:
 Create a program that asks the user to enter a number from 1 to 9
 Get the number from the user (For example if the user enters a 5, each loop below will repeat 5 times)
 Print the statement “FAU Owls - Hoot Hoot” the number of times entered by the user using a for loop.
 Print the statement “Programming is awesome” the same number of times using a do/while loop.
 Print the statement “Florida beaches are beautiful” the same number of times using a while loop.
 Note: You will be graded on whether or not you used the correct loop as described above, not just on output
 PART 2: calculates the remainder and the product of two integers with one user-defined functions:
 //takes two integer arguments and two integer pointer arguments //1. calculate the product and stores the result in prodPtr //2. calculate the remainder of num1 % num2 and store the result in remPtr
 //if num2 is 0 do not calculate the remainder and the value at remPtr will be 0 void CalculateBoth(int num1, int num2, int*prodPtr, int *remPtr); Call the CalculateBoth function from main. Print the results (value at remPtr and value at prodPtr) inside the CalculateBoth function
 Also, print the results again in the main function after the function has been called
 */

void CalculateBoth(int number1, int number2, int* product, int* remainder);

int part1()
{
    printf("Create a program that asks the user to enter a number from 1 to 9: ");
    int number;
    scanf(" %d", &number);
    
    int i;
    for (i = 0; i < number; i++) {
        printf("FAU Owls - Hoot Hoot\n");
    }
    
    i = 0;
    while (i < number) {
        printf("Programming is awesome\n");
        
        i++;
    }
    
    i = 0;
    do {
        printf("Florida beaches are beautiful\n");
        i++;
    } while (i < number);
    
    int a = 10;
    int b = 7;
    int product_of_a_b;
    int remainder_of_a_b;
    
    CalculateBoth(a, b, &product_of_a_b, &remainder_of_a_b);
    printf("Product of %d * %d = %d\n", a, b, product_of_a_b);
    printf("Remainder of %d mod %d = %d\n", a, b, remainder_of_a_b);
    
    return 0;
}

void CalculateBoth(int number1, int number2, int* product, int* remainder)
{
    *product = number1 * number2;
    *remainder = number1 % number2;
}

//takes two integer arguments and two integer pointer arguments //1. calculate the product and stores the result in prodPtr //2. calculate the remainder of num1 % num2 and store the result in remPtr
//if num2 is 0 do not calculate the remainder and the value at remPtr will be 0 void CalculateBoth(int num1, int num2, int*prodPtr, int *remPtr); Call the CalculateBoth function from main. Print the results (value at remPtr and value at prodPtr) inside the CalculateBoth function
//Also, print the results again in the main function after the function has been called

void smallprog4() {
  int number1 = 1;
  int number2 = 2;
  int product = 0;
  int remainder = 0;
  part1();
  CalculateBoth(number1, number2, &product, &remainder);
}
#endif /* smallprog4_h */
