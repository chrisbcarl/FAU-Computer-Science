
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
#include <string>
using namespace std;

int cStyleStringsExp3_main()
{
	char s[] = "123abc456def789ghi";
	char r[40];

	//my experiment
	strncpy(r, s, 40);
	cout << "The string r contains " << r << endl;
	cout << "The length of r equals " << strlen(r) << endl << endl;
	cout << "r[10] = " << r[10] << endl << endl;
	cout << "static_cast<int>r[10] = " << static_cast<int>(r[10]) << endl << endl;

	strcpy(r, "XXXXXX");
	cout << "The string r contains " << r << endl;
	cout << "The length of r equals " << strlen(r) << endl << endl;
	cout << "r[10] = " << r[10] << endl << endl;
	cout << "static_cast<int>r[10] = " << static_cast<int>(r[10]) << endl << endl;

	strncpy(r, s, 40);
	cout << "The string r contains " << r << endl;
	cout << "The length of r equals " << strlen(r) << endl << endl;
	cout << "r[10] = " << r[10] << endl << endl;
	cout << "static_cast<int>r[10] = " << static_cast<int>(r[10]) << endl << endl;

	strncpy(r, "YYXXXY", 40);
	cout << "The string r contains " << r << endl;
	cout << "The length of r equals " << strlen(r) << endl << endl;
	cout << "r[10] = " << r[10] << endl << endl;
	cout << "static_cast<int>r[10] = " << static_cast<int>(r[10]) << endl << endl;
	//my experiment


	cout << "The string s contains " << s << endl;
	cout << "The length of s equals " << strlen(s) << endl << endl;

	strcpy(r, s);
	cout << "The string r contains " << r << endl;
	cout << "The length of r equals " << strlen(r) << endl << endl;

	strncpy(r, "XXXXXX", 3);
	cout << "The string r contains " << r << endl << endl << endl;

	strcpy(r, "abcdef");
	cout << "Now the string r contains " << r << endl;
	cout << "The current length of r equals " << strlen(r) << endl << endl;

	strcat(r, r);
	cout << "Now the string r contains " << r << endl;
	cout << "Now the current length of r equals " << strlen(r) << endl << endl;

	return 0;
}
