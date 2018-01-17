#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 255

typedef struct 
{
	char name[SIZE];
	char manufacturer[SIZE];
	char description[SIZE];
	int id;
	double cost;

} Product;

void hardcode(Product inventory[],int * total);
void print_inventory(Product inventory[], int total);
Product new_product();
void edit_product(Product * product);
void delete_product(Product inventory[], int id, int * total);
void options(char * selection);
void app(char selection, Product inventory[], int total);

int main()
{
	char selection;
	int total;
	Product inventory[SIZE];
	hardcode(inventory, &total);
	
	do
	{
		options(&selection);
		app(selection, inventory, total);

	} while (selection != 'Q');

	return 0;
}

void hardcode(Product inventory[], int * total)
{
	Product a = {	"Echo Dot(2nd Generation) - Black", 
					"Amazon, LLC", 
					"Echo Dot (2nd Generation) is a hands-free, voice-controlled device that uses Alexa to play music, control smart home devices, provide information, read the news, set alarms, read audiobooks from Audible, and more", 
					0, 
					49.99 
				};
	Product b = {	"Kindle Oasis E-reader with Leather Charging Cover - Black, 6' High - Resolution Display(300 ppi), Wi - Fi - Includes Special Offers", 
					"Amazon, LLC",
					"Our thinnest and lightest Kindle ever--read even more comfortably for hours. \nAll - new ergonomic design with dedicated buttons to effortlessly turn the page",
					1,
					289.99
				};
	inventory[0] = a;
	inventory[1] = b;
	*total = 2;
}
void print_inventory(Product inventory[], int total)
{
	for (int i = 0; i < total; i++)
	{
		printf("%s\n", inventory[1].name);
		printf("%s\n", inventory[1].manufacturer);
		printf("%s\n", inventory[1].description);
		printf("ID: #%d\n", inventory[1].id);
		printf("Cost: $%0.2lf\n", inventory[1].cost);
		printf("\n");
	}

	printf("\n\n");
}
Product new_product()
{
	Product a;
	printf("---NEW PRODUCT---\n");
	printf("Name: ");
	scanf(" %s", a.name);
	
	printf("Manufacturer: ");
	scanf(" %s", a.manufacturer);
	
	printf("Description: ");
	scanf(" %s", a.description);

	printf("ID: #");
	scanf(" %d", &a.id);

	printf("Cost: $");
	scanf(" %lf", &a.cost);

	printf("\n\n");
	return a;
}
void edit_product(Product * product)
{
	printf("---EDIT PRODUCT---\n");
	printf("---ORIGINAL PRODUCT---\n");
	printf("%s\n", product->name);
	printf("%s\n", product->manufacturer);
	printf("%s\n", product->description);
	printf("ID: #%d\n", product->id);
	printf("Cost: $%0.2lf\n", product->cost);

	printf("---NEW PRODUCT---\n");
	printf("Name: ");
	scanf(" %s", product->name);

	printf("Manufacturer: ");
	scanf(" %s", product->manufacturer);

	printf("Description: ");
	scanf(" %s", product->description);

	printf("ID: #");
	scanf(" %d", &product->id);

	printf("Cost: $");
	scanf(" %lf", &product->cost);

	printf("\n\n");
}

void delete_product(Product inventory[], int id, int * total)
{
	for (int i = id; i < *total - 1; i++)
	{
		inventory[i] = inventory[i + 1];
	}
	*total = *total - 1;
}

void options(char * selection)
{
	printf("P - print\n");
	printf("E - edit\n");
	printf("D - delete\n");
	printf("A - add\n");
	printf("selection: ");
	scanf(" %c", selection);
	*selection = toupper(*selection);

	printf("\n\n");
}

void app(char selection, Product inventory[], int total)
{
	int id;
	switch (selection)
	{
	case 'P':
		print_inventory(inventory, total);
		break;
	case 'E':
		printf("which product? ");
		scanf(" %d", &id);
		edit_product(&inventory[id]);
		break;
	case 'D':
		printf("which product? ");
		scanf(" %d", &id);
		delete_product(inventory, id, &total);
		break;
	case 'A':
		inventory[total] = new_product();
		total = total + 1;
		break;
	default:
		printf("quitting.\n");
		break;
	}
	printf("\n\n");
}