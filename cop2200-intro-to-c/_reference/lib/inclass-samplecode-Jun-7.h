//
//  inclass-samplecode-Jun-7.cpp
//  testcode2
//
//  Created by Feng-Hao Liu on 6/7/16.
//  Copyright © 2016 Feng-Hao Liu. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

double carea(int r)
{
    double pi = 3.1415;
    return pi* r * r;
}

void printcareas(int a, int b, int c)
{
    cout<<"Area 1 : " <<carea(a)<<endl;
    cout<<"Area 2 : " <<carea(b)- carea(a)<<endl;
    cout<<"Area 3 : " <<carea(c) - carea(b)<<endl;


}

int main()
{

    cout<<"Enter three integers as r1 r2 r3"<<endl;
    int r1,r2,r3;
    cin>>r1>>r2>>r3;
    printcareas(r1,r2,r3);
    return 0;
}