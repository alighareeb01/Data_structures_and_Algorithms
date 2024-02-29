#include "list.h"

void CreateList(List *pl)
{
    pl->size = 0;
}
void InsertList(int pos, ListEntry e, List *pl)
{
    for(int i = pl->size - 1; i >= pos; i--)
    {
        pl->entry[i + 1] = pl->entry[i];
    }
    pl->entry[pos] = e;
    pl->size++;
}
void DeleteList(int pos, ListEntry *pe, List *pl)
{
    *pe = pl->entry[pos];
    for (int i = pos + 1; i <= pl->size - 1; i++)
    {
        pl->entry[i - 1] = pl->entry[i]; 
    }
    pl->size--;
}
int ListEmpty(List *pl)
{
    return !pl->size;
}
int ListFull(List *pl)
{
    return pl->size == MaxList;
}
int ListSize(List *pl)
{
    return pl->size;
}
void DestroyList(List *pl)
{
    pl->size = 0;
}
void ReplaceList(int pos, ListEntry e,List *pl)
{
    pl->entry[pos] = e;
}
void RetrieveList(int pos, ListEntry *pe,List *pl)
{
    *pe  = pl->entry[pos];
}
void TraverseList(List *pl, void(* PtrToFunc)(ListEntry e))
{
    for(int i = 0; i <= pl->size - 1;i++)
    {
        (*PtrToFunc)(pl->entry[i]);
    }
}