//4. Write a set of statements to perform the following steps: When the variable fruit contains the character uppercase P, increase the value in the integer variable papaya by one. When fruit contains the character uppercase G, increase the value in the integer variable guava by one. When fruit contains anything else, increase the value of the integer variable bananas by one.
char fruit = '_';
int guava = 0;
int papaya = 0;
int bananas = 0;
	
if (fruit == 'P')		//When the variable fruit contains the character uppercase P, increase the value in the integer variable papaya by one. 
{
	papaya++;
}
else if (fruit == 'G')	//When fruit contains the character uppercase G, increase the value in the integer variable guava by one. 
{
	guava = guava + 1;
}
else					//When fruit contains anything else, increase the value of the integer variable bananas by one.
{
	bananas = bananas + 1;
}