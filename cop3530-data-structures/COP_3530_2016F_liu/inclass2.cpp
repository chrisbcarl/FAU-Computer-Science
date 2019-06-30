

#include <iostream>
#include<cmath>
using namespace std;

int globenum=0;
class Point
{
public:
    int x,y, num;
    Point()
    {
        x=0; y=0; z=0;
        num = globenum++;
        cout<<"Constructor 1 is called"<<endl;
    }
    Point(int a)
    {
        x=a;
        y=0;
        num =globenum++;
        cout<<"Constructor 2 is called"<<endl;
    }
    
    Point (const Point &t) //copy constructor
    {
        num =globenum++;
        cout<<"Copy constructor is called"<<endl;
    
    }
    double norm()
    {
        return sqrt(x*x + y*y+ z*z);
    }
    void setz(int a)
    {
        z=a;
    }
    ~Point(); // destructor
    void publicprint();
    
    Point operator*(int c)// Point object * int
    {
        Point t;
        t.x= this->x*c;
        t.y=this->y*c;
        t.z= this->z*c;
        cout<<"hello"<<endl;
        return t;
    }
    
    Point operator+(const Point &b);
   
    
    void operator=(const Point &b)
    {
        cout<<"operator = is called"<<endl;
        
    }
    void display(ostream &out) const
    {
        out<<"(" << x<<" "<<y<<" "<<z<<")";
    }
    
    void input(istream &in)
    {
        cout<<"Input (x y z):"<<endl;
        cin>>x>>y>>z;
    }
    
private:
    int z;
    void privateprint()
    {
        cout<<z<<endl;
    }
};


Point::~Point()
{
    cout<<"Destructor is called: " << num <<endl;
}

void Point::publicprint()
{
    privateprint();
}

Point Point::operator+(const Point &b)
{
    Point ans;
    ans.x= x + b.x;
    ans.y= y+b.y;
    ans.z=z+b.z;
    return ans;

}



void function1()
{
    
    Point a,b(10);
    
}

Point function2(Point t)
{
    Point z;
    return z;
    
}

Point operator*(int x, const Point &a)
// int * Point
{
    Point z;
    z.x= a.x * x;
    z.y=a.y*x;
    
    return z;

}

ostream & operator<<(ostream &out, const Point &b)
{

    b.display(out);
    return out;
}


istream & operator>>(istream &in, Point &b)
{
    b.input(in);
    return in;
}


class C1
{
public:
    int x;
};


class C2
{
public:
    int x;
};


int operator-(C1 x,C2 y)// you can define operator over two different objects
{

    return x.x-y.x;
}

int main()
{
    Point a, b(10);
    Point *c;
    
  //  c= new Point(5);

   // function1();
   // function1();
    
    cout<<function2(a).x<<endl;;
    cout<<(b*3).x<<endl;
    cout<<b<<endl;
    
    
    cin>>a;
    cout<<a+b<<endl;
    
    return 0;
}

