#include <iostream>

using namespace std;


class Item
{
public:
       int val;
    Item *next, *pre;
    Item()
    {
        val =0;
        next=0;
        pre=0;
        
        
    }
    Item(int val)
    {
        this->val = val;
        next=0;
        pre=0;
    }

};


class DLinkedList
{
    
    int size;
    Item *front;
    Item *back;
    
public:
    
    DLinkedList();
    DLinkedList(const DLinkedList &list);

    void push_back(Item *a);
    void push_front(Item *a);
    
    Item * pop_front();
    Item * pop_back();
    
    void insert(Item *a, int t); // insert the item a after the t-th element
    void insertlist(DLinkedList *list, int t); // insert the whole list a after the t-th element
    void display(ostream &out);
    
    int getSize();
    Item * getfront();
    Item * getback();
    void swap(Item *p, Item *q); //swap two items pointed by p and q, you can assume that p and q are something in the list
    
    Item * extractmin(Item * start); // return the pointer of the min element after  "start",
                                     // here you can assume user will always input a valid pointer start that points to an item in the list
    Item * extractmax(Item * start);  // return the pointer of the max element after "start"
    
    
};


class myStack
{
    DLinkedList list;
public:
    myStack();
    int getSize();
    void in(Item *a);
    Item *top();
    void out();

};

class myQueue
{
    DLinkedList list;
public:
    myQueue();
    int getSize();
    void in(Item *a);
    Item *front();
    void out();
};






  int main() {
  return 0;
 }












 

