/*******************************************************************************

Name: Christopher Carl
Z#: Z23146703
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 16.06.12
Due Time: 23:30
Total Points: 100
Assignment 3: Call Cost Calculator w/ File Streams

Description:
In this assignment  a program a call management system is implemented.
The program used three functions: input, output, and process.
The function input gets input from the user, the function process performs
the necessary calculations, and the function output prints the results.

LOG:
16.05.31, 14:55 - start
16.05.31, 17:13 - logic completed, compiles
16.05.31, 17:31 - documentation added
16.05.31, 17:39 - formatting for readability/80char rule


BUG:	FOUND:			FIXED:			DESCIRPTION:
b0001	16.05.31,17:40	-				running the program correctly using 
										call_data.txt, hitting 'y', then using 
										the duplicate file name correctly,
										call_rate - Copy.txt causes the second 
										while prompt to not execute, 
										terminates program
						16.05.31,19:54	use getline() for everything dammit
*******************************************************************************/


#include <iostream>
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
void Input(ifstream & in, call_record & customer_record)
{
	in >> customer_record.cell_number;
	in >> customer_record.relays;
	in >> customer_record.call_length;
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
	if ((01 <= customer_record.relays) && (customer_record.relays <= 05)) 
		{ customer_record.call_tax = 0.01; }
	if ((06 <= customer_record.relays) && (customer_record.relays <= 11)) 
		{ customer_record.call_tax = 0.03; }
	if ((12 <= customer_record.relays) && (customer_record.relays <= 20)) 
		{ customer_record.call_tax = 0.05; }
	if ((21 <= customer_record.relays) && (customer_record.relays <= 50)) 
		{ customer_record.call_tax = 0.08; }
	if ((customer_record.relays > 50)) 
		{ customer_record.call_tax = 0.12; }

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
	cout	<< endl << endl;
	cout	<< "FIELD:                        VALUE:" << endl;
	cout	<< "== == == == == == == == == == == == == == == ==" << endl;
	cout	<< "Cell Phone                    " 
			<< customer_record.cell_number << endl;
	
	cout	<< "Number of Relay Station       " 
			<< customer_record.relays << endl;
	
	cout	<< "Minutes Used                  " 
			<< customer_record.call_length << " minutes" << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout	<< "Net Cost                      $" 
			<< customer_record.net_cost << endl;
	
	cout	<< "Call Tax                      $" 
			<< customer_record.call_tax << endl;

	cout	<< "Total Cost of Call            $" 
			<< customer_record.total_cost_of_call << endl;

	cout	<< endl << endl;
}


int main(int argc, const char * argv[])
{
	call_record customer_record_n;

	ifstream in;    //declaring an input file stream

	string user_response = "y";
	string filename = "call_data.txt";

	do
	{
		cout << "Enter the file name to parse: ";
		getline(cin, filename);
		cout << endl << endl;

		in.open(filename);

		if (in.fail())
		{
			cout << "Input file did not open correctly" << endl;
		}
		else
		{
			while (!in.eof())
			{
				Input(in, customer_record_n);
				Process(customer_record_n);
				Output(customer_record_n);
			}
		}
		
		in.close();

		cout << "Would you like to do another calculation (Y or N): ";
		getline(cin, user_response);
		cout << endl << endl;


	} while (user_response == "y" || user_response == "Y");

	return 0;
}

