#include <stdio.h>
#include <stdlib.h> // needed for malloc, calloc, realloc
#define LARGEST_RECEIPT_SIZE 1024

int main() {
    int numberOfItemsBought;
    printf("How many things did you buy from Publix today? ");
    scanf("%d", &numberOfItemsBought);

    double receipt[LARGEST_RECEIPT_SIZE];	// receipt holds UP TO 1024 product prices
    double * receipt_dynamic = (double *) malloc(sizeof(double) * numberOfItemsBought); // receipt dynamic can hold any number the user chooses.

    // we're going to fill up the receipt starting from the beginning until the amount of items we bought
    int i;
    int itemNumber;
    int itemLocation;
    double itemPrice;
    for (i = 0; i < numberOfItemsBought; i++) {
        itemNumber = i + 1;
        itemLocation = i;
        printf("How much was item #%d? $", itemNumber);
        scanf("%lf", &itemPrice);

        receipt[itemLocation] = itemPrice;	            // ASSIGN a value TO a static array's elements like this
        receipt_dynamic[itemLocation] = itemPrice;      // ASSIGN a value TO a dynamic array's elements like this, no difference.
    }
    printf("...\n\n\n");

    double totalPrice = 0;
    double averagePrice = 0;
    double itemPrice_dynamic;
    for (i = 0; i < numberOfItemsBought; i++) {
        itemNumber = i + 1;
        itemLocation = i;
        itemPrice = receipt[itemLocation];                      // ACCESS a value FROM a static array's elements like this
        itemPrice_dynamic = receipt_dynamic[itemLocation];      // ACCESS a value FROM a dynamic array's elements like this, no difference
        totalPrice += itemPrice;

        printf("Item #%d was $%0.2lf\t", itemNumber, itemPrice);
        printf("Item #%d from DYNAMIC array was $%0.2lf, no difference!\n", itemNumber, itemPrice_dynamic);
    }
    printf("...\n\n\n");

    averagePrice = totalPrice / numberOfItemsBought;
    printf("Total price comes out to $%0.2lf\n", totalPrice);
    printf("Average price was $%0.2lf\n", averagePrice);

    return 0;
}