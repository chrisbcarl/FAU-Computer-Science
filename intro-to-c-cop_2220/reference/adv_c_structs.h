#ifndef ADV_C_STRUCTS
#define ADV_C_STRUCTS

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct Numholder
{
	int* p;
};

typedef struct Bozo
{
	int* p;
} Bozo;

int adv_c_structs()
{
	struct Numholder numho;
	struct Numholder* numpy = &numho;
	Bozo bozo;

	int a = 0;
	numho.p = &a;
	*numho.p = 13;
	printf("a == %d\n", a);

	int b = 0;
	numpy->p = &b;
	(*numpy).p = &b;
	*numpy->p = 13;
	printf("b == %d\n", b);

	bozo.p = 0;

	return 0;
}

#endif