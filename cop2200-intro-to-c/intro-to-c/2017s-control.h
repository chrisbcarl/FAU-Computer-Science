#pragma once

#ifndef CONTROL_H
#define CONTROL_H

#include "stdio.h"

void control_demo()
{
	//get user input on controlling variable.
	printf("Run a battery of control tests on this number?: ");
	int user_input;
	scanf(" %d", &user_input);

	//error checking, prevents negative choices which doesn't make sense
	if (user_input < 0)
	{
		user_input = (-1) * user_input;
	}


	//SINGLE CONDITION
	if (user_input == 1)
	{
		printf("you entered 1.\n\n");
	}

	//DOUBLE CONDITIONS
	if (user_input != 1)
	{
		printf("you did not enter 1.\n\n");
	}
	else
	{
		printf("you DID enter 1.\n\n");
	}

	//MANY CONDITIONS
	if (user_input == 0)
	{
		printf("you entered 0.\n\n");
	}
	else if (user_input == 1)
	{
		printf("you entered 1.\n\n");
	}
	else if (user_input != 0)
	{
		printf("you entered something other than zero. Maybe even 1.\n\n");
	}
	else if(user_input < 0)
	{
		printf("you entered a negative number.\n\n");
	}
	else
	{
		printf("This will never print because we checked for 0 and ANYTHING other than 0.\n\n");
	}

	//NESTED CONDITIONS
	if (user_input > 1)
	{
		if (user_input > 10)
		{
			printf("you entered something bigger than 10.\n\n");
		}
		else
		{
			printf("you entered something between 1 and 10.\n\n");
		}
	}

	//GREATER THAN, LESS THAN CONDITIONS
	if (0 <= user_input && user_input <= 100)
	{
		printf("you entered something between 0 and 100.\n\n");
		if (10 <= user_input && user_input <= 50)
		{
			printf("you entered something between 10 and 50.\n\n");
		}
		else
		{
			printf("you entered something between 50 and 100 OR between 0 and 10.\n\n");
		}
	}

	//BOOLEAN CONDITIONALS
	//!
	if (0) printf("if(0) gets printed.\n\n");
	if (!0) printf("if(!0) gets printed.\n\n");
	if (1) printf("if(1) gets printed.\n\n");
	if (!1) printf("if(!1) gets printed.\n\n");

	//! and != statement
	if (0 != 0) printf("0 != 0 true.\n\n");
	if (0 != 1) printf("0 != 1 true.\n\n");
	if (1 != 0) printf("1 != 0 true.\n\n");
	if (1 != 1) printf("1 != 1 true.\n\n");

	//&& statement
	if (0 && 0) printf("0 && 0 true.\n\n");
	if (0 && 1) printf("0 && 1 true.\n\n");
	if (1 && 0) printf("1 && 0 true.\n\n");
	if (1 && 1) printf("1 && 1 true.\n\n");
	
	//OR statement
	if (0 || 0) printf("0 || 0 true.\n\n");
	if (0 || 1) printf("0 || 1 true.\n\n");
	if (1 || 0) printf("1 || 0 true.\n\n");
	if (1 || 1) printf("1 || 1 true.\n\n");

	//OR statement
	if (0 >= 0) printf("0 >= 0 true.\n\n");
	if (0 >= 1) printf("0 >= 1 true.\n\n");
	if (1 >= 0) printf("1 >= 0 true.\n\n");
	if (1 >= 1) printf("1 >= 1 true.\n\n");

	//COMPLEX CONDITIONALS
	if ((1 && 0) || (1 || 0)) printf("true.\n\n");

	//SWITCH OR MANY CONDITIONS
	switch (user_input)
	{
	case 0:
		printf("It's a 0.\n\n");
		break;
	case 2:
		printf("It's a 2.\n\n");
		break;
	case 3:
		printf("It's a 3.\n\n");
		break;
	case 1:
		printf("It's a 1.\n\n");
		break;
	default:
		printf("It's literally anything else besides 0, 1, 2, 3.\n\n");
		break;
	}
}


#endif