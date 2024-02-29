#define QueueEntry char

typedef struct queuenode{
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;

typedef struct queue
{
    QueueNode *front;
    QueueNode *rear;
    int size;
}Queue;

void CreateQueue(Queue *pqueue);
void Append(QueueEntry element,Queue *pqueue);
void Serve(QueueEntry *pelement, Queue *pqueue);
int QueueEmpty(Queue *pqueue);
int QueueFull(Queue *pqueue);
int QueueSize(Queue *pqueue);
void ClearQueue(Queue *pqueue);
void TraverseQueue(Queue *pqueue, void(*PtrFunction)(QueueEntry));