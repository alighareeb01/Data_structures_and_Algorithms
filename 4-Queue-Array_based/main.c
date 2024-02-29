#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
int menu();
void Display(QueueEntry element);
int main(void)
{
    Queue q;
    CreateQueue(&q);
    QueueEntry MyElement;
    while(1)
    {
        system("cls");
        int choose;
        choose = menu();
        switch (choose)
        {
        case 1:
            ClearQueue(&q);
            system("cls");
            break;
        case 2:
        system("cls");
        if(!QueueFull(&q))
        {
            printf("Enter char : ");
            fflush(stdin);
            scanf("%c",&MyElement);
            Append(MyElement,&q);
        }
        else
        {
            printf("Full Queue");
            system("pause");
        }
        break;
        case 3:
        system("cls");
        if(!QueueEmpty(&q))
        {
            Serve(&MyElement,&q);
            printf("%c",MyElement);
            system("pause");
        } 
        else
        {
            printf("Empty Queue");
            system("pause");
        }
        break;
        case 4:
        system("cls");
        printf("size = %d\n",QueueSize(&q));
        system("pause");
        break;
        case 5 :
        if(!QueueEmpty(&q))
        {
            TraverseQueue(&q,*Display);
            system("pause");
        }
        else
        {
            printf("Empty");
            system("pause");
        }
        break;
        case 6 :
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
    printf("1-Clear\n");
    printf("2-Append\n");
    printf("3-Serve\n");
    printf("4-Size\n");
    printf("5-Traverse\n");
    printf("6-Exit\n");
    scanf("%d",&choose);
    return choose;
}
void Display(QueueEntry element)
{
    printf("%c\t",element);
}
