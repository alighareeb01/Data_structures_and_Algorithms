#include <stdio.h>
#include<stdlib.h>
#include"queue.h"

int menu(void);
void Display(QueueEntry);
int main()
{
    Queue NewQue;
    QueueEntry element;
    int choose;
    CreateQueue(&NewQue);
    while(1)
    {
        system("cls");
        choose = menu();
        switch (choose)
        {
            case 1:
            ClearQueue(&NewQue);
            break;
            case 2:
            system("cls");
            if(!QueueFull(&NewQue))
            {
            printf("Enter element\n");
            fflush(stdin);
            scanf("%c",&element);
            Append(element,&NewQue);
            }
            else{
                printf("Full quue\n");
            }
            break;
            case 3:
            system("cls");
            if(!QueueEmpty(&NewQue))
            {
                Serve(&element,&NewQue);
                printf("element is %c\n",element);
                system("pause");
            }   
            else{
                printf("Qeueue is emoty\n");
            }
            break;
            case 4:
            system("cls");
            printf("size  is %d\n\n",QueueSize(&NewQue));
            system("pause");
            break;
            case 5 :
            if(!QueueEmpty(&NewQue))
            {
                TraverseQueue(&NewQue,&Display);
                system("pause");
            }
            else
            {
                printf("Empty queue\n");
                system("pause");

            }
            break;
            case 6:
            exit(0);
            break;
            default : 
            exit(0);
            break;
        }
    }
}
int menu(void)
{
    int choose;
    printf("Choose btn 1 and 6\n");
    printf("1-Clear\n2-Append new element\n3-Serve\n");
    printf("4-Size\n5-Traverse\n6-Exit");
    scanf("%d",&choose);
    return choose;
}
void Display(QueueEntry element)
{
    printf("%c\n",element);
}