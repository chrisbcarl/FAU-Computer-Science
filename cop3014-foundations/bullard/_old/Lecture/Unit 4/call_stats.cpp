



//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH ASSIGNMENT#2


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name:                                 Z#:                           
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:                      Due Time:
Total Points: 100
Assignment 2: call_stats.cpp

Description:
 
*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  //you must include this library if you wish to do file i/o
using namespace std;

/*********************************************************
//Following is the declaration of a call record
**********************************************************/
class call_record
{
public:
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};


//Prototypes for your functions: Input, Output, and Process will go here

void Input(ifstream &,call_record &);
void Output(const call_record &);
void Process(const call_record &);     

//Function Implementations will go here

///*************************************************************************************
//Name:  Input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:  
// Example:Get input (values of cell_number, relays, and call_length) from the user and store in call record.

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void Input(ifstream & in, call_record & customer_record) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	
	in>>customer_record.cell_number;
	in>>customer_record.relays;
	in>>customer_record.call_length;
}

///*************************************************************************************
//Name:  Output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************


void Output(const call_record & customer_record)
{
	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/

	
	cout<<customer_record.cell_number<<"  ";
	cout<<customer_record.relays<<"   ";
	cout<<customer_record.call_length<<endl;
	

}

///*************************************************************************************
//Name:  Process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

//Note: there is one 1 input/output parameter
void Process(call_record & customer_record)
{
	//this is an example of a stub
	/*Step 1: put your code here to determine the net_cost using the formula: relays / 50.0 * .40 * call_length;

	 Step 2: put your if-else statement here to determine the tax rate.
	 condition 1 if relays <= 1  && relays <= 5 then  tax_rate is .01 and call_tax = net_cost * tax_rate
	 condiion  2 if relays >=6 && relays <=1 then tax_rate is .03 and call_tax = net_cost * tax
	 and so forth

	 Step 3:put your code here to determine the total_cost using the formula: total_cost = net_cost + call_tax;

	 Note store all values in your call record

	*/
}

//Here is your driver to test the program
int main( )
{
	
	call_record customer_record;

	ifstream in;    //declaring an input file stream
	in.open("call_data.txt");

	if (in.fail())
	{
		cout<<"Input file did not open correctly"<<endl;
	}
	else
	{
		while (!in.eof())
		{
			Input(in,customer_record);
			Process(customer_record);
			Output(customer_record);
		}
	}

	in.close();

	return 0;
}


