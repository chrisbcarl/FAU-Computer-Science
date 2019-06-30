#include <iostream>

using namespace std;

int b = 111;

int VariableNameScope2_main()
{
	{
		int b = 222;
		{
			int b = 333;
			cout << "b = " << b << endl;
			{
				int b = 444;
				cout << "b = " << b << endl;
				{
					cout << "b = " << b << endl;
				}
			}
		}

		cout << "b = " << b << endl;
	}

	cout << "b = " << b << endl;

	return 0;
}
