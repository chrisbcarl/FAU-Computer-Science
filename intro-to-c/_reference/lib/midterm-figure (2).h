//#include <iostream>
//using namespace std;
//
//int function4(int x)
//{
//
//	cout << "function 4 is caalled " << endl;
//	x = x + 1;
//	return x;
//}
// 
//void function5()
//{
//	cout << "function five is called" << endl;
//
//	
//
//}
//
//void function6(int x)
//{
//	x++;
//	cout << "function 6 is caled " << endl;
//
//}
//
//
//int main()
//{
//	int i = 1, x = 3;
//	while(i < 12)
//	{
//
//		//note on mutual exclusivity, there are two mutually exclusive statements
//		//branch if-2 will only run one branch, but both ifs will run
//		//NOTE: 1%3 == 1
//		if (i % 3 == 0)
//		{
//			function4(x);
//		}
//		if (i == 7)
//		{
//			function5();
//		}
//		else if (i % 3 == 1)
//		{
//			function6(x);
//			x++;
//		}
//
//		cout << "i = " << i <<  " x = " << x << endl;
//		i = i + 2;
//	}
//	return 0;
//}