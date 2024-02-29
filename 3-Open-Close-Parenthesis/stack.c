#include "stack.h"
#include <stdlib.h>
void CreateStack(Stack *ps)
{
	ps->top = NULL;
	ps->size = 0; 
}
void Push(StackEntry e, Stack *ps)
{
	StackNode *NewNode = (StackNode *)malloc(sizeof(StackNode));
	NewNode->entry = e;
	NewNode->next = ps->top;
	ps->top = NewNode;
	ps->size++;
}
void Pop(StackEntry *pe, Stack *ps)
{
	StackNode *pn = ps->top;
	*pe = ps->top->entry;
	ps->top = ps->top->next;
	free(pn);
	ps->size--;
}
void ClearStack(Stack *ps)
{
	StackNode *pn = ps->top;
	while(pn != NULL)
	{
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
	ps->size = 0;
}
int StackEmpty(Stack *ps)
{
	return !ps->top;
}
int StackFull(Stack *ps)
{
	return 0;
}
int StackSize(Stack *ps)
{
	return ps->size;
}
void StackTop(StackEntry *pe, Stack *ps)
{
	*pe = ps->top->entry;
}
void TraverseStack(Stack *ps, void(*pf)(StackEntry))
{
	StackNode *pn = ps->top;
	while(pn)
	{
		(*pf)(pn->entry);
		pn = pn->next;
	}
}

