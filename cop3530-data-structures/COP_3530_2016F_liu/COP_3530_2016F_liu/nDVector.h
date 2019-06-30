#pragma once

#include "std_libraries.h"

class nDVector
{
private:
	int size;
	int count;
	int*p;

	bool isFull();
	bool isEmpty();
	void doubleSize();
public:
	nDVector();// default constructor
	nDVector(int c); // set the size to be as the input
	nDVector(const nDVector &b); // copy constructor
	~nDVector();//destructor

	int getSize();
	int getLength();
	int get(int i);//get p[i]
	void set(int i, int val);// set p[i] to be val, need to check whether it is out of bound
	void remove(int i);//remove p[i] (dimension reduced)
	void append(int x); // append x to the end of the vector (need to increase the dimension)

	void operator=(const nDVector &b); // assignment operator
	nDVector operator+(const nDVector &b);// add two nDVector's if their dimensions match
	nDVector operator-(const nDVector &b);// similar as above
	int operator*(const nDVector &b);// inner product of two nDVector's if their dimensions match
	nDVector operator*(const int x); //scalar product

	friend std::ostream& operator << (std::ostream &, const nDVector &);
	friend std::istream& operator >> (std::istream &, nDVector &);
};

/*
constructor
*/
nDVector::nDVector()
{
	size = 2;
	count = 0;
	p = new int[size];
}

/*
constructor
@param c - actual size of a vector such that 2^n > c
*/
nDVector::nDVector(int c)
{
	size = 2;
	while (size <= c) size *= 2;
	count = 0;
	p = new int[size];
}

/*
copy constructor using constant reference
*/
nDVector::nDVector(const nDVector& b)
{
	size = b.size;
	count = b.count;
	p = new int[size];
	for (int i = 0; i < count; i++)
	{
		p[i] = b.p[i];
	}
}

/*
destructor that deallocates dynamic array memory
*/
nDVector::~nDVector()
{
	delete[] p;
}

/*
returns amount of elements in nDVector
@return count
*/
int nDVector::getSize()
{
	return count;
}

/*
returns size of whole nDVector
@return size
*/
int nDVector::getLength()
{
	return size;
}

/*
gets an element
@param i - element to access nDVector
@return item at element i
*/
int nDVector::get(int i)
{
	if ((i < count) && (i > 0)) return p[i];
	else
	{
		std::cout << "INVALID ADDRESS REFERENCE: " << i << std::endl;
		return 0;
	}
}

/*
modifies an element
@param i - element to access nDVector
@param val - value to replace at element i
@postcondition - p modified
*/
void nDVector::set(int i, int val)
{
	if ((i < count) && (i > 0)) p[i] = val;
	else std::cout << "INVALID ADDRESS REFERENCE: " << i << std::endl;
}

/*
removes an element and shifts the others.
@param i - element to access nDVector
@postcondition - p modified
*/
void nDVector::remove(int i)
{
	if ((i < count) && (i > 0))
	{
		for (int n = i; n < count; n++)
		{
			p[n] = p[n + 1];
		}
		count--;
	}
	else
	{
		std::cout << "INVALID ADDRESS REFERENCE: " << i << std::endl;
	}
}

/*
adds an element to the end of the nDVector
@param x - value of new element to add
@postcondition - p modified
*/
void nDVector::append(int x)
{
	if (isFull())
	{
		doubleSize();
	}
	p[count] = x;
	count++;
}

/*
assignment overload using constant nDVector reference
@format
nDVector foo = nDvector();
nDVector bar = foo;
*/
void nDVector::operator=(const nDVector& b)
{
	size = b.size;
	count = b.count;
	for (int i = 0; i < count; i++)
	{
		p[i] = b.p[i];
	}
}

/*
addition overload using constant nDVector reference
@precondition both operands have same count
@return new nDVector
@format
nDVector foo = nDvector();
nDVector bar = nDvector();
nDVector foobar = foo + bar;
*/
nDVector nDVector::operator+(const nDVector& b)
{
	if (count != b.count)
	{
		std::cout << "size missmatch" << "\t god I wish I had Java exceptions" << std::endl;
		return 0;
	}

	nDVector n = *this;
	for (int i = 0; i < n.count; i++)
	{
		n.p[i] += b.p[i];
	}

	return n;
}

/*
addition overload using constant nDVector reference
@precondition both operands have same count
@return new nDVector
@format
nDVector foo = nDvector();
nDVector bar = nDvector();
nDVector foobar = foo - bar;
*/
nDVector nDVector::operator-(const nDVector& b)
{
	if (count != b.count)
	{
		std::cout << "size missmatch" << "\t god I wish I had Java exceptions" << std::endl;
		return 0;
	}

	nDVector n = *this;
	for (int i = 0; i < n.count; i++)
	{
		n.p[i] -= b.p[i];
	}

	return n;
}

/*
multiplication overload using constant nDVector reference
@precondition both operands have same count
@return dot product
*/
int nDVector::operator*(const nDVector& b)
{
	if (count != b.count) return 0;
	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += this->p[i]* b.p[i];
	}
	return sum;
}

/*
multiplication overload
@return new nDVector, a vector multiple
*/
nDVector nDVector::operator*(const int x)
{
	nDVector n = nDVector(*this);
	for (int i = 0; i < n.count; i++)
	{
		n.p[i] *= x;
	}
	return n;
}

/*
return whether the nDVector is full
@return bool
*/
bool nDVector::isFull()
{
	return size == count;
}

/*
return whether the nDVector is empty
@return bool
*/
bool nDVector::isEmpty()
{
	return count == 0;
}


/*
expands the size of the nDVector
@precondition   - isFull() == true
@postcondition  - isFull() == false
*/
void nDVector::doubleSize()
{
	size *= 2;
	int* p_temp = new int[size];
	for (int i = 0; i < count; i++)
	{
		p_temp[i] = p[i];
	}
	delete[] p;
	p = p_temp;
}

/*
std::ostream << overload using std::ostream reference and constant nDVector reference
@format
nDVector foo = nDvector();
nDVector bar = nDvector();
std::ostream << foo << bar;
*/
std::ostream& operator<<(std::ostream& out, const nDVector& n)
{
	for (int i = 0; i < n.count; i++)
	{
		out << n.p[i] << " ";
	}
	return out;
}

/*
std::istream >> overload using std::istream reference and constant nDVector reference
@format
nDVector foo = nDvector();
std::istream >> foo;
*/
std::istream& operator >> (std::istream& in, nDVector& n)
{
	for (int i = 0; i < n.count; i++)
	{
		in >> n.p[i];
	}
	return in;
}

/*
driver file
*/
void nDVectorTest()
{
    nDVector test;										//test constructor
    nDVector test1 = nDVector(test);					//test copy constructor
    test1.append(1);
    test1.append(-1);
    test1.append(3);
    test1.append(0);
    test1.append(5);
    test1.append(7);									//test append()
    
    nDVector test2 = nDVector(6);						//test constructor 2
    nDVector test3 = test1;								//test assignment operator
    
    std::cout << test1 << std::endl;					//test << overload
    std::cout << test1.getSize() << std::endl;			//test getSize()
    std::cout << test1.getLength() << std::endl;		//test getLength()
    std::cout << test1.get(1) << std::endl;				//test get()
    std::cout << test1 << std::endl;
    std::cout << std::endl;
    
    std::cout << test2 << std::endl;
    std::cout << test2.getSize() << std::endl;
    std::cout << test2.getLength() << std::endl;
    std::cout << test2.get(1) << std::endl;
    std::cout << test2 << std::endl;
    std::cout << std::endl;
    
    std::cout << test3 << std::endl;
    std::cout << test3.getSize() << std::endl;
    std::cout << test3.getLength() << std::endl;
    std::cout << test3.get(4) << std::endl;
    std::cout << test3.get(5) << std::endl;
    std::cout << test3.get(6) << std::endl;
    test3.remove(8);
    test3.remove(2);									//test remove()
    test3.set(4, -2);
    test3.set(5, -69);
    test3.set(6, -4);									//test set()
    std::cout << test3 << std::endl;
    std::cout << std::endl;
    
    nDVector test4 = test1 + test1;						//test + overload
    std::cout << test4 << std::endl;
    std::cout << test4.getSize() << std::endl;
    std::cout << test4.getLength() << std::endl;
    std::cout << test4.get(4) << std::endl;
    std::cout << test4.get(5) << std::endl;
    std::cout << test4.get(6) << std::endl;
    test4.remove(8);
    test4.remove(2);
    test4.set(4, -2);
    test4.set(5, -69);
    test4.set(6, -4);
    std::cout << test4 << std::endl;
    std::cout << std::endl;
    
    test4 = test4 + test4;
    std::cout << test4 << std::endl;
    std::cout << test4.getSize() << std::endl;
    std::cout << test4.getLength() << std::endl;
    std::cout << test4.get(4) << std::endl;
    std::cout << test4.get(5) << std::endl;
    std::cout << test4.get(6) << std::endl;
    test4.remove(8);
    test4.remove(2);
    test4.set(4, -2);
    test4.set(5, -69);
    test4.set(6, -4);
    std::cout << test4 << std::endl;
    std::cout << std::endl;
    
    nDVector test5 = test4 - test4;						//test - overload
    std::cout << test5 << std::endl;
    std::cout << test5.getSize() << std::endl;
    std::cout << test5.getLength() << std::endl;
    std::cout << test5.get(4) << std::endl;
    std::cout << test5.get(5) << std::endl;
    std::cout << test5.get(6) << std::endl;
    test5.remove(8);
    test5.remove(2);
    test5.set(4, -2);
    test5.set(5, -69);
    test5.set(6, -4);
    std::cout << test5 << std::endl;
    std::cout << std::endl;
    
    std::cout << test1* test1 << std::endl;			//test* overload for dot product
    std::cout << test2* test2 << std::endl;
    std::cout << test3* test3 << std::endl;
    std::cout << test4* test4 << std::endl;
    std::cout << test5* test5 << std::endl;
    std::cout << std::endl;
    
    std::cout << test1* 3 << std::endl;				//test* for scalar multiple of vector
    std::cout << test2* 3 << std::endl;
    std::cout << test3* 3 << std::endl;
    std::cout << test4* 3 << std::endl;
    std::cout << test5* 3 << std::endl;
    std::cout << std::endl;
    
    nDVector test6 = test1;
    std::cin >> test6;									//test >> overload
    std::cout << test6 << std::endl;
    std::cout << test6.getSize() << std::endl;
    std::cout << test6.getLength() << std::endl;
    std::cout << test6.get(4) << std::endl;
    std::cout << test6.get(5) << std::endl;
    std::cout << test6.get(6) << std::endl;
    test6.remove(8);
    test6.remove(2);
    test6.set(4, -2);
    test6.set(5, -69);
    test6.set(6, -4);
    std::cout << test6 << std::endl;
    std::cout << std::endl;
}
