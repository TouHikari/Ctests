#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int data;
   struct Node * next;
} Node, * LinkList;

void InitList(LinkList *L);
void CreateFromHead(LinkList L, int elenum, int list[]);
Node * Get(LinkList L, int i);

int main(void)
{
    int elenum;
    scanf("%d", &elenum);

    int list1[elenum];
    LinkList list2;
    InitList(&list2);

    for (int i = 0; i < elenum; i++)
    {
        scanf("%d", &list1[i]);
    }

    for (int i = elenum - 1; i >= 0; i--)
    {
        if (i != 0)
            printf("%d ", list1[i]);
        else
            printf("%d", list1[i]);
    }
    printf("\n");

    CreateFromHead(list2, elenum, list1);
    for (int i = 0; i < elenum; i++)
    {
        if (i != elenum - 1)
            printf("%d ", Get(list2, i + 1)->data);
        else
            printf("%d", Get(list2, i + 1)->data);
    }

    return 0;
}

void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void CreateFromHead(LinkList L, int elenum, int list[])
{
    Node * s;
    for (int i = 0; i < elenum; i++)
    {
        s = (Node *)malloc(sizeof(Node));
        s->data = list[i];
        s->next = L->next;
        L->next = s;
    }
}

Node * Get(LinkList L, int i)
{
    int j;
    Node * p;
    if (i <= 0)
        return NULL;
    p = L;
    j = 0;
    while ((p->next != NULL) && (j < i))
    {
        p = p->next;
        j++;
    }
    if (i == j)
        return p;
    else
        return NULL;
}