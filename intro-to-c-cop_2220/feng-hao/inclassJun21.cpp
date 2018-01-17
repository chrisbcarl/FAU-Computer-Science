// Testcode6.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<cmath>
using namespace std;

void test()
{
	int x=0;
//cin>>x;
char y;
cin>>y;
switch(y)
{
case 'A':
case 'a':
	cout<<"A or a"<<endl;
	break;
case 'b':
	cout<<"b"<<endl;
case 'C':
	cout<<"C"<<endl;
	break;
default:
	cout<<"default"<<endl;

}

}



void testwhile1()
{
    int i =0;
    while(i<11)
    {
        cout<<i<<endl;
        i++;
    }
    
}


void testwhile2()
{
    int i =0;
    while(true)
    {
        cout<<i++<<endl;
        if(i>10){
            break;
        }
    }
    
    
}


int number(int n, int x)
{
    int answer =0;
	int i=1;
	while(i <= n)
	{
             answer = answer + pow(i,x);	
			 i++;
	}
	return answer;
}


int main()
{
	int n,x;
cout<<"what is n"<<endl;
	cin>>n;
	cout<<"what is x"<<endl;
	cin>>x;
	cout<<"the answer is "<<number(n,x);


	return 0;
}

