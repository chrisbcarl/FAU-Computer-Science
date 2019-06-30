#pragma once

/*
Constantine Vittoratos		 Z23176568
callstats6
Description: The program is made to use classes
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
string input_file = "call_data6.txt";
string output_file = "weekly_call_info.txt";

class call_record
{
public:
	string firstname;
	string lastname;
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;

	call_record()
	{
		string firstname = "";
		string lastname = "";
		string cell_number = "";
		int relays = 0;
		int call_length = 0;
		double net_cost = 0;
		double tax_rate = 0;
		double call_tax = 0;
		double total_cost = 0;
	}
};

class call_class
{
public://the reason why the functions don't have paramwers in them is because we already have access to them thru *call_DB
	     call_class();
	     ~call_class(); //de-allocates all memory allocate to call_DB by operator new.
	bool is_empty(); //inline implementation
	bool is_full();//inline implementation
	int  search(const string & key);//returns location if item in listl; otherwise return -1
	void add(const string & key); //adds a call record to call_DB
	void remove(const string & key); //removes an item from the list
	void double_size();
	void process();
	void print(); //prints all the elements in the list to the screen
private:
	int count;
	int size;
	call_record * call_DB = 0;
};




/************************************************************************************************************************************/
//Name: default constructor
//Precondition: 
//Postcondition: 
//Decription: Reads the data file of call information (cell number, relays and call length) into the dynamic array of call record, 
//call_DB. If the count because equal to the size the function double_size is called and the memory allocated to call_DB is doubled.
/************************************************************************************************************************************/
call_class::call_class()
{
	int size = 5; //total amount of memory (cells) allocated for the dynamic array of call records
	int count = 0;
	call_DB = new call_record[size];

	/*
	input
	1) takes from file call_data.txt
	2) reads each line
	3) put each line into the array of call_record (shelf of call_record)
	*/
	ifstream in;
	in.open(input_file);
	if (in.fail())
	{
		cout << "INPUT FILE NOT OPENED" << endl;
		exit(1);
	}
	count = 0;

	string firstname = "";
	string lastname = "";
	string cell_number = "";
	int relays = 0;
	int call_length = 0;

	while (!in.eof())
	{
		if (is_full())
		{
			double_size();
		}
	
		in >> call_DB[count].firstname;
		in >> call_DB[count].lastname;
		in >> call_DB[count].cell_number;
		in >> call_DB[count].relays;
		in >> call_DB[count].call_length;
		count++;
	}
}

/***********************************************************************************************************************************/
//Name: is_empty
//Precondition: 
//Postcondition: 
//Decription: returns true if call_DB is empty
/**********************************************************************************************************************************/
bool call_class::is_empty()
{
	if (count == 0)
		return true;
	else
		return false;
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: 
//Postcondition: 
//Decription: returns true if call_DB is full
/*********************************************************************************************************************************/
bool call_class::is_full()
{
	if (count == size)
		return true;
	else
		return false;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: 
//Postcondition: 
//Decription: locates key in call_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int call_class::search(const string & key)
{
	for (int i = 0; i < count; i++)
	{
		if (call_DB[i].firstname == key)
			return i;
	}
	return -1;
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: 
//Postcondition: 
//Decription: adds a call_record to call_DB; if call_DB is full, double_size is called to increase the size of call_DB. The user 
//            is prompted to enter the firstname, lastname, cell number, relays and call length. 
/********************************************************************************************************************************/
void call_class::add(const string & key)
{
	if (is_full()) //this loop is meant to not count spaces
	{
		double_size();	//we double the size of the loop each time we get through 5, 10 names successively
	}
	istringstream iss;	//This declares iss as an input string stream
	iss.str(key);	//This connects iss to s by means of the dot operator

	string sss;			//I make this a string before the while loop
	while (!iss.eof()) //I made this loop to make sure that spaces are not counted
	{
		iss >> call_DB[count].firstname >> call_DB[count].lastname >> call_DB[count].cell_number >> call_DB[count].relays >> call_DB[count].call_length;
	}
	count++;
	process(); //this tells us the void function is for process
}

/********************************************************************************************************************************/
//Name: remove
//Precondition: 
//Postcondition: 
//Decription: remove key from call_DB if it is there.
/*******************************************************************************************************************************/
void call_class::remove(const string & key)
{
	int element = search(key); //we declare element to work with search
	if (element >= 0)
	{
		for (int i = element; i < count; i++)
		{
			call_DB[i] = call_DB[i + 1];	//this increments elements in our array
		}
	}
	else
	{
		cout << "string does not exist in call_DB" << endl; //this condition is for when the string does not call
	}
	count--;
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: 
//Postcondition: 
//Decription: doubles the size (capacity) of call_DB
/******************************************************************************************************************************/
void call_class::double_size()
{
	size *= 2;
	call_record *temp = new call_record[size];

	for (int i = 0; i<count; i++)
	{
		temp[i] = call_DB[i];
	}

	delete[] call_DB;
	call_DB = temp;
}


/******************************************************************************************************************************/
//Name: process
//Precondition: 
//Postcondition: 
//Decription: calculate the net cost, tax rate, call tax and total cost for every call record in call_DB.
/*****************************************************************************************************************************/
void call_class::process()
{
	/*
	process
	1) for each element in the array, process it
	*/
	for (int i = 0; i < count; i++)
	{
		if (call_DB[i].relays <= 1 && call_DB[i].relays <= 5)
		{
			call_DB[i].tax_rate = .01;
		}
		if (call_DB[i].relays <= 6 && call_DB[i].relays <= 11)
		{
			call_DB[i].tax_rate = .03;
		}
		if (call_DB[i].relays <= 12 && call_DB[i].relays <= 20)
		{
			call_DB[i].tax_rate = .05;
		}
		if (call_DB[i].relays <= 21 && call_DB[i].relays <= 50)
		{
			call_DB[i].tax_rate = .08;
		}
		else
		{
			call_DB[i].tax_rate = .12;
		}
		call_DB[i].net_cost = call_DB[i].relays / 50.0 * .40 * call_DB[i].call_length; //net cost equation

		call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate; //call tax equation

		call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax; //total cost equation
	}
}


/****************************************************************************************************************************/
//Name: print
//Precondition: 
//Postcondition: 
//Decription: prints every field of every call_record in call_DB formatted to the screen.
/***************************************************************************************************************************/
void call_class::print()
{
	/*
	output
	1) open a new file weekly_call_info.txt
	2) read each shelf line by line and output
	*/
	ofstream out;
	out.open(output_file);
	if (out.fail())
	{
		cout << "OUTPUT FILE NOT OPENED" << endl;
		exit(1);
	}
	cout.setf(ios::showpoint); //this magical equation makes cout round to the nearest 2 decimals
	cout.precision(2);
	cout.setf(ios::fixed);

	out.setf(ios::showpoint);	//this magical equation makes out round to the nearest 2 decimals
	out.precision(2);
	out.setf(ios::fixed);
	for (int i = 0; i < count; i++)
	{
		cout << call_DB[i].firstname << "\t" <<	//this is the display on msvs output
			call_DB[i].lastname << "\t" <<
			call_DB[i].cell_number << "\t" <<
			call_DB[i].relays << "\t" <<
			call_DB[i].call_length << "\t" <<
			call_DB[i].net_cost << "\t" <<
			call_DB[i].tax_rate << "\t" <<
			call_DB[i].call_tax << "\t" <<
			call_DB[i].total_cost << endl;

		out << call_DB[i].firstname << "\t" <<	//this is the display on weekly call info
			call_DB[i].lastname << "\t" <<
			call_DB[i].cell_number << "\t" <<
			call_DB[i].relays << "\t" <<
			call_DB[i].call_length << "\t" <<
			call_DB[i].net_cost << "\t" <<
			call_DB[i].tax_rate << "\t" <<
			call_DB[i].call_tax << "\t" <<
			call_DB[i].total_cost << endl;
	}
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: 
//Postcondition: 
//Decription: de-allocates all memory allocated to call_DB.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
call_class::~call_class()
{
	delete[] call_DB;
}


//driver to test the functionality of your class.
int call_stats6()
{
	call_class MyClass;
	//put code here to test your funcitons
	MyClass.process();
	MyClass.add("Oprah Winfrey1	5611234432	11	52"); //these were meant to demonstrate that the add works
	MyClass.add("Oprah Winfrey2	5611234454	50	502");
	MyClass.add("Oprah Winfrey3	5611234495	05	2");
	MyClass.print();
	cout << endl << endl << endl << "remove" << endl;
	MyClass.remove("Barack");
	MyClass.remove("Michelle");
	MyClass.print();

	return 0;
}