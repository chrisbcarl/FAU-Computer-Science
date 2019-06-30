#include <iostream>
#include <string>

using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

class QUEUE
{
public:

	class Qnode
	{
	public:
		string data;
		Qnode *next, *prev;
		Qnode(){ next = prev = 0;};
	};

	QUEUE();
	~QUEUE();
	QUEUE(const QUEUE &);
	void enQueue(const string &);
	void deQueue( );
	bool Empty(){return front==0;}
	string & Front();
	void Print();
	void Print_Reverse();
private:
	Qnode *front, *back;
};

#endif
	