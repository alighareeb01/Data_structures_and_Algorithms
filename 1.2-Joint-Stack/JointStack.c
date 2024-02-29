#include "JointStack.h"
void CreateJoinedStack(JStack *ps)
{
    ps -> top1 = -1;
    ps -> top2 = MAXSIZE;
}
void PushBottom(JStack *ps, STACKENTRY e)
{
    if(ps->top1 + 1 < ps->top2)
    {
        ps->top1++;
        ps->entry[ps->top1] = e;
    }
}
void PushUp(JStack *ps , STACKENTRY e)
{
    if(ps->top1 + 1 < ps->top2)
    {
     ps->top2--;
     ps->entry[ps->top2] = e;   
    }
}
int StackSize(JStack *ps , int StackNum)
{
    if(StackNum == 1)
    {
        return ps->top1 + 1;
    }
    else if(StackNum == 2)
    {
        return ps->top2 + 1;
    }
    else
    {
        return 0;
    }
}
int EmptyStack(JStack *ps,int StackNum)
{
    if(StackNum == 1)
    {
        return (ps->top1 == -1);
    }
    else  if(StackNum == 2)
    {
        return (ps->top2 == MAXSIZE);
    }
    else
    {
        return 0;
    }
}
int FullStack(JStack *ps,int StackNum)
{
    if(ps->top1 +1 == ps->top2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void DestroyStack(JStack *ps)
{
    ps -> top1 = -1;
    ps -> top2 = MAXSIZE;
}