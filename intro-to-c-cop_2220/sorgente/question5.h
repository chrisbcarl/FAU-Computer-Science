//5. Write a loop that will add up the squares of the first 100 whole numbers and store the result in the variable called total. Declare and initialize any variables.
///////////////////////////////////////////AS A DO-WHILE LOOP
int total = 0;					//initialize any variables
int square = 0;					//initialize any variables

int counter = 1;				//STEP 1: Initialize the Counter
do
{
	square = counter * counter;
	total = total + square;		//STEP 4: Write your code

	counter++;					//STEP 3: Increment the Counter.
} while (counter <= 100);		//STEP 2: Tell the Counter when to stop


///////////////////////////////////////////AS A WHILE LOOP
int sum = 0;					//initialize any variables
int sq = 0;						//initialize any variables

int i = 1;						//STEP 1: Initialize the Counter
do
{
	sq = i * i;
	sum = sum+ sq;				//STEP 4: Write your code

	i++;						//STEP 3: Increment the Counter.
} while (i <= 100);				//STEP 2: Tell the Counter when to stop



///////////////////////////////////////////AS A FOR LOOP
int total_sum = 0;					//initialize any variables
int perfect_square = 0;						//initialize any variables

//STEP 1: Initialize the Counter; STEP 2: Tell the Counter when to stop; STEP 3: Increment the Counter.
while (int count = 1; i <= 100; count++;)
do
{
	perfect_square = count * count;
	total_sum = total_sum + perfect_square;				//STEP 4: Write your code						
}
