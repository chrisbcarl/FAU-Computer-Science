#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstring>
using namespace std;

int cStyleStringsExp1_main()
{
	char my_name[20] = "James Madison";
	char her_name[] = "Michelle Obama";
	char his_name[20];

	cout << "my_name = " << my_name << endl;
	cout << "The length of my_name is " << strlen(my_name) << endl;
	cout << "The capacity of my_name is " << sizeof(my_name) << endl;

	cout << "her_name = " << her_name << endl;
	cout << "The length of her_name is " << strlen(her_name) << endl;
	cout << "The capacity of her_name is " << sizeof(her_name) << endl;

	strcpy(his_name, "Barack Obama");
	cout << "his_name = " << his_name << endl;
	cout << "The length of his_name is " << strlen(his_name) << endl;
	cout << "The capacity of his_name is " << sizeof(his_name) << endl;

	return 0;

}
