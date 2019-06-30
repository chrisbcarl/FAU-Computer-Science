/*******************************************************************************

Name: Christopher Carl
Z#: Z23146703
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 16.07.10
Due Time: 23:59
Total Points: 100
Assignment 9: Call Cost Calculator w/ Proper Classes

Description:
This assignment is an extension of Programming Assignment 5,(Unit 9’s Programming Assignment). You will implement class called “call_class”. The class will manage a dynamic array of call records called "call_stats6.cpp".  I have provide the driver “call_stats6cpp” to help you implement this program.
Your input data will be in the file “callstats_data.txt.
The descriptions of the functions you will implement are as follows:
1.	the default constructor  to initialize the state of your class. The default constructor will read the data from the file “callstats_data.txt” into the dynamic array call_DB.  If call_DB becomes full, the function should call the function “double_size” to double the size (capacity) of call_DB. Remember, count and call_DB are private members of your class and do not need to  be passed to an member function  of your class.
2.	is_empty is a Boolean public member function of the class.  It has no formal parameter because count is a member of the state of the class (private member) and does not need to be passed to it because the state of the class if known to all member functions of the class. If count == 0 then true is returned; otherwise false is returned.
3.	is_full is a Boolean public member function of the class.  It has no formal parameters because count and size are members of the state of the class (private members) and do not need to be passed to it because the state of the class if known to all member functions of the class. If count == size then true is return; otherwise false. The size is the capacity which is the total number of cells allocated to call_DB.
4.	search is an integer public member function that has only one formal parameter, the key.  key is the cell phone number for the record you are search for. The array of records, call_DB and count are members of the state of the class and do not need to be passed to a member function of the class; The function will return the location of key in call_DB if it is there; otherwise -1 is returned.
5.	add is a void public member function that inserts key (cell number) into call_DB.  Duplicates cell numbers are ok; add will prompt the user for the firstname, lastname, relays and call length. You may call process record to re-process when you add a new record. add has only one formal parameter, the key.
6.	remove is a void public member function thaqt deletes all records with the cell number stored in key. If duplicate records exist with the same cell number they must all be deleted. “remove” has only one formal parameter, the key.
7.	double_size is a void public member function that doubles the capacity of call_DB. “double_size” has no formal parameters because size, count and call_DB are all members of the state of the class, call_class. First, size is multipled by two; second, memory is allocated using “call_record *temp=new call_record[size]; third the records in call_DB are copied into temp with the statement “temp[i]=call_DB[i]” using a for loop. Forth, the old memory for call_DB is de-allocated using “delete [ ] call_DB”; Finally, call_DB is set to point to the new memory pointed to by temp using “call_DB = temp”.
8.	process is a void public member function the has no formal parameter because call_DB and count are members of the state of the class.. The function  process will calculate the net cost of a call (net_cost), the tax on a call (call_tax) and the total cost of the call (total_cost) using the number of relay stations (relays) and the length in minutes of the call (call_length) for all call records stored in call_DB.  Please consider the following:
|    a.	The tax rate on a call (call_tax) is simply based on the number of relay stations (relays) used to make the call  (0<= relays <=5 then call_tax = 1%; 6<= relays <=11 then call_tax = 3%; 12<= relays<=20 then call_tax = 5%; 21<= relays <=50 then call_tax = 8%; relays >50 then call_tax =12%) .
|    b.	The net cost of a call is calculated by the following formula:  net_cost = ( relays / 50  x  0.40 x call_length).
|    c.	The tax on a call is equal to net_cost x  call_tax / 100.
d.	The total cost of a call (rounded to the nearest hundredth) is calculated by the following formula: total_cost = net_cost + call_tax .  All tax and cost calculations should be rounded to the nearest hundredths.
9.	print is a void public member function that has no formal parameters because count and call_DB are members of the state of the class. The function will print every field of every call_record in call_DB to the screen.
10.	the destructor to de-allocate all memory allocated to call_DB.  This function has no formal parameters because call_DB is a member of the state of the class. It will be called automatically by the compiler.

asdfasdf

LOG:
16.07.04, 14:19 - start
16.06.29, 15:42 - all functions written
16.06.29, 15:47 - first compile, like 20 compiler errors
16.06.29, 15:53 - ~7th compile
16.06.29, 17:23 - ~25th compile, still trying to read from the file correctly, cin being a bitch
16.06.29, 19:38 - ~100th compile, logic 95% fine.

16.07.04, 10:15 - start
16.07.04, 10:57 - documentation added
16.07.04, 10:57- formatting for readability/80char rule
16.07.04, 10:57- final edits


BUG:	FOUND:			FIXED:			DESCIRPTION:
B0001	16.06.29,15:53	-				program hangs, cin bug
16.06.29,17:23	-				cin still causing problems, using workaround
16.06.29,15:45	call_record.cell_number is an int.
int's are smaller than most phone numbers
causing catastrophic cin due to out of bounds exceptions
B0002	16.06.29,17:53	-				getline is skipping one line
16.06.29,18:07	same problem as scanf, requires cin.ignore(1000, '\n');
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


/*void initialize(FILE * pFile, istream & in_stream, call_record * &call_DB, int & count, int & size);*/
void initialize(istream & in_stream, call_record * &call_DB, int & count, int & size);
bool is_empty(const int count); //inline implementation
bool is_full(const int count, int size);//inline implementation
int search(const call_record *call_DB, const int count, string key, int & occur);//returns location if item in listl; otherwise return -1
void add(call_record * &call_DB, int & count, int & size); //adds item inorder to the list
int remove(call_record *call_DB, int & count, string key); //removes an item from the list
void double_size(call_record * &call_DB, int & count, int & size);
void process(int args, call_record *call_DB, const int & count);
void print(int args, call_record *call_DB, int & count, int key); //prints all the elements in the list to the screen
void print(ofstream & out_stream, call_record *call_DB, int & count);
void destroy_call_DB(call_record * &call_DB); //de-allocates all memory allocate to call_DB by operator new.
void stringExtract(string got_line, string & firstname, string & lastname, string & number, int & relays, int & call_length);
bool isASCII_char(int i);
bool isASCII_num(int i);



int main(int argc, const char * argv[])
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
			int size = 5; //total amount of memory (cells) allocated for the dynamic array of call records
			int count = 0;
			int choice = 0;
			call_record *call_DB = new call_record[size];


			//put code here to test your funcitons

			/*FILE * pFile;
			pFile = fopen(input_filename.c_str(), "r");*/

			initialize(in_stream, call_DB, count, size);	/*fclose(pFile);*/
			process(0, call_DB, count);
			print(1, call_DB, count, 0);

			do
			{
				int n = 0;
				int occur = 0;
				string s;
				cout << "-MAIN MENU-" << endl;
				cout << "0 - Print record." << endl;
				cout << "1 - Add a record." << endl;
				cout << "2 - Search for a record." << endl;
				cout << "3 - Delete a record." << endl;
				cout << "4 - Save records." << endl;
				cout << "Select an option: ";
				cin >> choice; cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //probably totally necessary.
				cout << endl << endl;
				switch (choice)
				{
				case 0:
					cout << "SELECTED: 0 - Print records." << endl;
					process(0, call_DB, count);
					print(1, call_DB, count, 0);
					break;
				case 1:
					cout << "SELECTED: 1 - Add a record." << endl;
					add(call_DB, count, size);
					break;
				case 2:
					cout << "SELECTED: 2 - Search for a record." << endl;
					cout << "Input phone number to search: ";
					cin >> s; cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //probably totally necessary.
					n = search(call_DB, count, s, occur);
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
						int r = remove(call_DB, count, s);
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
					process(0, call_DB, count);
					print(out_stream, call_DB, count);
					out_stream.close();
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
			destroy_call_DB(call_DB);
		}

		in_stream.close();


		cout << "Would you like to do another calculation (Y or N): ";
		getline(cin, user_response);
		cout << endl << endl;


	} while (user_response == "y" || user_response == "Y");

	return 0;
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
void stringExtract(string got_line, string & firstname, string & lastname, string & number, int & relays, int & call_length)
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
Name:  initialize
Precondition:       VAR in_stream defined with a filename
|                   VAR &call_DB defined in higher function
|                   VAR &size > &count > 0

VARS:               istream & in_stream,
|                   call_record* &call_DB,
|                   int & count,
|                   int & size

RETURNS:            void

Postcondition:      VAR &call_DB, &count, &size all populated
Description:        Ingests a text document defined by in_stream,
|                   populates &call_DB with call_record objects.
|                   As it ingests, if the records, tracked by &count
|                   are more numerous than size, then the size of the
|                   dynamic array call_DB is doubled.
*/
void initialize(/*FILE * pFile, */istream & in_stream, call_record* &call_DB, int & count, int & size)
{
	int i = 0;
	string temp_name;
	while (!in_stream.eof())
	{
		if (is_full(count, size))
		{
			double_size(call_DB, count, size);

			getline(in_stream, temp_name);
			stringExtract(temp_name, call_DB[i].firstname, call_DB[i].lastname, call_DB[i].cell_number, call_DB[i].relays, call_DB[i].call_length);

			i++;
			count++;
		}
		else
		{
			getline(in_stream, temp_name);
			stringExtract(temp_name, call_DB[i].firstname, call_DB[i].lastname, call_DB[i].cell_number, call_DB[i].relays, call_DB[i].call_length);
			//n = temp_name.find(' ');
			//n2 = temp_name.find('\t');
			//call_DB[i].firstname = temp_name.substr(0, n);
			//call_DB[i].lastname = temp_name.substr(n + 1, n2 - 1);
			//fscanf(pFile, "%d", &call_DB[i].cell_number);
			//fscanf(pFile, "%d", &call_DB[i].relays);
			//fscanf(pFile, "%d", &call_DB[i].call_length);
			/*in_stream >> call_DB[i].cell_number;
			in_stream >> call_DB[i].relays;
			in_stream >> call_DB[i].call_length;*/
			i++;
			count++;
		}
	}
}


/*
Name:  is_empty
Precondition:       VARS all initialized in higher function

VARS:               const int count

RETURNS:            bool

Postcondition:      VARS unchanged
Description:        if (count == 0) return true;
*/
bool is_empty(const int count)
{
	if (count == 0) return true;
	return false;
}



/*
Name:  is_full
Precondition:       VARS all initialized in higher function

VARS:               const int count,
|                   int size

RETURNS:            bool

Postcondition:      VARS unchanged
Description:        if (count == size) return true;
*/
bool is_full(const int count, int size)
{
	if (count == size) return true;
	return false;
}


/*
Name:  search
Precondition:       VARS all initialized in higher function

VARS:               const call_record* call_DB,
|                   const int count,
|                   string key,
|                   int & occur

RETURNS:            int

Postcondition:      VAR &occur may contain a positive or negative
|					    integer.
Description:        Searches all records in VAR call_DB. At first, if a
|                   call_record.cell_number == VAR key, it is marked as
|                   the first occurance and is the value returned.
|                   On search continuation, the number of occurances
|                   is tracked and stored in VAR &occur. Otherwise,
|                   -1 is returned.
*/
int search(const call_record* call_DB, const int count, string key, int & occur)
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
Precondition:       VARS all initialized in higher function

VARS:               call_record* &call_DB,
|                   int & count,
|                   int & size

RETURNS:            void

Postcondition:      VAR call_DB contains a new call_record object
|                   VAR count++
Description:        Adds a call_record object to VAR &call_DB. If
|                   call_DB is full, double_size is called to
|                   increase the size of call_DB.
*/
void add(call_record* &call_DB, int & count, int & size)
{
	string got_line = "";
	string temp = "";
	if (is_full(count, size))
	{
		double_size(call_DB, count, size);

		cout << "First name: "; getline(cin, temp); got_line += temp + " ";
		cout << "Last name: "; getline(cin, temp); got_line += temp + " ";
		cout << "Phone number: "; getline(cin, temp); got_line += temp + " ";
		cout << "# of relays: "; getline(cin, temp); got_line += temp + " ";
		cout << "Call length: "; getline(cin, temp); got_line += temp + " ";

		stringExtract(got_line, call_DB[count].firstname, call_DB[count].lastname, call_DB[count].cell_number, call_DB[count].relays, call_DB[count].call_length);
		process(1, call_DB, count);
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
		process(1, call_DB, count);
		count++;
	}
}

/*
Name:  remove
Precondition:       VARS all initialized in higher function

VARS:               call_record* call_DB,
|                   int & count,
|                   string key

RETURNS:            int

Postcondition:      VAR call_DB may or may not contain a call_record
|                       object that is flagged as 'deleted'.
Description:        Flags a call_record in VAR call_DB as 'deleted'
|                       if an object contains a member cell_number
|                       equal to VAR key
*/
int remove(call_record* call_DB, int & count, string key)
{
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		if (call_DB[i].cell_number == key)
		{
			call_DB[i].deleted = true; j++;
		}
	}
	return j;
}

/*
Name:  double_size
Precondition:       VARS all initialized in higher function

VARS:               call_record* &call_DB,
|                   int & count,
|                   int & size

RETURNS:            void

Postcondition:      VAR size *= 2;
|                   VAR &call_DB represents a dynamic array that is
|                       twice its original size
Description:        Doubles the size of a dynamic array of call_record
*/
void double_size(call_record* &call_DB, int & count, int & size)
{
	size *= 2;
	call_record *temp = new call_record[size];
	for (int i = 0; i < count; i++)
	{
		temp[i] = call_DB[i];
	}
	delete[] call_DB;
	call_DB = temp;
}


/*
Name:  process
Precondition:       VARS all initialized in higher function

VARS:               int args,
|                   call_record* call_DB,
|                   const int & count

RETURNS:            void

Postcondition:      VAR out_stream has written a file
Description:        Prints call records to the console depending on
|                   the args specified.
|                   ARGS:
|                       0 - Prints only the record corresponding to
|                           the element specified by key to the
|							console
|                       1 - Prints all records in call_DB to the
|							console
*/
void process(int args, call_record* call_DB, const int & count)
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
Precondition:       VARS all initialized in higher function

VARS:               int args,
|                   call_record* call_DB,
|                   int & count,
|                   int key

RETURNS:            void

Postcondition:      console updated
Description:        Prints call records to the console depending on
|                   the args specified.
|                   ARGS:
|                       0 - Prints only the record corresponding to
|                           the element specified by key to the
|							console
|                       1 - Prints all records in call_DB to the
|							console
*/
void print(int args, call_record* call_DB, int & count, int key)
{
	//out_stream << endl << endl;
	//out_stream << "FIELD:                        VALUE:" << endl;
	//out_stream << "== == == == == == == == == == == == == == == ==" << endl;
	short int i = 0;

	switch (args)
	{
		//prints to the console the one according to the key
	case 0:
		if (!call_DB[key].deleted)
		{
			cout << endl << endl;
			cout << "FIELD:                        VALUE:" << endl;
			cout << "== == == == == == == == == == == == == == == ==" << endl;
			cout << "Name                          " << call_DB[key].firstname << " " << call_DB[key].lastname << endl;
			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(0);
			cout << "Cell Phone                    " << call_DB[key].cell_number << endl;
			cout << "Number of Relay Station       " << call_DB[key].relays << endl;
			cout << "Minutes Used                  " << call_DB[key].call_length << " minutes" << endl;

			cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(2);

			cout << "Net Cost                      $" << call_DB[key].net_cost << endl;
			cout << "Tax Rate                      $" << call_DB[key].tax_rate << endl;
			cout << "Call Tax                      $" << call_DB[key].call_tax << endl;
			cout << "Total Cost of Call            $" << call_DB[key].total_cost << endl;
			cout << endl << endl;
		}
		break;
		//prints all non-deleted records to the console
	case 1:
		while (i < count)
		{
			if (!call_DB[i].deleted)
			{
				cout.setf(ios::fixed);
				cout.setf(ios::showpoint);
				cout.precision(0);

				cout << endl << endl;
				cout << "FIELD:                        VALUE:" << endl;
				cout << "== == == == == == == == == == == == == == == ==" << endl;
				cout << "Name                          " << call_DB[i].firstname << " " << call_DB[i].lastname << endl;
				cout << "Cell Phone                    " << call_DB[i].cell_number << endl;

				cout.setf(ios::fixed);
				cout.setf(ios::showpoint);
				cout.precision(2);
				cout << "Number of Relay Station       " << call_DB[i].relays << endl;
				cout << "Minutes Used                  " << call_DB[i].call_length << " minutes" << endl;



				cout << "Net Cost                      $" << call_DB[i].net_cost << endl;
				cout << "Tax Rate                      $" << call_DB[i].tax_rate << endl;
				cout << "Call Tax                      $" << call_DB[i].call_tax << endl;
				cout << "Total Cost of Call            $" << call_DB[i].total_cost << endl;
				cout << endl << endl;
			}
			i++;
		}
		break;
	default:
		break;
	}
}


/*
Name:  print (overload 2)
Precondition:       VARS all initialized in higher function

VARS:               ofstream & out_stream,
|                   call_record* call_DB,
|                   int & count

RETURNS:            void

Postcondition:      VAR out_stream has written a file
Description:        The call record database is printed to a file
|                   defined by the out_stream
*/
void print(ofstream & out_stream, call_record* call_DB, int & count)
{
	//out_stream << endl << endl;
	//out_stream << "FIELD:                        VALUE:" << endl;
	//out_stream << "== == == == == == == == == == == == == == == ==" << endl;
	short int i = 0;

	while (i < count)
	{
		if (!call_DB[i].deleted)
		{
			out_stream.setf(ios::fixed);
			out_stream.setf(ios::showpoint);
			out_stream.precision(0);

			out_stream << call_DB[i].firstname << " " << call_DB[i].lastname << "\t";
			out_stream << call_DB[i].cell_number << "\t";

			out_stream.setf(ios::fixed);
			out_stream.setf(ios::showpoint);
			out_stream.precision(2);
			out_stream << call_DB[i].relays << "\t";
			out_stream << call_DB[i].call_length << "\t";



			out_stream << call_DB[i].net_cost << "\t";
			out_stream << call_DB[i].tax_rate << "\t";
			out_stream << call_DB[i].call_tax << "\t";
			out_stream << call_DB[i].total_cost << "\t";
			out_stream << endl;


		}
		i++;
	}
}

/*
Name:  destroy_call_DB
Precondition:       VARS all initialized in higher function

VARS:               call_record* &call_DB

RETURNS:            void

Postcondition:      VAR call_db[] dynamic array deleted
Description:        Deletes the dynamically allocated memory for
the dynamic array &call_DB
*/
void destroy_call_DB(call_record * &call_DB)
{
	delete[] call_DB;
}




/*


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
	bool is_full();//inline implementation
	int search(const string key);//returns location if item in listl; otherwise return -1
	void add(const string key); //adds item inorder to the list
	void remove(const string key); //removes an item from the list
	void double_size();
	void process();
	void print(); //prints all the elements in the list to the screen
private:
	int count;
	int size;
	call_record* call_DB;
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


}

/***********************************************************************************************************************************/
//Name: is_empty
//Precondition: 
//Postcondition: 
//Decription: returns true if call_DB is empty
/**********************************************************************************************************************************/
bool call_class::is_empty()
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: 
//Postcondition: 
//Decription: returns true if call_DB is full
/*********************************************************************************************************************************/
bool call_class::is_full()
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: 
//Postcondition: 
//Decription: locates key in call_DB if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int call_class::search(const string key)
{
	return -1;
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: 
//Postcondition: 
//Decription: add key to call_DB; if call_DB is full, double_size is called to increase the size of call_DB.
/********************************************************************************************************************************/
void call_class::add(const string key)
{
}

/********************************************************************************************************************************/
//Name: remove
//Precondition: 
//Postcondition: 
//Decription: remove key from call_DB if it is there.
/*******************************************************************************************************************************/
void call_class::remove(const string key)
{
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
}


/****************************************************************************************************************************/
//Name: print
//Precondition: 
//Postcondition: 
//Decription: prints every field of every call_record in call_DB formatted to the screen.
/***************************************************************************************************************************/
void call_class::print()
{
	for (int i = 0; i<count; i++)
	{
		cout << call_DB[i].firstname << "  " << call_DB[i].lastname
			<< "  " << call_DB[i].relays << "  " << call_DB[i].cell_number
			<< "  " << call_DB[i].call_length << endl;
	}
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
}


//driver to test the functionality of your class.
int main()
{
	call_class MyClass;

	MyClass.print();


	return 0;
}





