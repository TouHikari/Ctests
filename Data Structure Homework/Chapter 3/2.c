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
int GetStackLength(LinkStack S);
char * ReversePolishNotation(void);

int main(void)
{
    char * result = ReversePolishNotation();
    printf("%s", result);
    free(result);
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

int GetStackLength(LinkStack S)
{
    int count = 0;
    LinkStack p = S;
    while (!StackEmpty(p))
    {
        count++;
        p = p->next;
    }
    return count;
}

char * ReversePolishNotation(void)
{
    LinkStack nums;
    InitStack(&nums);
    LinkStack oprt;
    InitStack(&oprt);

    int ch = getchar();
    while (ch != '\n' && ch != EOF)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            StackPush(&nums, ch);
        if (ch == '(')
            StackPush(&oprt, ch);
        if (ch == '+' || ch == '-')
        {
            do
            {
                if (StackEmpty(oprt) || GetStackTop(oprt) == '(')
                {
                    StackPush(&oprt, ch);
                    break;
                }
                else
                {
                    char temp;
                    StackPop(&oprt, &temp);
                    StackPush(&nums, temp);
                }
            } while (1);
        }
        if (ch == '*' || ch == '/')
        {
            do
            {
                if (StackEmpty(oprt) || GetStackTop(oprt) == '(')
                {
                    StackPush(&oprt, ch);
                    break;
                }
                else
                {
                    if (GetStackTop(oprt) == '+' || GetStackTop(oprt) == '-')
                    {
                        StackPush(&oprt, ch);
                        break;
                    }
                    else
                    {
                        char temp;
                        StackPop(&oprt, &temp);
                        StackPush(&nums, temp);
                    }
                }
            } while (1);
        }
        if (ch == ')')
        {
            while (GetStackTop(oprt) != '(')
            {
                char temp;
                StackPop(&oprt, &temp);
                StackPush(&nums, temp);
            }
            StackPop(&oprt, NULL);
        }
        ch = getchar();
    }

    while (!StackEmpty(oprt))
    {
        char temp;
        StackPop(&oprt, &temp);
        StackPush(&nums, temp);
    }
    
    int len = GetStackLength(nums);
    char * result = (char *)malloc(sizeof(char) * (len + 1));
    for (int i = len - 1; i >= 0; i--)
        StackPop(&nums, &result[i]);
    result[len] = '\0';
    return result;
}