//6. Write a function called Product.The function will prompt the user to enter integers one by one and calculate the product of all the numbers entered, until the user enters a zero to stop.The function will return the product of all the numbers entered.Declare and initialize any variables needed.

void Product()
{
	int product = 1;			//initialize any variables needed
	int user_input = 1;			//initialize any variables needed
	do
	{
		printf("Enter a product: ");
		scanf(" %d", &user_input);
		if (user_input != 0)
		{
			product = user_input * product;
		}
		else
		{

		}
	} while (user_input != 0);
	printf("Product = %d", product);
}