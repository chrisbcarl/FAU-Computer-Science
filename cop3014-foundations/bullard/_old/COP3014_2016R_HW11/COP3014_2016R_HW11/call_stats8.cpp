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
This assignment is an extension of Unit 11 Programming Assignment.  You will modify your implementation of “call_class”. The class will still manage a dynamic array of call records. Call this program "call_stats8.cpp". You must separate the declaration and implementation for the class “call_class” into two separate files.  Please put the class declaration in the file called “call_class.h”, and put the class implementation in the file called “call_class.cpp.  Your driver will be called “call_stats8.cpp” that is provided.  However, you will need to modify it to test the functionality of your program.
Your input data will be in the file “callstats_data.txt.
The descriptions of the functions you will implement are as follows:
1.	the copy constructor  will perform a deep copy of an object.
2.	(you implemented this in the previous program) the default constructor  to initialize the state of your class. The default constructor will read the data from the file “callstats_data.txt” into the dynamic array call_DB.  If call_DB becomes full, the function should call the function “double_size” to double the size (capacity) of call_DB. Remember, count and call_DB are private members of your class and do not need to  be passed to an member function  of your class.
3.	 (you implemented this in the previous program) is_empty is a Boolean public member function of the class.  It has no formal parameter because count is a member of the state of the class (private member) and does not need to be passed to it because the state of the class if known to all member functions of the class. If count == 0 then true is returned; otherwise false is returned.
4.	(you implemented this in the previous program) is_full is a Boolean public member function of the class.  It has no formal parameters because count and size are members of the state of the class (private members) and do not need to be passed to it because the state of the class if known to all member functions of the class. If count == size then true is return; otherwise false. The size is the capacity which is the total number of cells allocated to call_DB.
5.	(you implemented this in the previous program) search is an integer public member function that has only one formal parameter, the key.  key is the cell phone number for the record you are search for. The array of records, call_DB and count are members of the state of the class and do not need to be passed to a member function of the class; The function will return the location of key in call_DB if it is there; otherwise -1 is returned.
6.	(you implemented this in the previous program) add is a void public member function that inserts key (cell number) into call_DB.  Duplicates cell numbers are ok; add will prompt the user for the firstname, lastname, relays and call length. You may call process record to re-process when you add a new record. add has only one formal parameter, the key.
7.	overload operator “-“ as a member function of call_class with chaining.  This function will have the same functionality as the “remove” function.  Recall the following about the function remove: “remove is a void public member function thaqt deletes all records with the cell number stored in key. If duplicate records exist with the same cell number they must all be deleted. “remove” has only one formal parameter, the key.” Note, because we are overloading with chaining we must return the current object “*this”.
8.	(you implemented this in the previous program) double_size is a void public member function that doubles the capacity of call_DB. “double_size” has no formal parameters because size, count and call_DB are all members of the state of the class, call_class. First, size is multipled by two; second, memory is allocated using “call_record *temp=new call_record[size]; third the records in call_DB are copied into temp with the statement “temp[i]=call_DB[i]” using a for loop. Forth, the old memory for call_DB is de-allocated using “delete [ ] call_DB”; Finally, call_DB is set to point to the new memory pointed to by temp using “call_DB = temp”.
9.	(you implemented this in the previous program) process is a void public member function the has no formal parameter because call_DB and count are members of the state of the class.. The function  process will calculate the net cost of a call (net_cost), the tax on a call (call_tax) and the total cost of the call (total_cost) using the number of relay stations (relays) and the length in minutes of the call (call_length) for all call records stored in call_DB.  Please consider the following:
a.	The tax rate on a call (call_tax) is simply based on the number of relay stations (relays) used to make the call  (0<= relays <=5 then call_tax = 1%; 6<= relays <=11 then call_tax = 3%; 12<= relays<=20 then call_tax = 5%; 21<= relays <=50 then call_tax = 8%; relays >50 then call_tax =12%) .
b.	The net cost of a call is calculated by the following formula:  net_cost = ( relays / 50  x  0.40 x call_length).
c.	The tax on a call is equal to net_cost x  call_tax / 100.
d.	The total cost of a call (rounded to the nearest hundredth) is calculated by the following formula: total_cost = net_cost + call_tax .  All tax and cost calculations should be rounded to the nearest hundredths.
10.	 (you implemented this in the previous program) overload operator “<<“ as a friend function of call_class with chaining.  This function will have the same functionality as the “print” function except it will print to the screen and a file called “stats8_output.txt”.  Recall the following about the function print: “print is a void public member function that has no formal parameters because count and call_DB are members of the state of the class. The function will print every field of every call_record in call_DB to the screen”.
11.	(you implemented this in the previous program) the destructor to de-allocate all memory allocated to call_DB.  This function has no formal parameters because call_DB is a member of the state of the class. It will be called automatically by the compiler.


LOG:
16.07.11, 21:24 - START
16.07.11, 21:35 - 1st compile, call_class copy constructor
16.07.11, 21:51 - migrated to 3 files
16.07.11, 22:45 - added #ifndef blocks
 - STOP


BUG:	FOUND:			FIXED:			DESCIRPTION:
B0001	16.07.11,21:51  -               BUG: 
|                                       C2668 'stringExtract': ambiguous 
|                                            call to overloaded function 
|                                            "in call_class.cpp line 62"
|                                       more than one instance of overloaded 
|                                            function "stringExtract" matches 
|                                            the argument list:
|                       16.07.11,20:43  FIX: the compiler was right. Originally
|                                       I had stringExtract set as a friend of
|                                       all call_class objects, even though I
|                                       never explicitly defined one, so the 
|                                       compiler was tring to use that 
|                                       definition first even though the 
|                                       functions that use it don't call 
|                                       themselves to use it as one of their 
|                                       members.
*******************************************************************************/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <ios>

#ifndef CALL_CLASS_H
	#define CALL_CLASS_H
	#include "call_class.h"
#endif

#ifndef CALL_RECORD_H
	#define CALL_RECORD_H
	#include "call_record.h"
#endif

using namespace std;


int main()
{
	ifstream in_stream;
	ofstream out_stream;

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

			call_class MyClassB = MyClass;

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
				cin >> choice; 
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //probably totally necessary.
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
					cin >> s; 
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //probably totally necessary.
					n = MyClass.search(s, occur);
					if (n > -1) cout << occur << " records exist. The first is record number: " << n + 1 << endl;
					else cout << "No record found." << n << endl;
					break;
				case 3:
					cout << "SELECTED: 3 - Delete a record." << endl;
					cout << "Input phone number to delete: ";
					cin >> s; 
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //probably totally necessary.
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
					if (!out_stream.fail())
					{
						MyClass.process(0);
						MyClass.print(out_stream);
						out_stream.close(); 
					}
					else cout << "Input file did not open correctly" << endl;
					

					
					out_stream.open(output_filename + "_original.txt");
					out_stream.open(output_filename);
					if (!out_stream.fail())
					{
						MyClassB.process(0);
						MyClassB.print(out_stream);
						out_stream.close();
					}
					else cout << "Input file did not open correctly" << endl;
					
					
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
			MyClassB.~call_class();
		}

		in_stream.close();

		cout << "Would you like to do another calculation (Y or N): ";
		getline(cin, user_response);
		cout << endl << endl;


	} while (user_response == "y" || user_response == "Y");

	return 0;
}