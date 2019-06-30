/*
//Name:Carl Saintilmont                                 Z#:23393739
//Course: Foundations of Computer Science (COP3014)
//Professor: Dr. Lofton Bullard
//Due Date:11/20/2016                     Due Time:11:59pm
//Total Points: 100
//Assignment 6: assignment9/ call_stats6
//Description: Modify my implementation of “call_class”. The class will still manage a dynamic
array of call records

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


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
};

class call_class
{
public:
	call_class();
	~call_class(); //de-allocates all memory allocate to call_DB by operator new.
	bool is_empty(); //inline implementation
	bool is_full(int count, int size);//inline implementation
	int search(const string key);//returns location if item in listl; otherwise return -1
	void add(); //adds a call record to call_DB
	call_class & operator-(const string key); //removes an item from the list
	void double_size(call_record *&, int count, int size); // pass the call record by reffference 
	void process();
	friend ostream & operator<<(ostream & out_to_file, call_class & Org); //prints all the elements in the 
																		  //list to the screen.
private:
	int count;
	int size;
	call_record *call_DB;
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
	size = 20; // after initiatyze double size , set it to small value
	count = 0;
	call_DB = new call_record[size];// declare a dynamic array
	ifstream in("callstats_data.txt"); // declare object of type call record[size] , need to initialyze count to zero
									   //check if it's open
									   //while we're not at the end of the file
	while (!in.eof())//the code when we run it only give use one name so we use a while loop to keep reading until it is empty
	{
		if (is_full(count, size)) // after iostream open the file, use a loop to read it
		{
			double_size(call_DB, count, size);
		}
		in >> call_DB[count].firstname;
		in >> call_DB[count].lastname;
		in >> call_DB[count].cell_number;
		in >> call_DB[count].relays;
		in >> call_DB[count].call_length;

		++count;
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
	{
		return true;
	}
	return false;
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: 
//Postcondition: 
//Decription: returns true if call_DB is full
/*********************************************************************************************************************************/
bool call_class::is_full(int count, int size)
{
	if (count == size)
	{
		return true;
	}
	return false;
}
/**********************************************************************************************************************************/
//Name: search
//Precondition: 
//Postcondition: 
//Decription: locates key in call_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int call_class::search(const string key)
{
	for (int i = 0; i < count; i++)
	{
		if (key == call_DB[i].cell_number)
		{
			return i;
		}
	}
	return -1;
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: 
//Postcondition: 
//Decription: adds the informaton for a call record to call_DB; if call_DB is full, double_size is called to increase the size of call_DB.
/********************************************************************************************************************************/
void call_class::add()
{
	char choice = 'n';
	do {
		if (is_full(count, size))
		{
			double_size(call_DB, count, size);  // INCREASING THE SIZE OF THE DYNAMIC ARRAY
		}
		cout << "\nEnter the first name into the field: ";
		cin >> call_DB[count].firstname;
		cout << "\nEnter the last name into the field: ";
		cin >> call_DB[count].lastname;
		cout << "\nEnter the cell number into the field: ";
		cin >> call_DB[count].cell_number;
		cout << "\nEnter the number of relays into the field: ";
		cin >> call_DB[count].relays;
		cout << "\nEnter the length of the call into the field: ";
		cin >> call_DB[count].call_length;
		count++;
		cout << "\nWould you like to make another entry (y or n): ";
	} while (choice == 'y');
}

/********************************************************************************************************************************/
//Name: operator-
//Precondition: 
//Postcondition: 
//Decription: remove key from call_DB if it is there.
/*******************************************************************************************************************************/
call_class & call_class::operator-(const string key)
{
	int k = search(key); //we declare element to work with search
	if (k>= 0)
	{
		count--;
		for (int i = k; i < count; i++)
		{
			call_DB[i] = call_DB[i + 1];	//this swaps elements in our array
		}
	}
	else
	{
		cout << "phone # not exist in call_DB" << endl; //this condition is for when the string does not call
	}
	
	return *this;
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: 
//Postcondition: 
//Decription: doubles the size (capacity) of call_DB
/******************************************************************************************************************************/
void call_class::double_size(call_record *&call_DB, int count, int size)
{
	size *= 2;  //step 1: double the capacity which is size in the program
	call_record *temp = new call_record[size];  //step 2: allocate new memory
	for (int i = 0; i < count; i++)  //step 3: copy contents of old memory (call_DB) into new memory
	{
		temp[i] = call_DB[i];
	}
	delete[] call_DB; //step 4: de-allocate old memory pointed to by call_DB; 
	call_DB = temp;  //step 5: set call_DB to point to new memory;
}


/******************************************************************************************************************************/
//Name: process
//Precondition: 
//Postcondition: 
//Decription: calculate the net cost, tax rate, call tax and total cost for every call record in call_DB.
/*****************************************************************************************************************************/
void call_class::process()
{
	for (int i = 0; i < count; i++) {
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
	}
	int i = 0;
	while (i < count) {
		call_DB[i].net_cost = call_DB[i].relays / 50.0 * .40 * call_DB[i].call_length;
		call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;
		call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;
		i++;
	}
}


/****************************************************************************************************************************/
//Name: operator<<
//Precondition: 
//Postcondition: 
//Decription: Overloading operator<< as a friend function. Prints every field of every call_record in call_DB 
//                   formatted to the screen and a file called "stats7_output.txt".
/***************************************************************************************************************************/
ostream & operator<<(ostream & out, call_class & Org)
{
	for (int i = 0; i < Org.count; i++)
	{
		out << Org.call_DB[i].firstname << "  " << Org.call_DB[i].lastname
			<< "  " << Org.call_DB[i].relays << "  " << Org.call_DB[i].cell_number
			<< "  " << Org.call_DB[i].call_length << endl;
	}

	//Put code to OPEN and CLOSE an ofstream and print to the file "stats7_output.txt".

	return out;  //must have this statement
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: 
//Postcondition: 
//Decription: de-allocates all memory allocated to call_DB.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
call_class::~call_class()
{
	delete[] call_DB;  // same name as the class with no return name ~class_class
}


//driver to test the functionality of your class.
int main()
{
	cout << "TEST1: Testing the Default Constructor, is_full and double_size\n";
	call_class MyClass;
	cout << "Finish TEST1: testing the default constructor\n\n\n\n";

	cout << "Test2: Testing add, double_size, process, and is_full() \n";
	MyClass.add();
	cout << "Finish TEST2\n\n\n\n";

	cout << "Test3: Testing operator-, serach, and is_empty\n";
	MyClass - "5617278899" - "9546321555" - "1234567890";
	cout << "Finish TEST3\n\n\n\n";

	cout << "Test4: Testing operator<<\n\n";
	cout << MyClass << endl;
	cout << "Finish TEST4\n\n\n\n";

	cout << "The destructor will be called automatically\n";

	return 0;
}
