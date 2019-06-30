/*******************************************************************************
Name:			Chris Carl
ID:				Z23146703
Due Date:		2/4/2013
Course:			C0P3014 - Foundations of Computer Science
Assignment:		Assignment 1
Professor:		Dr. Lofton Bullard
Time Log:
16.05.21, 16:37		| Begin
17:33
Time Elapsed:

Assignment Description:
In this assignment you will implement a program called "call_cost_calculator.cpp"
that calculates the net cost of a call (net_cost),
the tax on a call (call_tax) and the total cost of the call (total_cost).
The program should accept a cell phone number (cell_num), the number of
relay stations(relays), and the length in minutes of the call
(call_length) from a user.

Please consider the following:
1) The tax rate (in percent) on a call (call_rate) is simply based on the
number of relay stations (relays) used to make the call
(1<= relays <=5 then tax_rate = 1%; 6<= relays <=11 then tax_rate = 3%; 12<= relays <=20 then tax_rate = 5%; 21<= relays <=50 then tax_rate = 8%; relays  >50 then tax_rate =12%) .
2) The net cost of a call is calculated by the following formula:
net_cost = ( relays / 50.0  *  0.40 * call_length).
3) The tax on a call is calculated by the following formula:
call_tax = net_cost *  tax_rate / 100.
4). The total cost of a call (rounded to the nearest hundredth) is calculated
by the following formula: total_cost = net_cost + call_tax .
All tax and cost calculations should be rounded to the nearest
hundredths.

Use the following format information to print the variables:

Field                               Format
======================================
Cell Phone					XXXXXXXXX
Number of Relay Stations	XXXXXX
Minutes Used				XXXXXX
Net Cost					XXXXXXX.XX
Call Tax					XXXXX.XX
Total Cost of Call			XXXXXXX.XX

Handing in your program:
Electronically submit "call_cost_calculator.cpp" in the Assignments area of
Blackboard before the due date and time. Remember, complete the assignment
not matter if it is late.  It is very important that you do all
assignments to master the C++ programming language.

NOTES:
ROUNDING:
float price = 75.96999;
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
cout << "The price is " << price << endl;

Description:


*************************************************************/
#include <iostream> //standard library for i/o
#include <string>

using namespace std;

void main()
{
	

	string cell_num;
	short int relays;
	int call_length;
	float net_cost, call_rate, call_tax, total_cost;



	while (user_response == "y" || user_response == "Y")
	{
		//The code to get the user's input, perform the calculations, and print
		// the results to the screen should go here.  

		cout << "Phone number: "; getline(cin, cell_num);
		cout << "# of Relays: "; cin >> relays;
		cout << "Call length: "; cin >> call_length;

		if ((01 <= relays) && (relays <= 05)) { call_rate = 0.01; }
		if ((06 <= relays) && (relays <= 11)) { call_rate = 0.03; }
		if ((12 <= relays) && (relays <= 20)) { call_rate = 0.05; }
		if ((21 <= relays) && (relays <= 50)) { call_rate = 0.08; }
		if ((relays > 50)) { call_rate = 0.12; }

		net_cost = (relays / 50.0  *  0.40 * call_length);
		call_tax = net_cost *  call_rate;
		total_cost = net_cost + call_tax;

		cout << endl << endl;
		cout << "FIELD:                        VALUE:" << endl;
		cout << "== == == == == == == == == == == == == == == ==" << endl;
		cout << "Cell Phone                    " << cell_num << endl;
		cout << "Number of Relay Station       " << relays << endl;
		cout << "Minutes Used                  " << call_length << " minutes" << endl;
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << "Net Cost                      $" << net_cost << endl;
		cout << "Call Tax                      $" << call_rate << endl;
		cout << "Total Cost of Call            $" << total_cost << endl;

		cout << endl << endl;
		cout << "Would you like to do another calculation (Y or N): " << endl;
		cin >> user_response;
		cout << endl << endl;
	}
}