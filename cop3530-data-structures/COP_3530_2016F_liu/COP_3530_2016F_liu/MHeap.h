//
//  MHeap.h
//  COP_3530_2016F_liu
//
//  Created by Christopher Carl on 11/22/16.
//  Copyright © 2016 Christopher Carl. All rights reserved.
//

/*
LOG:
16.11.25, 16:00 - start
16.11.25, 19:54 - stop

16.11.26, 14:04 - start
16.11.26, 14:56 - all code written, none tested
16.11.26, 21:42 - everything except heapify and heapsort tested
	has a new print function which is SUPER NICE
16.11.26, 21:59 - DONE
16.11.26, 22:37 - stop
*/
#pragma once

#include "std_libraries.h"

int* int_to_base2_mHeap(const int& n, int& power)
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
		int x = n;
		while (x / 2 != 0)
		{
			power++;
			x = x / 2;
		}
		power++;
		temp = new int[power];

		x = n;
		int i = power - 1;
		while (i > -1)
		{
			temp[i--] = x % 2;
			x = x / 2;
		}
	}
	return temp;
}

int* int_to_base10_mHeap(const int& n, int& power)
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
		int x = n;
		while (x / 10 != 0)
		{
			power++;
			x = x / 10;
		}
		power++;
		temp = new int[power];

		x = n;
		int i = 0;
		while (i < power)
		{
			temp[i] = x % 10;
			x = x / 10;
			i++;
		}
	}
	return temp;
}

/*
strategy: keep multiplying by power and adding, left to right
*/
int base2_to_int_mHeap(int*& a, int& power)
{
	int base10 = 0;
	for (int i = 0; i < power; i++)
	{
		base10 += (int)pow(a[i] * 2, i);
	}
	return base10;
}


stringstream* print_base_mHeap(int n[], const int& power)
{
	stringstream* out = new stringstream();

	for (int i = 0; i < power; i++)
	{
		*out << std::to_string(n[power - 1 - i]);
	}
	return out;
}

stringstream* base_to_stream_mHeap(int*& base, const int& power, const int& digits)
{
	stringstream* out = new stringstream();
	*out << " " << print_base_mHeap(base, power)->str();
	if (digits % 2 == 1)
		*out << " ";
	else
		*out << "  ";

	return out;
}

class BNode
{
	friend class minHeap;
private:
	int data;
	BNode* left;
	BNode* right;
	BNode* parent;
public:
	BNode();
	BNode(const int& data);
	BNode(BNode* rhs);
	BNode* operator=(const BNode* rhs);
	~BNode();

	//SETTERS
	void setData(const int& data);
	void addleft(BNode* left);
	void addright(BNode* right);
	void addparent(BNode* parent);
	void addleftright(BNode* left, BNode* right);
	void addall(BNode* left, BNode* right, BNode* parent);

	//GETTERS
	bool isLeaf();
	bool hasLeft();
	bool hasRight();
	bool isFull();
	int getData();
	BNode* getLeft();
	BNode* getRight();
	BNode* getParent();

	//UTILITIES
	//bool connected(BNode* lhs, BNode* rhs);
};

class minHeap
{
private:
	int size;
	BNode* root;
public:
	minHeap();									//default
	minHeap(const int& root);					//explicit value of root
	minHeap(BNode* root);						//explicit value BNode pointer
	minHeap(const int* data, const int& size);	//construct using array
	minHeap(minHeap& rhs);					//copy constructor
	minHeap& operator=(minHeap& rhs);			//= overload
	~minHeap();									//destructor

													//GETTERS
	int getSize();
	BNode* getRoot();

	//SETTERS
	void add2left(BNode* newnode, BNode* pos);
	void add2right(BNode* newnode, BNode* pos);
	void add2left(BNode* newnode, const int& pos);
	void add2right(BNode* newnode, const int& pos);
	void add2left(minHeap* newsubtree, const int& pos);
	void add2right(minHeap* newsubtree, const int& pos);
	void removeLeaf(const int& pos);
	void removeLeaf(BNode* pos);
	void swapNodes(BNode* lhs, BNode* rhs);

	//UTILITIES
	friend bool isValidminHeap(const int* data, const int size);
	int computeSize();

	void copyTree(BNode*& lhs, BNode*& rhs);
	BNode* copyTree(BNode*& root);
	//void fromArray(const int*, const int&, const int&);
	BNode* fromArray(const int* data, const int& size, const int& pos);
	int* toArray();

	int convertPosition(BNode* pos);
	BNode* convertPosition(const int& pos);
	BNode* firstEmptyPosition(const int& pos);
	BNode* traverse();
	int getValue(const int& pos);

	//STREAM FUNCTIONS
	stringstream* print();
	stringstream* print_pre_order();
	stringstream* print_in_order();
	stringstream* print_post_order();





	void push(BNode*& newnode);			// you should new a new node and then add into the heap
	void pop_front();
	void pop_back();
	void pop_pos(const int& pos);
	BNode* top();

	void bubble_up(BNode*& pos);
	void bubble_down(BNode*& pos);

	friend int* heapify(const int* data, const int& size);	// p is an array of size n, representing a (full) binray tree of size n. You should not modify the array p
	friend int* heapSort(const int* data, const int& size);
};


ostream& operator<<(ostream& out, minHeap& rhs)
{
	out << rhs.print()->str();
	return out;
}

ofstream& operator<<(ofstream& out, minHeap& rhs)
{
	out << rhs.print()->str();
	return out;
}

BNode::BNode()
{
	data = 0;
	left = 0;
	right = 0;
	parent = 0;
}

BNode::BNode(const int& d)
{
	data = d;
	left = 0;
	right = 0;
	parent = 0;
}

BNode::BNode(BNode* rhs)
{
	data = rhs->data;
	if (rhs->left != 0)		left = new BNode(rhs->left->data);
	else					left = 0;

	if (rhs->right != 0)	right = new BNode(rhs->right->data);
	else					right = 0;

	if (rhs->parent != 0)	parent = new BNode(rhs->parent->data);
	else					parent = 0;
}

BNode* BNode::operator=(const BNode* rhs)
{
	if (this == rhs)
		return this;

	data = rhs->data;
	if (rhs->left != 0)		left = new BNode(rhs->left->data);
	else					left = 0;

	if (rhs->right != 0)	right = new BNode(rhs->right->data);
	else					right = 0;

	if (rhs->parent != 0)	parent = new BNode(rhs->parent->data);
	else					parent = 0;

	return this;
}

BNode::~BNode()
{
	if (left != 0)
		left->parent = 0;
	else				
		delete left;
	if (right != 0)
		right->parent = 0;
	else				
		delete right;
	if (parent != 0)
	{
		if (parent->left == this)	parent->left = 0;
		if (parent->right == this)	parent->right = 0;
	}
	else				
		delete parent;
}

void BNode::setData(const int& d)
{
	data = d;
}

void BNode::addleft(BNode* l)
{
	if (left == 0)
	{
		left = l;
		l->parent = this;
	}
}

void BNode::addright(BNode* r)
{
	if (right == 0)
	{
		right = r;
		r->parent = this;
	}
}

void BNode::addparent(BNode* p)
{
	if (parent == 0)
	{
		parent = p;
	}
}

void BNode::addleftright(BNode* l, BNode* r)
{
	if (left == 0)
	{
		left = l;
		l->parent = this;
	}

	if (right == 0)
	{
		right = r;
		r->parent = this;
	}
}

void BNode::addall(BNode* l, BNode* r, BNode* p)
{
	if (left == 0)
	{
		left = l;
		l->parent = this;
	}

	if (right == 0)
	{
		right = r;
		r->parent = this;
	}

	if (parent == 0)
	{
		parent = p;
	}
}

bool BNode::isLeaf()
{
	return (left == 0) && (right == 0);
}

bool BNode::hasLeft()
{
	return (left != 0);
}

bool BNode::hasRight()
{
	return (right != 0);
}

bool BNode::isFull()
{
	return (left != 0) && (right != 0);
}

int BNode::getData()
{
	return data;
}

BNode* BNode::getLeft()
{
	return left;
}

BNode* BNode::getRight()
{
	return right;
}

BNode* BNode::getParent()
{
	return parent;
}




minHeap::minHeap()
{
	size = 0;
	root = 0;
}

minHeap::minHeap(const int& r)
{
	size = 1;
	root = new BNode(r);
	computeSize();
}

minHeap::minHeap(BNode* r)
{
	size = 1;
	root = r;
	computeSize();
}

minHeap::minHeap(const int* data, const int& size)
{
	/*
	first, check
	if fail, fail
	else not fail
	run makeminHeap(array, position 1, size, count)
	*/
	if ((size == 0) || (!isValidminHeap(data, size)))
	{
		cout << "CANNOT MAKE TREE FROM DATA." << endl;
	}
	else
	{
		this->size = size - 1;
		this->root = 0;
		this->root = fromArray(data, size, 1);
	}
}

minHeap::minHeap(minHeap& rhs)
{
	if (rhs.root == 0)
		root = 0;
	else
		copyTree(root, rhs.root);

	computeSize();
}

minHeap& minHeap::operator=(minHeap& rhs)
{
	if (this == &rhs)
		return *this;

	if (rhs.root == 0)
		root = 0;
	else
		copyTree(root, rhs.root);

	computeSize();
	return *this;
}

minHeap::~minHeap()
{
	//traverse in post order and delete that way.
}

int minHeap::getSize()
{
	return size;
}

BNode* minHeap::getRoot()
{
	return root;
}

void minHeap::add2left(BNode* newnode, BNode* pos)
{
	if (newnode != 0)
		if (pos->left == 0)
		{
			pos->left = newnode;
			newnode->parent = pos;
			size++;
		}
		else
			cout << "left is already occupied" << endl;
	else
		cout << "newnode is empty" << endl;
}

void minHeap::add2right(BNode* newnode, BNode* pos)
{
	if (newnode != 0)
		if (pos->right == 0)
		{
			pos->right = newnode;
			newnode->parent = pos;
			size++;
		}
		else
			cout << "right is already occupied" << endl;
	else
		cout << "newnode is empty" << endl;
}

void minHeap::add2left(BNode* newnode, const int& pos)
{
	BNode* b = convertPosition(pos);
	if (newnode != 0)
		if (b->left == 0)
		{
			b->left = newnode;
			newnode->parent = b;
			size++;
		}
		else
			cout << "right is already occupied" << endl;
	else
		cout << "newnode is empty" << endl;
}

void minHeap::add2right(BNode* newnode, const int& pos)
{
	BNode* b = convertPosition(pos);
	if (newnode != 0)
		if (b->right == 0)
		{
			b->right = newnode;
			newnode->parent = b;
			size++;
		}
		else
			cout << "right is already occupied" << endl;
	else
		cout << "newnode is empty" << endl;
}

void minHeap::add2left(minHeap* newsubtree, const int& pos)
{
	this->root->left = newsubtree->root;
	this->size += size;
}

void minHeap::add2right(minHeap* newsubtree, const int& pos)
{
	this->root->right = newsubtree->root;
	this->size += size;
}

void minHeap::removeLeaf(const int& pos)
{
	int n = pos;
	BNode* b = this->root;
	while (n / 2 != 0)
	{
		if (n % 2 == 0) b = b->left;
		if (n % 2 == 1) b = b->right;
		n = n / 2;
	}

	removeLeaf(b);
}

void minHeap::removeLeaf(BNode* pos)
{
	if (pos->isLeaf())
	{
		size--;
		BNode* temp = pos->parent;
		if (temp->left == pos)
			temp->left = 0;
		if (temp->right == pos)
			temp->right = 0;
		delete pos;
	}
	else cout << "cannot delete, it is not a leaf." << endl;
}

void minHeap::swapNodes(BNode* lhs, BNode* rhs)
{
	int mhs = rhs->data;
	rhs->data = lhs->data;
	lhs->data = mhs;
}

int minHeap::computeSize()
{
	BNode* temp = root;
	int nodes = 0;

	//base case
	if (root == 0)
		return nodes;
	//case 1
	else
	{
		//recurse left
		minHeap left = minHeap(temp->left);
		nodes += left.computeSize();

		//recurse right
		minHeap right = minHeap(temp->right);
		nodes += right.computeSize();

		//print root
		nodes += 1;
	}
	size = nodes;
	return nodes;
}

void minHeap::copyTree(BNode*& lhs, BNode*& rhs)
{
	if (rhs == 0)
	{
		lhs = 0;
	}
	else
	{
		lhs = new BNode(rhs->data);
		size++;

		copyTree(lhs->left, rhs->left);
		copyTree(lhs->right, rhs->right);
	}
}

BNode* minHeap::copyTree(BNode*& root)
{
	BNode* b = 0;
	if (root == 0)
	{
		return b;
	}
	else
	{
		b = new BNode(root);
		if (b->left != 0)
			b->left = new BNode(b->left);
		else
			b->left = 0;

		if (b->right != 0)
			b->right = new BNode(b->right);
		else
			b->right = 0;

		return b;
	}
}

BNode* minHeap::fromArray(const int* data, const int& size, const int& pos)
{
	BNode* b = 0;

	if (pos > size - 1)
		return b;
	else
	{
		b = new BNode(data[pos]);
		b->left = fromArray(data, size, pos * 2);
		if (b->left != 0)
			b->left->parent = b;
		b->right = fromArray(data, size, pos * 2 + 1);
		if (b->right != 0)
			b->right->parent = b;
		return b;
	}
}

int* minHeap::toArray()
{
	int* a = 0;

	if (size < 1)
		return a;
	else
	{
		a = new int[size];
		a[0] = -1;
		for (int i = 1; i < size + 1; i++)
			a[i] = getValue(i);
		return a;
	}
}

int minHeap::convertPosition(BNode* pos)
{
	return 0;
}

BNode* minHeap::convertPosition(const int& pos)
{
	BNode* b = this->root;

	int power = 0;
	int* temp = int_to_base2_mHeap(pos, power);
	int* binary = new int[power];
	binary = temp;

	for (int i = 1; i < power; i++)
	{
		if (binary[i] == 0)	b = b->left;
		else				b = b->right;
	}

	delete binary;
	return b;
}

BNode * minHeap::firstEmptyPosition(const int& pos)
{
	BNode* b = this->root;

	int power = 0;
	int* temp = int_to_base2_mHeap(pos, power);
	int* binary = new int[power];
	binary = temp;

	for (int i = 1; i < power - 1; i++)
	{
		if ((!b->isLeaf()) || (b->hasLeft()) || (b->hasRight()))
		{
			if (binary[i] == 0)	b = b->left;
			else				b = b->right;
		}
	}

	delete binary;
	return b;
}

int minHeap::getValue(const int& pos)
{
	int n = pos;
	BNode* b = this->root;

	while (n / 2 != 0)
	{
		if (n % 2 == 0) b = b->left;
		if (n % 2 == 1) b = b->right;
		n = n / 2;
	}
	if (b != 0) return b->data;
	else return -999;
}

stringstream* minHeap::print()
{
	BNode* b = 0;
	stringstream* out = new stringstream();

	//base case
	if (root == 0)
		return out;
	//case 1
	else
	{
		*out << endl;
		//cout << endl;	//
		int exponent = 0;
		int power = 0;
		//int power2 = 0;
		int* temp = 0; 
		int* base2 = 0; 
		int pos = size;
		//int* base10 = 0;

		temp = int_to_base2_mHeap(pos, power);
		//temp = int_to_base10_mHeap(pos, power2);
		exponent = power;
		int nums_on_line = 0;

		for (int i = 0; i < size; i++)
		{
			pos = i + 1;
			temp = int_to_base2_mHeap(pos, power);
			base2 = new int[power];
			base2 = temp;
			b = convertPosition(pos);
			//temp = int_to_base10_mHeap(b->getData(), power2);
			//base10 = new int[power2];
			//base10 = temp;

			if (nums_on_line == 0)
				for (int i = 0; i < (int)pow(2, exponent) - 1; i++)
				{
					*out << " ";
					//cout << " ";	//
				}
			else if (nums_on_line < (int)pow(2, power - 1))
				for (int i = 0; i < (int)pow(2, exponent + 1) - 1; i++)
				{
					*out << " ";
					//cout << " ";	//
				}

			//*out << base_to_stream_mHeap(base10, power2, 3)->str();
			*out << b->getData();
			cout << b->getData();
			nums_on_line++;
			if (nums_on_line == (int)pow(2, power - 1))
			{
				*out << endl;
				//cout << endl;	//
				exponent--;
				nums_on_line = 0;
			}

		}
		return out;
	}
}

stringstream* minHeap::print_pre_order()
{
	BNode* temp = root;
	stringstream* out = new stringstream();

	//base case
	if (root == 0)
		return out;
	//case 1
	else
	{
		//print root
		*out << temp->data << " ";

		//recurse left
		minHeap left = minHeap(temp->left);
		if (temp->left != 0)
			*out << left.print_pre_order()->str();

		//recurse right
		minHeap right = minHeap(temp->right);
		if (temp->right != 0)
			*out << right.print_pre_order()->str();

		return out;
	}
}

stringstream* minHeap::print_in_order()
{
	BNode* temp = root;
	stringstream* out = new stringstream();

	//base case
	if (root == 0)
		return out;
	//case 1
	else
	{
		//recurse left
		minHeap left = minHeap(temp->left);
		if (temp->left != 0)
			*out << left.print_in_order()->str();

		//print root
		*out << temp->data << " ";

		//recurse right
		minHeap right = minHeap(temp->right);
		if (temp->right != 0)
			*out << right.print_in_order()->str();

		return out;
	}
}

stringstream* minHeap::print_post_order()
{
	BNode* temp = root;
	stringstream* out = new stringstream();

	//base case
	if (root == 0)
		return out;
	//case 1
	else
	{
		//recurse left
		minHeap left = minHeap(temp->left);
		if (temp->left != 0)
			*out << left.print_post_order()->str();

		//recurse right
		minHeap right = minHeap(temp->right);
		if (temp->right != 0)
			*out << right.print_post_order()->str();

		//print root
		*out << temp->data << " ";

		return out;
	}
}


void minHeap::push(BNode*& newnode)
{
	size++;
	BNode* b = firstEmptyPosition(size);
	if (b->isLeaf())
	{
		b->left = newnode;
		newnode->parent = b;
	}
	else if ((b->hasLeft()) && (!b->hasRight()))
	{
		b->right = newnode;
		newnode->parent = b;
	}
	else if ((!b->hasLeft()) && (b->hasRight()))
	{
		b->left = newnode;
		newnode->parent = b;
	}

	//bubble_up(newnode);
}

void minHeap::pop_front()
{
	BNode* b = convertPosition(size);
	swapNodes(root, b);
	delete b;
	size--;
	bubble_down(root);
}

void minHeap::pop_back()
{
	BNode* b = convertPosition(size);
	delete b;
	size--;
}

void minHeap::pop_pos(const int & pos)
{

}

BNode* minHeap::top()
{
	return root;
}

void minHeap::bubble_up(BNode*& pos)
{
	BNode* parent = pos->parent;
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

void minHeap::bubble_down(BNode*& pos)
{
	BNode* left_child = pos->left;
	BNode* right_child = pos->right;
	if (pos->isLeaf())
	{
		return;
	}
	else
	{
		if ((pos->hasLeft()) && (pos->hasRight()))
		{
			if ((pos->data > left_child->data) || (pos->data > right_child->data))
			{
				if (left_child->data < right_child->data)
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
		else if ((pos->hasLeft()) && (!pos->hasRight()))
		{
			if ((pos->data > left_child->data))
			{
				swapNodes(pos, left_child);
				bubble_down(left_child);
			}
		}
		else
			return;
	}
}


bool isValidminHeap(const int* data, const int size)
{
	if (data[0] > 0) return false;
	if (size % 2 != 0) return false;
	if (size == 2)
		return true;
	else
	{
		int i = size;
		while (i >= 2)
		{
			if ((i / 2) % 2 == 0)
				i = i / 2;
			else
				break;
		}
		if (i != 2)
			return false;
		else
			return true;
	}
}
















int* heapify(const int* data, const int& size)
{
	minHeap mh = minHeap(data, size);
	cout << "mh" << "\t" << "size == " << mh.getSize() << endl;
	cout << "mh = " << mh << endl;
	cout << endl << endl;
	BNode* b = new BNode();
	for (int i = 0; i < size - 1; i++)
	{	
		b = mh.convertPosition(size - 1 - i);
		cout << "bubble down " << b->getData() << endl;
		mh.bubble_down(b);
		cout << "mh" << "\t" << "size == " << mh.getSize() << endl;
		cout << "mh = " << mh << endl;
		cout << endl << endl;
	}
	int* temp = new int[size];
	temp = mh.toArray();
	return temp;
}

// arr is an integer array of numbers.
//You should output a pointer to a new array which is a sorted version of arr
int* heapSort(const int* data, const int& size)
{
	//pop the top of min, and put it at the end. for each i
	int* temp = new int[size];
	int* heaped = heapify(data, size);
	
	minHeap mh = minHeap(heaped, size);
	for (int i = 0; i < size; i++)
	{
		temp[i] = mh.top()->getData();
		mh.pop_front();
	}

	return temp;
}




void mHeapTest()
{
	BNode* a = new BNode(8);
	BNode* b = new BNode(4);
	BNode* c = new BNode(2);
	BNode* d = new BNode(6);
	a->addleftright(b, c);
	b->addleft(d);


	minHeap mh0 = minHeap(a);
	mh0.computeSize();
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;


	BNode* p = new BNode(9);
	BNode* q = new BNode(3);
	BNode* r = new BNode(5);
	BNode* s = new BNode(1);
	mh0.push(p);
	cout << "mh0 push new node " << p->getData() << endl;
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;
	mh0.push(q);
	cout << "mh0 push new node " << q->getData() << endl;
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;
	mh0.push(r);
	cout << "mh0 push new node " << r->getData() << endl;
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	mh0.push(s);
	cout << "mh0 push new node " << s->getData() << endl;
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;
	

	cout << "mh0 top == " << mh0.top()->getData() << endl;
	cout << endl << endl;

	
	cout << "mh0 bubble up " << s->getData() << endl;
	mh0.bubble_up(s);
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;
	
	cout << "mh0 bubble up " << r->getData() << endl;
	mh0.bubble_up(r);
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;

	cout << "mh0 bubble up " << q->getData() << endl;
	mh0.bubble_up(q);
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;

	cout << "mh0 bubble up " << p->getData() << endl;
	mh0.bubble_up(p);
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;
	
	cout << "mh0 bubble down " << a->getData() << endl;
	mh0.bubble_down(a);
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;
	
	cout << "mh0 bubble down " << b->getData() << endl;
	mh0.bubble_down(b);
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;
	
	cout << "mh0 bubble down " << c->getData() << endl;
	mh0.bubble_down(c);
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	
	cout << "mh0 bubble down " << d->getData() << endl;
	mh0.bubble_down(d);
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;


	mh0.pop_front();
	cout << "mh0 pop_front" << endl;
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;

	mh0.pop_front();
	cout << "mh0 pop_front" << endl;
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;

	BNode* y = new BNode(1);
	mh0.push(y);
	cout << "mh0 push new node " << y->getData() << endl;
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;

	cout << "mh0 bubble up " << y->getData() << endl;
	mh0.bubble_up(y);
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;

	BNode* z = new BNode(2);
	mh0.push(z);
	cout << "mh0 push new node " << z->getData() << endl;
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;

	cout << "mh0 bubble up " << z->getData() << endl;
	mh0.bubble_up(z);
	cout << "mh0" << "\t" << "size == " << mh0.getSize() << endl;
	cout << "mh0 = " << mh0 << endl;
	cout << endl << endl;


	minHeap mh1 = mh0;
	cout << "mh1" << "\t" << "size == " << mh1.getSize() << endl;
	cout << "mh1 = " <<mh1 << endl;
	cout << endl << endl;


	int data[16] = { -1, 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
	int* data2 = heapify(data, 8);
	int* data3 = heapify(data, 16);

	cout << "data = ";
	for (int i = 0; i < 16; i++)
		cout << data[i] << " ";
	cout << endl << endl;

	cout << "data2 = ";
	for (int i = 0; i < 8; i++)
		cout << data2[i] << " ";
	cout << endl << endl;

	cout << "data3 = ";
	for (int i = 0; i < 16; i++)
		cout << data3[i] << " ";
	cout << endl << endl;


	minHeap mh2 = minHeap(data3, 16);
	mh2.computeSize();
	cout << "mh2" << "\t" << "size == " << mh2.getSize() << endl;
	cout << "mh2 = " << mh2 << endl;
	cout << endl << endl;
	
	int* data4 = heapSort(data, 16);
	cout << "data4 = ";
	for (int i = 0; i < 16; i++)
		cout << data4[i] << " ";
	cout << endl << endl;
}