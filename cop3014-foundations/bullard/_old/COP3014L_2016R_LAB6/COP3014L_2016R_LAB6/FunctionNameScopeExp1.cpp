#include <iostream>

using namespace std;

void FunctionNameScopeExp1_Function_One()
{
	cout << "You are in Function One" << endl;
	cout << "Function_One called no one" << endl << endl;
}

void FunctionNameScopeExp1_Function_Two()
{
	cout << "You are in Function_Two" << endl;
	cout << "Function_Two will call Function_One" << endl << endl;
	FunctionNameScopeExp1_Function_One();
}

void FunctionNameScopeExp1_Function_Three()
{
	cout << "You are in Function_Three" << endl;
	cout << "Function_Three will call Function_Two" << endl << endl;
	FunctionNameScopeExp1_Function_Two();
}

int FunctionNameScopeExp1_main()
{
	FunctionNameScopeExp1_Function_Three();
	FunctionNameScopeExp1_Function_Two();
	FunctionNameScopeExp1_Function_One();

	return 0;
}
