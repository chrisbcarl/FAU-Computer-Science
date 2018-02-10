//
//  HW1
//  COP_2220_Intro_C
//
//  Created by Christopher Carl on 5/29/16.
//  Copyright © 2016 Chris B. Carl. All rights reserved.
//  Time Begin: 21:15
//  Time End::  21:36
//

/*
 PROMPT:
 In this assignment, you are going to turn in a single cpp file. Your goal is to calculate the
 areas of the following: (1) the circle of radius r, (2) the smallest square that contains the circle
 (think about what the width is), and (3) the difference.
 We break down things into the following tasks:
 • Task 1: you should print “Enter an integer for the radius:” in the first line.
 • Task 2: let the user input the integer as the radius. You can assume that the user enters
 the integer correctly.
 • Task 3: in the next line, print “The area of the circle is: ” and then print a floating number
 followed the colon. (The floating number should be the area, not something arbitrary.)
 • Task 4: in the next line, print “The area of the square is: ” and then print an integer
 followed the colon.
 • Task 5: in the next line , print “The difference is: ” and then print a floating number
 followed by the colon.
 To achieve the task, you must learn (1) how to declare variables of different types, e.g. int,
 double, (2) how to manipulate operations on the variables, and (3) how to handle input/output
 (cin/cout, printf/scanf).
 In addition to writing codes, you should think about why in task 3 you need to output a floating
 number, but in task 4 you only need to output an integer.
 */


/*
 RESPONSE:
 For a circle to fit in a square with radius r, the square's area must be (2r)^2, which can be represented
 as 4 * r * r. For this reason, the area of a square, given integer values for r, can only be an integer value.
 On the other hand, PI is a transcandental number with an infinite amount of values following a decimal point,
 so it must be approximated using a floating point value, defined here as PI with only five digits trailing.
 Therefore, any numerical operation performed using PI will result in a floating point value, as is the case in
 computing the area of a circle.
 */

#include "main.hpp"
#include <stdio.h>

#define PI 3.14159

void hw1()
{
    int radius, area_s;
    float area_c, difference;
    
    printf("Enter an integer for the radius: ");
    scanf("%d", &radius);
    
    area_c = PI * radius * radius;
    area_s = 4 * radius * radius;
    difference = area_s - area_c;
    
    printf("The area of the circle is: %f\n", area_c);
    printf("The area of the square is: %d\n", area_s);
    printf("The difference is: %f\n", difference);
    
}

