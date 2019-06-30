/*******************************************************************************

Name: Christopher Carl
Z#: Z23146703
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 16.06.19
Due Time: 23:30
Total Points: 100
Assignment 3: Call Cost Calculator w/ File I/O Streams

Description:
This assignment is an extension of Assignment#2. You will implement a program 
called "call_stats3.cpp" to process customer call records. Each customer call 
record contains seven fields, which are as follows: 1) a ten digit cell phone 
number (string, no dashes), 2) the number of relay stations used in making the 
call (integer), 3) the length of the call in minutes (integer), 4) the net cost 
of the call (double), 5) the tax rate (double), 6) the call tax (double) and 7) 
the total cost of the call (double). Your program will have 3 functions: Input, 
Process and Output. Your main program will call each function until the end of 
the datafile has been read. Each call record will be printed to a data file. 
Following are the descriptions of the functionality of each function:

LOG:
16.06.16, 18:44 - start
16.06.16, 19:06 - logic completed, first compile, works
16.06.16, 19:16 - documentation added
16.06.16, 19:16 - formatting for readability/80char rule
16.06.16, 19:24 - final edits


BUG:	FOUND:			FIXED:			DESCIRPTION:
b0001	16.06.16,19:06	-				Last line gets processed twice?!
						16.06.16,19:21	If the input has a last line, then the
										eof() is not satisfied and therefore
										fills it with something. If this were
										an encryption problem, we'd have 
										strange translations instead of just a
										doubly processed line.
*******************************************************************************/


#include <iostream>
#include <ios>
#include <string>
#include <fstream>

using namespace std;

class call_record
{
public:
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost_of_call;
};


void Input(ifstream &, call_record &);
void Output(const call_record &);
void Process(const call_record &);


/*
Name:  Input
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
void Input(ifstream & in_stream, call_record & customer_record)
{
	in_stream >> customer_record.cell_number;
	in_stream >> customer_record.relays;
	in_stream >> customer_record.call_length;
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
void Process(call_record & customer_record)
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
Name:  Output
Precondition:		VARS all initialized in higher function

VARS:				call_record customer_record

Postcondition:		VAR customer_record contains no new data
Description:		Outputs the individual attributes of the call_record
object customer_record to the user.
*/
void Output(const call_record & customer_record)
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
Name:  Output (overload)
Precondition:		VARS all initialized in higher function

VARS:				ofstream out_stream
					call_record customer_record

Postcondition:		VAR customer_record contains no new data
Description:		Outputs the individual attributes of the call_record
					object customer_record to the output file stream.
*/
void Output(ofstream & out_stream, const call_record & customer_record)
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


int main(int argc, const char * argv[])
{
	call_record customer_record_n;

	ifstream in_stream;		//declaring an input file stream
	ofstream out_stream;	//declaring an output file stream

	string user_response = "y";
	string input_filename = "call_data.txt";
	string output_filename = "weekly_call_info.txt";

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
			do
			{
				Input(in_stream, customer_record_n);
				Process(customer_record_n);
				Output(customer_record_n);
				Output(out_stream, customer_record_n);
			} while (!in_stream.eof());
		}

		in_stream.close();
		out_stream.close();

		cout << "Would you like to do another calculation (Y or N): ";
		getline(cin, user_response);
		cout << endl << endl;


	} while (user_response == "y" || user_response == "Y");

	return 0;
}

