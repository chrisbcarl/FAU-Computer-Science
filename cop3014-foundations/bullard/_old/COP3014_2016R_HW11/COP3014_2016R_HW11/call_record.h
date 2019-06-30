#pragma once

#include <iostream>
#include <string>

class call_record
{
public:
	call_record();
	~call_record();

	bool deleted = false;
	std::string firstname = "";
	std::string lastname = "";
	std::string cell_number = "";
	int relays = 0;
	int call_length = 0;
	double net_cost = 0;
	double tax_rate = 0;
	double call_tax = 0;
	double total_cost = 0;
	
	friend call_record operator - (const call_record &call_DB_element);
};