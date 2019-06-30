/*
CHRISTOPHER CARL
Z23146703
ccarl2@fau.edu

2016F_COP3530 - Liu, Data Structures and Algorithms

"Midterm Review"

start:	16.10.28, 00:23
end:	16.10.28, 04:24
tot:			, 04:01
*/
#pragma once

#include "std_libraries.h"

void swap_liu(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void extract(int arr[], const int& size)
{
	int min = arr[0];
	int max = arr[0];
	int total = 0; int avg = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
		total += arr[i];
	}
	avg = total / size;

	cout << "min == " << min << endl;
	cout << "max == " << max << endl;
	cout << "avg == " << avg << endl;
}

void reverse(int original[], int reversed[], const int& size)
{
	for (int i = 0; i < size; i++)
	{
		reversed[i] = original[size - 1 - i];
	}
}


class Node
{
private:
	int val;
	Node* next;
	Node* prev;
public:
	Node()
	{
		val = 0;
		next = 0;
		prev = 0;
	}
	Node(const int& a)
	{
		val = a;
		next = 0;
		prev = 0;
	}

	friend class SingleLinkedList;
	friend class DoubleLinkedList;
};

class SingleLinkedList
{
private:
	int size;
	Node* head;
public:
	SingleLinkedList()
	{
		size = 0;
		head = 0;
	}
	SingleLinkedList(Node* a)
	{
		size = 1;
		head = a;
	}
	SingleLinkedList(const SingleLinkedList& rhs)
	{
		size = 0;
		head = 0;
		Node* p = rhs.head;
		while (p->next != 0)
		{
			this->push_back(p);
			p = p->next;
			size++;
		}
	}
	void traverse()
	{
		if (size == 0)
		{
			cout << "EMPTY LIST";
		}
		else
		{
			Node* p = head;
			while (p->next != 0)
			{
				cout << "[ " << p->val << " ] -> ";
				p = p->next;
			}
			cout << "[ " << p->val << " ]";
		}
	}

	int search(const int& v)
	{
		if (size == 0)
		{
			return -1;
		}
		else
		{
			Node* p = head;
			int i = 1;
			while (p->next != 0)
			{
				if (p->val == v) return i;
				p = p->next;
				i++;
			}
			if (p->val == v) return i;
			return -1;
		}
	}

	void delete_at_index(const int& n)
	{
		if (size == 0)
		{
			return;
		}
		else if (size < n)
		{
			pop_back();
		}
		else
		{
			Node* p = head;
			int i = 1;
			while (i < n-1)
			{
				p = p->next;
				i++;
			}
			p->next = p->next->next;
			size++;
		}
	}

	void insert_before_value(const int& v, Node* a)
	{
		if (size == 0)
		{
			head = a;
			size++;
		}
		else if (size == 1)
		{
			if (a->val < v)
			{
				push_front(a);
			}
			else
			{
				push_back(a);
			}
		}
		else
		{
			Node* p = head;
			Node* q = head->next;
			while ( (q->next != 0) && (q->val < v) )
			{
				p = p->next;
				q = q->next;
			}
			a->next = p->next;
			p->next = a;
			size++;
		}
	}

	void insert_at_index(const int& n, Node* a)
	{
		if (size == 0)
		{
			head = a;
			size++;
		}
		else if (size < n)
		{
			Node* p = head;
			while (p->next != 0)
			{
				p = p->next;
			}
			p->next = a;
			size++;
		}
		else
		{
			Node* p = head;
			int i = 1;
			while (i < n-1)
			{
				p = p->next;
				i++;
			}
			a->next = p->next;
			p->next = a;
			size++;
		}
	}

	//~!!!!!!!!!!!!!!SOMETHING IS WRONG BUT THIS IS THE ONLY PROBLEM!!!!!!!!!!!~
	void insert_list(const int& n, const SingleLinkedList& rhs)
	{
		if (size == 0)
		{
			Node* p = rhs.head;
			while (p->next != 0)
			{
				push_back(p);
				p = p->next;
			}
			size += rhs.size;
		}
		else if (size < n)
		{
			Node* p = head;
			while (p->next != 0)
			{
				p = p->next;
			}
			p->next = rhs.head;
			size += rhs.size;
		}
		else
		{
			//find new tail
			//find temp head
			Node* p = head;
			Node* q = head->next;
			int i = 1;
			while (i < n-1)
			{
				p = p->next;
				q = q->next;
				i++;
			}

			//find rhs tail
			Node* r = rhs.head;
			while (r->next != 0)
			{
				r = r->next;
			}

			r->next = q;
			p->next = rhs.head;
			size += rhs.size;
		}
	}


	void print_n_from_front(int n)
	{
		Node* t1 = head;
		int i = 1;
		while (i < n)
		{
			if (t1->next == 0)
			{
				cout << "can't be done";
			}
			else
			{
				t1 = t1->next;
				i++;
			}
		}
		cout << " [ " << t1->val << " ]";
	}

	void print_n_from_last(int n)
	{
		Node* t2 = head;
		int i = 1;
		while (i < n)
		{
			if (t2->next == 0)
			{
				cout << "can't be done";
			}
			else
			{
				t2 = t2->next;
				i++;
			}
		}

		Node* t1 = head;
		while (t2->next != 0)
		{
			t2 = t2->next;
			t1 = t1->next;
		}

		cout << " [ " << t1->val << " ]";

	}

	void print_third_from_front()
	{
		Node* p = head;
		cout << "[ " << p->next->next->val << " ]";
	}

	void print_third_from_last()
	{
		Node* p = head;
		while (p->next->next->next != 0)
		{
			p = p->next;
		}
		cout << "[ " << p->val << " ]";
	}

	void push_front(Node* a)
	{
		if (size == 0)
		{
			head = a;
			size++;
		}
		else
		{
			a->next = head;
			head = a;
			size++;
		}
	}

	void push_back(Node* a)
	{
		if (size == 0)
		{
			head = a;
			size++;
		}
		else
		{
			Node* p = head;
			while (p->next != 0)
			{
				p = p->next;
			}
			p->next = a;
			size++;
		}
	}

	void pop_front()
	{
		if (size == 0)
		{
			return;
		}
		else
		{
			head = head->next;
			size--;
		}
	}

	void pop_back()
	{
		if (size == 0)
		{
			return;
		}
		else if (size == 1)
		{
			size = 0;
			head = 0;
		}
		else
		{
			Node* p = head;
			Node* q = head->next;
			while (q->next != 0)
			{
				p = p->next;
				q = q->next;
			}
			p->next = 0;
			size--;
		}
	}

	void swap_node(Node* b)
	{
		Node* a = head;
		int c = a->val;
		a->val = b->val;
		b->val = c;
	}

};

class MyStack
{
private:
	SingleLinkedList list;
public:
	MyStack()
	{
		list = SingleLinkedList();
	}

	MyStack(const SingleLinkedList& rhs)
	{
		list = rhs;
	}
	void push(Node* a)
	{
		list.push_front(a);
	}
	void pop()
	{
		list.pop_front();
	}
	void traverse()
	{
		list.traverse();
	}
};

class MyQueue
{
private:
	SingleLinkedList list;
public:
	MyQueue()
	{
		list = SingleLinkedList();
	}
	MyQueue(const SingleLinkedList& rhs)
	{
		list = rhs;
	}
	void push(Node* a)
	{
		list.push_back(a);
	}
	void pop()
	{
		list.pop_front();
	}
	void traverse()
	{
		list.traverse();
	}
};



int midterm_review()
{
	//SingleLinkedList()
	SingleLinkedList sll;
	SingleLinkedList sll_2;
	SingleLinkedList sll_3;
	
	//void push_back(Node* a)
	for (int i = 0; i < 3; i++) {
		sll.push_back(new Node(i));
	}

	//void push_front(Node* a)
	for (int i = 0; i < 3; i++) {
		sll_2.push_front(new Node(-i));
	}

	//SingleLinkedList(const SingleLinkedList& rhs)
	sll_3 = sll;

	//void traverse()
	std::cout << "sll   == "; 	sll.traverse();			std::cout << std::endl;
	std::cout << "sll_2 == "; 	sll_2.traverse();		std::cout << std::endl;
	std::cout << "sll_3 == "; 	sll_3.traverse();		std::cout << std::endl;
	std::cout << std::endl;

	//pop front
	sll.pop_front();
	sll_2.pop_front();


	//pop back
	sll.pop_back();
	sll_2.pop_back();


	//push front
	sll.push_front(new Node(0));
	sll_2.push_front(new Node(-9));


	//push back
	sll.push_back(new Node(9));
	sll_2.push_back(new Node(0));
	
	//int search(const int& v)
	std::cout << "0 exists in sll @ " << sll.search(0) << std::endl;
	std::cout << "0 exists in sll_2 @ " << sll_2.search(0) << std::endl;
	std::cout << std::endl;

	//void insert_before_value(const int& v, Node* a)
	sll.insert_before_value(3, new Node(-99));
	sll_2.insert_before_value(-3, new Node(99));

	//void insert_at_index(const int& n, Node* a)
	sll.insert_at_index(3, new Node(-101));
	sll_2.insert_at_index(3, new Node(101));

	//void delete_at_index(const int& n)
	sll.delete_at_index(3);
	sll_2.delete_at_index(3);

	//~!!!!!!!!!!!!!!SOMETHING IS WRONG BUT THIS IS THE ONLY PROBLEM!!!!!!!!!!!~
	//void insert_list(const int& n, const SingleLinkedList& rhs)
	//sll_3.insert_list(3, sll);


	//prints from endpoints
	std::cout << "print 2 from last == ";	sll.print_n_from_last(2);	std::cout << std::endl << std::endl;
	std::cout << "print 3 from last == ";	sll.print_third_from_last();	std::cout << std::endl << std::endl;
	std::cout << "print 2 from front == ";	sll.print_n_from_front(2);	std::cout << std::endl << std::endl;
	std::cout << "print 3 from front == ";	sll.print_third_from_front();	std::cout << std::endl << std::endl;


	//MyQueue(const SingleLinkedList& rhs)
	MyStack ms = MyStack(sll);
	MyQueue mq = MyQueue(sll_2);


	//void push(Node* a)
	for (int i = 0; i < 3; i++)
	{
		ms.push(new Node(i));
		mq.push(new Node(-i));
	}

	std::cout << "ms == "; 	ms.traverse();		std::cout << std::endl;
	std::cout << "mq == "; 	mq.traverse();		std::cout << std::endl;
	std::cout << std::endl;

	//void pop()
	for (int i = 0; i < 2; i++)
	{
		ms.pop();
		mq.pop();
	}

	std::cout << "ms == "; 	ms.traverse();		std::cout << std::endl;
	std::cout << "mq == "; 	mq.traverse();		std::cout << std::endl;
	std::cout << std::endl;

	return 0;

}