#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main()
{

	QUEUE Q;

	//Q.deQueue();

	Q.enQueue("1 hello world");
	Q.enQueue("2 good_bye_world");
	Q.enQueue("3 jurrasic_world");
	Q.enQueue("4 fish_world");
	Q.enQueue("5 water_world");
	Q.Print();
	//cout<<Q.Front()<<endl;
	Q.deQueue();
	cout<<endl<<endl;
	Q.Print_Reverse();
	//cout<<Q.Front()<<endl;
	Q.deQueue();
	Q.deQueue();
	cout<<endl<<endl;
	Q.Print_Reverse();

	return 0;
}
