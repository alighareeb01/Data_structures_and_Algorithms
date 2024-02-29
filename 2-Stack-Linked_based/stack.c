#include <stdlib.h>
#include "stack.h"

void CreateStack(Stack *ps)
{
    ps->size = 0;
    ps->Top = NULL;
}
/*
  * Pre Condition: The stack is initialized and not full
  * Post Condition: The element e has been stored at the top of the stack; 
  * and e does not change
  */
void Push(StackEntry e , Stack *ps)
{
    StackNode *NewNode = (StackNode *)malloc(sizeof(StackNode));
    NewNode ->entry = e;
    NewNode->next = ps->Top;
    ps->Top = NewNode;
    ps->size++;
}
void Pop(StackEntry *pe, Stack *ps)
{
    StackNode *pn = ps->Top;
    *pe = ps->Top->entry;
    ps->Top = ps->Top->next; //or ps->Top = pn->next;
    free(pn);
    ps->size--;
}
/*
  *Pre: Stack is initialized.
  *Post: destroy all elements; stack looks initialized.
*/
void ClearStack(Stack *ps)
{
    StackNode *pn = ps->Top;
    
//    while(ps->Top->next)
//    {
//     pn = ps->Top;
// 	ps->Top = ps->Top->next;
//     free(pn);
// 	pn = ps->Top;
//    }
    /*
        OR
    */   
 while (pn)
    {
        pn = pn->next;
        free(ps->Top);
        ps->Top = pn;
    }
    ps->size = 0;
}
int StackEmpty(Stack *ps)
{
    return !ps->Top;
}
int StackFull(Stack *ps)
{
    return 0;
}
/*  
  * Pre: Stack is initialized.
  * Post: returns how many elements exist
*/
int StackSize(Stack *ps)
{
    return ps->size;
}
/*
  * Pre: The stack is initialized and not empty
  * Post: The last element entered is returned
*/
void StackTop(StackEntry *pe,Stack *ps)
{
    *pe = ps->Top->entry;
}
/*
  * Precondition: The stack is Initialized
*/
void TraverseStack(Stack *ps, void(*pf)(StackEntry))
{
    StackNode *pn =ps->Top;
	while(pn)
	{
		(*pf)(pn->entry);
		pn = pn->next;
	}
}
