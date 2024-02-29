#define QueueEntry char
#define MAXQUEUE 50
typedef struct queue{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
}Queue;
void CreateQueue(Queue *pqueue);
void Append(QueueEntry element,Queue *pqueue);
void Serve(QueueEntry *pelement, Queue *pqueue);
int QueueEmpty(Queue *pqueue);
int QueueFull(Queue *pqueue);
int QueueSize(Queue *pqueue);
void ClearQueue(Queue *pqueue);
void TraverseQueue(Queue *pqueue, void(*PtrFunction)(QueueEntry));