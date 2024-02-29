#include "stack.h"

void CreateStack(Stack *ps)
{
    ps->top = 0;
    ps->size = 0;
}
/*
  * Pre Condition: The stack is initialized and not full
  * Post Condition: The element e has been stored at the top of the stack; 
  * and e does not change
*/
void Push(StackEntry e , Stack *ps)
{
    ps->entry[ps->top] = e;
    ps->top++;
    ps->size++;
}
/*
  * Pre: The stack is initialized and not empty
  * Post: The last element entered is returned
*/
void Pop(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[--ps->top];
    ps->size--;
}
/*
  *Pre: Stack is initialized.
  *Post: destroy all elements; stack looks initialized.
*/
void ClearStack(Stack *ps)
{
    ps->top = 0;
    ps->size = 0;
}
int StackEmpty(Stack *ps)
{
   // return !ps->top;
    //or
    return !ps->size;
}
int StackFull(Stack *ps)
{
    return ps->top == MAXSTACK;
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
    *pe = ps->entry[ps->top - 1];
}
void CopyStack(Stack *psrc,Stack *pdes)
{
    for(int i = 0; i < psrc->top;i++)
    {
        pdes->entry[i] = psrc->entry[i];
    }
}
/*
  * Precondition: The stack is Initialized
*/
void TraverseStack(Stack *ps, void(*pf)(StackEntry))
{
    for(int i = ps->top;i>=0;i--){
       (*pf)(ps->entry[i-1]); 
    }
}


