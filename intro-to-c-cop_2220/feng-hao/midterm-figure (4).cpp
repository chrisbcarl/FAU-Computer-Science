#include <iostream>
using namespace std;

//greatest common divisor: GCD
int functionT(int a, int b)
{
	int r;
	while (b > 0)
	{
		r = a%b;
		a = b;
		b = r;

	}
	return a;

}

int main()
{
	cout << functionT(5, 2) << endl;
	cout << functionT(84, 98) << endl;
	cout << functionT(3, 35) << endl;
	cout << functionT(369, 459) << endl;
}