//
//  main.cpp
//  Homework_5
//
//  Created by Cliford Guillaume on 11/20/16.
//  Copyright © 2016 Cliford Guillaume. All rights reserved.
//

#include <iostream>

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


class minHeap // binary heap
{
public:
    int size;
    int position;
    int pos;
    int val2 = 20;
    int mH ;
    int arrA [9];
    TNode *top;
    
    
    minHeap();     // Constructor
    ~minHeap ();    // deconstructr
    minHeap(const minHeap &h); //copy constructor
	minHeap(int* p, int n); //from array
	void copyTree(TNode*& lhs, const TNode* rhs);
    void display();
    void bubbleUp();
    void bubbledown (int k);
    void in(TNode &t);// you should new a new node and then add into the heap
	void removemin();
    void swap(int a, int b);
    TNode* getmin();
    void Heapify(const int n, const int *p);// p is an array of size n, representing a (full) binray tree of size n. You should not modify the array p
    
    
};


int * HeapSort(const int n, const int *arr);// arr is an integer array of numbers.
//You should output a pointer to a new array which is a sorted version of arr


void Test()
{
    
}

minHeap::minHeap () //constructor
{
    top = new TNode;
    top->parent = 0;
    top->right = top->left = 0;
    top->val = val2;
    
}


minHeap:: ~minHeap() //Destructor
{
    
}


 minHeap::minHeap (const minHeap & h)  // copy constructor
{
	if (h.top == 0)
	{
		top = 0;
	}
	else
	{
		top = new TNode;
		top->parent = 0;
		top->right = top->left = 0;
		top->val = h.val2;
		//this helper function is required to do the recursion
		copyTree(top, h.top);
	}

}

 //helper function to recurse during the copy constructor
 void minHeap::copyTree(TNode*& lhs, const TNode* rhs)
 {
	 if (rhs == 0)
	 {
		 lhs = 0;
	 }
	 else
	 {
		 lhs = new TNode(rhs->val);
		 size++;

		 copyTree(lhs->left, rhs->left);
		 copyTree(lhs->right, rhs->right);
	 }
 }


void minHeap:: display()
{
   for(int i=1;i<size;i++)
   {
       cout<<"Heap -->  ";
   }
    while (pos != 0)
    {
        cout<< pos <<" ";
        pos++;
    }
    cout <<endl;
}


void minHeap:: bubbleUp()
{
    int pos = position -1;
    while((pos>0) && (mH[pos/2]>mH[pos]))
    {
        int y = mH[pos];
        mH[pos]=mH[pos/2];
        mH[pos/2] = y;
        pos = pos/2;
    }
}


void minHeap:: in(TNode &t ) // this will create a new node and then add it into the heap.
{
   
     top = new TNode;
    
    if(position==0)
    {
        mH[position+1]=t;
        position = 2;
    }
    else
    {
        mH[position++]=t;
        bubbleUp();
   }
}


void minHeap::removemin()
{
    if (size == 0)
    {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    mH[0] = at(size - 1);
	removemin();
    bubbledown(0);
    cout<<"Element Deleted"<<endl;
}

void minHeap:: bubbledown (int z)
    {
        int a = mH[z];
        int smallest = z;
        
            if(2*z < position && mH[smallest] > mH[2*z])        //Google note
    {
        smallest = 2*z;
    }
    if(2*z+1 < position && mH[smallest] >mH[2*z+1])
    {
        smallest = 2*z+1;
    }
    if(smallest!=z)
    {
        swap(z,smallest);
        bubbledown(smallest);
    }
    
}

void minHeap:: swap(int a, int b)
{
    int temp = mH[a];
    mH[a] = mH[b];
    mH[b] = temp;
}


TNode* minHeap::getmin()
{
    if (size == 0)
    {
        return 0;
    }
    else
        return top;
}



void minHeap ::Heapify(const int n, const int *p)
{
	if ((n >= 0) && (parent(n) >= 0) && (mH[parent(n)] > mH[in]))
	{
		int temp = mH[n];
		mH[n] = mH[parent(n)];
		mH[parent(n)] = temp;
		bubbleUp(*parent(n));
	}

    int child = left(n);
    int child1 = right(n);
    if ((child >= 0) && (child1 >= 0) && (heap[child] > heap[child1]))
    {
        child = child1;
    }
    if (child > 0)
    {
        int temp = heap[in];
        heap[in] = heap[child];
        heap[child] = temp;
        bubbledown(child);
    }
}

int main()
{
    
    
    minHeap name;
    
    int arrA [10] = {-1,4,2,4,9,8,5,10,19,12};
    cout << "Original Array : "<< endl;
        
    for(int i=0;i<10;i++)
    {
        cout <<  arrA[i] << endl;
    }
    minHeap w = minHeap(arrA, 10);
    cout << "\nMin-Heap : " << endl;
    w.display();
    cout << "Extract Min :"<< endl;
        
    for(int i=0; i<10; i++)
    {
        cout << " " + w.getmin()->val<< endl;
    }
    
    return 0;
}

