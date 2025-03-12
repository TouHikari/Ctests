#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
} Node, * LinkList;

void InitList(LinkList *L);
void CreateFromHead(LinkList L, int elenum);
LinkList MergeLinkList(LinkList LA, LinkList LB);

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);

    LinkList A = NULL;
    LinkList B = NULL;
    LinkList C = NULL;
    InitList(&A);
    InitList(&B);
    InitList(&C);

    CreateFromHead(A, m);
    CreateFromHead(B, n);

    C = MergeLinkList(A, B);

    Node * p = C->next;
    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    return 0;
}

void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void CreateFromHead(LinkList L, int elenum)
{
    Node * s;
    for (int i = 0; i < elenum; i++)
    {
        int addon;
        scanf("%d", &addon);
        s = (Node *)malloc(sizeof(Node));
        s->data = addon;
        s->next = L->next;
        L->next = s;
    }
}

LinkList MergeLinkList(LinkList LA, LinkList LB)
{
    Node * pa, * pb, * r;
    LinkList LC;
    pa = LA->next;
    pb = LB->next;
    LC = LA;
    LC->next = NULL;
    r = LC;
    
    while ((pa != NULL) && (pb != NULL))
    {
        if (pa->data >= pb->data)
        {
            r->next = pa;
            r = pa;
            pa = pa->next;
        }
        else
        {
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
    }
    if (pa)
        r->next = pa;
    else
        r->next = pb;
    
    free(LB);
    return LC;
}