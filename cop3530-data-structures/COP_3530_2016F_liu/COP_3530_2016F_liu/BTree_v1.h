/*
Version 1

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

*/

#pragma once

#include "std_libraries.h"

class BNode
{
friend class BinaryTree;
private:
	int data;
	BNode* left;
	BNode* right;
	BNode* parent;
public:
	BNode();
	BNode(const int&);
	BNode(const int&, BNode*, BNode*);
	~BNode();

	void addleft(BNode*);
	void addright(BNode*);
	void addleftright(BNode*, BNode*);
};

class BinaryTree
{
private:
	int size;
	BNode* root;
public:
	BinaryTree();
	~BinaryTree();
	BinaryTree(BNode*);
	BinaryTree(BinaryTree &);
	void copyTree(BNode*&, BNode*&);
	BinaryTree(const int*, const int&);
	BNode* fromArray(const int*, const int&, const int&);
	
	BNode* convertpos(const int&);
	
	void add2left(BNode*, BNode*);
	void add2right(BNode*, BNode*p);
	void add2left(BNode*, const int&);
	void add2right(BNode*, const int&);
	void add2left(BinaryTree *, const int&);
	void add2right(BinaryTree *, const int&);
	
	void removeleaf(const int&);
	void removeleaf(BNode*);
	void swapnodes(BNode*, BNode*);
	
	int* to_array();
	int getvalue(const int&);
	int getSize();
	BNode* getRoot();
	void computesize();

	void print_pre_order(ostream &);
	void print_in_order(ostream &);
	void print_post_order(ostream &);

	friend bool isValidBinaryTree(const int*p, const int n);
};











BNode::BNode()
{
	data = 0;
	index = 0;
	left = 0;
	right = 0;
	parent = 0;
}

BNode::BNode(const int& d)
{
	data = d;
	index = 0;
	left = 0;
	right = 0;
	parent = 0;
}

BNode::BNode(const int& d, BNode* l, BNode* r)
{
	data = d;
	index = 0;
	data = d;
	left = l;
	right = r;
}

BNode::~BNode()
{

}

void BNode::addleft(BNode* l)
{
	if (left == 0)
	{
		left = l;
		l->parent = this;
		index = parent->index * 2;
	}
	else
	{
		return;
	}
}

void BNode::addright(BNode* r)
{
	if (right == 0)
	{
		right = r;
		r->parent = this;
		index = parent->index * 2 + 1;
	}
	else
	{
		return;
	}
}

void BNode::addleftright(BNode* l, BNode* r)
{
	if (left == 0)
	{
		left = l;
		left->index = this->index * 2;
		l->parent = this;
	}
	else
	{
		return;
	}
	if (right == 0)
	{
		right = r;
		right->index = this->index * 2 + 1;
		r->parent = this;
	}
	else
	{
		return;
	}
}

BinaryTree::BinaryTree()
{
	size = 0;
	root = 0;
}

BinaryTree::~BinaryTree()
{
}

BinaryTree::BinaryTree(BNode* r)
{
	size = 1;
	root = r;
}

BinaryTree::BinaryTree(BinaryTree& t)
{
	if (t.root == 0)
	{
		root = 0;
	}
	else
	{
		copyTree(root, t.root);
	}
}

//inorder?
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
		lhs->index = size;

		copyTree(lhs->left, rhs->left);
		copyTree(lhs->right, rhs->right);
	}
}

//NOT PROPER YET
BinaryTree::BinaryTree(const int* data, const int& n)
{
	/*
	first, check
	if fail, fail
	else not fail
	run makeBinaryTree(array, position 1, size, count)
	*/
	if ((n == 0) || (!isValidBinaryTree(data, n)))
	{
		cout << "CANNOT MAKE TREE FROM DATA." << endl;
	}
	else
	{
		this->size = n - 1;
		this->root = 0;
		this->root = fromArray(data, 1, n);
	}

}


/*

run fromArray(array, position n, size, count)
if n > size -1 return 0
root = array[position n]
root->left = fromArray(array, n * 2)
root->right = fromArray(array, n * 2 + 1)

0 1 2 3 4 5 6 7

root
1
2   3
4 5 6 7

123 245 367

*/

//THIS IS THE RIGHT IDEA
BNode * BinaryTree::fromArray(const int* data, const int& loc, const int& size)
{
	BNode* b = 0;
	if (loc > size - 1)
		return b;
	else
	{
		b = new BNode(data[loc]);
		b->left = fromArray(data, loc * 2, size);
		if (b->left != 0)
			b->left->parent = b;
		b->right = fromArray(data, loc * 2 + 1, size);
		if (b->right != 0)
			b->right->parent = b;
		return b;
	}
}




//BNode* BinaryTree::fromArray(const int* data, const int& n)
//{
//	if (n == 1)
//	{
//		root = new BNode(data[1]);
//	}
//	else
//	{
//		if (!isValidBinaryTree(data, n))
//			root = 0;
//		else
//			if (n == 2)
//				root = new BNode(data[1]);
//			else
//			{
//				root = new BNode(data[1]);
//				BNode* p = root;
//
//				int e = 0;
//				int j = 0;
//				int k = 0;
//				int lower_left;
//				int upper_left;
//				int lower_right;
//				int upper_right;
//				int two;
//
//				for (int i = 2; i < n; i++)
//				{
//					p = root;
//					e = 2;
//
//					while (exponent(2, e) <= i)
//						e++;
//
//					two = exponent(2, e);
//					j = 2;
//
//					while (j < e)
//					{
//						k = exponent(2, e - j - 1);
//						lower_left = exponent(2, j);
//						upper_left = exponent(2, j) + exponent(2, j - 1);
//
//						lower_right = exponent(2, j) + exponent(2, j - 1);
//						upper_right = exponent(2, j) + exponent(2, j);
//						if ((lower_left <= i / k) && (i / k < upper_left))
//							p = p->left;
//						else if ((lower_right <= i / k) && (i / k < upper_right))
//							p = p->right;
//						j++;
//					}
//					if (i % 2 == 0)
//						add2left(new BNode(data[i]), p);
//					else if (i % 2 == 1)
//						add2right(new BNode(data[i]), p);
//				}
//			}
//	}
//}
//{
//	BNode *new_root = new BNode(data[0]);
//	if (n == 1) {
//		return new_root;
//	}
//	int* leftside = new int[n];
//	int* rightside = new int[n];
//
//	int l = 0;
//	int r = 0;
//
//	for (int i = 1; i < n; i = (i* 2) + 1) {
//		for (int j = i; j < i + ((i + 1) / 2); j++) {
//			leftside[l] = data[j];
//			l++;
//			if ((j + (i + 1) / 2)<n) {
//				rightside[r] = data[j + (i + 1) / 2];
//				r++;
//			}
//
//		}
//	}
//	new_root->left = fromArray(leftside, l);  // recursive call>     array- left sub tree's children and size
//	new_root->right = fromArray(rightside, r); // recursive     call> array- right sub tree's children and size
//	return new_root;
//}

//{
//	/*if (!isValidBinaryTree(data, n))
//		root = 0;
//	else
//		if (n == 2)
//			root = new BNode(data[1]);
//		else
//		{
//			root = new BNode(data[1]);
//			BNode* p = root;
//
//			int e = 0;
//			int j = 0;
//			int k = 0;
//			int lower_left;
//			int upper_left;
//			int lower_right;
//			int upper_right;
//			int two;
//
//			for (int i = 2; i < n; i++)
//			{
//				p = root;
//				e = 2;
//				
//				while (exponent(2, e) <= i)
//					e++;
//
//				two = exponent(2, e);
//				j = 2;
//				
//				while (j < e)
//				{
//					k = exponent(2, e - j - 1);
//					lower_left = exponent(2, j);
//					upper_left = exponent(2, j) + exponent(2, j - 1);
//
//					lower_right = exponent(2, j) + exponent(2, j - 1);
//					upper_right = exponent(2, j) + exponent(2, j);
//					if ( ( lower_left <= i / k ) && ( i / k < upper_left) )
//						p = p->left;
//					else if ( (lower_right <= i / k ) && (i / k < upper_right) )
//						p = p->right;
//					j++;
//				}
//				if (i % 2 == 0)
//					add2left(new BNode(data[i]), p);
//				else if (i % 2 == 1)
//					add2right(new BNode(data[i]), p);
//			}
//		}*/
//}

BNode* BinaryTree::convertpos(const int& pos)
{
	return 0;
}
//{
//	if (pos < 1)
//	{
//		return 0;
//	}
//	if (pos == 1)
//	{
//		return 0;
//	}
//	else
//	{
//		BNode* p = root;
//		if (pos % 2 == 0)
//		{
//			p = convertpos(pos / 2 + pos % 2)->left;
//		}
//		else if (pos % 2 == 1)
//		{
//			p = convertpos(pos / 2 + pos % 2)->right;
//		}
//	}
//
//}

void BinaryTree::add2left(BNode *newnode, BNode *pos)
{
	if (newnode != 0)
		if (newnode->left == 0)
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

void BinaryTree::add2right(BNode *newnode, BNode *pos)
{
	if (newnode != 0)
		if (newnode->right == 0)
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

void BinaryTree::add2left(BinaryTree* btree, const int& size)
{
	this->root->left = btree->root;
	this->size += size;
}

void BinaryTree::add2right(BinaryTree* btree, const int& size)
{
	this->root->right = btree->root;
	this->size += size;
}

void BinaryTree::removeleaf(BNode* pos)
{
	size--;
	if ((pos->left == 0) && (pos->right == 0))
	{
		BNode* temp = pos->parent;
		if (temp->left == pos)
		{
			temp->left = 0;
		}
		if (temp->right == pos)
		{
			temp->right = 0;
		}
		delete pos;
	}
}

//swap-the-dataues is fine
void BinaryTree::swapnodes(BNode* n1, BNode* n2)
{
	int temp = n1->data;
	n1->data = n2->data;
	n2->data = temp;
}

int* BinaryTree::to_array()
{
	if (size < 1)
	{
		return 0;
	}
	else
	{
		int* p = new int[size];
		p[0] = -1;
		for (int i = 1; i < size + 1; i++)
		{
			p[i] = getvalue(i);
		}
		return p;
	}

}

void BinaryTree::computesize()
{
	BNode* temp = root;
	//base case
	if (size == 0)
	{
		return;
	}
	//case 1
	else
	{
		//print
		if (temp->data != 0)
		{
			size++;
		}
		else
		{
			//recurse left
			BinaryTree left = BinaryTree(temp->left);
			left.computesize();

			//recurse right
			BinaryTree right = BinaryTree(temp->right);
			right.computesize();
		}
	}
}

int BinaryTree::getvalue(const int& loc)
{
	int n = loc;
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


/*
{
	BNode* temp = root;
	//base case
	if (size == 0)
	{
		return 0;
	}
	//case 1
	else
	{
		int value_l = 0;
		int value_r = 0;
		int value_m = 0;
		//recurse left
		BinaryTree left = BinaryTree(temp->left);
		value_l = left.getvalue(i);

		//recurse right
		BinaryTree right = BinaryTree(temp->right);
		value_r = right.getvalue(i);
		//print
		if (temp->index == i)
		{
			value_m = temp->data;
		}
	}
}
*/

int BinaryTree::getSize()
{
	return size;
}

BNode * BinaryTree::getRoot()
{
	return root;
}


void BinaryTree::print_pre_order(ostream& out)
{
	BNode* temp = root;

	//base case
	if (root == 0)
	{
		return;
	}
	//case 1
	else
	{
		//print root
		out << temp->data << " ";

		//recurse left
		BinaryTree left = BinaryTree(temp->left);
		left.print_pre_order(out);

		//recurse right
		BinaryTree right = BinaryTree(temp->right);
		right.print_pre_order(out);
	}

}
void BinaryTree::print_in_order(ostream& out)
{
	BNode* temp = root;

	//base case
	if (root == 0)
	{
		return;
	}
	//case 1
	else
	{
		//recurse left
		BinaryTree left = BinaryTree(temp->left);
		left.print_in_order(out);

		//print root
		out << temp->data << " ";

		//recurse right
		BinaryTree right = BinaryTree(temp->right);
		right.print_in_order(out);
	}
}

void BinaryTree::print_post_order(ostream& out)
{
	BNode* temp = root;

	//base case
	if (root == 0)
	{
		return;
	}
	//case 1
	else
	{
		//recurse left
		BinaryTree left = BinaryTree(temp->left);
		left.print_post_order(out);

		//recurse right
		BinaryTree right = BinaryTree(temp->right);
		right.print_post_order(out);

		//print root
		out << temp->data << " ";
	}
}


bool isValidBinaryTree(const int*p, const int n)
{
	if (p[0] > 0) return false;
	if (n % 2 != 0) return false;
	if (n == 2)
		return true;
	else
	{
		int i = n;
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

ostream& operator << (ostream& out, BinaryTree& rhs)
{
	rhs.print_in_order(out);
	return out;
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
	cout << "bt1" << "\t" << "size == " << bt1.getSize() << endl;
	bt1.print_pre_order(cout);
	bt1.print_in_order(cout << endl);
	bt1.print_post_order(cout << endl);
	cout << endl << endl;

	cout << "remove leaf, 15" << endl;
	cout << "bt1" << "\t" << "size == " << bt1.getSize() << endl;
	bt1.removeleaf(o);
	bt1.computesize();

	bt1.print_pre_order(cout);
	bt1.print_in_order(cout << endl);
	bt1.print_post_order(cout << endl);
	cout << endl << endl;


	int* bt1_arr = bt1.to_array();
	for (int i = 0; i < bt1.getSize(); i++)
		cout << bt1_arr[i] << " ";
	cout << endl << endl;


	BinaryTree bt2 = bt1;
	cout << "bt2" << "\t" << "size == " << bt2.getSize() << endl;
	bt2.print_pre_order(cout);
	bt2.print_in_order(cout << endl);
	bt2.print_post_order(cout << endl);
	cout << endl << endl;

	BinaryTree bt3 = BinaryTree(input, 16);
	cout << "bt3" << "\t" << "size == " << bt3.getSize() << endl;
	bt3.print_pre_order(cout);
	bt3.print_in_order(cout << endl);
	bt3.print_post_order(cout << endl);
	cout << endl << endl;


	BinaryTree bt4 = BinaryTree(bt2);
	cout << "bt4" << "\t" << "size == " << bt4.getSize() << endl;
	bt3.print_pre_order(cout);
	bt3.print_in_order(cout << endl);
	bt3.print_post_order(cout << endl);
	cout << endl << endl;

	BinaryTree bt5 = BinaryTree(input, 4);
	cout << "bt5" << "\t" << "size == " << bt5.getSize() << endl;
	bt5.print_pre_order(cout);
	bt5.print_in_order(cout << endl);
	bt5.print_post_order(cout << endl);
	cout << endl << endl;

	int* fromBTree = new int[32];
	fromBTree = bt5.to_array();
	

	return 0;
}