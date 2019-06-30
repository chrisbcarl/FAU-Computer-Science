#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int FunctionDeclaration_anonymous(int, int, int)
{
	return 1;
}

double FunctionDeclaration_Print_Message(double balance, double limit)
{
	if (limit > 0)
	{
		cout << "Your Balance is $" << balance << endl;
		cout << "Your have money.  Proceed with your transaction\n";
	}
	else
	{
		cout << "Your Balance is $" << balance << endl;
		cout << "Your transaction has been cancelled\n";
	}

	return balance;
}

int FunctionDeclaration()
{
	double balance = 99.99, limit = 2000.22;

	cout << "Balacne and Limt have the following values before Print_Message is called" << endl;
	cout << "balance= " << balance << " and limit = " << limit << endl;
	FunctionDeclaration_Print_Message(balance, limit);
	cout << "a and b have the following values after swap is called" << endl;
	cout << "Balance = " << balance << " and Limit = " << limit << endl;
	return 0;
}
