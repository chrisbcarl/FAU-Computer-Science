#include <iostream>
#include <string>

using namespace std;

struct student_record
{
	string firstname, lastname;
	double age, income;
	int number_of_children;
	char sex;
};

int StructureLogOps()
{

	student_record Mary;
	student_record Susan;

	cout << "Enter the firstname and lastname: ";
	cin >> Mary.firstname;
	cin >> Mary.lastname;
	cout << "Enter age: ";
	cin >> Mary.age;
	cout << "Enter income: ";
	cin >> Mary.income;
	cout << "Enter number of children: ";
	cin >> Mary.number_of_children;
	cout << "Enter sex: ";
	cin >> Mary.sex;

	Susan = Mary;

	//if (Susan == Mary)
	if (Susan.firstname == Mary.firstname)
	{
		cout << Susan.firstname << "    " << Mary.lastname << endl;
		cout << Susan.age << endl;
		cout << Susan.income << endl;
		cout << Susan.number_of_children << endl;
		cout << Susan.sex << endl;
	}
	return 0;
}
