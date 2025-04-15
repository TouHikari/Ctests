/*
某部队进行新兵队列训练，将新兵从1开始按顺序依次编号，并排成一行横队，训练的规则如下：
从头开始1至2报数，凡报到2的出列，剩下的向小序号方向靠拢，再从头开始进行1至3报数，凡报
到3的出列，剩下的向小序号方向靠拢，继续从头开始进行1至2报数，以后从头开始轮流进行1至2
报数、1至3报数直到剩下的人数不超过三人为止。编写程序，输入数N为最开始的新兵人数（2 < 
N < 6000），输出剩下的新兵最初的编号。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int code;
    struct Node * next;
} Node, * LinkList;

int InitList(LinkList * L);
void DestroyList(LinkList * L);
int CreateFromTail(LinkList L, int count);
int DelNode(LinkList L, int serial_num, int * e);
void CallOutLine(LinkList L, int length);
void PrintLineCode(LinkList L);

int main(void)
{
    int length = 3;
    scanf("%d", &length);

    LinkList line;
    InitList(&line);

    CreateFromTail(line, length);

    CallOutLine(line, length);

    PrintLineCode(line);

    DestroyList(&line);

    return 0;
}

int InitList(LinkList * L)
{
    if (!(*L = (LinkList)malloc(sizeof(Node))))
        return 0;
    (*L)->next = NULL;
    return 1;
}

void DestroyList(LinkList * L)
{
    Node * p_node = (*L)->next;
    while (p_node != NULL)
    {
        Node * p_temp = p_node;
        p_node = p_node->next;
        free(p_temp);
    }
    free(*L);
}

int CreateFromTail(LinkList L, int count)
{
    Node * p_rear = L, * p_new;

    for (int i = 1; i <= count; i++)
    {
        if (!(p_new = (Node *)malloc(sizeof(Node))))
            return 0;
        p_new->code = i;
        p_rear->next = p_new;
        p_rear = p_new;
    }
    p_rear->next = NULL;
    return 1;
}

int DelNode(LinkList L, int serial_num, int * e)
{
    Node * pre = L, * r;
    int k = 0;
    while ((pre->next != NULL) && (k < serial_num - 1))
    {
        pre = pre->next;
        k++;
    }
    if (pre->next == NULL)
    {
        return 0;
    }
    r = pre->next;
    pre->next = r->next;
    if (e != NULL)
        *e = r->code;
    free(r);
    return 1;
}

void CallOutLine(LinkList L, int length)
{
    while (1)
    {
        if (length > 3)
        {
            int serial_num = length - length % 2;
            int count = 0;
            for (int i = serial_num; i > 1; i -= 2)
            {
                DelNode(L, i, NULL);
                count++;
            }
            length -= count;
        }
        else
            break;
        if (length > 3)
        {
            int count = 0;
            int serial_num = length - length % 3;
            for (int i = serial_num; i > 1; i -= 3)
            {
                DelNode(L, i, NULL);
                count++;
            }
            length -= count;
        }
        else
            break;
    }
}

void PrintLineCode(LinkList L)
{
    Node * p = L->next;
    while (p != NULL)
    {
        Node * r = p->next;
        if (r != NULL)
            printf("%d ", p->code);
        else
            printf("%d", p->code);
        p = r;
    }
}