
#include "queue.h"

using namespace std;






QUEUE::QUEUE():front(0), back(0)
{}

QUEUE::~QUEUE()
{
	cout<<"~QUEUE has been called\n";
	while (!Empty())
	{
		deQueue();
	}
}
	//QUEUE(const QUEUE &);
void QUEUE::enQueue(const string & item)
{
	if (Empty())
	{
		front = back = new Qnode;
		front->data = item;
	}
	else
	{
		back->next = new Qnode;
		back->next->prev = back;
		back = back->next;
		back->data = item;
	}
}

void QUEUE::deQueue( )
{
	if (!Empty())
	{
		Qnode *p = front;
		front = front->next;
		if (front != 0)
			front->prev = 0;
		else
			back = 0;

		delete p;
	}
	else
	{
		cout<<"Cannot deQueue because queue is empty\n";
	}

}


string & QUEUE::Front()
{
	string s="";

	if (!Empty())
	{
		return front->data;
	}
	else
	{
		return s;
	}
}

void QUEUE::Print()
{

Qnode *p = front;
	//Qnode *p = back;

	while(p!=0)
	{
		cout<<p->data<<endl;
	    p = p->next;
		//p=p->prev;
	}
}

void QUEUE::Print_Reverse()
{
	Qnode *p = back;

	while(p!=0)
	{
		cout<<p->data<<endl;
		p = p->prev;
	}
}