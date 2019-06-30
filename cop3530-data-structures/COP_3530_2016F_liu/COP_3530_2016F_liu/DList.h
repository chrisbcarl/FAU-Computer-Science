#pragma once

#ifdef _MSC_VER
#define INLINE __forceinline /* use __forceinline (VC++ specific) */
#else
#define INLINE inline        /* use standard inline */
#endif

#include "std_libraries.h"

class DNode
{
public:
	int data;
	DNode* next;
	DNode* prev;
public:
	DNode();
	DNode(int data);
	~DNode();

	void print(std::ostream& out) const;
	void swap(DNode* rhs);
};




inline DNode::DNode()
{
	data = 0;
	next = 0;
	prev = 0;
}

inline DNode::DNode(int data)
{
	this->data = data;							//(*this).data = data;

	next = 0;
	prev = 0;
}

inline DNode::~DNode()
{
	delete this;
}

inline void DNode::print(std::ostream& out) const
{
	out << data;
}

inline void DNode::swap(DNode* rhs)
{
	if (this != rhs)
	{
		int c = this->data;
		this->data = rhs->data;
		rhs->data = c;
	}
}


class DLinkedList
{
public:
	int size;
	DNode* first;
	DNode* last;
    
public:
    
	DLinkedList();									//constructor
	DLinkedList(const DLinkedList& list);			//copy constructor
	~DLinkedList();									//deep destructor;

	int getSize() const;
	bool isEmpty() const;

	void push_back	(DNode* a);
	void push_front	(DNode* a);
    
	void insert		(DNode* a, int n);				// insert the item a after the n-th element
	void insertList	(DLinkedList& list, int n);	// insert the whole list a after the n-th element
	void swap		(DNode* a, DNode* b);			//swap two items pointed by p and q, you can assume that p and q are something in the list
	void print	(std::ostream& out) const;
	
	DNode* pop_front();
	DNode* pop_back();
	DNode* getfront() const;
	DNode* getback() const;

	// here you can assume user will always input a dataid pointer start that points to an item in the list
	DNode* extractMin	(DNode* start);				// return the pointer of the min element after "start"
	DNode* extractMax	(DNode* start);				// return the pointer of the max element after "start"

};


inline DLinkedList::DLinkedList()
{
	size = 0;
	first = 0;
	last = 0;
}

inline DLinkedList::DLinkedList(const DLinkedList& list)
{
	if (list.getSize() > 0)
	{
		DNode* p = list.first;
		first = new DNode(p->data);
		last = first;
		p = p->next;

		while (p->next != 0)
		{
			this->push_back(new DNode(p->data));
			p = p->next;
		}
		p = new DNode(p->data);
		this->push_back(p);
		last = p;
	}

}

inline DLinkedList::~DLinkedList()
{

}



inline int DLinkedList::getSize() const
{
	return size;
}

inline bool DLinkedList::isEmpty() const
{
	return (size == 0);
}

inline void DLinkedList::push_back(DNode* a)
{
	if (size == 0)
	{
		first = a;
		last = a;
		size++;
	}
	else
	{
		last->next = a;
		a->prev = last;
		last = a;
		size++;
	}
}

inline void DLinkedList::push_front(DNode* a)
{
	if (size == 0)
	{
		first = a;
		last = a;
		size++;
	}
	else
	{
        a->next = first;
        last->prev = a;
		first = a;
		size++;
	}
}

inline void DLinkedList::insert(DNode* a, int n)
{
	if ( getSize() == 0 )
	{
		push_back(a);
	}
	else if (n > getSize() - 1)
	{
		push_back(a);
	}
	else 
	{
		int counter = 0;
		DNode* p = first;
		counter++;

		while (counter < n)
		{
			p = p->next;
			counter++;
		}
		
		a->next = p->next;
		a->prev = p;

		p->next->prev = a;
		p->next = a;

		size++;
	}
}

inline void DLinkedList::insertList(DLinkedList& rhs, int n)
{
	DLinkedList list = rhs;
	if (getSize() == 0)
	{
		first = list.first;
		last = list.last;
	}
	else if ( getSize() - 1 > n )
	{
		int counter = 0;
		DNode* p = first;
		counter++;

		while (counter < n)
		{
			p = p->next;
			counter++;
		}
		
		list.first->prev = p;
		list.last->next = p->next;

		p->next->prev = list.last;
		p->next = list.first;
	}
	else
	{
		last->next = list.first;
		list.first->prev = last;
		last = list.last;
	}
	size += list.size;
}

inline void DLinkedList::swap(DNode* a, DNode* b)
{
	if (a != b)
	{
		/*
		swap(a,b)
		c = a;
		a = b;
		b = c;
		*/

		int c = a->data;
		a->data = b->data;
		b->data = c;
	}
}

inline void DLinkedList::print(std::ostream& out) const
{
	if (size == 0)
	{
		out << "EMPTY LIST" << std::endl;
	}
	else
	{
		DNode* p = first;
		while (p->next != 0)
		{
			out << "[" << p->data << "]->";
			p = p->next;
		}
		out << "[" << p->data << "]" << std::endl;
	}

}

inline DNode* DLinkedList::pop_front()
{
	if (size == 0)
	{
		return 0;
	}
	else
	{
		DNode* p = first;
		first->prev = 0;
		first = first->next;
		size--;
		return p;
	}
}

inline DNode* DLinkedList::pop_back()
{
	if (size == 0)
	{
		return 0;
	}
	else
	{
		DNode* p = last;
		last->next = 0;
		last = last->prev;
		size--;
		return p;
	}
}

inline DNode* DLinkedList::getfront() const
{
	if (size == 0)
	{
		return 0;
	}
	else
	{
		DNode* p = first;
		return p;
	}
}

inline DNode* DLinkedList::getback() const
{
	if (size == 0)
	{
		return 0;
	}
	else
	{
		DNode* p = last;
		return p;
	}
}

inline DNode* DLinkedList::extractMin(DNode* start)
{
	DNode* p = start;
	DNode* min = p;
	while (p->next != 0)
	{
		if (p->data < min->data) min = p;
		p = p->next;
	}
	return min;
}

inline DNode* DLinkedList::extractMax(DNode* start)
{
	DNode* p = start;
	DNode* max = p;
	while (p->next != 0)
	{
		if (p->data > max->data) max = p;
		p = p->next;
	}
	return max;
}


class MyStack
{
private:
	DLinkedList list;
	
public:
	MyStack();
    MyStack(const DLinkedList& list);
	int getSize();
	void push(DNode* a);
	DNode* top();
	void pop();
    void print(std::ostream& out) const;

};


inline MyStack::MyStack()
{
    list = DLinkedList();
}

inline MyStack::MyStack(const DLinkedList& list)
{
    this->list = list;
}

inline int MyStack::getSize()
{
    return list.getSize();
}

inline void MyStack::push(DNode* a)
{
    if ( list.getSize() == 0 )
    {
        list.push_front(a);
    }
    else
    {
        list.push_front(a);
    }
}

inline DNode* MyStack::top()
{
    return list.first;
}

inline void MyStack::pop()
{
    list.first = list.first->next;
    list.first->next->prev = list.first;
    list.size--;
}

inline void MyStack::print(std::ostream& out) const
{
    list.print(out);
}



class MyQueue
{
private:
	DLinkedList list;

public:
	MyQueue();
    MyQueue(const DLinkedList& list);
	int getSize();
	void push(DNode* a);
	DNode* top();
	void pop();
    void print(std::ostream& out) const;
};

inline MyQueue::MyQueue()
{
    list = DLinkedList();
}

inline MyQueue::MyQueue(const DLinkedList& list)
{
    this->list = list;
}

inline int MyQueue::getSize()
{
    return list.getSize();
}

inline void MyQueue::push(DNode* a)
{

    DNode* temp = list.first;
    while(temp != 0)
    {
        temp = temp->next;
    }
    
    a->prev = temp;
    a->next = 0;
    
    temp->next = a;
    list.last = a;
    
    /*
     if ( list.getSize() == 0 )
     {
     list.push_back(a);
     }
     else
     {
     list.push_back(a);
     }
     */
}

inline DNode* MyQueue::top()
{
    return list.first;
}

inline void MyQueue::pop()
{
    list.first = list.first->next;
    list.first->next->prev = list.first;
    list.size--;
}

inline void MyQueue::print(std::ostream& out) const
{
    list.print(out);
}

//NOT POSSIBLE because:
/*
If you stored a DNode object inside itself, what would sizeof(DNode) be? 
It would be sizeof(int) + sizeof(DNode), which would be equal to sizeof(int) + (sizeof(int) + sizeof(DNode)), 
	which would be equal to sizeof(int) + (sizeof(int) + (sizeof(int) + sizeof(DNode))), etc. to infinity.

An object like that can't exist. It's impossible.

std::ostream& operator<<(std::ostream& out, const DNode& node)
{
	node.print(out);
	return out;
}
*/

std::ostream& operator<<(std::ostream& out, const DNode& node)
{
	node.print(out);
	return out;
}

std::ostream& operator<<(std::ostream& out, DNode* node)
{
	node->print(out);
	return out;
}

std::ostream& operator<<(std::ostream& out, const DLinkedList& list)
{
	list.print(out);
	return out;
}

std::ostream& operator<<(std::ostream& out, const MyStack& ms)
{
    ms.print(out);
    return out;
}

std::ostream& operator<<(std::ostream& out, const MyQueue& mq)
{
    mq.print(out);
    return out;
}


void dListTest()
{
    DLinkedList dll;			//NOTE THAT THIS IS AN OBJECT
    DNode* a = new DNode(-1);	//NOTE THAT THESE ARE POINTERS
    DNode* b = new DNode(-2);
    DNode* c = new DNode(6);
    DNode* d = new DNode(5);
    
    std::cout << "a == " << a << std::endl;
    std::cout << "b == " << b << std::endl;
    std::cout << "c == " << c << std::endl;
    std::cout << "d == " << d << std::endl;
    std::cout << std::endl;
    
    //a->swap(b);
    (*c).swap(d);
    
    //std::cout << "a == " << a << std::endl;
    //std::cout << "b == " << b << std::endl;
    //std::cout << "c == " << c << std::endl;
    //std::cout << "d == " << d << std::endl;
    //std::cout << std::endl;
    
    dll.push_back(a);
    dll.push_back(b);
    
    for (int i = 0; i < 5; i++)
    {
        dll.push_back(new DNode(i));
    }
    
    dll.push_back(c);
    dll.push_back(d);
    
    std::cout << dll << std::endl;
    std::cout << std::endl;
    
    dll.swap(a, b);
    std::cout << dll << std::endl;
    std::cout << std::endl;
    
    std::cout << dll.pop_front()->data << std::endl;
    std::cout << dll << std::endl;
    std::cout << std::endl;
    
    DLinkedList dll2 = dll;			//NOTE THAT THIS IS AN OBJECT
    std::cout << dll2 << std::endl;
    std::cout << std::endl;
    
    dll.swap(b, c);					//should only affect dll, not dll2
    std::cout << dll << std::endl;
    std::cout << dll2 << std::endl;
    std::cout << std::endl;
    
    dll2.insert(new DNode(-6), 2);
    std::cout << dll2 << std::endl;
    std::cout << std::endl;
    
    dll2.insert(new DNode(-6), 8);
    std::cout << dll2 << std::endl;
    std::cout << std::endl;
    
    dll2.insertList(dll, 9);
    std::cout << dll << std::endl;
    std::cout << dll2 << std::endl;
    std::cout << std::endl;
    
    dll2.insertList(dll, 9);
    std::cout << dll << std::endl;
    std::cout << dll2 << std::endl;
    std::cout << std::endl;
    
    std::cout << dll.extractMax(dll.first) << std::endl;
    std::cout << dll.extractMin(dll.first) << std::endl;
    std::cout << std::endl;
    
    std::cout << dll2.extractMax(dll2.first) << std::endl;
    std::cout << dll2.extractMin(dll2.first) << std::endl;
    std::cout << std::endl;
    
    MyStack ms = MyStack(dll);
    std::cout << ms << std::endl;
    std::cout << std::endl;
    
    std::cout << "ms getSize(); " << ms.getSize() << std::endl;
    std::cout << std::endl;
    
    //
    ms.push(new DNode(6));
    std::cout << ms << std::endl;
    std::cout << std::endl;
    
    std::cout << "ms DNode* top();  " << ms.top() << std::endl;
    std::cout << ms << std::endl;
    std::cout << std::endl;
    
    ms.pop();
    std::cout << ms << std::endl;
    std::cout << std::endl;
    
    MyQueue mq = MyQueue(dll);
    std::cout << mq << std::endl;
    std::cout << std::endl;
    
    std::cout << "mq getSize(); " << mq.getSize() << std::endl;
    std::cout << std::endl;
    
    //
    mq.push(new DNode(-6));
    std::cout << mq << std::endl;
    std::cout << std::endl;
    
    std::cout << "mq DNode* top();  " << mq.top() << std::endl;
    std::cout << mq << std::endl;
    std::cout << std::endl;
    
    mq.pop();
    std::cout << mq << std::endl;
    std::cout << std::endl;
    
}
