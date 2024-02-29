#include "queue.h"

void CreateQueue(Queue *pqueue)
{
    pqueue->front = 0;
    pqueue->rear = -1;
    pqueue->size = 0;
}
void Append(QueueEntry element,Queue *pqueue)
{
    /*
    if(pqueue->rear == MAXQUEUE -1)
    {
        pqueue->rear = 0;
    }
    else
    {
        pqueue->rear++;
    }*/
    pqueue->rear = (pqueue->rear + 1) % MAXQUEUE;
    pqueue->entry[pqueue->rear] = element;
    pqueue->size++;
}
void Serve(QueueEntry *pelement, Queue *pqueue)
{
    *pelement = pqueue->entry[pqueue->front];
     /*
    if(pqueue->front == MAXQUEUE -1)
    {
        pqueue->front = 0;
    }
    else
    {
        pqueue->front++;
    }*/
    pqueue->front = (pqueue->front + 1) % MAXQUEUE;
    pqueue->size--;
}
int QueueEmpty(Queue *pqueue)
{
    return !pqueue->size;
}
int QueueFull(Queue *pqueue)
{
    return pqueue->size == MAXQUEUE;
}
int QueueSize(Queue *pqueue)
{
    return pqueue->size;
}
void ClearQueue(Queue *pqueue)
{
    pqueue->front = 0;
    pqueue->rear = -1;
    pqueue->size = 0;
}
void TraverseQueue(Queue *pqueue, void(*PtrFunction)(QueueEntry))
{
   int pos,s;
//    for(pos = pqueue->size,s = 0;s<pqueue->size;s++)
//    {
//     (*PtrFunction)(pqueue->entry[pos]);
//     if(pos == 0)
//     {
//         pos = MAXQUEUE-1;
//     }
//     else
//     {
//         pos--;
//     }
//    }
   for(pos = pqueue->front,s = 0;s<pqueue->size;s++)
   {
    (*PtrFunction)(pqueue->entry[pos]);
    pos = (pos + 1) % MAXQUEUE;
   }
}