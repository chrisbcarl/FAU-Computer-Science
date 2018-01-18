//
//  lab3.h
//  FAU_COP2200_2016R_sorgente
//
//  Created by Christopher Carl on 10/19/16.
//  Copyright © 2016 Christopher Carl. All rights reserved.
//

#ifndef SORGENTE_LAB3
#define SORGENTE_LAB3

#include <stdio.h>


int lab3()
{
    int repeat = 0;
    
    printf("Enter a number 1-9: ");
    scanf(" %d", &repeat);
    
    int i;
    
    for (i = 0; i < repeat; i++) {
        printf("FAU OWLs go 'hoot, hoot'!\n");
    }
    
    i = 0;
    while (i < repeat) {
        printf("The beach is nice.\n");
        i++;
    }
    
    i = 0;
    do {
        printf("Programming is fun!\n");
        i++;
    } while (i < repeat);
    
    return 0;
}


#endif /* lab3_h */
