/*
Kevin Seepaul
Dr. Feng-Hao Liu
hw5.cpp
*/
#pragma once

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//converts integers to arrays with the most significant bit in the 0th slot.
static int* int2base2(const int& n, int& power)
{
    power = 0;
    int* temp = 0;
    if (n == 0)
    {
        power++;
        temp = new int[power];
        temp[power] = 0;
    }
    else
    {
        //this section gets the size of the binary array
        int x = n;
        while (x / 2 != 0)
        {
            power++;
            x = x / 2;
        }
        power++;
        temp = new int[power];
        
        //this section fills the binary arry
        x = n;
        int i = 0;
        while (i < power)
        {
            temp[i] = x % 2;    //stored msb to lsb
            x = x / 2;
            i++;
        }
    }
    return temp;
}

//prints arrays given the size
static void print_array(int* p, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node* parent;

	Node()
	{
		data = 0;
		left = 0;
		right = 0;
		parent = 0;
	}
	Node(int v)
	{
		data = v;
		left = 0;
		right = 0;
		parent = 0;
	}
	~Node()
	{
		//if there's a left child remove the link to this, left child's parent
		if (left != 0)
		{
			left->parent = 0;
		}
		else
		{
			delete left;
		}
		
		//if there's a right child remove the link to this, left child's parent
		if (right != 0)
		{
			right->parent = 0;
		}
		else
		{
			delete right;
		}

		//if this is a child, figure out if it was a left or right, then sever that.
		if (parent != 0)
		{
			if (parent->left == this)	parent->left = 0;
			if (parent->right == this)	parent->right = 0;
		}
		else
		{
			delete parent;
		}
	}
};

class minHeap
{
public:
	int size;
	Node* root;

	minHeap();									//default
	minHeap(Node* root);						//explicit value Node pointer
	minHeap(const minHeap& rhs);				//copy constructor
	minHeap(int *data, int size);               //from minHeap array constructor
	~minHeap();									//destructor

	void add2left(Node* newnode, Node* pos);
	void add2right(Node* newnode, Node* pos);
	void add2left(Node* newnode, int pos);
	void add2right(Node* newnode, int pos);
	void add2left(minHeap& newsubtree, int pos);
	void add2right(minHeap& newsubtree, int pos);

	Node* convertPosition(int pos);
	void removeLeaf(int pos);
	void removeLeaf(Node*& pos);
	void swapNodes(Node* lhs, Node* rhs);
	
	int computeSize();
	int* toArray();
	Node* fromArray(int* data, int size, int pos);
	void heapify(int* data, int size);	// p is an array of size n, representing a (full) binray tree of size n. You should not modify the array p
	void copyTree(Node*& lhs, const Node* rhs);

	void in(Node* newnode);			// you should new a new node and then add into the heap
	void removemin();
	Node* getmin();

	void bubble_up(Node* pos);
	void bubble_down(Node* pos);

	void print(ostream& out);
	void print_pre_order();
	void print_in_order();
	void print_post_order();

	friend bool isValidMinHeap(int* data, int size);
	friend int* heapSort(int* data, int size);
};

minHeap::minHeap() 
{
	size = 0;
	root = 0;
}

minHeap::minHeap(Node* newnode)
{ 
	size = 1;
	root = newnode;
	computeSize();

	Node* m = 0;
	for (int i = 0; i < this->size; i++)
	{
		m = convertPosition(this->size - i);
		bubble_down(m);
	}
}

minHeap::minHeap(const minHeap& rhs) 
{
	if (rhs.root == 0)
    {
        root = 0;
    }
	else
    {
        //this helper function is required to do the recursion
        copyTree(root, rhs.root);
    }

	computeSize();
}

minHeap::minHeap(int *data, int size) 
{
	if (size != 0)
	{
        heapify(data, size);
	}
}

minHeap::~minHeap() 
{ 
}

//adds a new node as a left child at an existing node's position
void minHeap::add2left(Node* newnode, Node* pos) 
{ 
	if (newnode != 0)
	{
		if (pos->left == 0)
		{
			pos->left = newnode;
			newnode->parent = pos;
			size++;
			bubble_up(pos);
		}
		else
		{
			cout << "left is already occupied" << endl;
		}
	}
	else
	{
		cout << "newnode is empty" << endl;
	}
}

//adds a new node as a right child at an existing node's position
void minHeap::add2right(Node* newnode, Node* pos) 
{
	if (newnode != 0)
	{
		if (pos->right == 0)
		{
			pos->right = newnode;
			newnode->parent = pos;
			size++;
			bubble_up(pos);
		}
		else
		{
			cout << "right is already occupied" << endl;
		}
	}
	else
	{
		cout << "newnode is empty" << endl;
	}
}

//adds a new node as a left child at an existing node's position
void minHeap::add2left(Node* newnode, int pos) 
{
	if (newnode != 0)
	{
		Node* m = convertPosition(pos);
		if (m->left == 0)
		{
			m->left = newnode;
			newnode->parent = m;
			size++;
			bubble_up(newnode);			/////
		}
		else
		{
			cout << "right is already occupied" << endl;
		}
	}
	else
	{
		cout << "newnode is empty" << endl;
	}
}

//adds a new node as a right child at an existing node's position
void minHeap::add2right(Node* newnode, int pos) 
{
	if (newnode != 0)
	{
		Node* m = convertPosition(pos);
		if (m->right == 0)
		{
			m->right = newnode;
			newnode->parent = m;
			size++;
			bubble_up(newnode);			//asdfasdfasdf
		}
		else
		{
			cout << "right is already occupied" << endl;
		}
	}
	else
	{
		cout << "newnode is empty" << endl;
	}
}

//adds the root of a new tree as a left child at an existing node's position
void minHeap::add2left(minHeap& newsubtree, int pos)
{
	add2left(newsubtree.root, pos);
	Node* m = 0;
	for (int i = 0; i < this->size; i++)
	{
		m = convertPosition(this->size - i);
		bubble_down(m);
	}
}

//adds the root of a new tree as a right child at an existing node's position
void minHeap::add2right(minHeap& newsubtree, int pos)
{
	add2right(newsubtree.root, pos);
	Node* m = 0;
	for (int i = 0; i < this->size; i++)
	{
		m = convertPosition(this->size - i);
		bubble_down(m);
	}
}

//converts a position on a binary tree into a Node*
//1 is considered to be the root, while the binary tree's size is
//considered to be the last node of an ideal tree.
Node* minHeap::minHeap::convertPosition(int pos)
{
	Node* m = root;
    int power = 0;
    
    //gets binary representation
    int* temp = int2base2(pos, power);
    int* binary = new int[power];       //stored msb to lsb, lsb will always be 1 on the right hand side.
    binary = temp;
    
    //uses binary representation to decide to go left or right
    int i = 1;
    while (i < power)
	{
		if (binary[power - 1 - i] == 0)			m = m->left;
		else if (binary[power - 1 - i] == 1)	m = m->right;
        i++;
	}
	return m;
}

//remove a node from a specific position
void minHeap::removeLeaf(int pos)
{
	if(pos <= size)
    {
        Node* m = convertPosition(pos);
		removeLeaf(m);
        delete m;
    }
}

//remove a node from a specific position
void minHeap::removeLeaf(Node*& pos)
{
	if ((pos->left == 0) && (pos->right == 0))
	{
		size--;
		Node* m = pos->parent;
		if (m->left == pos)
			m->left = 0;
		if (m->right == pos)
			m->right = 0;
		delete pos;
	}
	else cout << "cannot delete, it is not a leaf." << endl;
}

//swap two nodes' values
void minHeap::swapNodes(Node* lhs, Node* rhs)
{
	int mhs = rhs->data;
	rhs->data = lhs->data;
	lhs->data = mhs;
}

//compute the size of the tree by tallying up each subtree's size.
int minHeap::computeSize()
{
	Node* m = root;
	int nodes = 0;

	//base case
	if (root == 0)
		return nodes;
	//case 1
	else
	{
		//recurse left
		minHeap left = minHeap(m->left);
		nodes += left.computeSize();

		//recurse right
		minHeap right = minHeap(m->right);
		nodes += right.computeSize();

		//print root
		nodes += 1;
	}
	size = nodes;
	return nodes;
}

//transform a binary tree or minheap to an integer array
int* minHeap::toArray()
{
	int* temp = 0;
	Node* m = 0;

	if (size < 1)
		return temp;
	else
	{
		temp = new int[size];
		temp[0] = -1;
		for (int i = 1; i < size + 1; i++)
		{
			m = convertPosition(i);
			temp[i] = m->data;
		}
		return temp;
	}
}

//transform an integer array to a binary tree or minheap
Node* minHeap::fromArray(int* data, int size, int pos)
{
	Node* m = 0;

	if (pos > size - 1)
		return m;
	else
	{
		m = new Node(data[pos]);
		m->left = fromArray(data, size, pos * 2);
		if (m->left != 0)
			m->left->parent = m;
		m->right = fromArray(data, size, pos * 2 + 1);
		if (m->right != 0)
			m->right->parent = m;
		return m;
	}
}

//arrange the data in a binary tree or minHeap to conform
//to a true min heap, where each nodes' children are
//greater than itself.
void minHeap::heapify(int* data, int size)
{
    this->size = size - 1;
	int* temp = new int[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}
	root = fromArray(temp, size, 1);

	Node* b = new Node();
	for (int i = 0; i < size; i++)
	{
		b = convertPosition(this->size - i);
		bubble_down(b);
	}
}

//helper function to recurse during the copy constructor
void minHeap::copyTree(Node*& lhs, const Node* rhs)
{
	if (rhs == 0)
	{
		lhs = 0;
	}
	else
	{
		lhs = new Node(rhs->data);
		size++;

		copyTree(lhs->left, rhs->left);
		copyTree(lhs->right, rhs->right);
	}
}

//inserts a node at the earliest available space.
void minHeap::in(Node* newnode)
{
	size++;
	Node* b = convertPosition(size);
	if (b == 0)
	{
		b = convertPosition(size/2);
	}
	if ((b->left == 0) && (b->right == 0))
	{
		b->left = newnode;
		newnode->parent = b;
	}
	else if ((b->left != 0) && (b->right == 0))
	{
		b->right = newnode;
		newnode->parent = b;
	}
	else if ((b->left != 0) && (b->right != 0))
	{
		b->left = newnode;
		newnode->parent = b;
	}

	bubble_up(newnode);
}

//pops the root node, replaces it with the last node
//then bubbles that node down to preserve the heap
void minHeap::removemin()
{
	Node* b = convertPosition(size);
	swapNodes(root, b);
	delete b;
	if (b == root) root = 0;
	size--;
	bubble_down(root);
}

//gets the value of the root node
Node* minHeap::minHeap::getmin()
{
	return root;
}

//allows a node whose value is lower than its parent to
//ascend into parenthood
void minHeap::bubble_up(Node* pos)
{
	Node* parent = pos->parent;
	if (parent == 0)
	{
		return;
	}
	else
	{
		if (pos->data < parent->data)
		{
			swapNodes(parent, pos);
			bubble_up(parent);
		}
	}
}

//allows a node whose value is greater than its children to
//descend into childhood
void minHeap::bubble_down(Node* pos)
{
	if (pos != 0)
	{
		Node* left_child = pos->left;
		Node* right_child = pos->right;
		if ((pos->left == 0) && (pos->right == 0))
		{
			return;
		}
		else
		{
			if ((pos->left != 0) && (pos->right != 0))
			{
				if ((pos->data > left_child->data) || (pos->data > right_child->data))
				{
					if (left_child->data <= right_child->data)
					{
						if (pos->data > left_child->data)
						{
							swapNodes(pos, left_child);
							bubble_down(left_child);
						}
					}
					else if (right_child->data < left_child->data)
					{
						if (pos->data > right_child->data)
						{
							swapNodes(pos, right_child);
							bubble_down(right_child);
						}
					}
				}
			}
			else if ((pos->left != 0) && (pos->left != 0))
			{
				if ((pos->data > left_child->data))
				{
					swapNodes(pos, left_child);
					bubble_down(left_child);
				}
			}
			else
			{
				return;
			}
		}
	}
}

//sort of helper to tidy up the code
void minHeap::print(ostream & out)
{
	out << "size == " << size << endl;
	out << "pre  = ";	print_pre_order();	cout << endl;
	out << "in   = ";	print_in_order();	cout << endl;
	out << "post = ";	print_post_order();	cout << endl;
	out << endl << endl;
}

//prints the values of the binary tree or minheap in pre order
void minHeap::print_pre_order()
{
	Node* m = root;
	if (root == 0)
		cout << "EMPTY";
	else
	{
		//print root
		cout << m->data << " ";

		//recurse left
		if (m->left != 0)
		{
			minHeap left = minHeap(m->left);
			left.print_pre_order();
		}

		//recurse right
		if (m->right != 0)
		{
			minHeap right = minHeap(m->right);
			right.print_pre_order();
		}
	}
}

//prints the values of the binary tree or minheap in order
void minHeap::print_in_order()
{
	Node* m = root;
	if (root == 0)
		cout << "EMPTY";
	else
	{
		//recurse left
		if (m->left != 0)
		{
			minHeap left = minHeap(m->left);
			left.print_pre_order();
		}

		//print root
		cout << m->data << " ";

		//recurse right
		if (m->right != 0)
		{
			minHeap right = minHeap(m->right);
			right.print_pre_order();
		}
	}
}

//prints the values of the binary tree or minheap in post order
void minHeap::print_post_order()
{
	Node* m = root;
	if (root == 0)
		cout << "EMPTY";
	else
	{
		//recurse left
		if (m->left != 0)
		{
			minHeap left = minHeap(m->left);
			left.print_pre_order();
		}

		//recurse right
		if (m->right != 0)
		{
			minHeap right = minHeap(m->right);
			right.print_pre_order();
		}
		
		//print root
		cout << m->data << " ";
	}
}

//validates if an array is binary tree or minheap material
bool isValidMinHeap(int* data, int size)
{
	if (data[0] > 0)
	{
		return false;
	}
	if (size % 2 != 0)
	{
		return false;
	}
	if (size == 2)
	{
		return true;
	}
	else
	{
		int i = size;
		while (i >= 2)
		{
			if ((i / 2) % 2 == 0)
			{
				i = i / 2;
			}
			else
			{
				break;
			}
		}
		if (i != 2)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

//heapsort takes an array, creates a heap out of it,
//then pops off every minimum value and adds it to an
//array.
int* heapSort(int* data, int size)
{
	//pop the getmin of min, and put it at the end. for each i
	minHeap mh = minHeap(data, size);
	int* heaped = new int[size];

    heaped[0] = -1;
	for (int i = 1; i < size; i++)
	{
		heaped[i] = mh.getmin()->data;
		mh.removemin();
	}
	return heaped;
}


void main()
{
	Node* a = new Node(8);                    //three test nodes
	Node* b = new Node(4);
	Node* c = new Node(2);
    minHeap mh0 = minHeap(a);                   //testing explicit node constructor
    mh0.add2left(b, 1);                         //testing add2left/right
	mh0.add2right(c, 1);
	cout << "mh0" << "\t"; mh0.print(cout);     //testing all print functions

	Node* e = new Node(8);
	Node* f = new Node(4);
	Node* g = new Node(2);
	minHeap mh1 = minHeap(g);
	mh1.add2left(f, g);
	mh1.add2right(e, g);
	cout << "mh1" << "\t"; mh1.print(cout);

	Node* i = new Node(1);
	Node* j = new Node(69);
	minHeap mh2 = minHeap(mh0);                 //testing copy constructor
	minHeap mh3 = minHeap(mh1);
	minHeap mh4 = minHeap(i);
	mh4.add2left(mh2, 1);                       //testing adding subtrees
	mh4.add2right(mh3, 1);
	cout << "mh4" << "\t"; mh4.print(cout);
	mh4.add2left(j, 4);
	cout << "mh4" << "\t"; mh4.print(cout);

	mh4.removeLeaf(7);                          //testing remove leaf based on number
	cout << "mh4" << "\t"; mh4.print(cout);
	mh4.removeLeaf(j);                          //testing remove leaf based on reference
	cout << "mh4" << "\t"; mh4.print(cout);

	int dataset1[8] = { -1, 8, 4, 3, 2, 6, 5, 7 };
    int dataset2[16] = { -1, 8, 4, 3, 2, 6, 5, 7, 2, 4, 8, 7, 3, 5, 6, 2};
    int dataset3[8] = { -1, 2, 4, 8, 7, 3, 5, 6 };

	minHeap mh5;
	mh5.heapify(dataset1, 8);                   //testing heapify
	cout << "mh5" << "\t"; mh5.print(cout);
	Node* k = new Node(1);
    mh5.in(k);                                  //testing in and the heap's self preservation
	cout << "mh5" << "\t"; mh5.print(cout);
    Node* l = new Node(9);
    mh5.in(l);
	cout << "mh5" << "\t"; mh5.print(cout);

	minHeap mh6;
	mh6.heapify(dataset2, 16);
	cout << "mh6" << "\t"; mh6.print(cout);
	Node* m = new Node(1);
    mh6.in(m);
    cout << "mh6" << "\t"; mh6.print(cout);
	Node* n = new Node(9);
    mh6.in(n);
	cout << "mh6" << "\t"; mh6.print(cout);

	int* dataset4 = heapSort(dataset3, 8);         //testing heapsort
	cout << "dataset4 = ";
	print_array(dataset4, 8);
	cout << endl << endl;
	
}
