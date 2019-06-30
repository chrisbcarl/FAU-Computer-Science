
#include <iostream>

using namespace std;

void FunctionNameScopeExp3_Function_One();
void FunctionNameScopeExp3_Function_Two();
void FunctionNameScopeExp3_Function_Three();

void FunctionNameScopeExp3_Function_One()
{
	cout << "You are in Function One" << endl;
	cout << "Function_One will call Function_Two" << endl << endl;
	FunctionNameScopeExp3_Function_Two();
}

void FunctionNameScopeExp3_Function_Two()
{
	cout << "You are in Function_Two" << endl;
	cout << "Function_Two will call Function_Three" << endl << endl;
	FunctionNameScopeExp3_Function_Three();
}

void FunctionNameScopeExp3_Function_Three()
{
	cout << "You are in Function_Three" << endl;
	cout << "Function_Three calls no one" << endl << endl;
}

int main()
{

	FunctionNameScopeExp3_Function_Three();
	FunctionNameScopeExp3_Function_Two();
	FunctionNameScopeExp3_Function_One();

	return 0;
}
