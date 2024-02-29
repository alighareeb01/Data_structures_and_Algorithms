#define StackEntry char

typedef struct stacknode
{
	StackEntry entry;
	struct stacknode *next;
}StackNode;

typedef struct stack{
	StackNode *Top;
	int size;
}Stack;

void CreateStack(Stack *ps);
/*
  * Pre Condition: The stack is initialized and not full
  * Post Condition: The element e has been stored at the top of the stack; 
  * and e does not change
  */
void Push(StackEntry e , Stack *ps);
void Pop(StackEntry *pe, Stack *ps);
/*
  *Pre: Stack is initialized.
  *Post: destroy all elements; stack looks initialized.
*/
void ClearStack(Stack *ps);
int StackEmpty(Stack *ps);
int StackFull(Stack *ps);
/*  
  * Pre: Stack is initialized.
  * Post: returns how many elements exist
*/
int StackSize(Stack *ps);
/*
  * Pre: The stack is initialized and not empty
  * Post: The last element entered is returned
*/
void StackTop(StackEntry *pe,Stack *ps);
/*
  * Precondition: The stack is Initialized
*/
void TraverseStack(Stack *ps, void(*pf)(StackEntry));




