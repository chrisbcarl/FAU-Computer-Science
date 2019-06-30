/*******************************************************************************

Name: Christopher Carl
Z#: Z23146703
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 16.06.26
Due Time: 23:59
Total Points: 100
Assignment 6: Call Cost Calculator w/ File I/O Streams and Arrays

Description:
This assignment is an extension of Assignments 2 and 2B. You will implement a 
program called "call_stats4.cpp" to process customer call records. You will 
read the records in a datafile into an array of call records, then process 
each call record in the array, and finally print the array of call records 
to a datafile. Remember, each customer call record contains seven fields, 
which are as follows: 1) a ten digit cell phone number (string, no dashes), 
2) the number of relay stations used in making the call (integer), 3) the 
length of the call in minutes (integer), 4) the net cost of the call (double), 
5) the tax rate (double), 6) the call tax (double) and 7) the total cost of 
the call (double). Your program will have 3 functions: Input, Process, and 
Output. Your main program will call each function once. Following are the 
descriptions of the functionality of each function:

LOG:
16.06.17, 16:04 - start
16.06.17, 16:13 - logic completed, first compile, works with greedy
					implementation
16.06.17, 16:30 - logic completed, first compile, new non-greedy 
					implementation, b0001
16.06.17, 17:07 - documentation added
16.06.17, 17:07 - formatting for readability/80char rule
16.06.17, 17:07 - final edits


BUG:	FOUND:			FIXED:			DESCIRPTION:
b0001	16.06.17,16:34	-				program hangs
						16.06.17,16:45	forgot el stupid i++
*******************************************************************************/


#include <iostream>
#include <ios>
#include <string>
#include <fstream>

using namespace std;

//data structures
struct call_record
{
	string cell_number = "0000000000";
	int relays = 0;
	int call_length = 0;
	double net_cost = 0;
	double tax_rate = 0;
	double call_tax = 0;
	double total_cost_of_call = 0;
};

//prototypes
void Input_greedy(ifstream & , call_record & );
void Process_greedy(call_record &);
void Output_greedy(const call_record &);
void Output_greedy(ofstream &, const call_record &);

void Input(istream & , call_record , const short int & );
void Process(call_record , const short int & );
void Output(call_record , const short int & );
void Output(ofstream & , call_record , const short int & );

//globals
const short int size_global = 200;


/*
Name:  Input_greedy
Precondition:		VARS all initialized in higher function

VARS:				ifstream in
					call_record customer_record

Postcondition:		VAR customer_record contains new data
Description:		Get input (values of cell_number, relays,
					and call_length) from a data text file.
					Each "line" of this data text file becomes
					the same object, customer_record which
					becomes processed by void Process()
*/
void Input_greedy(ifstream & in_stream, call_record & customer_record)
{
	in_stream >> customer_record.cell_number;
	in_stream >> customer_record.relays;
	in_stream >> customer_record.call_length;
}


/*
Name:  Input_greedy
Precondition:		VARS all initialized in higher function

VARS:				istream & in_stream, 
					call_record call_db[], 
					const short int & size

Postcondition:		VAR call_db array contains new data
Description:		Get input (values of cell_number, relays,
					and call_length) from a data text file.
					Each "line" of this data text file becomes
					the added to an element of an array at 
					element i, which is less than a global
					variable const short int size.
*/
void Input(istream & in_stream, call_record call_db[], const short int & size)
{
	short int i = 0;
	while (!in_stream.eof())
	{
		in_stream >> call_db[i].cell_number;
		in_stream >> call_db[i].relays;
		in_stream >> call_db[i].call_length;
		i++;
	}
}


/*
Name:  Process
Precondition:		VARS all defined in higher function

VARS:				call_record customer_record

Postcondition:		VARS all calculated in higher function
Description:		Processes all attributes in the call_record object
					customer_record and assign the computed attributes
					to the customer_record object
*/
void Process_greedy(call_record & customer_record)
{
	if (0 >= customer_record.relays)
	{
		customer_record.call_tax = 0.00;
	}
	if ((01 <= customer_record.relays) && (customer_record.relays <= 05))
	{
		customer_record.call_tax = 0.01;
	}
	if ((06 <= customer_record.relays) && (customer_record.relays <= 11))
	{
		customer_record.call_tax = 0.03;
	}
	if ((12 <= customer_record.relays) && (customer_record.relays <= 20))
	{
		customer_record.call_tax = 0.05;
	}
	if ((21 <= customer_record.relays) && (customer_record.relays <= 50))
	{
		customer_record.call_tax = 0.08;
	}
	if ((customer_record.relays > 50))
	{
		customer_record.call_tax = 0.12;
	}

	customer_record.tax_rate = customer_record.call_tax;

	customer_record.net_cost =
		(customer_record.relays / 50.0  *  0.40 * customer_record.call_length);

	customer_record.call_tax =
		customer_record.net_cost *  customer_record.call_tax;

	customer_record.total_cost_of_call =
		customer_record.net_cost + customer_record.call_tax;
}


/*
Name:  Process
Precondition:		VARS all defined in higher function

VARS:				call_record call_db[], 
					const short int & size

Postcondition:		VARS call_db[] has fully computed values
Description:		Processes all attributes in the call_db array element
					customer_record and assign the computed attributes
					to the customer_record object
*/
void Process(call_record call_db[], const short int & size)
{
	short int i = 0;
	while (i < (size-1))
	{
		if (0 >= call_db[i].relays)
		{
			call_db[i].call_tax = 0.00;
		}
		if ((01 <= call_db[i].relays) && (call_db[i].relays <= 05))
		{
			call_db[i].call_tax = 0.01;
		}
		if ((06 <= call_db[i].relays) && (call_db[i].relays <= 11))
		{
			call_db[i].call_tax = 0.03;
		}
		if ((12 <= call_db[i].relays) && (call_db[i].relays <= 20))
		{
			call_db[i].call_tax = 0.05;
		}
		if ((21 <= call_db[i].relays) && (call_db[i].relays <= 50))
		{
			call_db[i].call_tax = 0.08;
		}
		if ((call_db[i].relays > 50))
		{
			call_db[i].call_tax = 0.12;
		}

		call_db[i].tax_rate = call_db[i].call_tax;

		call_db[i].net_cost =
			(call_db[i].relays / 50.0  *  0.40 * call_db[i].call_length);

		call_db[i].call_tax =
			call_db[i].net_cost *  call_db[i].call_tax;

		call_db[i].total_cost_of_call =
			call_db[i].net_cost + call_db[i].call_tax;

		i++;
	}
}


/*
Name:  Output_greedy
Precondition:		VARS all initialized in higher function

VARS:				call_record customer_record

Postcondition:		VAR customer_record contains no new data
Description:		Outputs the individual attributes of the call_record
					object customer_record to the user.
*/
void Output_greedy(const call_record & customer_record)
{
	cout << endl << endl;
	cout << "FIELD:                        VALUE:" << endl;
	cout << "== == == == == == == == == == == == == == == ==" << endl;
	cout << "Cell Phone                    "
		<< customer_record.cell_number << endl;

	cout << "Number of Relay Station       "
		<< customer_record.relays << endl;

	cout << "Minutes Used                  "
		<< customer_record.call_length << " minutes" << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Net Cost                      $"
		<< customer_record.net_cost << endl;

	cout << "Tax Rate                      $"
		<< customer_record.tax_rate << endl;

	cout << "Call Tax                      $"
		<< customer_record.call_tax << endl;

	cout << "Total Cost of Call            $"
		<< customer_record.total_cost_of_call << endl;

	cout << endl << endl;
}


/*
Name:  Output_greedy
Precondition:		VARS all initialized in higher function

VARS:				ofstream out_stream
					call_record customer_record

Postcondition:		VAR customer_record contains no new data
Description:		Outputs the individual attributes of the call_record
					object customer_record to the output file stream.
*/
void Output_greedy(ofstream & out_stream, const call_record & customer_record)
{
	//out_stream << endl << endl;
	//out_stream << "FIELD:                        VALUE:" << endl;
	//out_stream << "== == == == == == == == == == == == == == == ==" << endl;
	out_stream << customer_record.cell_number << "\t";
	out_stream << customer_record.relays << "\t";
	out_stream << customer_record.call_length << "\t";

	out_stream.setf(ios::fixed);
	out_stream.setf(ios::showpoint);
	out_stream.precision(2);

	out_stream << customer_record.net_cost << "\t";
	out_stream << customer_record.tax_rate << "\t";
	out_stream << customer_record.call_tax << "\t";
	out_stream << customer_record.total_cost_of_call << "\t";
	out_stream << endl;
}


/*
Name:  Output (overload)
Precondition:		VARS all initialized in higher function

VARS:				call_record call_db[], 
					const short int & size

Postcondition:		VAR call_db contains no new data
Description:		Outputs the individual attributes of the call_db
					array of customer_record to the user.
*/
void Output(call_record call_db[], const short int & size)
{
	//out_stream << endl << endl;
	//out_stream << "FIELD:                        VALUE:" << endl;
	//out_stream << "== == == == == == == == == == == == == == == ==" << endl;
	short int i = 0;

	while (i < (size-1))
	{

		cout << endl << endl;
		cout << "FIELD:                        VALUE:" << endl;
		cout << "== == == == == == == == == == == == == == == ==" << endl;
		cout << "Cell Phone                    "
			<< call_db[i].cell_number << endl;

		cout << "Number of Relay Station       "
			<< call_db[i].relays << endl;

		cout << "Minutes Used                  "
			<< call_db[i].call_length << " minutes" << endl;

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "Net Cost                      $"
			<< call_db[i].net_cost << endl;

		cout << "Tax Rate                      $"
			<< call_db[i].tax_rate << endl;

		cout << "Call Tax                      $"
			<< call_db[i].call_tax << endl;

		cout << "Total Cost of Call            $"
			<< call_db[i].total_cost_of_call << endl;

		cout << endl << endl;

		i++;
	}
}


/*
Name:  Output (overload)
Precondition:		VARS all initialized in higher function

VARS:				ofstream & out_stream,
					call_record call_db[],
					const short int & size

Postcondition:		VAR call_db contains no new data
Description:		Outputs the individual attributes of the call_db
					array of customer_record to the output file stream.
*/
void Output(ofstream & out_stream, call_record call_db[], const short int & size)
{
	//out_stream << endl << endl;
	//out_stream << "FIELD:                        VALUE:" << endl;
	//out_stream << "== == == == == == == == == == == == == == == ==" << endl;
	short int i = 0;
	
	while (i < (size-1))
	{
		out_stream << call_db[i].cell_number << "\t";
		out_stream << call_db[i].relays << "\t";
		out_stream << call_db[i].call_length << "\t";

		out_stream.setf(ios::fixed);
		out_stream.setf(ios::showpoint);
		out_stream.precision(2);

		out_stream << call_db[i].net_cost << "\t";
		out_stream << call_db[i].tax_rate << "\t";
		out_stream << call_db[i].call_tax << "\t";
		out_stream << call_db[i].total_cost_of_call << "\t";
		out_stream << endl;

		i++;
	}
}


int main(int argc, const char * argv[])
{
	ifstream in_stream;		//declaring an input file stream
	ofstream out_stream;	//declaring an output file stream

	string user_response = "y";
	string input_filename = "call_data.txt";
	string output_filename = "weekly4_call_info.txt";

	call_record call_db[size_global];

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
		out_stream.open(output_filename);

		if (in_stream.fail())
		{
			cout << "Input file did not open correctly" << endl;
		}
		else
		{
			Input(in_stream, call_db, size_global);
			Process(call_db, size_global);
			Output(call_db, size_global);
			Output(out_stream, call_db, size_global);
			//do
			//{
				//Input_greedy(in_stream, call_db[i]);
				//Process_greedy(call_db[i]);
				//Output_greedy(call_db[i]);
				//Output_greedy(out_stream, call_db[i]);
				//i++;
			//} while (!in_stream.eof());
		}

		in_stream.close();
		out_stream.close();

		cout << "Would you like to do another calculation (Y or N): ";
		getline(cin, user_response);
		cout << endl << endl;


	} while (user_response == "y" || user_response == "Y");

	return 0;
}