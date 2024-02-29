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
    InsertList(0,1,&MyList);
    InsertList(1,2,&MyList);
    InsertList(2,4,&MyList);
    InsertList(2,3,&MyList);
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
    ReplaceList(1,0,&MyList);
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
