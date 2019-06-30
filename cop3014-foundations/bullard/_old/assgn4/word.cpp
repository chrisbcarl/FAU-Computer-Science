//
//  word.cpp
//  WORD
//
//  Created by sphota on 9/24/15.
//  Copyright © 2015 Lex Levi. All rights reserved.
//

#include <stdio.h>
#include "word.h"

/*
 * word.cpp
 
 *
 *  Created on: Sep 24, 2015
 *      Author: lexlevi
 */

//*************************************************************************************
//Name:  WORD
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to null pointers (front, back and length)
//Description:  This is the default constructor which will be called automatically when
//				 an object is declared.  It will initialize the state of the class
//				 The front and back pointers of the list are initialized to null. The length
//				 is initialized to 0;
//*************************************************************************************

WORD::WORD() {
	//cout << endl << "*** WORD( DEFAULT ) ***" << endl;
	front = back = 0;
	length = 0;
}

//*************************************************************************************
//Name:  WORD ( string )
//Precondition: The state of the object (private data) has not been initialized, a constant string is passed
//Postcondition: The state has been initialized to a front pointer pointing to the first character of the string
//				 and the back pointer pointing to the last character of the string
//Description:  This is the explicit-value constructor that is called when a string constant is passed to the
//				constructor. The front and back pointers of the list are initialized to the first and last
//				characters of the string, respectively, as CHARACTER nodes. The rest of the string's characters
//				are added to the list afterwards.
//*************************************************************************************

WORD::WORD(const string & s) {
	//cout << "*** WORD( " << s << " ) ***" << endl;
	
	CHARACTER *first = new CHARACTER;

	front = back = first;
	length = (int)s.length();
		
	front->symbol = s[s.length() - 1];
	back->symbol = s[s.length() - 1];
		
	for (int i = length - 2; i >= 0; --i) {
		CHARACTER *c = new CHARACTER;
			
		c->symbol = s[i];
		
		CHARACTER *temp = front;
		front = c;
		c->next = temp;
	}
	
}

//*************************************************************************************
//Name:  WORD ( copy )
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized as a copy of the passed WORD object
//Description:  This is the copy constructor which will be called everytime a WORD object
//				is passed to the constructor. The passed object's contents are converted to a string,
//				and the contents of the string are added to the current object as CHARACTER nodes.
//*************************************************************************************

WORD::WORD(const WORD & Org) {
	//cout << endl << "*** WORD( COPY ) ***" << endl;
	
	string s;
	int i;

	front = back = 0;
	i = length = Org.length;
	
	CHARACTER *c = Org.front;
	
	/* convert to string */
	while (c && i >= 0)
	{
		s.push_back(c->symbol);
		c = c->next;
		i--;
	}
	
	CHARACTER *first = new CHARACTER;
	front = back = first;
	
	front->symbol = s[s.length() - 1];
	back->symbol = s[s.length() - 1];
	
	for (int j = length - 2; j >= 0; --j) {
		CHARACTER *c = new CHARACTER;
		
		c->symbol = s[j];
		
		CHARACTER *temp = front;
		front = c;
		c->next = temp;
	}
}

//*************************************************************************************
//Name:  ~WORD()
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The dynamic memory belonging to the current object is freed
//Description: Every pointer's memory in the current object is freed
//*************************************************************************************


WORD::~WORD() {
	//cout<< endl << "*** ~WORD( " << (*this).AsString() << " ) ***" << endl;
	while (front != 0)
	{
		CHARACTER *p = front;
		front = front->next;
		delete p;
	}
}

//*************************************************************************************
//Name:  Insert()
//Precondition: The current object has been initialized (either empty or containing nodes)
//Postcondition: The current object has been populated with the characters in the passed object
//Description:  The insert method creates a copy of the passed object and the pointer of the
//				current object before position p points to the front of the copied passed object.
//*************************************************************************************

void WORD::Insert(const WORD & w, const int & p) {
	//cout << endl << "*** INSERT( WORD ) ***" << endl;
	
	int j = 0;

	WORD *v = new WORD(w);
	CHARACTER *offset, *end = 0;

	offset = front;
	
	while (offset) {
		if (p == 0) {
			break;
		}
		if (j == p - 1) {
			break;
		}
		offset = offset->next;
		j++;
	}
	
	if (p <= 1) {
		//cout << "PUSHING " << (*v) << " at the FRONT of " << (*this) << endl;
		length += w.length;
		CHARACTER *temp = front;
		front = v->front;
		v->back->next = temp;
	}
	else if (j >= length - 1) {
		//cout << "PUSHING " << (*v) << " at the BACK of " << (*this) << endl;
		length += w.length;
		back->next = v->front;
		back = v->back;
	}
	else {
		end = offset->next;
		//cout << "INSERTING " << (*v) << " : BETWEEN " << offset->symbol << " AND " << end->symbol << " IN " << (*this) << endl;
		length += w.length;
		offset->next = v->front;
		v->back->next = end;
	}
}

//*************************************************************************************
//Name:  IsEmpty()
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: Returns true if list is empty (front in null), false otherwise
//Description:
//*************************************************************************************

bool WORD::IsEmtpy() {
	return front == 0;
}

//*************************************************************************************
//Name:  operator <<
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The characters of the current object are outputed to the console
//Description:  The characters of the current object are passed to the ostream variable,
//				which in turn is returned for chaining.
//*************************************************************************************

ostream & operator<<(ostream & out, const WORD & Org) {
	cout << endl;
	
	CHARACTER *p;
	
	for (p = Org.front; p; p = p->next) {
		cout << p->symbol;
	}
	
	cout << endl;
	
	return out;
}

//*************************************************************************************
//Name:  operator =
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The dynamic memory of the current object is freed. The state of the current object
//				is initialized to the state of the copy of the passed object.
//Description:
//*************************************************************************************

WORD & WORD::operator=(const WORD &other) {
	//cout << endl << "ASSIGNING " << other << " TO " << (*this) << endl;
	
	if (!(*this).IsEqual(other)) {
		length = other.length;
		
		CHARACTER *temp = front;
		while (front) {
			front = front->next;
			delete temp;
			temp = front;
		}
		
		WORD *w = new WORD(other);
		
		front = w->front;
		back = w->back;

		//cout << this << " is now " << (*this);
		
		return (*this);
	}
	else {
		return (*this);
	}
}

//*************************************************************************************
//Name:  operator = string
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The current object's dynamic memory is freed and the explicit-value constructor with
//				 string constant is called.
//Description:
//*************************************************************************************

void WORD::operator=(const string &s) {
	//cout << endl << "ASSIGNING STRING \"" << s << "\" TO " << (*this) << endl;
	
	length = (int)s.length();
	
	CHARACTER *temp = front;
	while (front) {
		front = front->next;
		delete temp;
		temp = front;
	}
	
	(*this) = *new WORD(s);
	
	//cout << this << " is now " << (*this);
}

//*************************************************************************************
//Name:  operator + string
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The current object is appeded to with the characters of the passed object
//Description:  The + operator calls the Insert() method, which inserts the passed object
//				to the current object at the back.
//*************************************************************************************

void WORD::operator+(const WORD &b) {
	(*this).Insert(b, length);
}

//*************************************************************************************
//Name:  Length()
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state variable "length" is returned.
//Description:  This getter method Length() returns the state variable "length"
//*************************************************************************************

int WORD::Length() {
	return length;
}

//*************************************************************************************
//Name:  IsEqual()
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: Returns true if the passed object's characters are equal to the current object's,
//				 false otherwise.
//Description:
//*************************************************************************************


bool WORD::IsEqual(const WORD & Org) {
	string sCurent = (*this).AsString();
	string sOrg = WORD(Org).AsString();
	
	return (sCurent	== sOrg) ? true : false;
}

//*************************************************************************************
//Name:  Remove()
//Precondition: The state of the object (private data) has not been initialized, an object is passed
//Postcondition: The characters of the passed object are removed from the current object, if they
//				 are present.
//Description:  The Remove() method creates a string representation of both the passed object
//				and the current object. The former is removed from the latter using C++'s
//				string manipulation methods. The current object is initialized to the new string.
//*************************************************************************************

void WORD::Remove(const WORD &w) {
	WORD copy = WORD(w);
	
	//cout << endl << "REMOVING \"" << copy.AsString() << "\" FROM \"" << (*this).AsString() << "\"" << endl;
	
	string current_s = (*this).AsString();
	string orig_s = copy.AsString();
	
	CHARACTER *temp = front;
	while (front) {
		front = front->next;
		delete temp;
		temp = front;
	}
	
	if (current_s.length() != 0) {
		size_t pos = current_s.find(orig_s);
		current_s.erase(pos, orig_s.length());
		
		(*this) = WORD(current_s);
	}
}

//*************************************************************************************
//Name:  RemoveAll()
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: All instances of the characters of the passed object are removed from the current object, if they
//				 are present.
//Description:  The RemoveALL() method creates a string representation of both the passed object
//				and the current object. The former is removed from the latter using C++'s
//				string manipulation methods. The current object is initialized to the new string.
//*************************************************************************************

void WORD::RemoveALL(const WORD &w) {
	WORD copy = WORD(w);
	
	//cout << endl << "REMOVING ALL \"" << copy.AsString() << "\" FROM \"" << (*this).AsString() << "\"" << endl;
	
	string current_s = (*this).AsString();
	string orig_s = copy.AsString();
	
	CHARACTER *temp = front;
	while (front) {
		front = front->next;
		delete temp;
		temp = front;
	}
	
	size_t pos = current_s.find(orig_s);
	while (pos != string::npos) // removes all occurences of a subtring
	{
		current_s.erase(pos, orig_s.length());
		pos = current_s.find(orig_s);
	}
	
	(*this) = WORD(current_s);
}

//*************************************************************************************
//Name:  AsString()
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: A string representation of the current object is returned
//Description:  The character nodes of the current object are formed into a string, which
//				is returned.
//*************************************************************************************

string WORD::AsString() {
	string s;
	int i;
	
	i = length = (*this).length;
	
	CHARACTER *c = (*this).front;
	
	/* convert to string */
	while (c && i >= 0)
	{
		s.push_back(c->symbol);
		c = c->next;
		i--;
	}

	return s;
}

