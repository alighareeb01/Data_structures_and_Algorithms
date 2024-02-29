#define ListEntry char


typedef struct listnode{
    ListEntry entry;
    struct listnode *next;
}ListNode;

typedef struct list
{
    ListNode *head;
    ListNode *current;
    int size;
    int currentpos;
}List;

void CreateList(List *pl);
void InsertList(int pos, ListEntry e, List *pl);
void DeleteList(int pos, ListEntry *pe, List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void ReplaceList(int pos, ListEntry e,List *pl);
void RetrieveList(int pos, ListEntry *pe,List *pl);
void TraverseList(List *pl, void(* PtrToFunc)(ListEntry e));