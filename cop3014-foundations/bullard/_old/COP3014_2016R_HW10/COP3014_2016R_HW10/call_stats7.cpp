/*******************************************************************************

Name: Christopher Carl
Z#: Z23146703
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 16.07.24
Due Time: 23:59
Total Points: 100
Assignment 10: Call Cost Calculator w/ Friends and Overloaded Operators

DESCRIPTION:
This assignment is an extension of Unit 10 Programming Assingnment.  You will modify your implementation of “call_class”. The class will still manage a dynamic array of call records. Call this program "call_stats7.cpp".  I have provide the driver “call_stats7cpp” to help you implement this program.
Your input data will be in the file “callstats_data.txt.
The descriptions of the functions you will implement are as follows:
1.	(you implemented this in the previous program) the default constructor  to initialize the state of your class. The default constructor will read the data from the file “callstats_data.txt” into the dynamic array call_DB.  If call_DB becomes full, the function should call the function “double_size” to double the size (capacity) of call_DB. Remember, count and call_DB are private members of your class and do not need to  be passed to an member function  of your class.
2.	(you implemented this in the previous program) is_empty is a Boolean public member function of the class.  It has no formal parameter because count is a member of the state of the class (private member) and does not need to be passed to it because the state of the class if known to all member functions of the class. If count == 0 then true is returned; otherwise false is returned.
3.	(you implemented this in the previous program) is_full is a Boolean public member function of the class.  It has no formal parameters because count and size are members of the state of the class (private members) and do not need to be passed to it because the state of the class if known to all member functions of the class. If count == size then true is return; otherwise false. The size is the capacity which is the total number of cells allocated to call_DB.
4.	(you implemented this in the previous program) search is an integer public member function that has only one formal parameter, the key.  key is the cell phone number for the record you are search for. The array of records, call_DB and count are members of the state of the class and do not need to be passed to a member function of the class; The function will return the location of key in call_DB if it is there; otherwise -1 is returned.
5.	(you implemented this in the previous program) add is a void public member function that inserts key (cell number) into call_DB.  Duplicates cell numbers are ok; add will prompt the user for the firstname, lastname, relays and call length. You may call process record to re-process when you add a new record. add has only one formal parameter, the key.
6.	overload operator “-“ as a member function of call_class with chaining.  This function will have the same functionality as the “remove” function.  Recall the following about the function remove: “remove is a void public member function thaqt deletes all records with the cell number stored in key. If duplicate records exist with the same cell number they must all be deleted. “remove” has only one formal parameter, the key.” Note, because we are overloading with chaining we must return the current object “*this”.
7.	(you implemented this in the previous program) double_size is a void public member function that doubles the capacity of call_DB. “double_size” has no formal parameters because size, count and call_DB are all members of the state of the class, call_class. First, size is multipled by two; second, memory is allocated using “call_record *temp=new call_record[size]; third the records in call_DB are copied into temp with the statement “temp[i]=call_DB[i]” using a for loop. Forth, the old memory for call_DB is de-allocated using “delete [ ] call_DB”; Finally, call_DB is set to point to the new memory pointed to by temp using “call_DB = temp”.
8.	(you implemented this in the previous program) process is a void public member function the has no formal parameter because call_DB and count are members of the state of the class.. The function  process will calculate the net cost of a call (net_cost), the tax on a call (call_tax) and the total cost of the call (total_cost) using the number of relay stations (relays) and the length in minutes of the call (call_length) for all call records stored in call_DB.  Please consider the following:
a.	The tax rate on a call (call_tax) is simply based on the number of relay stations (relays) used to make the call  (0<= relays <=5 then call_tax = 1%; 6<= relays <=11 then call_tax = 3%; 12<= relays<=20 then call_tax = 5%; 21<= relays <=50 then call_tax = 8%; relays >50 then call_tax =12%) .
b.	The net cost of a call is calculated by the following formula:  net_cost = ( relays / 50  x  0.40 x call_length).
c.	The tax on a call is equal to net_cost x  call_tax / 100.
d.	The total cost of a call (rounded to the nearest hundredth) is calculated by the following formula: total_cost = net_cost + call_tax .  All tax and cost calculations should be rounded to the nearest hundredths.
9.	overload operator “<<“ as a friend function of call_class with chaining.  This function will have the same functionality as the “print” function except it will print to the screen and a file called “stats7_output.txt”.  Recall the following about the function print: “print is a void public member function that has no formal parameters because count and call_DB are members of the state of the class. The function will print every field of every call_record in call_DB to the screen”.
10.	the destructor to de-allocate all memory allocated to call_DB.  This function has no formal parameters because call_DB is a member of the state of the class. It will be called automatically by the compiler.


LOG:
16.07.11, 19:40 - START
16.07.11, 20:16 - 10th compile, << overloaded for call_class
16.07.11, 20:54 - 20th compile, - overloaded for call_record
16.07.11, 21:03 - qa'd, final edits
16.07.11, 21:17 - documentation added
16.07.11, 21:17 - formatting for readability/80char rule
16.07.11, 21:17 - STOP


BUG:	FOUND:			FIXED:			DESCIRPTION:
B0001	16.07.11,20:02  -               selecting print just prints addresses
|                       16.07.11,20:04  FIX: because I was just saying "this"
|                                       it's no suprise that addresses were 
|                                       being printed. "*this" is correct.

B0002	16.07.11,20:02  -               BUG: for some reason it prints all of
|                                       them over and over and over again?
|                       16.07.11,20:16  FIX: because I was calling a while loop
|                                       within print(ostream&), it's redundant
*******************************************************************************/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <ios>

using namespace std;


class call_record
{
public:
	friend call_record operator - (const call_record &call_DB_element);

	bool deleted = false;
	string firstname = "";
	string lastname = "";
	string cell_number = "";
	int relays = 0;
	int call_length = 0;
	double net_cost = 0;
	double tax_rate = 0;
	double call_tax = 0;
	double total_cost = 0;
};

class call_class
{
public:
	call_class();
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

	void call_class::get(int &c, int &s) const;

	friend ostream& operator << (ostream &out_stream, const call_class &call_class_object);
	friend ostream& operator << (ofstream &out_stream, const call_class &call_class_object);
private:
	int count;
	int size;
	call_record* call_DB;
};

bool isASCII_char(int i);
bool isASCII_num(int i);
void stringExtract(string got_line, string &firstname, string &lastname, string &number, int &relays, int &call_length);


//driver to test the functionality of your class.
int main()
{
	ifstream in_stream;		//declaring an input file stream
	ofstream out_stream;	//declaring an output file stream

	string user_response = "y";
	string input_filename = "callstats_data.txt";
	string output_filename = "call_info.txt";

	do
	{

		cout << "Use default file name? ";
		getline(cin, user_response);

		if ((user_response != "Y") && (user_response != "y"))
		{
			cout << "Enter the file name to parse: ";
			getline(cin, input_filename);
			cout << endl << endl;
		}

		in_stream.open(input_filename);

		if (in_stream.fail())
		{
			cout << "Input file did not open correctly" << endl;
		}
		else
		{

			int choice = 0;
			call_class MyClass = call_class(in_stream);


			//put code here to test your funcitons

			MyClass.process(0);
			MyClass.print(out_stream);

			do
			{
				int n = 0;
				int occur = 0;
				int count = 0; int size = 0; MyClass.get(count, size);
				string s;
				cout << "-MAIN MENU-" << endl;
				cout << "0 - Print record." << endl;
				cout << "1 - Add a record." << endl;
				cout << "2 - Search for a record." << endl;
				cout << "3 - Delete a record." << endl;
				cout << "4 - Save records." << endl;
				cout << "5 - Exit." << endl;
				cout << "Select an option: ";
				cin >> choice; cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //probably totally necessary.
				cout << endl << endl;
				switch (choice)
				{
				case 0:
					cout << "SELECTED: 0 - Print records." << endl;
					MyClass.process(0);
					MyClass.print(out_stream);
					break;
				case 1:
					cout << "SELECTED: 1 - Add a record." << endl;
					MyClass.add();
					break;
				case 2:
					cout << "SELECTED: 2 - Search for a record." << endl;
					cout << "Input phone number to search: ";
					cin >> s; cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //probably totally necessary.
					n = MyClass.search(s, occur);
					if (n > -1) cout << occur << " records exist. The first is record number: " << n + 1 << endl;
					else cout << "No record found." << n << endl;
					break;
				case 3:
					cout << "SELECTED: 3 - Delete a record." << endl;
					cout << "Input phone number to delete: ";
					cin >> s; cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //probably totally necessary.
					if (n > count) cout << "No record found. " << n << endl;
					else
					{
						n = MyClass.search(s, occur);
						if (n > -1) cout << occur << " records exist. The first is record number: " << n + 1 << endl;
						int r = MyClass.remove(s);
						cout << "Deleted " << r << " records." << endl;
					}
					break;
				case 4:
					cout << "SELECTED: 4 - Save records." << endl;
					cout << "Use default file name? ";
					getline(cin, user_response);
					if ((user_response != "Y") && (user_response != "y"))
					{
						cout << "Enter output file name: ";
						getline(cin, output_filename);
						cout << endl;
					}
					out_stream.open(output_filename);
					MyClass.process(0);
					MyClass.print(out_stream);
					out_stream.close();
					break;
				case 5:
					cout << "SELECTED: 5 - Exit." << endl;
					break;
				default:
					cout << "!!!INVALID!!!" << endl << endl;
					break;
				}

				cout << "Operation completed." << endl << endl;

				cout << "Again (Y or N)? ";
				getline(cin, user_response);
				cout << endl << endl;
			} while (user_response == "y" || user_response == "Y");
			MyClass.~call_class();
		}

		in_stream.close();

		cout << "Would you like to do another calculation (Y or N): ";
		getline(cin, user_response);
		cout << endl << endl;


	} while (user_response == "y" || user_response == "Y");

	return 0;
}



/*
Name:  call_class constructor (overload 1)
Precondition:       call_class instantiated

VARS:               void

RETURNS:            void

Postcondition:      new call_class object created
Description:        Creates a call_class object.
|                   Prompts the user for input file name and then creates
|                   a call_class object to interract with call_records
*/
call_class::call_class()
{
	ifstream in_stream;		//declaring an input file stream
	string input_filename = "callstats_data.txt";
	string user_response = "y";


	cout << "Use default file name? ";
	getline(cin, user_response);

	if ((user_response != "Y") && (user_response != "y"))
	{
		cout << "Enter the file name to parse: ";
		getline(cin, input_filename);
		cout << endl << endl;
	}

	in_stream.open(input_filename);

	int i = 0;
	size = 5; //total amount of memory (cells) allocated for the dynamic array of call records
	count = 0;
	string temp_name = "";
	call_DB = new call_record[size];
	while (!in_stream.eof())
	{
		if (is_full())
		{
			double_size();

			getline(in_stream, temp_name);
			stringExtract(temp_name, call_DB[i].firstname, call_DB[i].lastname, call_DB[i].cell_number, call_DB[i].relays, call_DB[i].call_length);

			i++;
			count++;
		}
		else
		{
			getline(in_stream, temp_name);
			stringExtract(temp_name, call_DB[i].firstname, call_DB[i].lastname, call_DB[i].cell_number, call_DB[i].relays, call_DB[i].call_length);
			i++;
			count++;
		}
	}

}



/*
Name:  call_class constructor (overload 2)
Precondition:       call_class instantiated
|                   VARS instantiated in higher function

VARS:               ifstream & in_stream

RETURNS:            void

Postcondition:      new call_class object created
Description:        Creates a call_class object.
|                   Prompts the user for input file name and then creates
|                   a call_class object to interract with call_records
*/
call_class::call_class(ifstream & in_stream)
{
	int i = 0;
	size = 5; //total amount of memory (cells) allocated for the dynamic array of call records
	count = 0;
	string temp_name;
	this->call_DB = new call_record[size];
	while (!in_stream.eof())
	{
		if (is_full())
		{
			double_size();

			getline(in_stream, temp_name);
			stringExtract(temp_name, this->call_DB[i].firstname, this->call_DB[i].lastname, this->call_DB[i].cell_number, this->call_DB[i].relays, this->call_DB[i].call_length);

			i++;
			count++;
		}
		else
		{
			getline(in_stream, temp_name);
			stringExtract(temp_name, this->call_DB[i].firstname, this->call_DB[i].lastname, this->call_DB[i].cell_number, this->call_DB[i].relays, this->call_DB[i].call_length);
			i++;
			count++;
		}
	}

}



/*
Name:  get
Precondition:       VARS instantiated in higher function

VARS:               int &c,
|                   int &s

RETURNS:            void

Postcondition:      VARS contain new data
Description:        GET the private attributes count and size from
|                   a call_class object
*/
void call_class::get(int &c, int &s) const
{
	c = count;
	s = size;
}; //prints all valids to file




   /*
   Name:  isASCII_char
   Precondition:       VARS definied in higher function

   VARS:               int i;

   RETURNS:            bool

   Postcondition:      VARS unchanged
   Description:        Determines whether a number corresponds to
   |                   an ASCII english letter character:
   |                       A - Z; a - z
   */
bool isASCII_char(int i)
{
	return ((65 <= i) && (i <= 90)) || ((97 <= i) && (i <= 122));
}



/*
Name:  isASCII_num
Precondition:       VARS definied in higher function

VARS:               int i;

RETURNS:            bool

Postcondition:      VARS unchanged
Description:        Determines whether a number corresponds to
|                   an ASCII number character: 0 - 9
*/
bool isASCII_num(int i)
{
	return ((48 <= i) && (i <= 57));
}



/*
Name:  stringExtract
Precondition:       VAR got_line definied in higher function

VARS:               string got_line,
|                   string & firstname,
|                   string & lastname,
|                   string & number,
|                   int & relays,
|                   int & call_length

RETURNS:            void

Postcondition:      VARS &first_name, &last_name, &number,
|                       &relays, &call_length now populated
Description:        Ingests a string formatted as a call_record by
|                   whitespace and populates the first_name,
|                   last_name, cell phone number, number of relays
|                   and the length of the call in higher order
|                   variables
*/
void stringExtract(string got_line, string &firstname, string &lastname, string &number, int &relays, int &call_length)
{
	unsigned int i = 0;
	while (i < got_line.length())
	{
		while (!isASCII_char(static_cast<int>(got_line[i]))) i++;
		while (isASCII_char(static_cast<int>(got_line[i])))
		{
			firstname += got_line[i];
			i++;
		}

		while (!isASCII_char(static_cast<int>(got_line[i]))) i++;
		while (isASCII_char(static_cast<int>(got_line[i])))
		{
			lastname += got_line[i];
			i++;
		}

		string num = "";
		while (!isASCII_num(static_cast<int>(got_line[i]))) i++;
		while (isASCII_num(static_cast<int>(got_line[i])))
		{
			number += got_line[i];
			i++;
		}


		num = "";
		while (!isASCII_num(static_cast<int>(got_line[i]))) i++;
		while (isASCII_num(static_cast<int>(got_line[i])))
		{
			num += got_line[i];
			i++;
		}
		relays = stoi(num, nullptr, 10);


		num = "";
		while (!isASCII_num(static_cast<int>(got_line[i]))) i++;
		while (isASCII_num(static_cast<int>(got_line[i])))
		{
			num += got_line[i];
			i++;
		}
		call_length = stoi(num, nullptr, 10);

		while (i < got_line.length()) i++;
	}
}




/*
Name:  is_empty
Precondition:       call_class object instantciated

VARS:               void

RETURNS:            bool

Postcondition:      VARS unchanged
Description:        if (count == 0) return true;
*/
bool call_class::is_empty()
{
	return count == 0;
}



/*
Name:  is_full
Precondition:       call_class object instantciated

VARS:               void

RETURNS:            bool

Postcondition:      VARS unchanged
Description:        if (count == size) return true;
*/
bool call_class::is_full()
{
	return count == size;
}




/*
Name:  search
Precondition:       call_class object instantciated
|                   VARS all initialized in higher function

VARS:               string key,
|                   int & occur

RETURNS:            int

Postcondition:      VAR &occur may contain a positive or negative
|					    integer.
Description:        Searches all records in a call_class object's dynamic
|                   array call_DB. At first, if a
|                   call_record.cell_number == VAR key, it is marked as
|                   the first occurance and is the value returned.
|                   On search continuation, the number of occurances
|                   is tracked and stored in VAR &occur. Otherwise,
|                   -1 is returned.
*/
int call_class::search(const string key, int &occur)
{
	int first;
	int i = 0;
	for (i; i < count; i++)
	{
		if (call_DB[i].cell_number == key)
		{
			first = i;
			i++;
			occur++;
			break;
		}
	}

	for (i; i < count; i++)
	{
		if (call_DB[i].cell_number == key)
		{
			occur++;
		}
	}

	if (occur > 0)
	{
		return first;
	}
	return -1;
}



/*
Name:  add
Precondition:       call_class object instantciated

VARS:               void

RETURNS:            void

Postcondition:      The call_class object member dynamic array
|                   call_DB contains a new call_record object
Description:        Adds a call_record object to call_class object
|                   member dynamic array call_DB. If call_DB is
|                   full, double_size is called to increase the
|                   size of call_DB.
*/
void call_class::add(/*const string key*/)
{
	string got_line = "";
	string temp = "";
	if (is_full())
	{
		double_size();

		cout << "First name: "; getline(cin, temp); got_line += temp + " ";
		cout << "Last name: "; getline(cin, temp); got_line += temp + " ";
		cout << "Phone number: "; getline(cin, temp); got_line += temp + " ";
		cout << "# of relays: "; getline(cin, temp); got_line += temp + " ";
		cout << "Call length: "; getline(cin, temp); got_line += temp + " ";

		stringExtract(got_line, call_DB[count].firstname, call_DB[count].lastname, call_DB[count].cell_number, call_DB[count].relays, call_DB[count].call_length);
		process(1);
		count++;
	}
	else
	{


		cout << "First name: "; getline(cin, temp); got_line += temp + " ";
		cout << "Last name: "; getline(cin, temp); got_line += temp + " ";
		cout << "Phone number: "; getline(cin, temp); got_line += temp + " ";
		cout << "# of relays: "; getline(cin, temp); got_line += temp + " ";
		cout << "Call length: "; getline(cin, temp); got_line += temp + " ";

		stringExtract(got_line, call_DB[count].firstname, call_DB[count].lastname, call_DB[count].cell_number, call_DB[count].relays, call_DB[count].call_length);
		process(1);
		count++;
	}
}







/*
Name:  double_size
Precondition:       call_class object instantciated

VARS:               void

RETURNS:            void

Postcondition:      VAR size *= 2;
|                   VAR &call_DB represents a dynamic array that is
|                       twice its original size
Description:        Doubles the size of a dynamic array of call_record
*/
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





/*
Name:  process
Precondition:       call_class object instantciated
|                   VARS all initialized in higher function

VARS:               int args

RETURNS:            void

Postcondition:      call_class object member dynamic array call_DB
|                   element member attributes have been modified
Description:        call records are proccessed according to the
|                   args specified.
|                   ARGS:
|                       0 - Processes only the call_record corresponding
|                           to the element specified by key
|                       1 - Processes all call_record elements in the
|                           call_class object member dynamic array call_DB
*/
void call_class::process(int args)
{

	short int i = 0;
	switch (args)
	{
	case 0:
		while (i < (count - 1))
		{
			if (0 >= call_DB[i].relays) call_DB[i].call_tax = 0.00;
			if ((01 <= call_DB[i].relays) && (call_DB[i].relays <= 05)) call_DB[i].call_tax = 0.01;
			if ((06 <= call_DB[i].relays) && (call_DB[i].relays <= 11)) call_DB[i].call_tax = 0.03;
			if ((12 <= call_DB[i].relays) && (call_DB[i].relays <= 20)) call_DB[i].call_tax = 0.05;
			if ((21 <= call_DB[i].relays) && (call_DB[i].relays <= 50)) call_DB[i].call_tax = 0.08;
			if ((call_DB[i].relays > 50)) call_DB[i].call_tax = 0.12;
			call_DB[i].tax_rate = call_DB[i].call_tax;
			call_DB[i].net_cost = (call_DB[i].relays / 50.0  *  0.40 * call_DB[i].call_length);
			call_DB[i].call_tax = call_DB[i].net_cost *  call_DB[i].call_tax;
			call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;
			i++;
		}
		break;
	case 1:
		if (0 >= call_DB[count].relays) call_DB[count].call_tax = 0.00;
		if ((01 <= call_DB[count].relays) && (call_DB[count].relays <= 05)) call_DB[count].call_tax = 0.01;
		if ((06 <= call_DB[count].relays) && (call_DB[count].relays <= 11)) call_DB[count].call_tax = 0.03;
		if ((12 <= call_DB[count].relays) && (call_DB[count].relays <= 20)) call_DB[count].call_tax = 0.05;
		if ((21 <= call_DB[count].relays) && (call_DB[count].relays <= 50)) call_DB[count].call_tax = 0.08;
		if ((call_DB[count].relays > 50)) call_DB[count].call_tax = 0.12;
		call_DB[count].tax_rate = call_DB[count].call_tax;
		call_DB[count].net_cost = (call_DB[count].relays / 50.0  *  0.40 * call_DB[count].call_length);
		call_DB[count].call_tax = call_DB[count].net_cost *  call_DB[count].call_tax;
		call_DB[count].total_cost = call_DB[count].net_cost + call_DB[count].call_tax;
		i++;
		break;

	default:
		break;
	}

}



/*
Name:  print (overload 1)
Precondition:       call_class object instantciated
|                   VARS all instantiated in higher function

VARS:               int key

RETURNS:            void

Postcondition:      one call_class object member dynamic array
|                   call_DB element member attributes has been displayed
|                   to the console
Description:        one call record is printed according to the key
|                   specified.
*/
/***************************************************************************************************************************/
void call_class::print(int key)
{
	if (!call_DB[key].deleted)
	{
		cout << endl << endl;
		cout << "FIELD:                        VALUE:" << endl;
		cout << "== == == == == == == == == == == == == == == ==" << endl;
		cout << "Name                          " << call_DB[key].firstname << " " << call_DB[key].lastname << endl;
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(0);
		
		std::cout << this;
	}
}



/*
Name:  print (overload 2)
Precondition:       call_class object instantciated
|                   VARS instantiated in higher function

VARS:               ofstream & out_stream

RETURNS:            void

Postcondition:      all call_class object member dynamic array
|                   call_DB element member attributes have been written
|                   to the file specified in VAR out_stream as well as 
|                   the console
Description:        all non-deleted call records in the call_class object
|                   are written to the file specified in VAR out_stream
|                   as well as the console
*/
void call_class::print(ofstream &out_stream)
{
	out_stream.setf(ios::fixed);
	out_stream.setf(ios::showpoint);
	out_stream.precision(0);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(0);

	cout << endl << endl;
	cout << "FIELD:                        VALUE:" << endl;
	cout << "== == == == == == == == == == == == == == == ==" << endl;
	cout << *this;
	out_stream << *this;

	cout << endl << endl;
}



/*
Name:  call_class destructor
Precondition:       call_class object instantiated

VARS:               void

RETURNS:            void

Postcondition:      call_class object deallocated
Description:        Deletes the memory for the call_class object
*/
call_class::~call_class()
{
}


/*
Name:  << (overload 1)
Precondition:       VARS all initialized in higher function

VARS:               ofstream &out_stream,
|                   const call_class &call_class_object

RETURNS:            ostream

Postcondition:      ofstream object updated with the contents of a
|                   call_class object
Description:        Allows an ofstream to create a file based on a 
|                   call_class object
*/
ostream& operator << (ofstream &out_stream, const call_class &call_class_object)
{
	short int i = 0;

	while (i < call_class_object.count)
	{
		if (!call_class_object.call_DB[i].deleted)
		{
			out_stream.setf(ios::fixed);
			out_stream.setf(ios::showpoint);
			out_stream.precision(0);

			out_stream << call_class_object.call_DB[i].firstname << " " << call_class_object.call_DB[i].lastname << "\t";
			out_stream << call_class_object.call_DB[i].cell_number << "\t";

			out_stream.setf(ios::fixed);
			out_stream.setf(ios::showpoint);
			out_stream.precision(2);
			out_stream << call_class_object.call_DB[i].relays << "\t";
			out_stream << call_class_object.call_DB[i].call_length << "\t";

			out_stream << call_class_object.call_DB[i].net_cost << "\t";
			out_stream << call_class_object.call_DB[i].tax_rate << "\t";
			out_stream << call_class_object.call_DB[i].call_tax << "\t";
			out_stream << call_class_object.call_DB[i].total_cost << "\t";
			out_stream << std::endl;
		}
		i++;
	}

	return out_stream;
}



/*
Name:  << (overload 2)
Precondition:       VARS all initialized in higher function

VARS:               ostream &out_stream, 
|                   const call_class &call_class_object

RETURNS:            ostream

Postcondition:      ostream object updated with the contents of a call_class
|                   object
Description:        Allows an ostream to print a call_class object
*/
ostream& operator << (ostream &out_stream, const call_class &call_class_object)
{ 
	short int i = 0;

	while (i < call_class_object.count)
	{
		if (!call_class_object.call_DB[i].deleted)
		{
			out_stream.setf(ios::fixed);
			out_stream.setf(ios::showpoint);
			out_stream.precision(0);

			out_stream << call_class_object.call_DB[i].firstname << " " << call_class_object.call_DB[i].lastname << "\t";
			out_stream << call_class_object.call_DB[i].cell_number << "\t";

			out_stream.setf(ios::fixed);
			out_stream.setf(ios::showpoint);
			out_stream.precision(2);
			out_stream << call_class_object.call_DB[i].relays << "\t";
			out_stream << call_class_object.call_DB[i].call_length << "\t";

			out_stream << call_class_object.call_DB[i].net_cost << "\t";
			out_stream << call_class_object.call_DB[i].tax_rate << "\t";
			out_stream << call_class_object.call_DB[i].call_tax << "\t";
			out_stream << call_class_object.call_DB[i].total_cost << "\t";
			out_stream << endl;
		}
		i++;
	}

	return out_stream;
}




/*
Name:  - (overload)
Precondition:       a call_record object is instantiated

VARS:               const call_record &call_DB_element

RETURNS:            call_record

Postcondition:      current call_DB element, which is a call_record
|                   is flagged as deleted.
Description:        Flags a call_record object as deleted
*/
call_record operator - (const call_record &call_DB_element)
{
	call_record temp = call_DB_element;
	temp.deleted = true;
	return temp;
}


/*
Name:  remove
Precondition:       call_class object instantciated
|                   VARS all initialized in higher function

VARS:               const string key

RETURNS:            int

Postcondition:      The call_class object member dynamic array
|                   call_DB may or may not contain a
|                   call_record object that is flagged as 'deleted'.
Description:        Flags a call_record in call_class object member
|                   dynamic array call_DB as 'deleted' if an object
|                   contains a call_record.cell_number equal to VAR key
*/
int call_class::remove(const string key)
{
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		if (call_DB[i].cell_number == key)
		{
			call_DB[i] = -call_DB[i];
		}
	}
	return j;
}