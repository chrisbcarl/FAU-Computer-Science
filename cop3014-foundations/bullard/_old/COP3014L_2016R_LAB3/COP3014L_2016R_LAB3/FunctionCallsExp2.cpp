#include <iostream>
#include <string>

using namespace std;

void FunctionCallsExp2_swap(int & a, int & b)
{
	int temp = a;
	cout << "a and b have the following values at the start of swap" << endl;
	cout << "a = " << a << " and b = " << b << endl;
	a = b;
	b = temp;
	cout << "a and b have the following values at the end of swap" << endl;
	cout << "a = " << a << " and b = " << b << endl;

}
int FunctionCallsExp2()
{
	int a = 111, b = 222;

	cout << "a and b have the following values before swap is called" << endl;
	cout << "a = " << a << " and b = " << b << endl;
	FunctionCallsExp2_swap(a, b);
	cout << "a and b have the following values after swap is called" << endl;
	cout << "a = " << a << " and b = " << b << endl;
	return 0;
}
