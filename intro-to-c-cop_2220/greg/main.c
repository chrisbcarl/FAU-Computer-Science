

//
//  main.c
//  greg
//
//  Created by Christopher Carl on 12/8/16.
//  Copyright © 2016 Christopher Carl. All rights reserved.
//

#include <stdio.h>


/*
 for greg
 
 a program that prints all even numbers up to a number of the user's choosing.
 
 a program that prints hello world if the user says yes.
 
 a program that writes all characters of the english alphabet as many times as the user wants
 */

void printEvens(int choice);

int main1()
{
    int choice = 0;
    printf("Up to what number would you like to print the even set? ");
    scanf(" %d", &choice);
    printEvens(choice);
    return 0;
}

void printEvens(int choice)
{
    int i = 1;
    while ( i < choice) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
        i++;
    }
}


void helloWorld();
char getChoice();

int main2()
{
    char choice = '_';
    choice = getChoice();
    while (choice == 'y') {
        helloWorld();
        choice = getChoice();
    }
    
    return 0;
}

void helloWorld()
{
    printf("Hello, world!\n");
}

char getChoice()
{
    char choice = '_';
    printf("Would you like to print Hello World? ");
    scanf(" %c", &choice);
    return choice;
}

int getAmount();
void printAlphabet(FILE * ptr, int amount);

int main3()
{
    FILE * file_pointer = fopen("alphabet_repeat.txt", "a+");
    int amount = getAmount();
    printAlphabet(file_pointer, amount);
    fclose(file_pointer);
    return 0;
}

int getAmount()
{
    int amount = 0;
    printf("How many prints? ");
    scanf(" %d", &amount);
    return amount;
}

void printAlphabet(FILE * ptr, int amount)
{
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < 26; j++) {
            fprintf(ptr, "%c", 'a' + j);
        }
        fprintf(ptr, "\n");
    }
}









int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    main1();
    printf("\n\n");
    main2();
    printf("\n\n");
    main3();
    printf("\n\n");
    
    char c = '_';
    printf("ENTER A CHARACTER TO EXIT: ");
    while (c == '_')
    {
        scanf(" %c", &c);
    }
    
    return 0;
}
