//
//  main.cpp
//  HW7_interesting
//
//  Created by Christopher Carl on 7/28/16.
//  Copyright © 2016 Christopher Carl. All rights reserved.
//

#include <iostream>
#include <time.h>

template<class type_a>
class rand_array{
public:
    rand_array<type_a>();
    ~rand_array<type_a>();
    
    int size();
    void print();
    
    friend bool operator== (const rand_array<type_a>& lhs, const rand_array<type_a>& rhs);
    friend std::ostream& operator<< (std::ostream& stream, const rand_array<type_a>& array);
private:
    type_a *pointer;
    int count;
};


template<class type_a>
rand_array<type_a>::rand_array()
{
    count = rand() % 10 + 1;
    pointer = new type_a[count];
    for (int i = 0; i < count; i++) {
        pointer[i] = rand() % 57 + 48;
    }
};


template<>
rand_array<char>::rand_array()
{
    count = rand() % 10 + 1;
    pointer = new char[count];
    for (int i = 0; i < count; i++) {
        pointer[i] = rand() % 99 + 97;
    }
};

template<>
rand_array<int>::rand_array()
{
    count = rand() % 10 + 1;
    pointer = new int[count];
    for (int i = 0; i < count; i++) {
        pointer[i] = rand() % 3 + 1;
    }
};


template<class type_a>
rand_array<type_a>::~rand_array()
{
    delete[] pointer;
};



template<class type_a>
int rand_array<type_a>::size()
{
    return count;
}

template<class type_a>
void rand_array<type_a>::print()
{
    std::cout << "[ ";
    for (int i = 0; i < count; i++) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

template<class class_a>
bool operator==(const rand_array<class_a>& lhs, const rand_array<class_a>& rhs)
{
    if (lhs.size() != rhs.size()) return false;
    for (int i = 0; i < lhs.size(); i++)
        if (lhs[i] != rhs[i]) return false;
    return true;
}

template<class class_a>
std::ostream& operator<< (std::ostream& stream, const rand_array<class_a>& array)
{
    stream << "[ ";
    for (int i = 0; i < array.size(); i++) {
        stream << i << " ";
    }
    stream << "]";
    return stream;
}


int main(int argc, const char * argv[]) {
    
    srand (unsigned(time(NULL)));
    
    rand_array<int> a;
    //std::cout << a;
    a.print();
    
    
    rand_array<int> b;
    b.print();
    
    
    rand_array<int> c;
    c.print();
    
    
    rand_array<int> a2;
    //std::cout << a;
    a.print();
    
    
    rand_array<int> b2;
    b.print();
    
    
    rand_array<int> c2;
    c.print();
    
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
