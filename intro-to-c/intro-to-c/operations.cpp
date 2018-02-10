//
//  operations.cpp
//  IntroToC
//
//  Created by Christopher Carl on 7/29/16.
//  Copyright © 2016 Christopher Carl. All rights reserved.
//

#include <iostream>

#include "operations.hpp"


int integer1 = 34.03;
int integer2 = 69.04;

char character1 = '0';
char character2 = 'A';

double double1 = 39.14159;
double double2 = 92.71828;

bool boolean1 = false;
bool boolean2 = true;

void operations1()
{
    
    int integer1 = 34;
    int integer2 = 69;
    
    char character1 = '0';
    char character2 = 'A';
    
    double double1 = 39.14159;
    double double2 = 92.71828;
    
    bool boolean1 = false;
    bool boolean2 = true;
    
    std::cout << "VARIABLE DECLARATIONS" << std::endl;
    std::cout << "int integer1 = " << integer1 << ";\nint integer2 = " << integer2 << ";\nchar character1 = '" << character1 << "';\nchar character2 = '" << character2 << "';\ndouble double1 = " << double1 << ";\ndouble double2 = " << double2 << ";\nbool boolean1 = false;\nbool boolean2 = true;" << std::endl;
    
    std::cout << std::endl << std::endl;
    
    std::cout << "THE COMPUTER SEES" << std::endl;
    std::cout << "Integer 1: " << "\t" << integer1 << std::endl;
    std::cout << "Integer 2: " << "\t" << integer2 << std::endl;
    std::cout << "Character 1: " << "\t" << "'" << character1 << "'" << std::endl;
    std::cout << "Character 2: " << "\t" << "'" << character2 << "'" << std::endl;
    std::cout << "Double 1: " << "\t\t" << double1 << std::endl;
    std::cout << "Double 2: " << "\t\t" << double2 << std::endl;
    std::cout << "Boolean 1: " << "\t" << boolean1 << std::endl;
    std::cout << "Boolean 2: " << "\t" << boolean2 << std::endl;
    
    std::cout << std::endl << std::endl;
    
    std::cout << "TYPE CASTING, ONLY WORKS ON POSITIVE NUMBERS" << std::endl;
    std::cout << "Integer 1 as a Character " << "\t\t" << "'" << (char) integer1 << "'" << std::endl;
    std::cout << "Integer 2 as a Character " << "\t\t" << "'" << (char) integer2 << "'" << std::endl;
    std::cout << "Integer 1 as a Double " << "\t\t" << (double) integer1 << std::endl;
    std::cout << "Integer 2 as a Double " << "\t\t" << (double) integer2 << std::endl;
    std::cout << "Integer 1 as a Boolean " << "\t\t" << (bool) integer1 << std::endl;
    std::cout << "Integer 2 as a Boolean " << "\t\t" << (bool) integer2 << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Character 1 as an Integer: " << "\t" << (int) character1 << std::endl;
    std::cout << "Character 2 as an Integer: " << "\t" << (int) character2 << std::endl;
    std::cout << "Character 1 as an Double: " << "\t" << (double) character1 << std::endl;
    std::cout << "Character 2 as an Double: " << "\t" << (double) character2 << std::endl;
    std::cout << "Character 1 as an Boolean: " << "\t" << (bool) character1 << std::endl;
    std::cout << "Character 2 as an Boolean: " << "\t" << (bool) character2 << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Double 1 as an Integer: " << "\t\t" << (int) double1 << std::endl;
    std::cout << "Double 2 as an Integer: " << "\t\t" << (int) double2 << std::endl;
    std::cout << "Double 1 as a Character: " << "\t\t" << "'" << (char) double1 << "'" << std::endl;
    std::cout << "Double 2 as a Character: " << "\t\t" << "'" << (char) double2 << "'" << std::endl;
    std::cout << "Double 1 as a Boolean: " << "\t\t" << (bool) double1 << std::endl;
    std::cout << "Double 2 as a Boolean: " << "\t\t" << (bool) double2 << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Boolean 1 as an Integer " << "\t\t" << (int) boolean1 << std::endl;
    std::cout << "Boolean 2 as an Integer " << "\t\t" << (int) boolean2 << std::endl;
    std::cout << "Boolean 1 as a Character " << "\t\t" << "'" << (char) boolean1 << "'" << std::endl;
    std::cout << "Boolean 2 as a Character " << "\t\t" << "'" << (char) boolean2 << "'" << std::endl;
    std::cout << "Boolean 1 as a Double " << "\t\t" << (double) boolean1 << std::endl;
    std::cout << "Boolean 2 as a Double " << "\t\t" << (double) boolean2 << std::endl;
    
    std::cout << std::endl;
}
