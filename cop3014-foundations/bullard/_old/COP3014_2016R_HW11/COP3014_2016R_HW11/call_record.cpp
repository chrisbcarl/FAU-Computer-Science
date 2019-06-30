#include "call_record.h"

call_record::call_record()
{
}


call_record::~call_record()
{
}


/*
Name:  - (overload)
Precondition:       a call_record object is instantiated

VARS:               const call_record &call_DB_element

RETURNS:            call_record

Postcondition:      current call_DB element, which is a call_record
|                   is flagged as deleted.
Description:        Flags a call_record object as deleted
*/
call_record operator - (const call_record &call_DB_element)
{
	call_record temp = call_DB_element;
	temp.deleted = true;
	return temp;
}