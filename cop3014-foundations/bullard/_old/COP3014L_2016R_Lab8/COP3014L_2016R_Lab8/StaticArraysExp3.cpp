#include <iostream>
using namespace std;

int StaticArraysExp3()
{
	int static_Array[5];
	int *dynamic_Array;

	dynamic_Array = new int[5];

	int i;

	for (i = 0; i<5; i++)
	{
		static_Array[i] = i;
		dynamic_Array[i] = 5;
	}


	for (i = 0; i<5; i++)
	{
		cout << "static_Array[" << i << "] = " << static_Array[i] << endl;
		cout << "dynamic_Array[" << i << "] = " << dynamic_Array[i] << endl;
	}

	cout << endl << endl << endl;

	//delete[] dynamic_Array;
	dynamic_Array = static_Array;
	
	for (i = 0; i<5; i++)
	{
		cout << "static_Array[" << i << "] = " << static_Array[i] << endl;
		cout << "dynamic_Array[" << i << "] = " << dynamic_Array[i] << endl;
	}

	return 0;
}
