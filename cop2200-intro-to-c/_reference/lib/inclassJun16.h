// testcode5.cpp : Defines the entry point for the console application.
//


#include <iostream>

using namespace std;

int MIN(int x, int y)
{
  if(x>y)
  {	  return y;}
  else 
  {	  return x;}
}
int MAX(int x, int y)
{
   int answer = x;
   if (y >x)
   {answer = y;}

   return answer;


}


int MinIndex(int x, int y);
int MaxIndex(int x, int y);
int MIN(int x, int y, int z)
{
	return MIN(x, MIN(y,z));
	//return MIN(MIN(x,y),z);
}


int main()
{
	int x =10, y= 5, z=102;
	cout<<MIN(x,y)<<endl;
	cout<<MAX(x,y)<<endl;
	cout<<MIN(x,y,z)<<endl;
	return 0;
}

