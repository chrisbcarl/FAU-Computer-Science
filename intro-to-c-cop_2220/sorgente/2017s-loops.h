#pragma once

#ifndef LOOPS_H
#define LOOPS_H

#include "stdio.h"

void loops_demo()
{
	//get user input on loop numbers.
	printf("How many loops?: ");
	int user_input;
	scanf(" %d", &user_input);

	//error checking, prevents negative looping which doesn't make sense
	if (user_input < 0)
	{
		user_input = (-1) * user_input;
	}


	printf("FOR LOOP DEMO:\n");
	//for(counter variable intialization; when the counter should stop, increment the counter)
	for (int i = 0; i < user_input; i++)
	{
		printf("%d ", i);
	}
	printf("\n\n");

	printf("WHILE LOOP DEMO:\n");
	int i = 0;
	while (i < user_input)
	{
		printf("%d ", i);

		i++;					//THIS COMES LAST
	}
	printf("\n\n");


	printf("DO-WHILE LOOP DEMO:\n");
	int j = 0;					//SINCE I DECLARED i ALREADY, I"M GONNA USE SOMETHING ELSE
	do 
	{
		printf("%d ", j);

		j++;					//THIS COMES LAST
	}while (j < user_input);	//NEEDS SEMICOLON
	printf("\n\n");

}


#endif