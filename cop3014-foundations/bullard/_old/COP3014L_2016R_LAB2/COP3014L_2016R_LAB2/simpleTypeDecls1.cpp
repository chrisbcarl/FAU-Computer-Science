#include <iostream>
using namespace std;

int simpleTypeDecls1()
{
	bool response;
	char character;
	int integer;
	float single_precision_number;
	double double_precision_number;

	cout << "A boolean uses " << sizeof(bool) << " bytes." << endl;
	cout << "A character uses " << sizeof(char) << " bytes." << endl;
	cout << "An integer uses " << sizeof(int) << " bytes." << endl;
	cout << "A float uses " << sizeof(float) << " bytes." << endl;
	cout << "A double uses " << sizeof(double) << " bytes." << endl;

	return 0;
}
