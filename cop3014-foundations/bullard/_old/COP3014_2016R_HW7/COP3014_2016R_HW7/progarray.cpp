//
////THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH ASSIGNMENT#2
//
//
////EXAMPLE OF PROGRAM HEADER
///************************************************************************************************************************
//
//Name:                                 Z#:                           
//Course: Foundations of Computer Science (COP3014)
//Professor: Dr. Lofton Bullard
//Due Date:                      Due Time:
//Total Points: 100
//Assignment :
//
//Description:
// 
//*************************************************************************************************************************/
//
////Include the following
//
//#include <iostream>
//#include <string>
//#include <fstream>  //you must include this library if you wish to do file i/o
//using namespace std;
//
//
//const int SIZE = 200;  //declaration the capacity of the array
//
///*********************************************************
////Following is the declaration of a call record
//**********************************************************/
//class call_record
//{
//public:
//	string cell_number;
//	int relays;
//	int call_length;
//	double net_cost;
//	double tax_rate;
//	double call_tax;
//	double total_cost;
//};
//
//
////Prototypes for your functions: Input, Output, and Process will go here
//
//void Input(call_record call_DB[ ], int & count);
//void Output(call_record call_DB[ ], const int count);
//void Process(call_record call_DB[ ], const int count);     
//
////Function Implementations will go here
//
/////*************************************************************************************
////Name:  Input
////Precondition: State what is true before the function is called.
//// Example: the varialbes (formal parameters) have not been initialized
////Postcondition: State what is true after the function has executed.
//// Example: the varaibles (formal parameters) have been initialized
////Description:  
//// Example:Get input (values of cell_number, relays, and call_length) from the user and store in call record.
//
////PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS
//
////*************************************************************************************
//
//void Input(call_record call_DB[ ], int & count) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
//{
//                 //initialize count to zero   --- count = 0;
//	//open the datafile here-- call ifstream "in"
//                 //for loop starts here
//	// for loop body  ---read data into array call_DB
//	//   in>>call_DB[count].cell_number>>call_DB[count].relays>>call_DB[count].call_length;
//                 //   count++;   --- increment count
//                //end of for loop
//               //close ifstream
//}
//
/////*************************************************************************************
////Name:  Output
////Precondition: State what is true before the function is called.
////Postcondition: State what is true after the function has executed.
////Description:  Describe what the function does (purpose).
////*************************************************************************************
//
//
//void Output(call_record call_DB[ ], const int count)
//{
//                 //open ofstream called out
//
//	//start for loop here with i=0; i<count; i++
//                 //  beginning of for loop body
//	//Use thee following statement to help you format you our output. These statements are called the magic formula.
//	//out.setf(ios::showpoint);
//	//out.precision(2);
//	//out.setf(ios::fixed);
//	/********************************************/
//	//out<<DB[i].cell_number<<"  ";
//	//out<<DB[i].relays<<"   ";
//	//out<<DB[i].call_length<<endl;
//	
//
//}
//
/////*************************************************************************************
////Name:  Process
////Precondition: The state what is true before the function is called.
////Postcondition: State what is true after the function has executed.
////Description:  Describe what the function does (purpose).
////*************************************************************************************
//
//
//void Process(call_record call_DB[ ], const int count)
//{
//	//code goes here
//}
//
////Here is your driver to test the program
//int main( )
//{
//	
//	call_record call_DB[SIZE];
//	int count = 0;
//
//	Input(call_DB, count);
//	Process(call_DB,count);
//	Output(call_DB, count);
//
//	return 0;
//}
//
