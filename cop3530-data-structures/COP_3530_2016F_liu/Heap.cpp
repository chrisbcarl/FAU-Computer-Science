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
    int size;
    TNode *top;
    
public:
    minHeap();
    minHeap(const minHeap &h);
    void in(const TNode &t);// you should new a new node and then add into the heap
    void removemin();
    Node* getmin();
    void Heapify(const int n, const int *p);// p is an array of size n, representing a (full) binray tree of size n. You should not modify the array p

    
};





int * HeapSort(const int n, const int *arr);// arr is an integer array of numbers.
                                            //You should output a pointer to a new array which is a sorted version of arr

void Test()
{

}

int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}


