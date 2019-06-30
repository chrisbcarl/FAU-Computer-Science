#include <iostream>
#include <iomanip>
using namespace std;

int simpleTypeDecls2()
{
	bool response = 63;
	char character = 68;
	int integer = 123.456789;
	float single_precision_number = 0.01234567890123456789;
	double double_precision_number = 0.01234567890123456789;


	cout << "response =  " << response << endl;
	cout << "character =  " << character << endl;
	cout << "integer =  " << integer << endl;
	cout << "single_precision_number =  " << setprecision(24)
		<< single_precision_number << endl;
	cout << "double_precision_number =  " << setprecision(24)
		<< double_precision_number << endl;

	return 0;
}
