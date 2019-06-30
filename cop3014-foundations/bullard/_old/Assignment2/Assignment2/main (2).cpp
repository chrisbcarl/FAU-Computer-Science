/*******************************************************************************

Name: Christopher Carl
Z#: Z23146703
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 16.05.29
Due Time: 23:59
Total Points: 100
Assignment 1: Date program

Description:
In this assignment  a program a call management system is implemented.  
The program used three functions: input, output, and process.  
The function input gets input from the user, the function process performs
the necessary calculations, and the function output prints the results.

LOG:
16.05.29, 21:55 - start
16.05.29, 22:10 - logic completed
16.05.29, 22:24 - documentation added
16.05.29, 22:28 - fixed whitespace bug using getline()

*******************************************************************************/


#include <iostream>
#include <string>

using namespace std;

void Input(		string & cell_number, 
				int & relays, 
				int & call_length);
void Output(	const string cell_number, 
				const int relays, 
				const int call_length, 
				const double & net_cost, 
				const double & call_tax, 
				const double & total_cost_of_call);
void Process(	const int relays, 
				const int call_length, 
				double & net_cost, 
				double & call_tax, 
				double & total_cost_of_call);


/*
Name:  Input
Precondition:		VARS all initialized in higher function
VARS:
					string cell_number
					int relays
					int call_length

Postcondition:		VARS all defined in higher function
Description:		Get input (values of cell_number, relays, 
					and call_length) from the user.
					example of all formal parameter using the 
					call by reference mechanism in C++

*/
void Input(string & cell_number, int & relays, int & call_length) 
{
	cout << "Enter your Cell Phone Number: "; 
	getline(cin, cell_number);
	cout << "Enter the number of relay stations: ";
	cin >> relays;
	cout << "Enter the length of the call in minutes: ";
	cin >> call_length;
}


/*
Name:  Output
Precondition:		VARS all defined in higher function
VARS:				string cell_number
					int relays
					int call_length

Postcondition:		VARS all defined in higher function
Description:		Output all VARS to user
*/
void Output(const string cell_number, 
			const int relays, 
			const int call_length, 
			const double & net_cost, 
			const double & call_tax, 
			const double & total_cost_of_call)
{
	
	cout << endl << endl;
	cout << "FIELD:                        VALUE:" << endl;
	cout << "== == == == == == == == == == == == == == == ==" << endl;
	cout << "Cell Phone                    " << cell_number << endl;
	cout << "Number of Relay Station       " << relays << endl;
	cout << "Minutes Used                  " << call_length << " minutes" << endl;
	
	//Use thee following statement to help you format you our output. T
	//these statements are called the magic formula.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Net Cost                      $" << net_cost << endl;
	cout << "Call Tax                      $" << call_tax << endl;
	cout << "Total Cost of Call            $" << total_cost_of_call << endl;

	cout << endl << endl;
}


/*
Name:  Process
Precondition:		VARS all defined in higher function
VARS:				string cell_number
					const int relays
					const int call_length
					double & net_cost
					double & call_tax
					double & total_cost_of_call

Postcondition:		VARS all calculated in higher function
Description:		Processes all VARS to compute the total_cost_of_call
*/
void Process(const int relays, 
			const int call_length, 
			double & net_cost, 
			double & call_tax, 
			double & total_cost_of_call)
{
	if ((01 <= relays) && (relays <= 05)) { call_tax = 0.01; }
	if ((06 <= relays) && (relays <= 11)) { call_tax = 0.03; }
	if ((12 <= relays) && (relays <= 20)) { call_tax = 0.05; }
	if ((21 <= relays) && (relays <= 50)) { call_tax = 0.08; }
	if ((relays > 50)) { call_tax = 0.12; }

	net_cost = (relays / 50.0  *  0.40 * call_length);
	call_tax = net_cost *  call_tax;
	total_cost_of_call = net_cost + call_tax;
}

/*
Name:  Process
Precondition:		VARS all initialized in this function
VARS:				string user_response
					string cell_number
					int relays
					int call_length
					double net_cost
					double call_tax
					double total_cost_of_call

Postcondition:		VARS all calculated and output to the user
Description:		Continuous loop that asks the user to input their 
					cell number, the amount of relays for the call, 
					and the duration of the call, finally, outputing 
					the results to the user and asking to repeat.
*/
int main()
{
	string user_response = "y";

	while (user_response == "y" || user_response == "Y")
	{
		string cell_number;
		int relays;
		int  call_length;
		double net_cost;
		double call_tax;
		double total_cost_of_call;

		Input(cell_number, relays, call_length);
		Process(relays, call_length, net_cost, call_tax, total_cost_of_call);
		Output(cell_number, relays, call_length, net_cost, call_tax, total_cost_of_call);

		cout << "Would you like to do another calculation (Y or N): " << endl;
		cin >> user_response;
		cout << endl << endl;
	}

	return 0;
}


