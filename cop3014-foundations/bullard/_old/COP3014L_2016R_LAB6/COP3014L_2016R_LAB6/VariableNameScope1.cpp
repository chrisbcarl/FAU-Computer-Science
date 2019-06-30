#include <iostream>
using namespace std;

void VariableNameScope1_Function_One();
void VariableNameScope1_Function_Two();
void VariableNameScope1_Function_Three(int);

int a = 100;

void VariableNameScope1_Function_One()
{
	cout << "a in Function_One = " << a << endl;
}
void VariableNameScope1_Function_Two()
{
	int a = 555;
	cout << "a in Function_Two = " << a << endl;
}
void VariableNameScope1_Function_Three(int i)
{
	cout << "a in Function_Three = " << a << endl;
}
int VariableNameScope1_main()
{
	int a = 777;
	VariableNameScope1_Function_Three(666);
	VariableNameScope1_Function_Two();
	VariableNameScope1_Function_One();
	cout << "a in main = " << a << endl;
	return 0;
}
