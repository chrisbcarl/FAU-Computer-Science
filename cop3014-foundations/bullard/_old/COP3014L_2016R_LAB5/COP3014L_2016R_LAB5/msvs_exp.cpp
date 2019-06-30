#include <iostream>
#include <string>
using namespace std;

void msvs_exp_pr_message(string s)
{
	cout << s << endl;
}

int msvs_exp()
{
	int x = 1, y = 1;
	msvs_exp_pr_message("Hello world!");
	x++;
	y = x;
	msvs_exp_pr_message("Hmm, what to do next?");
	// Later on, un-comment out the following line, run it without
	//  the debugger, and then choose to debug when it crashes.
	//  A new VC++ debugger sessions starts.
	x = y / x;  // divide by zero run-time error!
	msvs_exp_pr_message("Ooh, that was close!");
	x = 7;
	msvs_exp_pr_message("OK, let's quit.");
	return 0;
}


