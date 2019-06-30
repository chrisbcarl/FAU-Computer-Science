#include <iostream>

using namespace std;

int ptrsAndrefs1()
{
	int i = 90;
	//int *p; causes errors
	int *p = 0;

	cout << i << endl;
	cout << &i << endl;
	cout << p << endl;
	//cout << *p << endl; causes errors
	cout << &p << endl << endl;

	i = 90;
	p = &i;

	cout << i << endl;
	cout << *p << endl;
	cout << (*p) << endl;

	return 0;
}
