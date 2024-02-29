#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef enum {
	CLEARSTACK = 1,
	PUSH,POP,SIZE,TOP,TRAVERSE,EXIT
}MagicNumber;

int menu();
void Display(StackEntry e);
int main()
{
	int choose;
	Stack s;
	StackEntry e;
	CreateStack(&s);
	while(1)
	{
		system("cls");
		choose = menu();
		switch(choose)
		{
			case CLEARSTACK :
			system("cls");
			CreateStack(&s);
			system("pause");
			break;
			case PUSH :
			system("cls");
			if(!StackFull(&s))
			{
				printf("Enter : ");
				fflush(stdin);
				scanf("%c",&e);
				Push(e,&s);
				system("pause");
			}
			else
			{
				printf("full\n");
				system("pause");
			}
			break;
			case POP :
			system("cls");
			if(!StackEmpty(&s))
			{
				Pop(&e,&s);
				printf("element is %c\n",e);
				system("pause");
			}
			else
			{
				printf("empty\n");
				system("pause");
			}
			break;
			case SIZE :
			 system("cls");
			 printf("Size is %d\n",StackSize(&s));
			 system("pause");
			break;
			case TOP :
			system("cls");
			if(!StackEmpty(&s))
			{
			StackTop(&e,&s);
			printf("Top is %c\n",e);
			system("pause");
			}
			else
			{
				printf("empty\n");
				system("pause");
			}
			break;
			case TRAVERSE :
			system("cls");
			if(!StackEmpty(&s))
			{
				TraverseStack(&s,&Display);
				system("pause");
			}
			else
			{
				printf("empty\n");
				system("pause");
			}
			break;
			case EXIT :
			exit(0);
			break;
			default :
			break;
		}
	}
	
	
	return 0;
}
int menu()
{
	int choose;
	printf("Choose\n------------\n");
	printf("1- Clear Stack\n");
	printf("2- Push\n");
	printf("3- Pop\n");
	printf("4- Size\n");
	printf("5- Top of Stack\n");
	printf("6- Traverse Stack\n");
	printf("7- Exit\n");
	scanf("%d",&choose);
	return choose;
}
void Display(StackEntry e)
{
	printf("%c\n",e);
}