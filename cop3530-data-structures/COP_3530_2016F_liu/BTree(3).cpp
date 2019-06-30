
#include<iostream>

using namespace std;


class TNode
{
public:
    int val;
    TNode(){}
    TNode(int v){val = v;}
    TNode * left;
    TNode * right;
    TNode * parent;
};



class BTree
{
public:

    //constructors and destructor
    BTree();
    BTree(TNode *r);// initialize BTree with the root r. r is the only node.
    BTree(const BTree & t); // copy constructor
    BTree(const int *p, const int n);// similar to the copy constructor, but your input is of the array form.
    // input is given an array that denotes a tree that uses  up to n slots. The size of the tree is not given directly as input.
    // the array is pointed by p and has size n, where p[0] is used to store the empty symbol.
    //the function converts the array representation into a linked-list representation, i.e. BTree
    

    
    ~BTree();
    
    int size;
    TNode *root;
    
    TNode * convertpos(int position);// find the pointer where the position points to

    void add2left(TNode *newnode,  TNode *p);
    void add2right(TNode *newnode,  TNode *p);
    
    void add2left(TNode *newnode, int position);
    void add2right(TNode *newnode, int position);

    
    void add2left(BTree *newsubtree, int position);
    void add2right(BTree *newsubtree, int position);
    
    
    void removeleaf(int position);
    void removeleaf(TNode *p);
    
    void swapnodes(TNode *n1, TNode *n2);//swap-the-values is fine
    
    int * Toarray(int &n);// convert the BT into the array form. Determine what the size n should be, and new an array of size n, and store the empty symbol at array[0]. Convert the BT into the array form and  retrun the array
    
    void print_pre_order();// print the node as you traverse according to the order.
    void print_in_order();
    void print_post_order();
};


bool isValidBT(const int *p, const int n);
//Determine whether the array forms a valid BT.
// the input format is the same as the above



int main()
{
   
    return 0;
}


