#include <iostream>
#include <time.h>
using namespace std;

void iterative_countdown(int count)
{
	while (count != 0)							// O(n) = 1
	{
		cout << "count=" << count << endl;;		// O(n) = 1
		--count;								// O(n) = 1
	} 
	cout << "count=" << count << endl;			// O(n) = 1
}
//for count = 2, O(n) = 10

void recursive_countdown(int count)
{
	if (count == 0)								// O(n) = 1
		cout << "count=" << count << endl;		// O(n) = 1
	else
	{
		cout << "count=" << count << endl;		// O(n) = 1
		recursive_countdown(--count);			// O(n) = ?
	}
}
//for count = 2, O(n) = 7


int main(void)
{
	int count = 1000;


	clock_t start;
	double diff1;
	double diff2;
	
	start = clock();
	recursive_countdown(count);
	diff1 = (clock() - start) / (double)CLOCKS_PER_SEC;

	start = clock();
	iterative_countdown(count);
	diff2 = (clock() - start) / (double)CLOCKS_PER_SEC;

	cout << "diff1: " << diff1 << '\n';
	cout << "diff2: " << diff2 << '\n';

	return 0;
}
