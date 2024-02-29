#define StackEntry char

typedef struct stacknode
{
	StackEntry entry;
	struct stacknode *next;
}StackNode;

typedef struct stack{
	StackNode *top;
	int size;
}Stack;

void CreateStack(Stack *);
void Push(StackEntry, Stack *);
void Pop(StackEntry *, Stack *);
void ClearStack(Stack *);
int StackEmpty(Stack *);
int StackFull(Stack *);
int StackSize(Stack *);
void StackTop(StackEntry *, Stack *);
void TraverseStack(Stack *, void(*pf)(StackEntry));

