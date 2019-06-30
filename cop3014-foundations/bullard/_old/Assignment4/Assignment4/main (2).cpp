/*******************************************************************************

NAME: Christopher Carl
Z#: Z23146703
COURSE: Foundations of Computer Science (COP3014)
PROFESSOR: Dr. Lofton Bullard
DUE DATE: 16.06.12
DUE TIME: 23:30
TOTAL POINTS: 100
ASSIGNMENT 4: all_area_semi.cpp 

DESCRIPTION:
1. Be able to use the call - by - value mechanism
2. Be able to use the call - by - reference mechanism
Write a program called “all_area_semi.cpp” that computes the area of an 
arbitrary triangle. Use the following formula :
	𝑎𝑟𝑒𝑎 = √𝑠(𝑠 − 𝑎)(𝑠 − 𝑏)(𝑠 − 𝑐)
where a, b and c are the lengths of the sides, and s is the semi_perimeter.
	s = (a + b + c) / 2

Include a void function call “Compute” that computes the area and shape_perimeter of a
triangle based on the length of the sides.The function should use five parameters –
three call by value parameters(a, b, c) that provide the lengths of the edges and
two call by reference parameters(area, semi_perimeter) that stores the computed
area and shape_perimeter.Make your function robust.The function “Compute” should
be called from your main program.Your must print the computed area and
semi_perimeter rounded to the nearest hundredths.In main you should declared the
necessary variables, and include a while loop asking the user if he / she would like
to continue computing area and semi_perimeters.

Note that not all combinations of a, b, and c produce a triangle.Remember, the
sum of any two sides of a triangle must be greater than the third side.You must
make sure that the lengths of the sides of the triangle entered by the user are valid;
if not valid lengths, you should let the user know by printing a message stating that
the lengths are invalid, and then prompt the user if he / she would like to continue
computing area and semi_perimeters.Your function should produce correct results
for legal data and reasonable results for illegal combinations.

You may implement more functions if you find it necessary. Please start the
assignment ASAP and ask questions to make sure you understand what you
must do.Remember to follow all style rules and to include all necessary
documentation(consistent, indentation, proper variable names, pre / post
condition, program header, function headers, and so forth.)

Electronically submit the source file " all_area_semi.cpp " in the Assignments
area of blackboard before the due date and time.Remember, submit your
assignment on time no matter if it is complete or incorrect.
Consider the following skeleton as a hint :

LOG:
16.05.31, 18:12 - start
16.05.31, 18:49 - logic completed, 1st compile using class
16.05.31, 19:24 - logic completed, 2nd compile using STRUCTS
16.05.31, 19:59 - logic completed, 3rd compile following directions
16.05.31, 20:16 - logic completed, 4th compile
16.05.31, 20:26 - formatting for readability/80char rule
16.05.31, 20:37 - documentation added
 


 BUG:	FOUND:			FIXED:			DESCIRPTION:
*******************************************************************************/


#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class triangle_class
{
public:
	double s, a, b, c, area, p; //really should be private
private:
};


struct TRIANGLE_STRUCT {   
	double s, a, b, c, area, p;
};

void Input(ifstream & in, TRIANGLE_STRUCT & triangle_s);
void Input(ifstream & in, triangle_class & triangle_c);
void Compute(double a, double b, double c, double & p, double & s, double & area);
void Compute(const TRIANGLE_STRUCT & triangle_s);
void Compute(const triangle_class & triangle_c);
void Output(double a, double b, double c, double p, double s, double area);
void Output(const TRIANGLE_STRUCT & triangle_s);
void Output(const triangle_class & triangle_c);

double shape_perimeter(double a, double b, double c);
double shape_semiperimeter(double a, double b, double c);
double shape_area(double a, double b, double c, double s);

/*
Name:  Input
Precondition:		VARS all initialized in higher function

VARS:				ifstream in
					TRIANGLE_STRUCT & triangle_s

Postcondition:		VAR triangle_s contains new data
Description:		Gets triangle input from a data text file.
					Each "line" of this data text file becomes
					the same object, triangle_s which
					becomes processed by void Compute()
*/
void Input(ifstream & in, TRIANGLE_STRUCT & triangle_s)
{
	in >> triangle_s.a;
	in >> triangle_s.b;
	in >> triangle_s.c;
}


/*
Name:  Input
Precondition:		VARS all initialized in higher function

VARS:				ifstream in
					triangle_class & triangle_c

Postcondition:		VAR triangle_s contains new data
Description:		Gets triangle input from a data text file.
					Each "line" of this data text file becomes
					the same object, triangle_c which
					becomes processed by void Compute()
*/
void Input(ifstream & in, triangle_class & triangle_c)
{
	in >> triangle_c.a;
	in >> triangle_c.b;
	in >> triangle_c.c;
}


/*
Name:  Process
Precondition:		VARS all defined in higher function

VARS:				double a, 
					double b, 
					double c, 
					double & p, 
					double & s, 
					double & area

Postcondition:		VARS all calculated in higher function
Description:		Processes all of the main variables a, b, c to 
					compute the last variables p, s, and area.
					Demonstrates the first three being passed by 
					value, and the last three passed by refference.
*/
void Compute(double a, double b, double c, double & p, double & s, double & area)
{
	p = shape_perimeter(a, b, c);
	s = shape_semiperimeter(a, b, c);
	area = shape_area(a, b, c, s);
}


/*
Name:  Input
Precondition:		VARS all initialized in higher function

VARS:				ifstream in
					TRIANGLE_STRUCT & triangle_s

Postcondition:		VAR triangle_s contains new data
Description:		Processes all of the main variables a, b, c to
					compute the last variables p, s, and area.
					Demonstrates all six being passed by refference.
*/
void Compute(TRIANGLE_STRUCT & triangle_s)
{
	triangle_s.p = shape_perimeter(triangle_s.a, triangle_s.b, triangle_s.c);
	triangle_s.s = shape_semiperimeter(triangle_s.a, triangle_s.b, triangle_s.c);
	triangle_s.area = shape_area(triangle_s.a, triangle_s.b, triangle_s.c, triangle_s.s);
}


/*
Name:  Input
Precondition:		VARS all initialized in higher function

VARS:				ifstream in
					triangle_class & triangle_c

Postcondition:		VAR triangle_c contains new data
Description:		Processes all of the main variables a, b, c to
					compute the last variables p, s, and area.
					Demonstrates all six being passed by refference.
*/
void Compute(triangle_class & triangle_c)
{
	triangle_c.p = shape_perimeter(triangle_c.a, triangle_c.b, triangle_c.c);
	triangle_c.s = shape_semiperimeter(triangle_c.a, triangle_c.b, triangle_c.c);
	triangle_c.area = shape_area(triangle_c.a, triangle_c.b, triangle_c.c, triangle_c.s);
}


/*
Name:  Output
Precondition:		VARS all initialized in higher function

VARS:				call_record customer_record

Postcondition:		VAR customer_record contains no new data
Description:		Outputs the individual attributes of the call_record
object customer_record to the user.
*/
void Output(double a, double b, double c, double p, double s, double area)
{
	if (p != 0)
	{
		cout << endl << endl;
		cout << "FIELD:                        VALUE:" << endl;
		cout << "== == == == == == == == == == == == == == == ==" << endl;
		cout << "Side A                        " << a << endl;
		cout << "Side B                        " << b << endl;
		cout << "Side C                        " << c << endl;
		cout << "Perimeter                     " << p << endl;
		cout << "Semiperimeter                 " << s << endl;
		cout << "Area                          " << area << endl;
		cout << endl << endl;
	}
	else
	{
		cout << endl << endl;
		cout << "FIELD:                        VALUE:" << endl;
		cout << "== == == == == == == == == == == == == == == ==" << endl;
		cout << "Side A                        " << a << endl;
		cout << "Side B                        " << b << endl;
		cout << "Side C                        " << c << endl;
		cout << "                              INVALID TRIANGLE" << endl;
		cout << endl << endl;
	}
}


void Output(const TRIANGLE_STRUCT & triangle_s)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	if (triangle_s.p != 0)
	{
		cout << endl << endl;
		cout << "FIELD:                        VALUE:" << endl;
		cout << "== == == == == == == == == == == == == == == ==" << endl;
		cout << "Side A                        " << triangle_s.a << endl;
		cout << "Side B                        " << triangle_s.b << endl;
		cout << "Side C                        " << triangle_s.c << endl;
		cout << "Perimeter                     " << triangle_s.p << endl;
		cout << "Semiperimeter                 " << triangle_s.s << endl;
		cout << "Area                          " << triangle_s.area << endl;
		cout << endl << endl;
	}
	else
	{
		cout << endl << endl;
		cout << "FIELD:                        VALUE:" << endl;
		cout << "== == == == == == == == == == == == == == == ==" << endl;
		cout << "Side A                        " << triangle_s.a << endl;
		cout << "Side B                        " << triangle_s.b << endl;
		cout << "Side C                        " << triangle_s.c << endl;
		cout << "                              INVALID TRIANGLE" << endl;
		cout << endl << endl;
	}	
}
void Output(const triangle_class & triangle_c)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	if (triangle_c.p != 0)
	{
		cout << endl << endl;
		cout << "FIELD:                        VALUE:" << endl;
		cout << "== == == == == == == == == == == == == == == ==" << endl;
		cout << "Side A                        " << triangle_c.a << endl;
		cout << "Side B                        " << triangle_c.b << endl;
		cout << "Side C                        " << triangle_c.c << endl;
		cout << "Perimeter                     " << triangle_c.p << endl;
		cout << "Semiperimeter                 " << triangle_c.s << endl;
		cout << "Area                          " << triangle_c.area << endl;
		cout << endl << endl;
	}
	else
	{
		cout << endl << endl;
		cout << "FIELD:                        VALUE:" << endl;
		cout << "== == == == == == == == == == == == == == == ==" << endl;
		cout << "Side A                        " << triangle_c.a << endl;
		cout << "Side B                        " << triangle_c.b << endl;
		cout << "Side C                        " << triangle_c.c << endl;
		cout << "                              INVALID TRIANGLE" << endl;
		cout << endl << endl;
	}
}


double shape_perimeter(double a, double b, double c)
{
	if ((a + b) < c || (a + c) < b || (b + c) < a)
	{
		return 0;
	}
	else
	{
		return a + b + c;
	}
}
double shape_semiperimeter(double a, double b, double c)
{
	if ((a + b) < c || (a + c) < b || (b + c) < a)
	{
		return 0;
	}
	else
	{
		return (a + b + c) / 2;
	}
}
double shape_area(double a, double b, double c, double s)
{
	if ((a + b) < c || (a + c) < b || (b + c) < a)
	{
		return 0;
	}
	else
	{
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
}

int main(int argc, const char * argv[])
{
	TRIANGLE_STRUCT triangle_s;
	triangle_class triangle_c;

	ifstream in;    //declaring an input file stream

	string user_selection = "0";
	string user_response = "y";
	string filename = "tri_data.txt";

	do
	{
		cout << "== == == == == == == == == == == == == == == ==" << endl;
		cout << "                    MAIN MENU                  " << endl;
		cout << "== == == == == == == == == == == == == == == ==" << endl;

		cout << "Select 1 Option:" << endl;
		cout << "0) Compute w/ Variables" << endl;
		cout << "1) Compute w/ Structs" << endl;
		cout << "2) Compute w/ Classes" << endl;
		cout << "User Selection:               ";
		getline(cin, user_selection);
		cout << endl << endl;

		if (user_selection == "0")
		{
			cout << "== == == == == == == == == == == == == == == ==" << endl;
			cout << "               Compute w/ Variables            " << endl;
			cout << "== == == == == == == == == == == == == == == ==" << endl;

			do
			{
				string a_string, b_string, c_string;
				cout << "Side A: "; getline(cin, a_string);
				cout << "Side B: "; getline(cin, b_string);
				cout << "Side C: "; getline(cin, c_string);
				double a = stod(a_string), b = stod(b_string), c = stod(c_string), p, s, area;

				Compute(a, b, c, p, s, area);
				Output(a, b, c, p, s, area);

				cout << "Would you like to do another calculation (Y or N): ";
				getline(cin, user_response);
				cout << endl << endl;

			} while (user_response == "y" || user_response == "Y");
		}
		else if (user_selection == "1")
		{
			cout << "== == == == == == == == == == == == == == == ==" << endl;
			cout << "               Compute w/ Structs              " << endl;
			cout << "== == == == == == == == == == == == == == == ==" << endl;
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
						Input(in, triangle_s);
						Compute(triangle_s);
						Output(triangle_s);
					}
				}

				in.close();

				cout << "Would you like to do another calculation (Y or N): ";
				getline(cin, user_response);
				cout << endl << endl;


			} while (user_response == "y" || user_response == "Y");
		}
		else if (user_selection == "2")
		{
			cout << "== == == == == == == == == == == == == == == ==" << endl;
			cout << "               Compute w/ Classes              " << endl;
			cout << "== == == == == == == == == == == == == == == ==" << endl;
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
						Input(in, triangle_c);
						Compute(triangle_c);
						Output(triangle_c);
					}
				}

				in.close();

				cout << "Would you like to do another calculation (Y or N): ";
				getline(cin, user_response);
				cout << endl << endl;


			} while (user_response == "y" || user_response == "Y");
		}


		cout << "Would you like to select another option? (Y or N): ";
		getline(cin, user_response);
		cout << endl << endl;

	} while (user_response == "y" || user_response == "Y");

	return 0;
}

