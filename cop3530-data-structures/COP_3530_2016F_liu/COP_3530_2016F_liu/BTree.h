/*
Version 2

Chris Carl
LOG:
16.11.03, 12:05 - start
16.11.03, 12:21 - completed:
BNode(), BNode(int), BinaryTree(), BinaryTree(BNode*), removeleaf(BNode*), swapnodes(BNode*, BNode*)
16.11.03, 12:39 - completed:, stop
isValidBinaryTree(const int*, const int )

16.11.03, 12:39 - start
16.11.03, 01:21 - completed:
print_pre_order(), print_post_order()
16.11.03, 01:54 - completed:
BinaryTree(Btree &)
16.11.03, 02:10 - completed:
BinaryTree(const int*, const int)
16.11.03, 02:32 - stop
after some minimal testing, I am dismayed to find that barely any of the constructors work...

16.11.03, 15:30 - start
16.11.03, 16:35 - completed:
pre, in, post all work correctly as Feng Hao intended
16.11.03, 16:41 - completed:
all constructors verified, now moving onto arrays
16.11.03, 17:36 - completed:
array constructor verified and complete
16.11.03, 17:50 - stop

16.11.03, 17:55 - start
16.11.03, 17:59 - completed:
size computes correctly
16.11.03, 19:09 - bug:
BinaryTree to array construction is not correct
16.11.03, 23:24 - bug:
still working on the debug
16.11.04, 00:10 - stop

16.11.24, 22:25 - start
16.11.24, 23:35 - progress made on array to btree
16.11.24, 23:35 - stop

16.11.25, 11:18 - start
16.11.25, 12:24 - finished fromArray and toArray, refactoring
16.11.25, 15:45 - finished EVERYTHING.
16.11.25, 15:10 - stop


*/

#pragma once

#include "std_libraries.h"

class BNode
{
	friend class BinaryTree;
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

class BinaryTree
{
private:
	int size;
	BNode* root;
public:
	BinaryTree();									//default
	BinaryTree(const int& root);					//explicit value of root
	BinaryTree(BNode* root);						//explicit value BNode pointer
	BinaryTree(const int* data, const int& size);	//construct using array
	BinaryTree(BinaryTree& rhs);					//copy constructor
	BinaryTree& operator=(BinaryTree& rhs);			//= overload
	~BinaryTree();									//destructor

	//GETTERS
	int getSize();
	BNode* getRoot();

	//SETTERS
	void add2left(BNode* newnode, BNode* pos);
	void add2right(BNode* newnode, BNode* pos);
	void add2left(BNode* newnode, const int& pos);
	void add2right(BNode* newnode, const int& pos);
	void add2left(BinaryTree* newsubtree, const int& pos);
	void add2right(BinaryTree* newsubtree, const int& pos);
	void removeLeaf(const int& pos);
	void removeLeaf(BNode* pos);
	void swapNodes(BNode* lhs, BNode* rhs);

	//UTILITIES
	friend bool isValidBinaryTree(const int* data, const int size);
	int computeSize();

	void copyTree(BNode*& lhs, BNode*& rhs);
	BNode* copyTree(BNode*& root);
	//void fromArray(const int*, const int&, const int&);
	BNode* fromArray(const int* data, const int& size, const int& pos);
	int* toArray();

	int convertPosition(BNode* pos);
	BNode* convertPosition(const int& pos);
	int getValue(const int& pos);

	//STREAM FUNCTIONS
	stringstream* print_pre_order();
	stringstream* print_in_order();
	stringstream* print_post_order();
};

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
	if (left != 0) delete left;
	if (right != 0) delete right;
	if (parent != 0) delete parent;
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




BinaryTree::BinaryTree()
{
	size = 0;
	root = 0;
}

BinaryTree::BinaryTree(const int& r)
{
	size = 1;
	root = new BNode(r);
	computeSize();
}

BinaryTree::BinaryTree(BNode* r)
{
	size = 1;
	root = r;
	computeSize();
}

BinaryTree::BinaryTree(const int* data, const int& size)
{
	/*
	first, check
	if fail, fail
	else not fail
	run makeBinaryTree(array, position 1, size, count)
	*/
	if ((size == 0) || (!isValidBinaryTree(data, size)))
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

BinaryTree::BinaryTree(BinaryTree& rhs)
{
	if (rhs.root == 0)
		root = 0;
	else
		copyTree(root, rhs.root);

	computeSize();
}

BinaryTree& BinaryTree::operator=(BinaryTree& rhs)
{
	if (this == &rhs)
		return *this;

	if (rhs.root == 0)
		root = 0;
	else
		copyTree(root, rhs.root);

	computeSize();
}

BinaryTree::~BinaryTree()
{
	//traverse in post order and delete that way.
}

int BinaryTree::getSize()
{
	return size;
}

BNode* BinaryTree::getRoot()
{
	return root;
}

void BinaryTree::add2left(BNode* newnode, BNode* pos)
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

void BinaryTree::add2right(BNode* newnode, BNode* pos)
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

void BinaryTree::add2left(BNode* newnode, const int& pos)
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

void BinaryTree::add2right(BNode* newnode, const int& pos)
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

void BinaryTree::add2left(BinaryTree* newsubtree, const int& pos)
{
	this->root->left = newsubtree->root;
	this->size += size;
}

void BinaryTree::add2right(BinaryTree* newsubtree, const int& pos)
{
	this->root->right = newsubtree->root;
	this->size += size;
}

void BinaryTree::removeLeaf(const int& pos)
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

void BinaryTree::removeLeaf(BNode* pos)
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

void BinaryTree::swapNodes(BNode* lhs, BNode* rhs)
{
	int mhs = rhs->data;
	rhs->data = lhs->data;
	lhs->data = mhs;
}

int BinaryTree::computeSize()
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
		BinaryTree left = BinaryTree(temp->left);
		nodes += left.computeSize();

		//recurse right
		BinaryTree right = BinaryTree(temp->right);
		nodes += right.computeSize();

		//print root
		nodes += 1;
	}
	size = nodes;
	return nodes;
}

void BinaryTree::copyTree(BNode*& lhs, BNode*& rhs)
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

BNode* BinaryTree::copyTree(BNode*& root)
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

BNode* BinaryTree::fromArray(const int* data, const int& size, const int& pos)
{
	BNode* b = 0;

	if (pos > size - 1)
		return b;
	else
	{
		b = new BNode(data[pos]);
		b->left = fromArray(data, size, pos* 2);
		if (b->left != 0)
			b->left->parent = b;
		b->right = fromArray(data, size, pos* 2 + 1);
		if (b->right != 0)
			b->right->parent = b;
		return b;
	}
}

int* BinaryTree::toArray()
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

int BinaryTree::convertPosition(BNode* pos)
{
	return 0;
}

BNode* BinaryTree::convertPosition(const int& pos)
{
	int n = pos;
	BNode* b = this->root;

	while (n / 2 != 0)
	{
		if (n % 2 == 0) b = b->left;
		if (n % 2 == 1) b = b->right;
		n = n / 2;
	}
	if (b != 0) return b;
	else return 0;
}

int BinaryTree::getValue(const int& pos)
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

stringstream* BinaryTree::print_pre_order()
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
		BinaryTree left = BinaryTree(temp->left);
		if (temp->left != 0)
			*out << left.print_pre_order()->str();

		//recurse right
		BinaryTree right = BinaryTree(temp->right);
		if (temp->right != 0)
			*out << right.print_pre_order()->str();

		return out;
	}
}

stringstream* BinaryTree::print_in_order()
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
		BinaryTree left = BinaryTree(temp->left);
		if (temp->left != 0)
			*out << left.print_in_order()->str();

		//print root
		*out << temp->data << " ";

		//recurse right
		BinaryTree right = BinaryTree(temp->right);
		if (temp->right != 0)
			*out << right.print_in_order()->str();

		return out;
	}
}

stringstream* BinaryTree::print_post_order()
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
		BinaryTree left = BinaryTree(temp->left);
		if (temp->left != 0)
			*out << left.print_post_order()->str();

		//recurse right
		BinaryTree right = BinaryTree(temp->right);
		if (temp->right != 0)
			*out << right.print_post_order()->str();

		//print root
		*out << temp->data << " ";

		return out;
	}
}












bool isValidBinaryTree(const int* data, const int size)
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

int bTreeTest()
{
	BNode* a = new BNode(8);
	BNode* b = new BNode(4);
	BNode* c = new BNode(12);
	BNode* d = new BNode(2);
	BNode* e = new BNode(6);
	BNode* f = new BNode(10);
	BNode* g = new BNode(14);
	BNode* h = new BNode(1);
	BNode* i = new BNode(3);
	BNode* j = new BNode(5);
	BNode* k = new BNode(7);
	BNode* l = new BNode(9);
	BNode* m = new BNode(11);
	BNode* n = new BNode(13);
	BNode* o = new BNode(15);
	a->addleftright(b, c);
	b->addleftright(d, e);
	c->addleftright(f, g);
	d->addleftright(h, i);
	e->addleftright(j, k);
	f->addleftright(l, m);
	g->addleftright(n, o);

	int input[16] = { -1, 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };

	BinaryTree bt1 = BinaryTree(a);
	bt1.computeSize();
	cout << "bt1" << "\t" << "size == " << bt1.getSize() << endl;
	cout << "pre  = " << bt1.print_pre_order()->str() << endl;
	cout << "in   = " << bt1.print_in_order()->str() << endl;
	cout << "post = " << bt1.print_post_order()->str() << endl;
	cout << endl << endl;

	BinaryTree bt2 = bt1;
	cout << "bt2" << "\t" << "size == " << bt2.getSize() << endl;
	cout << "pre  = " << bt2.print_pre_order()->str() << endl;
	cout << "in   = " << bt2.print_in_order()->str() << endl;
	cout << "post = " << bt2.print_post_order()->str() << endl;
	cout << endl << endl;

	cout << "remove leaf from bt1, 15" << endl;
	bt1.removeLeaf(o);
	bt1.computeSize();

	cout << "bt1" << "\t" << "size == " << bt1.getSize() << endl;
	cout << "pre  = " << bt1.print_pre_order()->str() << endl;
	cout << "in   = " << bt1.print_in_order()->str() << endl;
	cout << "post = " << bt1.print_post_order()->str() << endl;
	cout << endl << endl;

	cout << "bt1_arr == ";
	int* bt1_arr = bt1.toArray();
	for (int i = 0; i < bt1.getSize(); i++)
		cout << bt1_arr[i] << " ";
	cout << endl << endl;

	BinaryTree bt3 = BinaryTree(input, 16);
	cout << "bt3" << "\t" << "size == " << bt3.getSize() << endl;
	cout << "pre  = " << bt3.print_pre_order()->str() << endl;
	cout << "in   = " << bt3.print_in_order()->str() << endl;
	cout << "post = " << bt3.print_post_order()->str() << endl;
	cout << endl << endl;


	BinaryTree bt4 = BinaryTree(bt2);
	cout << "bt4" << "\t" << "size == " << bt4.getSize() << endl;
	cout << "pre  = " << bt4.print_pre_order()->str() << endl;
	cout << "in   = " << bt4.print_in_order()->str() << endl;
	cout << "post = " << bt4.print_post_order()->str() << endl;
	cout << endl << endl;

	BinaryTree bt5 = BinaryTree(input, 4);
	cout << "bt5" << "\t" << "size == " << bt5.getSize() << endl;
	cout << "pre  = " << bt5.print_pre_order()->str() << endl;
	cout << "in   = " << bt5.print_in_order()->str() << endl;
	cout << "post = " << bt5.print_post_order()->str() << endl;
	cout << endl << endl;

	cout << "bt5_arr == ";
	int* bt5_arr = new int[4];
	bt5_arr = bt5.toArray();
	for (int i = 0; i < 4; i++)
		cout << bt5_arr[i] << " ";
	cout << endl << endl;


	return 0;
}