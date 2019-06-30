#pragma once

#include <iostream>
#include <cassert>
#include <new>
#include <iostream>

using namespace std;

typedef int StackElement;

class Stack
{
public:
	Stack(int numElements = 128);
	Stack(const Stack & original);
	~Stack();
	const Stack & operator= (const Stack & rightHandSide);

	bool empty() const;
	void push(const StackElement & value);
	void display(ostream & out) const;
	StackElement top() const;
	void pop();
private:
	int myCapacity,           // capacity of stack
		myTop;                // top of stack
	StackElement * myArray;   // dynamic array to store elements

};


Stack::Stack(int numElements)
{
	assert(numElements > 0);  // check precondition
	myCapacity = numElements;  // set stack capacity
							   // allocate array of this capacity
	myArray = new(nothrow) StackElement[myCapacity];
	if (myArray != 0)          // memory available
		myTop = -1;
	else
	{
		cerr << "Inadequate memory to allocate stack \n"
			" -- terminating execution\n";
		exit(1);
	}                          // or assert(myArray != 0);
}


Stack::Stack(const Stack & original)
	: myCapacity(original.myCapacity), myTop(original.myTop)
{
	//--- Get new array for copy
	myArray = new(nothrow) StackElement[myCapacity];
	if (myArray != 0)                 // check if memory available
									  // copy original's array member into this new array
		for (int pos = 0; pos <= myTop; pos++)
			myArray[pos] = original.myArray[pos];
	else
	{
		cerr << "*Inadequate memory to allocate stack ***\n";
		exit(1);
	}
}


Stack::~Stack()
{
	delete[] myArray;
}


const Stack & Stack::operator=(const Stack & rightHandSide)
{
	if (this != &rightHandSide)                // check that not st = st
	{
		//-- Allocate a new array if necessary
		if (myCapacity != rightHandSide.myCapacity)
		{
			delete[] myArray;                    // destroy previous array

			myCapacity = rightHandSide.myCapacity;  // copy myCapacity 
			myArray = new StackElement[myCapacity];
			if (myArray == 0)                    // check if memory available
			{
				cerr << "*** Inadequate memory ***\n";
				exit(1);
			}
		}

		myTop = rightHandSide.myTop;            // copy myTop member
		for (int pos = 0; pos <= myTop; pos++)  // copy stack elements
			myArray[pos] = rightHandSide.myArray[pos];

	}
	return *this;
}


bool Stack::empty() const
{
	return (myTop == -1);
}


void Stack::push(const StackElement & value)
{
	if (myTop < myCapacity - 1) //Preserve stack invariant
	{
		++myTop;
		myArray[myTop] = value;
	}
	else
	{
		cerr << "*** Stack full -- can't add new value ***\n"
			"Must increase the stack's capacity.\n";
		exit(1);
	}
}


void Stack::display(ostream & out) const
{
	for (int i = myTop; i >= 0; i--)
		out << myArray[i] << endl;
}


StackElement Stack::top() const
{
	if (!empty())
		return (myArray[myTop]);
	else
	{
		cerr << "*** Stack is empty -- returning garbage value ***\n";
		StackElement garbage = -999999999;
		return garbage;
	}
}

//--- Definition of pop()
void Stack::pop()
{
	if (!empty())
		myTop--;
	else
		cerr << "*** Stack is empty -- can't remove a value ***\n";
}