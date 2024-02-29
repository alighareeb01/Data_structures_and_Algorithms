#include <stdlib.h>
#include "queue.h"
void CreateQueue(Queue *pqueue)
{
    pqueue->front = NULL;
    pqueue->rear = NULL;
    pqueue->size = 0;
}
void Append(QueueEntry element,Queue *pqueue)
{
    QueueNode *NewNode = (QueueNode *)malloc(sizeof(QueueNode));
    NewNode->entry = element;
    NewNode->next = NULL;
    if(!pqueue->rear)//empty
    {
        pqueue->front = NewNode;
    }
    else
    {
        pqueue->rear->next = NewNode;
    }
    pqueue->rear = NewNode;
    pqueue->size++;
}
void Serve(QueueEntry *pelement, Queue *pqueue)
{
    QueueNode *ptr = pqueue->front;
    *pelement = pqueue->front->entry;
    pqueue->front = pqueue->front->next;
    free(ptr);
    if(pqueue->front == NULL)
    {
        pqueue->rear = NULL;
    }
    pqueue->size--;
}
int QueueEmpty(Queue *pqueue)
{
    return !pqueue->front;
}
int QueueFull(Queue *pqueue)
{
    //never can be full, only if there are no memeory to be allocated
    return 0;
}
int QueueSize(Queue *pqueue)
{
    return pqueue->size;
}
void ClearQueue(Queue *pqueue)
{
    while(pqueue->front)
    {
        pqueue->rear = pqueue->front->next;
        free(pqueue->front);
        pqueue->front = pqueue->rear;
    }
    pqueue->size = 0;
}
void TraverseQueue(Queue *pqueue, void(*PtrFunction)(QueueEntry))
{
    for(QueueNode *pn = pqueue->front;pn;pn=pn->next)
    {
        (*PtrFunction)(pn->entry);
    }
}