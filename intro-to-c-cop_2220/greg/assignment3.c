//define
//include

#include <stdio.h>


/*
 for greg
 
 a program that writes all characters of the english alphabet as many times as the user wants
 */

int getAmount();
void printAlphabet(FILE * ptr, int amount);

int main()
{
    FILE * file_pointer = fopen("alphabet_repeat.txt", "a+");
    //your code here
    fclose(file_pointer);
    return 0;
}

//your function here

void printAlphabet(FILE * ptr, int amount)
{
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < 26; j++) {
            //your code here
        }
        fprintf(ptr, "\n");
    }
}
