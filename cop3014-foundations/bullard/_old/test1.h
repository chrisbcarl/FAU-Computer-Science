#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool Is_Vowel(char ch)
{
	if ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U')) return true;
	else return false;
}

void input(double x, double y, double z);
void output(int p, int q);

class patient_record
{
public:
	int room_number;
	int age;
	string hospital_wing;
};
void ReadFile(ifstream & in, patient_record & pr)
{
	in >> pr.room_number;
	in >> pr.age;
	in >> pr.hospital_wing;
}

void Find_Results(const int & a, const int & b, const int & c, double & f, double & g, double & p);


void post_in_discrepency()
{
	int x = 0;
	std::cout << "x == " << x << std::endl;
	if (x++ != 0)
	{
		std::cout << "blashphemy!" << std::endl;
		std::cout << "x == " << x << std::endl;
	}
	else
	{
		std::cout << "the church is right once more." << std::endl;
		std::cout << "x == " << x << std::endl;
	}

	std::cout << std::endl << std::endl;
}




//int a = 10;
//double b = pow(a, 2);
//double c = log10(b);
//int r = rand() % 100 - 0;
//int sum = 0;
//int average_percent = 0;
//
//cout << a << " " << b << " " << c << " " << r << " " << endl;
//for (int i = 0; i < 100; i++)
//{
//	sum = 0;
//	for (int i = 0; i < 100; i++)
//	{
//		sum += rand() % 10 - 0;
//	}
//	cout << "test " << i << " performance == " << sum / 100 << "\%" << endl;
//	average_percent += sum / 100;
//}
//
//cout << "average percent == " << average_percent / 100 << "\%" << endl;
