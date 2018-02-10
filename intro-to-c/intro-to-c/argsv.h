#ifndef ARGSV
#define ARGSV

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int argsv_func1(int args, char** argsv)
{
	int i;
	printf("addess of argsv = %x\n", argsv);
	for (i = 0; i < args; i++)
	{
		printf("arg%d: %x \t %s\n", i, argsv[i], argsv[i]);
	}
	printf("\n");

	return 0;
}

int argumentsv()
{
	int args;
	char ** argsv;
	printf("How many args? ");
	scanf(" %d", &args);

	argsv = (char**)malloc(args);
	if (argsv == NULL) 
		exit(1);

	int i;
	for (i = 0; i < args; i++)
	{
		scanf("%s", &argsv[i]);
	}

	argsv_func1(args, argsv);

	free(argsv);

	return 0;
}

#endif