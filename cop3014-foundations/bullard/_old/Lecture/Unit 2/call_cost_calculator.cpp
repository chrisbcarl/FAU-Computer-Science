/****SAMPLE PROGRAM HEADER*******************************************************
Lofton Bullard	        Total Points:  100
Due Date:  2/4/2013
Course:  C0P3014
Assignment:  Assignment 1
Professor: Dr. Lofton Bullard

Description: (Your program description goes here -- what is does--In the program we processed....


*************************************************************/
#include <iostream> //standard library for i/o
#include <string>

using namespace std;

int main()
{
	 string user_response = "y";

	while (user_response == "y" || user_response == "Y")
	{
                       //The code to get the user's input, perform the calculations, and print
                       // the results to the screen should go here.  
           
	    cout<<"Would you like to do another calculation (Y or N): "<<endl;
	    cin>>user_response;
	}

	return  0;
}






