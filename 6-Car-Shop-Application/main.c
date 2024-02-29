#include <stdio.h>
#include <stdlib.h>

#include "global.h"
#include "queue.h"
#include "stack.h"

Queue MyQueue;
Stack MyStack;
Queue NewQueue;

void StringFlushing(char *string);
void Display(Information CurrCustomer);
void StackDisplay(Information cust);
int menu(void);


int main()
{
	
	Information Customer;
	CreateQueue(&MyQueue);
	CreateStack(&MyStack);
	int choose;
	while (1)
	{
		system("cls");
		choose = menu();
		switch (choose)
		{
		case 1:
			system("cls");
			if (QueueFull(&MyQueue))
			{
				printf("Queue is Full.\n");
			}
			else
			{
				printf("Enter Customer name : ");
				StringFlushing(Customer.name);
				printf("\nEnter ID : ");
				fflush(stdin);
				scanf("%d", &Customer.ID);
				printf("\nEnter Model Year: ");
				fflush(stdin);
				scanf("%d", &Customer.Model_Year);
				Append(Customer,&MyQueue);
			}
			break;
		case 2:
		system("cls");
			if(QueueEmpty(&MyQueue))
			{
				printf("Queue is Empty.\n");
				system("pause");
			}
			else
			{
				Serve(&Customer,&MyQueue);
				printf("Customer ID is %s\n",Customer.name);
				printf("Customer ID is %d\n",Customer.ID);
				printf("Customer Model Year is %d\n",Customer.Model_Year);
				system("pause");
			}
			break;
		case 3:
			printf("Number of Waiting Customer is %d\n",QueueSize(&MyQueue));
			system("pause");
			break;
		case 4:
		
		CreateQueue(&NewQueue);
			if(QueueEmpty(&MyQueue))
			{
				printf("There are no customers waiting");
			}
			else
			{
				CopyQueue(&MyQueue,&NewQueue);
				TraverseQueue(&NewQueue,&Display);
				system("pause");
			}
			break;
		case 5:
		system("cls");
		TraverseQueue(&MyQueue,&StackDisplay);
		TraverseStack(&MyStack,&Display);
		system("pause");
			break;
		case 6:
		printf("Shutting System Down.....");
		exit(0);
			break;

		default:
			break;
		}
	}
}

void StringFlushing(char *string)
{
	fflush(stdin);
	char ch = 0;
	unsigned char i = 0;
	while (1)
	{
		scanf("%c", &ch);
		if (ch == '\n')
			break;
		string[i++] = ch;
	}
	string[i] = '\0';
}
int menu(void)
{
	int choose;
	printf("---------\n");
	printf("1. Add new Customer\n2. Serve a Customer.\n3. How many Customers are waiting\n");
	printf("4. Display Customers Information\n5. Display Customers information in a most-recent Order\n6. Exit\n");
	printf("Choose : ");
	scanf("%d", &choose);
	return choose;
}
void Display(Information CurrCustomer)
{
	printf("Customer Info\n--------------\n");
	printf("Customer Name is %s\n",CurrCustomer.name);
	printf("Customer ID is %d\n",CurrCustomer.ID);
	printf("Customer Model Year is %d\n",CurrCustomer.Model_Year);
	printf("Customer Info\n--------------\n");
}
void StackDisplay(Information cust)
{
	Push(cust,&MyStack);
}
