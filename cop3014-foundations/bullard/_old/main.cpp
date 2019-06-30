#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <string>
#include <time.h>       /* time */
//#include "call_stats3.h"
//#include "call_stats4.h"
//#include "call_stats6.h"
#include "call_stats6_saintilmont.h"
#include "Strings.h"
//#include "charword_freq.h"

//#include "Fig7_15.h"
//#include "post_to_in.h"

#include <ctype.h>


int main(int argc, const char* argv[])
{
	// Prints each argument on the command line.
	for (int i = 0; i < argc; i++)
	{
		std::cout << "arg " << i << ": " << argv[i] << std::endl;
	}

	srand(clock());
	

	//call_stats3();
	//call_stats4();
	//call_stats6();

	//c_strings();
	//cpp_strings();

	//charword_freq();
	//Fig7_15();
	//post_to_in();

	call_stats6_saintilmont();


	return 0;
}