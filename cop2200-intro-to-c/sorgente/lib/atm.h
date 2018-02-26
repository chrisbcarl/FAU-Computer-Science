#ifndef SORGENTE_ATM
#define SORGENTE_ATM

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Welcome();											//step 1
void Again(char *choicePtr);
void SelectTransaction(int* transaction_choice);		//step 2
void SelectAccount(int* account_choice);				//step 3
void AmountMoney(double* money);						//step 4
void Withdraw(double* money, double* account);			//step 5
void Deposit(double* money, double* account);			//step 5
void Transfer(double* money, double* account1, double* account2);//step 5
void Goodbye();											//step 6

void atm()
{
	int transaction_choice;
    char repeat;
    int account_choice, account_choice2;
	double money, checking = 0, savings = 0, credit = 0;

	Welcome();
	do
	{
      SelectTransaction(&transaction_choice);
      SelectAccount(&account_choice);
      switch (transaction_choice)
      {
        // balance
        case 1:
          switch (account_choice)
          {
            case 1:
              printf("Your checking account balance is: $%0.2f\n\n", checking);
              break;
            case 2:
              printf("Your savings account balance is: $%0.2f\n\n", savings);
              break;
            case 3:
              printf("Your credit account balance is: $%0.2f\n\n", credit);
              break;
            default:
              break;
          }
          break;
        // withdraw
        case 2:
          AmountMoney(&money);
          switch (account_choice)
          {
          case 1:
            Deposit(&money, &checking);
            break;
          case 2:
            Deposit(&money, &savings);
            break;
          case 3:
            Deposit(&money, &credit);
            break;
          default:
            break;
          }
          break;
        // withrdaw
        case 3:
          AmountMoney(&money);
          switch (account_choice)
          {
          case 1:
            Withdraw(&money, &checking);
            break;
          case 2:
            Withdraw(&money, &savings);
            break;
          case 3:
            Withdraw(&money, &credit);
            break;
          default:
            break;
          }
          break;
        // transfer
        case 4:
          printf("\nTransfer to which other account?");
          SelectAccount(&account_choice2);
          AmountMoney(&money);
          switch (account_choice)
          {
          case 1:
            switch (account_choice2)
            {
              case 1:
                Transfer(&money, &checking, &checking);
                break;
              case 2:
                Transfer(&money, &checking, &savings);
                break;
              case 3:
                Transfer(&money, &checking, &credit);
                break;
              default:
                break;
            }
            break;
          case 2:
            switch (account_choice2)
            {
            case 1:
              Transfer(&money, &savings, &checking);
              break;
            case 2:
              Transfer(&money, &savings, &savings);
              break;
            case 3:
              Transfer(&money, &savings, &credit);
              break;
            default:
              break;
            }
            break;
          case 3:
            switch (account_choice2)
            {
            case 1:
              Transfer(&money, &credit, &checking);
              break;
            case 2:
              Transfer(&money, &credit, &savings);
              break;
            case 3:
              Transfer(&money, &credit, &credit);
              break;
            default:
              break;
            }
            break;
          default:
            break;
          }
          break;
        default:
          break;
      }

      Again(&repeat);
	} while (repeat == 'y' || repeat == 'Y');
	//logical contradiction true while (repeat != 'n' && repeat != 'N');
	//logical assertion true while (repeat == 'y' || repeat == 'Y');
	Goodbye();
}
void Welcome()
{
	printf("Hello, welcomme to ATM!\n");
}

void Again(char * choicePtr)
{
	printf("Would you like to go again? ");
	scanf(" %c", choicePtr);
}

void SelectTransaction(int* transaction_choice)
{
  printf("\n---TRANSACTION MENU---\n");
  printf("1) Balance\n");
  printf("2) Deposit\n");
  printf("3) Withdraw\n");
  printf("4) Transfer\n");
  printf("0) EXIT\n\n");

  printf("What transaction would you like to make? ");
  scanf(" %d", transaction_choice);
  while (*transaction_choice < 4 && *transaction_choice < 0) {
    printf("Invalid selection!\nWhat transaction would you like to make? ");
    scanf(" %d", transaction_choice);
  }
}

void SelectAccount(int* account_choice)
{
  printf("\n---ACCOUNT MENU---\n");
  printf("1) Checking\n");
  printf("2) Savings\n");
  printf("3) Credit\n");

  printf("What account would you like to chose? ");
  scanf(" %d", account_choice);
  while (*account_choice < 2 && *account_choice < 1) {
    printf("Invalid selection!\nWhat account would you like to chose? ");
    scanf(" %d", account_choice);
  }
}

void AmountMoney(double* money)
{
  printf("How much? $");
  scanf(" %lf", money);
  while (*money < 0.01) {
    printf("Must enter actual monetary value!\nHow much? $");
    scanf(" %lf", money);
  }
}

void Withdraw(double* money, double* account)
{
  if (*account - *money > 0) {
    *account -= *money;
    printf("Money withdrawn.\n\n");
  } 
  else {
    printf("Funds are not available to withdraw so much!\n");
  }
  printf("Your account balance is: $%0.2f\n\n", *account);
}

void Deposit(double* money, double* account)
{
  *account += *money;
  printf("Money deposited.\n");
  printf("Your account balance is: $%0.2f\n\n", *account);
}

void Transfer(double* money, double* account1, double* account2)
{
  if (*account1 - *money > 0) {
    *account1 -= *money;
    *account2 += *money;
    printf("Money transferred.\n");
  }
  else {
    printf("Funds are not available to transfer so much!\n");
  }
  printf("Your first account balance is : $%0.2f, and your second account balance is : $%0.2f\n\n", *account1, *account2);
}

void Goodbye()
{
	printf("Goodbye world!\n");
}

#endif