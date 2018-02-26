#include <iostream>
#include <time.h>

using namespace std;

class Item
{
public:
	int val;
	Item *next, *pre;
	
	Item()
	{
		val = 0;
		next = 0;
		pre = 0;

	}

	Item(int val)
	{
		this->val = val;
		next = 0;
		pre = 0;
	}

	~Item()
	{
		//delete this;
	}

};


class DLinkedList
{
public:
	int size;
	Item *front;
	Item *back;

public:

	DLinkedList();
	DLinkedList(const DLinkedList &list);
	~DLinkedList();

	void push_back(Item *a);
	void push_front(Item *a);

	void pop_front();
	void pop_back();

	void insert(Item *a, int t); // insert the item a AFTER the t-th element
	void insertlist(DLinkedList &list, int t); // insert the whole list a AFTER the t-th element
	void display(ostream &out);

	int getSize();
	Item * getfront();
	Item * getback();
	void swap(Item *p, Item *q); //swap two items pointed by p and q, you can assume that p and q are something in the list

	Item * extractmin(Item *start); // return the pointer of the min element after  "start",
									 // here you can assume user will always input a valid pointer start that points to an item in the list
	Item * extractmax(Item *start);  // return the pointer of the max element after "start"


};


class myStack
{
public:
	DLinkedList list;
public:
	myStack();
	int getSize();
	void in(Item *a);
	Item *top();
	void out();

};

class myQueue
{
public:
	DLinkedList list;
public:
	myQueue();
	int getSize();
	void in(Item *a);
	Item *front();
	void out();
};

DLinkedList::DLinkedList()
{
	size = 0;
	front = 0;
	back = 0;
}

 DLinkedList::DLinkedList(const DLinkedList & list)
{
	size = 0;

	if (list.size == 0)
	{
		front = 0;
		back = 0;
	}
	else
	{
		Item * p = list.front;				//p iterates through the "list" dlist
		Item * a = new Item(p->val);		//a is a new node based on the value of p

		front = a;
		back = a;

        //while (p->next != 0)
		while (p != list.back)
		{
			p = p->next;

			a = new Item(p->val);
			a->pre = back;
			back->next = a;
			back = a;
		}
	}
	size = list.size;
}

 DLinkedList::~DLinkedList()
 {
      //if (size == 0) {
      //    //
      //}
      //else
      //{
      //    Item * p = back;
      //    while (p != front)
      //    {
      //        p = p->pre;
      //        delete p->next;
      //    }
      //delete front;
      //}
 }

void DLinkedList::push_back(Item * a)
{
	if (size == 0)
	{
		front = a;
		back = a;
	}
	else
	{
		a->pre = back;
		back->next = a;
		back = a;
	}

	size++;
}

void DLinkedList::push_front(Item * a)
{
	if (size == 0)	//if list is empty
	{
		front = a;
		back = a;
	}
	else
	{
		//(*a).next = front;
		a->next = front;
		front->pre = a;
		front = a;
	}

	size++;
}

void DLinkedList::pop_front()
{
	front = front->next;
	front->pre = 0;

	size--;
}

void DLinkedList::pop_back()
{
	back = back->pre;
	back->next = 0;

	size--;
}

void DLinkedList::insert(Item * a, int t)
{
	if (size == 0)
	{
		front = a;
		back = a;
	}
	else
	{
		if (t < 1)
		{
            a->next = front;
            front->pre = a;
            front = a;
		}
		else if (t < size)
		{
			Item * p = front;

			int i = 0;
			while (i < t - 1)
			{
				p = p->next;
				i++;
			}
			Item * p2 = p;
			p = p->pre;

			a->pre = p;
			a->next = p2;

			p->next = a;
			p2->pre = a;
		}
		else
		{
			a->pre = back;
			back->next = a;
			back = a;

			//OR push_back(a);
		}
	}
	size++;
}

void DLinkedList::insertlist(DLinkedList & list, int t)
{
	if (size == 0)
	{
		front = list.front;
		back = list.back;
	}
	else
	{
		DLinkedList newlist = list;		//ABSOLUTELY CRITICAL
		if (t < size)
		{

			Item * p = front;

			int i = 0;
			while (i < t - 1)
			{
				p = p->next;
				i++;
			}

			p = p->pre;
			Item * p2 = p->next;
			Item * a = newlist.front;
			Item * b = newlist.back;


			p->next = a;
			a->pre = p;

			b->next = p2;
			p2->pre = b;
		}
		else
		{
			Item * a = newlist.front;
			Item * b = newlist.back;

			a->pre = back;
			back->next = a;
			back = b;

			//OR push_back(a);
		}
	}
	size += list.size;
}

void DLinkedList::display(ostream & out)
{
	if (size == 0)
	{
		out << "size == " << size << "\t";
		out << "EMPTY LIST";
	}
	else if (size == 1)
	{
		out << "[" << front->val << "]";
	}
	else 
	{
		out << "size == " << size << "\t";		
		
		Item * p = front;				//p iterates through "this" dlist
		while (p != back)
		{
			out << "[" << p->val << "] -> ";
			p = p->next;
		}
        out << "[" << back->val << "]";
	}
}

int DLinkedList::getSize()
{
	return this->size;
}

Item * DLinkedList::getfront()
{
	return new Item(front->val);
}

Item * DLinkedList::getback()
{
	return new Item(back->val);
}

void DLinkedList::swap(Item * p, Item * q)
{
	int a = p->val;
	p->val = q->val;
	q->val = a;

	/*
	ORRRR?? Except a is now p, and any mods to a now mod p.

	Item * a = p;
	p->next = q->next;
	p->pre = q->pre;

	q->next = a->next;
	q->pre = a->pre;
	*/
}

Item * DLinkedList::extractmin(Item * start)
{
	Item * min;
	if (size == 0)
	{
		min = new Item(-858993460);
	}
	else
	{
		Item * p = start;					//p iterates through "this" dlist
		min = new Item(p->val);		//min stores the min value. That's it.
		while (p != back)
		{
			p = p->next;
			if (p->val < min->val) min->val = p->val;
		}
	}
	return min;
	
	//Item * temp = start;
	//int min = temp->val;
	//while (temp != 0)
	//{
	//	temp = temp->next;
	//	if (temp->val < min) min = temp->val;
	//}
	//
	////return a new node with val == min;
	//return new Item(min);

}

Item * DLinkedList::extractmax(Item * start)
{
	Item * max;
	if (size == 0)
	{
		max = new Item(858993460);
	}
	else
	{
		Item * p = start;					//p iterates through "this" dlist
		max = new Item(p->val);		//max stores the max value. That's it.

		while (p != back)
		{
			p = p->next;
			if (p->val > max->val) max->val = p->val;
		}
	}
	return max;
}

myStack::myStack()
{
	list = DLinkedList();
}

int myStack::getSize()
{
	return list.getSize();
}

void myStack::in(Item * a)
{
	list.push_front(a);
}

Item * myStack::top()
{
	return list.getfront();
}

void myStack::out()
{
	list.pop_front();
}

myQueue::myQueue()
{
	list = DLinkedList();
}

int myQueue::getSize()
{
	return list.getSize();
}

void myQueue::in(Item * a)
{
	list.push_back(a);
}

Item * myQueue::front()
{
	return list.getfront();
}

void myQueue::out()
{
	list.pop_front();
}

/* generate secret number between 1 and 10: */
int randomNumber(const int & upper, const int & lower)
{
	return rand() % upper + lower;
}

int main() {

	srand(static_cast<unsigned int>(time(NULL)));

	DLinkedList doubly_linked_list = DLinkedList();
	cout << "dll  :\t";  doubly_linked_list.display(cout);
	cout << endl << endl;

	DLinkedList doubly_linked_list_null = doubly_linked_list;
	cout << "dll N:\t";  doubly_linked_list_null.display(cout);
	cout << endl << endl;



	doubly_linked_list.push_back(new Item(0));
	cout << "dll  :\t";  doubly_linked_list.display(cout);
	cout << endl << endl;

	DLinkedList doubly_linked_list_0 = doubly_linked_list;
	cout << "dll 0:\t";  doubly_linked_list_0.display(cout);
	cout << endl << endl;



	for (int i = 1; i < 6; i++)
	{
		doubly_linked_list.push_back(new Item(i));
		cout << "dll  :\t";  doubly_linked_list.display(cout);
		cout << endl;
	}
	cout << endl;

	DLinkedList doubly_linked_list_pos = doubly_linked_list;
	cout << "dll +:\t";  doubly_linked_list_pos.display(cout);
	cout << endl << endl;


	doubly_linked_list = doubly_linked_list_0;
	for (int i = -1; i > -6; i--)
	{
		doubly_linked_list.push_front(new Item(i));
		cout << "dll  :\t";  doubly_linked_list.display(cout);
		cout << endl;
	}
	cout << endl;

	DLinkedList doubly_linked_list_neg = doubly_linked_list;
	cout << "dll -:\t";  doubly_linked_list_neg.display(cout);
	cout << endl << endl;


	DLinkedList doubly_linked_list_real = doubly_linked_list_null;
	cout << "dll r:\t";  doubly_linked_list_real.display(cout);
	cout << endl;
	doubly_linked_list_real.insert(new Item(69), 3);
	cout << "dll r:\t";  doubly_linked_list_real.display(cout);
	cout << endl;
	doubly_linked_list_real.insert(new Item(0), 3);
	cout << "dll r:\t";  doubly_linked_list_real.display(cout);
	cout << endl;
	doubly_linked_list_real.insert(new Item(6), 3);
	cout << "dll r:\t";  doubly_linked_list_real.display(cout);
	cout << endl;
	doubly_linked_list_real.insert(new Item(23), 3);
	cout << "dll r:\t";  doubly_linked_list_real.display(cout);
	cout << endl;
	doubly_linked_list_real.insert(new Item(-69), 3);
	cout << "dll r:\t";  doubly_linked_list_real.display(cout);
	cout << endl;
	doubly_linked_list_real.insert(new Item(54), 3);
	cout << "dll r:\t";  doubly_linked_list_real.display(cout);
	cout << endl;

	DLinkedList doubly_linked_list_sure = doubly_linked_list_null;
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl;
	Item * a = new Item(randomNumber(100, -100));
	Item * b = new Item(randomNumber(100, -100));
	Item * c = new Item(randomNumber(100, -100));
	Item * d = new Item(randomNumber(100, -100));


	doubly_linked_list_sure.insert(a, 3);
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl;
	doubly_linked_list_sure.insert(b, 3);
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl;
	doubly_linked_list_sure.insert(c, 3);
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl;
	doubly_linked_list_sure.insert(d, 3);
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl;
	doubly_linked_list_sure.insert(new Item(0), 0);
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl;
	doubly_linked_list_sure.insertlist(doubly_linked_list_real, 3);
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl << endl;

	doubly_linked_list_sure.swap(b, c);
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl;
	doubly_linked_list_sure.swap(a, d);
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl << endl;

	Item * w = doubly_linked_list_real.getfront();
	doubly_linked_list_real.pop_front();
	cout << "dll r:\t";  doubly_linked_list_real.display(cout);
	cout << endl;
	Item * x = doubly_linked_list_real.getback();
	doubly_linked_list_real.pop_back();
	cout << "dll r:\t";  doubly_linked_list_real.display(cout);
	cout << endl << endl;

	Item * y = doubly_linked_list_sure.getfront();
	doubly_linked_list_sure.pop_front();
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl;
	Item * z = doubly_linked_list_sure.getback();
	doubly_linked_list_sure.pop_back();
	cout << "dll s:\t";  doubly_linked_list_sure.display(cout);
	cout << endl << endl;


	DLinkedList doubly_linked_list_huh;
	doubly_linked_list_huh.insert(w, 1);
	doubly_linked_list_huh.insert(x, 2);
	doubly_linked_list_huh.insert(y, 3);
	doubly_linked_list_huh.insert(z, 4);
	cout << "dll h:\t";  doubly_linked_list_huh.display(cout);
	cout << endl;
	cout << endl << endl;

	DLinkedList doubly_linked_list_mins;
	Item * min1 = doubly_linked_list.extractmin(doubly_linked_list.front);
	Item * min2 = doubly_linked_list_0.extractmin(doubly_linked_list_0.front);
	Item * min3 = doubly_linked_list_huh.extractmin(doubly_linked_list_huh.front);
	Item * min4 = doubly_linked_list_neg.extractmin(doubly_linked_list_neg.front);
	Item * min5 = doubly_linked_list_null.extractmin(doubly_linked_list_null.front);
	Item * min6 = doubly_linked_list_pos.extractmin(doubly_linked_list_pos.front);
	Item * min7 = doubly_linked_list_real.extractmin(doubly_linked_list_real.front);
	Item * min8 = doubly_linked_list_sure.extractmin(doubly_linked_list_sure.front);
	doubly_linked_list_mins.insert(min1, 1);
	doubly_linked_list_mins.insert(min2, 2);
	doubly_linked_list_mins.insert(min3, 3);
	doubly_linked_list_mins.insert(min4, 4);
	doubly_linked_list_mins.insert(min5, 5);
	doubly_linked_list_mins.insert(min6, 6);
	doubly_linked_list_mins.insert(min7, 7);
	doubly_linked_list_mins.insert(min8, 8);
	cout << "dll m:\t";  doubly_linked_list_mins.display(cout);
	cout << endl;

	DLinkedList doubly_linked_list_max;
	Item * max1 = doubly_linked_list.extractmax(doubly_linked_list.front);
	Item * max2 = doubly_linked_list_0.extractmax(doubly_linked_list_0.front);
	Item * max3 = doubly_linked_list_huh.extractmax(doubly_linked_list_huh.front);
	Item * max4 = doubly_linked_list_neg.extractmax(doubly_linked_list_neg.front);
	Item * max5 = doubly_linked_list_null.extractmax(doubly_linked_list_null.front);
	Item * max6 = doubly_linked_list_pos.extractmax(doubly_linked_list_pos.front);
	Item * max7 = doubly_linked_list_real.extractmax(doubly_linked_list_real.front);
	Item * max8 = doubly_linked_list_sure.extractmax(doubly_linked_list_sure.front);
	doubly_linked_list_max.insert(max1, 1);
	doubly_linked_list_max.insert(max2, 2);
	doubly_linked_list_max.insert(max3, 3);
	doubly_linked_list_max.insert(max4, 4);
	doubly_linked_list_max.insert(max5, 5);
	doubly_linked_list_max.insert(max6, 6);
	doubly_linked_list_max.insert(max7, 7);
	doubly_linked_list_max.insert(max8, 8);
	cout << "dll m:\t";  doubly_linked_list_max.display(cout);
	cout << endl << endl;

	myStack ms1 = myStack();
	ms1.list = doubly_linked_list_max;
	cout << "ms  1:\t";  ms1.list.display(cout);
	cout << endl;
	ms1.in(new Item(-13));
	cout << "ms  1:\t";  ms1.list.display(cout);
	cout << endl;
	DLinkedList d_turd2 = DLinkedList();
	d_turd2.push_back(ms1.top());
	cout << "ms  1: top\t"; d_turd2.display(cout); cout << endl;
	cout << "ms  1:\t";  ms1.list.display(cout);
	cout << endl;
	ms1.out();
	cout << "ms  1:\t";  ms1.list.display(cout);
	cout << endl << endl;

	myQueue mq1 = myQueue();
	mq1.list = doubly_linked_list_mins;
	cout << "mq  1:\t";  mq1.list.display(cout);
	cout << endl;
	mq1.in(new Item(-13));
	cout << "mq  1:\t";  mq1.list.display(cout);
	cout << endl;
	DLinkedList d_turd1 = DLinkedList();
	d_turd1.push_back(mq1.front());
	cout << "mq  1: front\t"; d_turd1.display(cout); cout << endl;
	cout << "mq  1:\t";  mq1.list.display(cout);
	cout << endl;
	mq1.out();
	cout << "mq  1:\t";  mq1.list.display(cout);
	cout << endl << endl;





	return 0;
}
