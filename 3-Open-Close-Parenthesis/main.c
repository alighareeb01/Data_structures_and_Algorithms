#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"


char str[10];
StackEntry e;
Stack MyStack;

void String_Flushing();
void Matching(char str[]);

int main(void)
{
	CreateStack(&MyStack);
	String_Flushing();
	Matching(str);	
}

void String_Flushing()
{
	printf("Enter String : ");
	fflush(stdin);
	char ch = 0;
	unsigned char i = 0;
	while(1)
	{
		scanf("%c",&ch);
		if(ch == '\n')
			break;
		str[i++] = ch;	
	}
	str[i]='\0';
	int len = strlen(str);
	// for(int i = 0;i <= len; i++)
	// {
	// 	printf("%c",str[i]);
	// }
}
void Matching(char str[])
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            Push(str[i], &MyStack);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (StackEmpty(&MyStack))
            {
                printf("Invalid\n");
                return;
            }
            else
            {
                StackTop(&e, &MyStack); 
                if ((e == '(' && str[i] == ')') || (e == '{' && str[i] == '}') || (e == '[' && str[i] == ']'))
                {
                    Pop(&e, &MyStack);
                }
                else
                {
                    printf("Invalid\n");
                    return;
                }
            }
        }
    }

    if (!StackEmpty(&MyStack))
    {
        printf("Invalid\n");
    }
    else
    {
        printf("Valid\n");
    }
}
