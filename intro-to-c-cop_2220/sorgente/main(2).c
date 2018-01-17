//
//  main.c
//  IntroC
//
//  Created by Christopher Carl on 2/14/17.
//  Copyright © 2017 Christopher Carl. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "noujumian.h"
#include "smallprog4.h"
#include "lab9.h"

void whatsup(int, double*);             //problem 1, function prototype

void whatsup(int arg1, double* arg2)    //problem 2, function definition
{
    *arg2 = arg1 * 60;
}


int main(int argc, const char * argv[])
{
    //part1();
    //double f;
    //noujumian();
    
    //lab9();
    int something = 1;
    double nothing = 10000000;
    whatsup(something, &nothing);       //problem 3, calling function, this is all you need to write
    printf("nothing == %lf", nothing);
    
    
    
    return 0;
    
    

}
