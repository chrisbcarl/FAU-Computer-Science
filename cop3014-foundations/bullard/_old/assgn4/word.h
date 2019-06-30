//
//  word.h
//  WORD
//
//  Created by sphota on 9/24/15.
//  Copyright © 2015 Lex Levi. All rights reserved.
//
#ifndef WORD_H_
#define WORD_H_

#include <iostream>
#include <string>
using namespace std;

class CHARACTER {
	//node
 public:
	char symbol;
	CHARACTER *next;
};

class WORD {
	
 public:
	WORD(); // default ctor
	WORD(const string & s); // explicit-value ctor
	WORD(const WORD & Org); // copy ctor
	~WORD(); // dtor
	
	int Length(); // returns length of WORD
	bool IsEmtpy(); // returns true if WORD is empty
	string AsString(); // converts current object to a string representation
	bool IsEqual(const WORD & Org); // returns true if passed WORD is identical to current object
	
	void operator=(const string & s); // deep-assigns string to current object
	void operator+(const WORD & b); // appends representation of orig to end of current WORD
	WORD & operator=(const WORD & other); // deep-assigns orig to current object
	friend ostream & operator<<(ostream & out, const WORD & Org); // outputs contents of orig WORD to console with chaining
	
	void Insert(const WORD & w, const int & p); // insert word w into current object before position p
	void Remove(const WORD & w); // remove first instance of w from current object
	void RemoveALL(const WORD & w); // remove all instances of w from a
	
 private:
	CHARACTER *front, *back;
	int length;
};

#endif /* WORD_H_ */