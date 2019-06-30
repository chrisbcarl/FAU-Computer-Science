using namespace std;

#include <iostream>

namespace myspace
{
	double value = 3.1459;
}

int namespace3()
{
	cout << myspace::value << endl;
	return 0;
}