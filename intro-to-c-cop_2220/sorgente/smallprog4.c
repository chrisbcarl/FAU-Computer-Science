//
//  smallprog4.h
//  IntroC
//
//  Created by Jacob Cardo on 3/14/17.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//function prototypes
void CalculateBoth(int number1, int number2, int* product, int* remainder);

//main definition
int main()
{
    //how to get a number from user
	printf("Enter a number from 1 to 9: ");
	int number;
    scanf(" %d", &number);
	
    
    //structure of a for loop
    int i;
    for (i = 0; i < number; i++) {
        printf("FAU Owls - Hoot Hoot\n");
    }
    
    //structure of a while loop
    i = 0;
    while (i < number) {
        printf("Programming is awesome\n");
        
        i++;
    }
    
    //structure of a do while loop
    i = 0;
    do {
        printf("Florida beaches are beautiful\n");
        i++;
    } while (i < number);
    
    //how to get a number from user
    printf("Enter a number: ");
    int a;
    scanf(" %d", &a);
    //how to get a number from user
    printf("Enter another number: ");
    int b;
    scanf(" %d", &b);
    int product_of_a_b;
    int remainder_of_a_b;
    
    CalculateBoth(a, b, &product_of_a_b, &remainder_of_a_b);
    printf("Product of %d * %d = %d\n", a, b, product_of_a_b);
    printf("Remainder of %d mod %d = %d\n", a, b, remainder_of_a_b);
    
    return 0;
}


//function definitions
void CalculateBoth(int number1, int number2, int* product, int* remainder)
{
    *product = number1 * number2;
    *remainder = number1 % number2;
}
