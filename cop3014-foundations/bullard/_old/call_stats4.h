#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int $SIZE = 200;

string input_file = "call_data.txt";
string output_file = "weekly_call_info4.txt";

struct call_record
{
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};


//we need to pass an array of call_records
void Input(call_record call_DB[], int & count);	
void Process(call_record call_DB[], const int & count);
void Output(const call_record call_DB[], const int & count);

int call_stats4()
{
	int count = 0;
	//call_record * call_DB = new call_record[$SIZE];
	call_record call_DB[$SIZE];

	Input(call_DB, count);
	Process(call_DB, count);
	Output(call_DB, count);

	return 0;
}

void Input(call_record call_DB[], int & count)
{
	/*
	input
	1) takes from file call_data.txt
	2) reads each line
	3) put each line into the array of call_record (shelf of call_record)
	*/
	ifstream in;
	in.open(input_file);

	if (in.fail())
	{
		cout << "INPUT FILE NOT OPENED" << endl;
		exit(1);
	}

	int i = 0;
	while (!in.eof())
	{
		in >> call_DB[i].cell_number >> call_DB[i].relays >> call_DB[i].call_length;
		i++;
	}
	count = i;

}


void Process(call_record call_DB[], const int & count)
{	
	/*
	process
	1) for each element in the array, process it
	*/
	for (int i = 0; i < count; i++)
	{
		if (call_DB[i].relays <= 1 && call_DB[i].relays <= 5)
		{
			call_DB[i].tax_rate = .01;
		}
		if (call_DB[i].relays <= 6 && call_DB[i].relays <= 11)
		{
			call_DB[i].tax_rate = .03;
		}
		if (call_DB[i].relays <= 12 && call_DB[i].relays <= 20)
		{
			call_DB[i].tax_rate = .05;
		}
		if (call_DB[i].relays <= 21 && call_DB[i].relays <= 50)
		{
			call_DB[i].tax_rate = .08;
		}
		else
		{
			call_DB[i].tax_rate = .12;
		}

		call_DB[i].net_cost = call_DB[i].relays / 50.0 * .40 * call_DB[i].call_length;
		call_DB[i].call_tax = call_DB[i].net_cost * call_DB[i].tax_rate;
		call_DB[i].total_cost = call_DB[i].net_cost + call_DB[i].call_tax;
	}
}

void Output(const call_record call_DB[], const int & count)
{
	/*
	output
	1) open a new file weekly_call_info.txt
	2) read each shelf line by line and output
	*/
	ofstream out;
	out.open(output_file);

	if (out.fail())
	{
		cout << "OUTPUT FILE NOT OPENED" << endl;
		exit(1);
	}

	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

	for (int i = 0; i < count; i++)
	{
		cout << call_DB[i].cell_number << "\t" <<
			call_DB[i].relays << "\t" <<
			call_DB[i].call_length << "\t" <<
			call_DB[i].net_cost << "\t" <<
			call_DB[i].tax_rate << "\t" <<
			call_DB[i].call_tax << "\t" <<
			call_DB[i].total_cost << endl;

		out << call_DB[i].cell_number << "\t" <<
			call_DB[i].relays << "\t" <<
			call_DB[i].call_length << "\t" <<
			call_DB[i].net_cost << "\t" <<
			call_DB[i].tax_rate << "\t" <<
			call_DB[i].call_tax << "\t" <<
			call_DB[i].total_cost << endl;
	}

}