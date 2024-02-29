#include "list.h"
#include <stdlib.h>

void CreateList(List *pl)
{
    pl->size = 0;
    pl->current = NULL;
    pl->currentpos = 0;
    pl->head = NULL;
}
void InsertList(int pos, ListEntry e, List *pl)
{
    ListNode *NewNode = (ListNode *)malloc(sizeof(ListNode));
    NewNode->entry = e;
    if(pos == 0)
    {
        NewNode->next = pl->head;
        pl->head = NewNode;
        pl->current = pl->head;
        pl->currentpos = 0;
    }
    else
    {
        if(pos <= pl->currentpos)
        {
            pl->current = pl->head;
            pl->currentpos = 0;
        }
        for(;pl->currentpos != pos - 1;pl->currentpos++)
        {
            pl->current = pl->current->next;
        }
        NewNode->next = pl->current->next;
        pl->current->next = NewNode;
    }
    pl->size++;
}
void DeleteList(int pos, ListEntry *pe, List *pl)
{
    ListNode *temp;
    if(pos == 0)
    {
        *pe = pl->head->entry;
        pl->current = pl->head->next;
        free(pl->head);
        pl->head = pl->current;
        pl->currentpos = 0;
    }
    else
    {
        if(pos <= pl->currentpos)
        {
            pl->current = pl->head;
            pl->currentpos = 0;
        }
        for(;pl->currentpos != pos -1; pl->currentpos++)
        {
            pl->current =pl->current->next;
        }
        *pe = pl->current->next->entry;
        temp = pl->current->next->next;
        free(pl->current->next);
        pl->current->next = temp; 
    }
    pl->size--;
}
int ListEmpty(List *pl)
{
    return pl->size == 0;
}
int ListFull(List *pl)
{
    return 0;
}
int ListSize(List *pl)
{
    return pl->size;
}
void DestroyList(List *pl)
{
    while(pl->head)
    {
        pl->current = pl->head->next;
        free(pl->head);
        pl->head = pl->current;
    }
    pl->size = 0;
}
void ReplaceList(int pos, ListEntry e,List *pl)
{
    if(pos <= pl->currentpos)
    {
        pl->current = pl->head;
        pl->currentpos = 0;
    }
    for(;pl->currentpos != pos-1;pl->currentpos++)
    {
        pl->current = pl->current->next;
    }
    pl->current->next->entry = e;
}
void RetrieveList(int pos, ListEntry *pe,List *pl)
{
     if(pos <= pl->currentpos)
    {
        pl->current = pl->head;
        pl->currentpos = 0;
    }
    for(;pl->currentpos != pos-1;pl->currentpos++)
    {
        pl->current = pl->current->next;
    }
    *pe = pl->current->next->entry;
}
void TraverseList(List *pl, void(* PtrToFunc)(ListEntry e))
{
    pl->current = pl->head;
    pl->currentpos = 0;
    while(pl->current)
    {
        (*PtrToFunc)(pl->current->entry);
        pl->current = pl->current->next;
        pl->currentpos++;
    }
}