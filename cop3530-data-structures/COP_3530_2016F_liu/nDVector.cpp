
#include<iostream>

using namespace std;

class nDVector
{
public:
    nDVector();// default constructor
    nDVector(int c); // set the size to be as the input
    nDVector(const nDVector &b); // copy constructor
    ~nDVector();//destructor
    
    int getSize();
    int get(int i);//get p[i]
    void set(int i, int val);// set p[i] to be val, need to check whether it is out of bound
    void remove(int i);//remove p[i] (dimension reduced)
    void append(int x); // append x to the end of the vector (need to increase the dimension)
    
    
    void operator=(const nDVector &b); // assignment operator
    nDVector operator+(const nDVector &b);// add two nDVector's if their dimensions match
    nDVector operator-(const nDVector &b);// similar as above
    int operator*(const nDVector &b);// inner product of two nDVector's if their dimensions match
    nDVector operator*(const int x); //scalar product
    
private:
    int size;
    int *p;

};

//overload cin>> and cout<<


int main()
{

    return 0;
}