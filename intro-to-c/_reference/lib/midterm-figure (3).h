//#include <iostream>
//using namespace std;
//
//	int function1(int x, int y, int z) {
//	cout << "function 1 is called " << endl;
//	x = x + y;
//	y = z + x;
//	z = x - y;
//	cout << x << y << z << endl;
//	return x;
//}
//
//double function2(int x, int y, int z)
//{
//	cout << "function 2 is called" << endl;
//
//	double t = (x + x + y*y + z*z) / 4.0;
//	function1(x, y, z);
//	return t;
//}
//
//int main()
//{
//	int x = 3, y = 4, z = 5;
//	function1(x, y, z);
//	cout << "Main " << x << y << z;
//	cout << "hello" << endl;
//
//	x = x + 1;
//	y = y*y;
//	z = z + 2;
//	double d = function2(x, y, z);
//	cout << d << endl;
//
//	cout << "main " << x <<  y << z;
//	return 0;
//}