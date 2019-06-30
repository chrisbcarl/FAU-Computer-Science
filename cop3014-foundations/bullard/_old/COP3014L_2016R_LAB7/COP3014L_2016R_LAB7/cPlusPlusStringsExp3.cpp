#include <iostream>
#include <string>
using namespace std;

int add_two_numbers(int a, int b)
{
	int x = 1, y = 2;
	a = x;
	cout << a << endl;
	return 0;
}

int main()
{
	int b = add_two_numbers(5, 6);

	string s1 = "123abc456de111ef789eehij111ee";
	string s2;
	int loc = 0;

	for (int i = 0; i<s1.length(); i++)
	{
		loc = s1.find("1", loc);
		if (loc != -1)
		{
			cout << "1 appears at location " << loc << endl;
			loc++;
		}
	}
	cout << endl << endl;

	s2 = s1.substr(0, 3);
	cout << "s2 equals " << s2 << endl;
	cout << "s2.max_size equals " << s2.max_size() << endl;

	s2 = s1.substr(3, 3);
	cout << "s2 equals " << s2 << endl;

	s2 = s1.substr(0, 500);
	cout << "s2 equals " << s2 << endl << endl;


	loc = 0;
	s2 = "";

	for (int i = 0; i<s1.length(); i++)
	{
		loc = s1.find("e", loc);
		if (loc != -1)
		{
			s2 += s1.substr(loc, 1);
			loc++;
		}
	}
	cout << "s2 equals " << s2 << endl << endl;

	return 0;

}
