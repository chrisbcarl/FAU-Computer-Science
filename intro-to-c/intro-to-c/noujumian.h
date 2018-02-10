//
//  noujumian.h
//  IntroC
//
//  Created by Christopher Carl on 3/14/17.
//  Copyright © 2017 Christopher Carl. All rights reserved.
//

#ifndef noujumian_h
#define noujumian_h

#include <stdio.h>
#include <math.h>

//http://ariya.blogspot.com/2007/02/modulus-with-mersenne-prime.html
int noojuvoodju(int n, int k)
{
    int p = pow(2, k) - 1;      //mersenne prime
    
    int r = n >> k;         //rotation part, called high
    int m = n & p;          //masking part, called low
    int mod = m + r;        //the remainder/residue/modulus
    if (mod > p) {          //if the remainder is bigger than the prime, something's up
        return mod - p;
    }
    else{
        return mod;
    }
}

int noujumian()
{
    //127 = 2^7 - 1
    //0x7F
    
    int n = 23456789;
    int p = (int)pow(2, 17) - 1;
    int m = n % p;
    
    printf("%0x\n", n);
    printf("%0x\n", p);
    printf("%0x\n", m);
    printf("%0x\n", noojuvoodju(n, 17));
    
    return 0;
    
    return 0;
}


#endif /* noujumian_h */
