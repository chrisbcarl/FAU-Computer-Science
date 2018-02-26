#include <iostream>
#include <cmath>
using namespace std;
double circumference(int r)
{
    double pi = 3.1415;
    cout<<"Hello I am going to compute ";
    cout<<"circumference of a circle of radius "<< r <<endl;
    return  2* pi * r ;
}
int areaofsquare(int w, int d, double red1, double red2)
{	cout<<"Hello first function is called"<<endl;
    return w * d;
}
int areaofsquare(int w, int d)
{
    cout<<"Hello second function is called"<<endl;
    return w * d;
}
//double areaofsquare(int w, int d);
double areaofsquare(double w, double d)
{
    cout<<"Hello thrid function is called"<<endl;
    return w * d;
}

void dosomething()
{
    cout<<"print a b c"<<endl;
}
void testsomething();
int testsomething2(int, int);
void function2()
{
    cout<<"function 2 is called"<<endl;
}
void function1()
{
    cout<<"function1 is called"<<endl;
    function2();
}
/*
int main()
{
    function1();
    function2();
    testsomething();
 
    //testsomthing2(1,2);
      return 0;
}
 */


void testsomething()
{
    cout<<"test something"<<endl;
}

int testsomthing2(int x, int y)
{
    cout<<"test something 2"<<endl;

    return 1;
}