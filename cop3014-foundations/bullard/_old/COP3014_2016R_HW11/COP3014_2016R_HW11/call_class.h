#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "call_record.h"

using std::ostream;
using std::ifstream;
using std::ofstream;
using std::string;


class call_class
{
public:
	call_class();
	call_class(const call_class &original);
	call_class(ifstream & in_stream);
	~call_class(); //de-allocates all memory allocate to call_DB by operator new.
	bool is_empty(); //inline implementation
	bool is_full();//inline implementation
	int search(const string key, int &occur);//returns location if item in listl; otherwise return -1
	void add(/*const string key*/); //adds item inorder to the list
	int remove(const string key); //removes an item from the list
	void double_size();
	void process(int args);
	void print(int key); //prints one elements
	void print(ofstream & out_stream); //prints all valids to file
	void get(int &c, int &s) const;

	friend ostream& operator << (ostream &out_stream, const call_class &call_class_object);
	friend ostream& operator << (ofstream &out_stream, const call_class &call_class_object);
private:
	int count;
	int size;
	call_record* call_DB;
};