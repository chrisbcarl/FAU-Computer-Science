//
//  main.cpp
//  testCode3
//
//  Created by Feng-Hao Liu on 6/9/16.
//  Copyright © 2016 Feng-Hao Liu. All rights reserved.
//

#include<iostream>
using namespace std;

//#define pi 3.14

const double pi = 3.1415;

void function1(int x, int y)
{
    //cout << pi<<endl;
    int z;
    x= 10;
    y=20;
    z= 100;
    cout<<x<<" " <<y <<endl;
}
void function2()
{
    int x= 100;
    x= x+1;
    cout<<x<<endl;
}

void testswap(int x, int y)
{
    int emptybasket;
    cout<<x<<" " <<y <<endl;
    emptybasket = x;
    x=y;
    y= emptybasket;
    cout<<x<<" " <<y <<endl;
}
int main()
{
    int x=10, y=20, z =30;
    int emptybasket;
    cout<<x<<" " <<y <<endl;
    testswap(x,y);
    /*emptybasket = x;
     x=y;
     y= emptybasket;*/
    cout<<x<<" " <<y <<endl;
    
    //cout<<x<<" " <<y <<endl;
    //function1(y,x);
    //cout<<x<<" " <<y <<endl;
    
    return 0;
}
