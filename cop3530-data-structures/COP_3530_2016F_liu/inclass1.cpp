

#include <iostream>
#include<cmath>
using namespace std;

int globenum=0;
class Point
{
public:
    int x,y;
    Point()
    {
        x=0; y=0; z=0;
        globenum++;
        cout<<"Constructor 1 is called"<<endl;
    }
    Point(int a)
    {
        x=a;
        globenum++;
        cout<<"Constructor 2 is called"<<endl;
    }
    double norm()
    {
        return sqrt(x*x + y*y+ z*z);
    }
    void setz(int a)
    {
        z=a;
    }
    ~Point();
    void publicprint();

    
private:
    int z;
    void privateprint()
    {
        cout<<z<<endl;
    }
};


Point::~Point()
{
    cout<<"Destructor is called"<<endl;
}

void Point::publicprint()
{
    privateprint();
}


void function1()
{

    Point a,b(10);
    
}

int main()
{
    Point a, b(10);
    Point *c;
    c= new Point(5);
    
    cout<<globenum<<endl;
    cout<<b.norm()<<endl;
    cout<< (*c).norm()<<endl;
    c->norm();
    return 0;
}

