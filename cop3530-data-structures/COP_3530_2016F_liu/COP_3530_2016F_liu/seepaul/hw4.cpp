#include <iostream>
#include <math.h>

using namespace std;


class Node
{
public:
	int data;
	int index;	//index to keep track of its index inside of an array

	Node() { data = 0; index = 0; left = 0; right = 0; parent = 0; }
	Node(const int & d) { data = d; index = 0; left = 0; right = 0; parent = 0; }
	~Node() {}
	Node* left;
	Node* right;
	Node* parent;
};


class BTreeree
{
public:
	int size;
	Node * root;
public:

	BTreeree();	//constructors and destructor
	~BTreeree();	// initialize BTreeree_2 with the root r. r is the only node.
	BTreeree(Node *); // this one initializes one with a root // copy constructor
	BTreeree(BTreeree &); //this is acopy constructor, but the problem is that trees are recursive
					// similar to the copy constructor, but your input is of the array form.
					// input is given an array that denotes a tree that uses  up to n slots. The size of the tree is not given directly as input.
					// the array is pointed by p and has size n, where p[0] is used to store the empty symbol.
					//the function converts the array representation into a linked-list representation, i.e. BTreeree_2

	void copyTree(Node * &, Node * &); // so copy constructor uses this helper to do the recursive part. Basically it builds the nodes together and returns the top root, and the copy constructor just assigns that root to itself
	BTreeree(const int *, const int &);

	Node * convertpos(const int &); //***not implemented // find the pointer where the position points to

	void add2left(Node *, Node *);	//checks if empty, if it is, adds it to left
	void add2right(Node *, Node *p);//checks if empty, if it is, adds it to right
	void add2left(Node *, const int &); //***not implemented
	void add2right(Node *, const int &); //***not implemented
	void add2left(BTreeree *, const int &); //***not implemented
	void add2right(BTreeree *, const int &); //***not implemented

	void removeleaf(const int &); //***not implemented
	void removeleaf(Node *);	//basic check to see if it is a leaf
	void swapnodes(Node *, Node *);		//swaps node values

	int * to_array(); //not implemented // convert the BTree into the array form. Determine what the size n should be, and new an array of size n, and store the empty symbol at array[0]. Convert the BTree into the array form and  retrun the array
	void print_pre_order(ostream &);		//implemented using recursion and temporary left and temporary right subtrees
	void print_in_order(ostream &);	//implemented using recursion and temporary left and temporary right subtrees. usually inorder is a nodebased traversal, but this was a subtree based traversal
	void print_post_order(ostream &);		//implemented using recursion and temporary left and temporary right subtrees

	friend bool isValidBTreeree(const int *p, const int n);	//checks if the size n is bigger than 1, checks that the first element is garbage, check that n is a 2==2^k, some kind of exponent of 2, declared as friend so that other functions also have access to it and we don’t need to put it above the class
															//Determine whether the array forms a valid BTree.
															// the input format is the same as the above

};

BTreeree::BTreeree()
{
	size = 0;
	root = 0;
}

BTreeree::~BTreeree()
{
}

BTreeree::BTreeree(Node * r)
{
	size = 1;
	root = r;
}

BTreeree::BTreeree(BTreeree & t)
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

//inorder copying?
void BTreeree::copyTree(Node * & lhs, Node * & rhs)
{
	if (rhs == 0)
	{
		lhs = 0;
	}
	else
	{
		lhs = new Node(rhs->data);
		size++;
		lhs->index = size;

		copyTree(lhs->left, rhs->left);
		copyTree(lhs->right, rhs->right);
	}
}

//NOT PROPER YET
BTreeree::BTreeree(const int * data, const int & n)
{
	if (n == 0)
	{

	}
	else
	{
		if (n == 1)
		{
			root = new Node(data[1]);
		}
		else
		{
			if (!isValidBTreeree(data, n))
				root = 0;
			else
				if (n == 2)
					root = new Node(data[1]);
				else
				{
					root = new Node(data[1]);
					Node * p = root;
					int e = 0;
					int j = 0;
					int k = 0;
					int lower_left;
					int upper_left;
					int lower_right;
					int upper_right;
					int two;
					for (int i = 2; i < n; i++)
					{
						p = root;
						e = 2;

						while (floor(pow(2, e)) <= i)
							e++;
						two = floor(pow(2, e));
						j = 2;

						while (j < e)
						{
							k = floor(pow(2, e - j - 1));
							lower_left = floor(pow(2, j));
							upper_left = floor(pow(2, j)) + floor(pow(2, j - 1));
							lower_right = floor(pow(2, j)) + floor(pow(2, j - 1));
							upper_right = floor(pow(2, j)) + floor(pow(2, j));
							if ((lower_left <= i / k) && (i / k < upper_left))
								p = p->left;
							else if ((lower_right <= i / k) && (i / k < upper_right))
								p = p->right;
							j++;
						}
						if (i % 2 == 0)
							add2left(new Node(data[i]), p);
						else if (i % 2 == 1)
							add2right(new Node(data[i]), p);
					}
				}
		}
	}

}



void BTreeree::add2left(Node *newnode, Node *pos)
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

void BTreeree::add2right(Node *newnode, Node *pos)
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

void BTreeree::removeleaf(Node * pos)
{
	size--;
	if ((pos->left == 0) && (pos->right == 0))
	{
		if (pos == pos->parent->left)
		{
			pos->parent->left = 0;
		}
		else if (pos == pos->parent->right)
		{
			pos->parent->right = 0;
		}
		delete pos;
	}
}

//swap is fine
void BTreeree::swapnodes(Node * n1, Node * n2)
{
	int temp = n1->data;
	n1->data = n2->data;
	n2->data = temp;
}


void BTreeree::print_pre_order(ostream & out)
{
	Node * temp = root;

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
		BTreeree left = BTreeree(temp->left);
		left.print_pre_order(out);

		//recurse right
		BTreeree right = BTreeree(temp->right);
		right.print_pre_order(out);
	}

}
void BTreeree::print_in_order(ostream & out)
{
	Node * temp = root;

	//base case
	if (root == 0)
	{
		return;
	}
	//case 1
	else
	{
		//recurse left
		BTreeree left = BTreeree(temp->left);
		left.print_in_order(out);
		//print root
		out << temp->data << " ";

		//recurse right
		BTreeree right = BTreeree(temp->right);
		right.print_in_order(out);
	}
}

void BTreeree::print_post_order(ostream & out)
{
	Node * temp = root;

	//base case
	if (root == 0)
	{
		return;
	}
	//case 1
	else
	{
		//recurse left
		BTreeree left = BTreeree(temp->left);
		left.print_post_order(out);

		//recurse right
		BTreeree right = BTreeree(temp->right);
		right.print_post_order(out);

		//print root
		out << temp->data << " ";
	}
}


bool isValidBTreeree(const int *p, const int n)
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

int main()
{
	Node* a = new Node(8);
	Node* b = new Node(4);
	Node* c = new Node(12);
	Node* d = new Node(2);
	Node* e = new Node(6);
	Node* f = new Node(10);
	Node* g = new Node(14);
	Node* h = new Node(1);
	Node* i = new Node(3);
	Node* j = new Node(5);
	Node* k = new Node(7);
	Node* l = new Node(9);
	Node* m = new Node(11);
	Node* n = new Node(13);
	Node* o = new Node(15);

	a->left = b;	b->parent = a;
	a->right = c;	c->parent = a;
	b->left = d;	d->parent = b;
	b->right = e;	e->parent = b;
	d->left = h;	h->parent = d;
	d->right = i;	i->parent = d;
	e->left = j;	j->parent = e;
	e->right = k;	k->parent = e;
	c->left = f;	f->parent = c;
	c->right = g;	g->parent = c;
	f->left = l;	l->parent = f;
	f->right = m;	m->parent = f;
	g->left = n;	g->parent = n;
	g->right = o;	o->parent = g;

	/*
	a
	b								c
	d				e				f				g
	h		i		j		k		l		m		n		o
	*/

	/*
	8
	4								12
	2				6				10				14
	1		3		5		7		9		11		13		15

	*/




	BTreeree BTreeree1 = BTreeree(a);
	cout << "BTreeree1" << "\t" << "size == " << BTreeree1.size << endl;
	BTreeree1.print_pre_order(cout);
	BTreeree1.print_in_order(cout << endl);
	BTreeree1.print_post_order(cout << endl);
	cout << endl << endl;

	BTreeree BTreeree2 = BTreeree1;
	cout << "BTreeree2" << "\t" << "size == " << BTreeree2.size << endl;
	BTreeree2.print_pre_order(cout);
	BTreeree2.print_in_order(cout << endl);
	BTreeree2.print_post_order(cout << endl);
	cout << endl << endl;

	int input[16] = { -1, 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };

	BTreeree BTreeree3 = BTreeree(input, 16);
	cout << "BTreeree3" << "\t" << "size == " << BTreeree3.size << endl;
	BTreeree3.print_pre_order(cout);
	BTreeree3.print_in_order(cout << endl);
	BTreeree3.print_post_order(cout << endl);
	cout << endl << endl;

	return 0;
}

