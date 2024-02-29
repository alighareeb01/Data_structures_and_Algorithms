#include <stdio.h>
#include "list.h"

// Function to display an integer
void DisplayInt(ListEntry e) {
    printf("%d ", e);
}

int main() {
   List MyList;
   CreateList(&MyList);
    ListEntry elemnt;
    InsertList(0,10,&MyList);
    InsertList(1,20.,&MyList);
    InsertList(2,30,&MyList);
    printf("List elemnt ");
    TraverseList(&MyList,&DisplayInt);
    printf("\n");
    if(ListEmpty(&MyList))
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Not Empty\n");
    }
    if(ListFull(&MyList))
    {
        printf("List is full\n");
    }
    else
    {
        printf("not full\n");
    }
    printf("List size is %d\n",ListSize(&MyList));
    ReplaceList(1,25,&MyList);
     printf("Modified list: ");
    TraverseList(&MyList,&DisplayInt);
    printf("\n");
    RetrieveList(2,&elemnt,&MyList);
    printf("Retrieved element at position 2 is %d\n",elemnt);
    DeleteList(0,&elemnt,&MyList);
    printf("Deleted element at position 0 %d\n", elemnt);
    printf("Final List  ");
    TraverseList(&MyList,&DisplayInt);
    
    return 0;
}
