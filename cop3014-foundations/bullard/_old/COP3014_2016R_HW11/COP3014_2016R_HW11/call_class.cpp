#include "call_class.h"

#include <iostream>
#include <fstream>
#include <string>

using std::ostream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::ios;

using std::cout;
using std::cin;
using std::endl;


bool isASCII_char(int i);
bool isASCII_num(int i);
void stringExtract(string got_line, string &firstname, string &lastname, string &number, int &relays, int &call_length);


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



/*
Name:  call_class constructor (overload 3)
Precondition:       call_class &original instantiated

VARS:               void

RETURNS:            call_class object

Postcondition:      new call_class object created
Description:        Creates a call_class object that is a
|                   deep copy of the &original
*/
call_class::call_class(const call_class &original)
{
	count = original.count;
	size = original.size;
	call_DB = original.call_DB;

	call_DB = new call_record[size];
	int i = 0;
	while (i < size)
	{
		call_DB[i].firstname = original.call_DB[i].firstname;
		call_DB[i].lastname = original.call_DB[i].lastname;
		call_DB[i].cell_number = original.call_DB[i].cell_number;
		call_DB[i].relays = original.call_DB[i].relays;
		call_DB[i].call_length = original.call_DB[i].call_length;
		call_DB[i].net_cost = original.call_DB[i].net_cost;
		call_DB[i].tax_rate = original.call_DB[i].tax_rate;
		call_DB[i].call_tax = original.call_DB[i].call_tax;
		call_DB[i].total_cost = original.call_DB[i].total_cost;

		i++;
	}
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