#pragma once

#include <iostream>
#include <random>

using namespace std;

//function to generate random numbers using c++-style seeding
static int RNG(const int& lower, const int& upper)
{
	if (lower == upper) return lower;

	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<mt19937::result_type> dist6(lower, upper); // distribution in range [lower, upper]

	return dist6(rng);
}

class TNode
{
public:
	int val;
	TNode(){
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}
	TNode(int v) {
		val = v;
		left = nullptr;
		right = nullptr;
		parent = nullptr;

	}
	
	TNode * left;
	TNode * right;
	TNode * parent;
};



class minHeap // binary heap
{
private:

	int size;
	TNode *top;
	TNode next;
	TNode * back;
	void Bubbledown(TNode* curr);
	void Bubbleup(TNode* curr);
	void swap(TNode * a, TNode * b);
public:
	minHeap();
	void copyh(TNode * curr);
	minHeap(const minHeap &h);
	void in(const TNode &t);// you should new a new node and then add into the heap
	void removemin();
	TNode* getmin();
	void Heapify(const int n, const int *p);// p is an array of size n, representing a (full) binray tree of size n. You should not modify the array p

};





int * HeapSort(const int n, const int *arr)
{
	minHeap srt;
	int * r = new int[n];
	srt.Heapify(n,arr);
	for (size_t i = 0; i < n; i++)
		{
			r[i] = srt.getmin()->val;
			srt.removemin();
		}

	return r;
}			
			// arr is an integer array of numbers.
			//You should output a pointer to a new array which is a sorted version of arr

void hw5_lotarynski()
{
	minHeap Heap;
	cout << "Heap" << endl;
	int rand;
	for (int i = 10; i > 0; i--)
	{
		rand = RNG(0, 10);
		Heap.in(rand);
		
	}
	minHeap * scndh = new minHeap(Heap);
	for (int i = 10; i > 0; i--)
	{
		cout << (Heap.getmin())->val << endl;
		Heap.removemin();

	}	
		cout << "Copy Heap" << endl;
	for (int i = 10; i > 0; i--)
	{
		cout << (scndh->getmin())->val << endl;
		scndh->removemin();

	}
	int arr = 20;
	int * usrta = new int[arr];
	int * srta = new int[arr];
	int j = arr;
	cout << "Unsorted" << endl;
	for (int i = 0; i < arr ; i++)
	{
		usrta[i] = j;
		cout << j << endl;
		j--;
	}
	cout << endl;
	srta = HeapSort(arr, usrta);
	cout << "Sorted" << endl;
	for (int i = 0; i < arr; i++)
	{
		cout << srta[i] << endl;
	}
	cout << endl;
}

minHeap::minHeap()
{
	size = 0;
	top = nullptr;
	back = nullptr;
}
minHeap::minHeap(const minHeap &h) 
{
	size = 0;
	top = nullptr;
	back = nullptr;
	copyh(h.top);
}
void minHeap::copyh(TNode * curr) 
{
	TNode t(curr->val);
	in(t);
	if (curr->left != nullptr)
	{
		copyh(curr->left);
	}
	if (curr->right != nullptr)
	{
		copyh(curr->right);
	}
}
void minHeap::in(const TNode &t)
{
	if (top == nullptr)//empty
	{
		top = new TNode(t.val);
		back = top;
	}
	else
	{
		if (size == 1)//top 1
		{
			back->left = new TNode(t.val);
			back = back->left;
			back->parent = top;
		}
		else if (size % 2 == 0)//even
		{
			back->parent->right = new TNode(t.val);
			back->parent->right->parent = back->parent;
			back = back->parent->right;
		}
		else//odd
		{
			TNode * temp = back;
			temp = temp->parent;
			while (temp -> parent != nullptr && temp->right == back)
			{
				temp = temp->parent;
				back = back->parent;
			}
			if (temp->parent == nullptr && temp->right== back)
			{
				back = temp;
				while (back->left != nullptr)
				{
					back = back->left;
				}
				back->left = new TNode(t.val);
				back->left->parent = back;
				back = back->left;
			}
			else
			{
				back = temp->right;
				while (back->left != nullptr)
				{
					back = back->left;
				}
				back->left = new TNode(t.val);
				back->left->parent = back;
				back = back->left;
			}
		}
	Bubbleup(back);// sort

	}
	size++;
}
// you should new a new node and then add into the heap
void minHeap::removemin() {
	if (size<1)
	{
		cout << "This no good " << endl;
	}
	if (size==1)
	{
		delete top;
		back = nullptr;
		top = nullptr;

	}
	else
	{
		if (size % 2 != 0)//even
		{
			swap(back, top);
			back = back->parent->left;
			delete back->parent->right;
			back->parent->right = nullptr;
		}
		else//odd
		{
			swap(back, top);
			TNode * temp1 = back;
			TNode * temp2 = back;
			
			back = back->parent;
			while (back->parent != nullptr && back->right != temp2)
			{
				temp2 = temp2->parent;
				back = back->parent;
			}
			if (back->parent!=nullptr || (back->parent == nullptr && back-> right== temp2))
			{
				back = back->left;
			}
			while (back->right != nullptr)
			{
				back = back->right;
			}
			temp1 = temp1->parent;
			delete temp1->left;
			temp1->left = nullptr;
			
		}
		Bubbledown(top);
	}
	size--;
}
		//swap(top, lastin);

TNode * minHeap::getmin() 
{
	return top;
}
void minHeap::Heapify(const int n, const int *p)
{
	for ( size_t i=0;  i < n; i++)
	{
		in(p[i]);
	}
}// p is an array of size n, representing a (full) binray tree of size n. You should not modify the array p

void minHeap::Bubbledown(TNode* curr)
{
	if (curr->left != nullptr && curr->val > curr->left->val)
	{
		swap(curr, curr->left);
		Bubbledown(curr->left);
	}
	if (curr->right != nullptr && curr->val > curr->right->val)
	{
		swap(curr, curr->right);
		Bubbledown(curr->right);
	}
}
void minHeap::Bubbleup(TNode* curr)
{
	if (curr->parent != nullptr && curr->parent->val > curr->val)
	{
		swap(curr, curr->parent);
		Bubbleup(curr->parent);
	}
}
void minHeap::swap(TNode * a, TNode * b)
{
	TNode temp(a->val);
	a->val = b->val;
	b->val = temp.val;
}
