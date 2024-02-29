#define MAXSIZE 100
#define STACKENTRY char
typedef struct JointStack
{
    int top1;
    int top2;
    STACKENTRY entry[MAXSIZE];
}JStack;

void CreateJoinedStack(JStack *);
void PushBottom(JStack *, STACKENTRY );
void PushUp(JStack * , STACKENTRY );
int StackSize(JStack* , int );
int EmptyStack(JStack*,int );
int FullStack(JStack*,int );
void DestroyStack(JStack *);