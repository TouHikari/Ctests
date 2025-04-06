#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    char data;
    struct StackNode * next;
} StackNode, * LinkStack;

int InitStack(LinkStack *S);
int StackPush(LinkStack *S, char e);
int StackPop(LinkStack *S, char *e);
char GetStackTop(LinkStack S);
int StackEmpty(LinkStack S);
int Matching(void);

int main(void)
{
    if (Matching())
        printf("yes");
    else
        printf("no");
    
    return 0;
}

int InitStack(LinkStack *S)
{
    *S = NULL;
    return 1;
}

int StackPush(LinkStack *S, char e)
{
    StackNode * p;
    if (p = (StackNode *)malloc(sizeof(StackNode)))
    {
        p->data = e;
        p->next = *S;
        *S = p;
        return 1;
    }
    else
        return 0;
}

int StackPop(LinkStack *S, char *e)
{
    StackNode * p;
    if (*S == NULL)
        return 0;
    if (e != NULL)
        *e = (*S)->data;
    p = *S;
    *S = (*S)->next;
    free(p);
    return 1;
}

char GetStackTop(LinkStack S)
{
    if (S != NULL)
        return S->data;
    else
        return '\0';
}

int StackEmpty(LinkStack S)
{
    if (S == NULL)
        return 1;
    else
        return 0;
}

int Matching(void)
{
    LinkStack S;
    InitStack(&S);

    int flag_wrong = 1;
    int ch = getchar();

    while (ch != '\n' && ch != EOF && flag_wrong)
    {
        switch (ch)
        {
        case '{':
        case '[':
        case '(':
            StackPush(&S, ch);
            break;
        case ')':
            if (!StackEmpty(S) && GetStackTop(S) == '(')
                StackPop(&S, NULL);
            else
                flag_wrong = 0;
            break;
        case ']':
            if (!StackEmpty(S) && GetStackTop(S) == '[')
                StackPop(&S, NULL);
            else
                flag_wrong = 0;
            break;
        case '}':
            if (!StackEmpty(S) && GetStackTop(S) == '{')
                StackPop(&S, NULL);
            else
                flag_wrong = 0;
            break;
        default:
            break;
        }
        ch = getchar();
    }
    if (StackEmpty(S) && flag_wrong)
        return 1;
    else
        return 0;
}