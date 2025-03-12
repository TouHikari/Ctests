#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
} Node, * LinkList;

void InitList(LinkList *L);
void CreateFromTail(LinkList L, int elenum);
Node * Locate(LinkList L, int key);
int DelList(LinkList L, Node *R);

int main(void)
{
    LinkList A, B, C;
    InitList(&A);
    InitList(&B);
    InitList(&C);

    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);

    CreateFromTail(A, m);
    CreateFromTail(B, n);
    CreateFromTail(C, p);

    LinkList temp = NULL;
    InitList(&temp);

    LinkList ptrC = C->next;
    while (ptrC != NULL)
    {
        Node * newNode = Locate(B, ptrC->data);
        if (newNode != NULL)
        {
            newNode = (Node *)malloc(sizeof(Node));
            newNode->data = ptrC->data;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        ptrC = ptrC->next;
    }

    LinkList ptrA = A->next;
    while (ptrA != NULL)
    {
        Node * nodeToDelete = Locate(temp, ptrA->data);
        if (nodeToDelete != NULL)
        {
            Node * nextNode = ptrA->next;
            DelList(A, ptrA);
            ptrA = nextNode;
        }
        else
        {
            ptrA = ptrA->next;
        }
    }

    ptrA = A->next;
    while (ptrA != NULL)
    {
        printf("%d ", ptrA->data);
        ptrA = ptrA->next;
    }

    while (A != NULL)
    {
        Node * tempNode = A;
        A = A->next;
        free(tempNode);
    }
    while (B != NULL)
    {
        Node * tempNode = B;
        B = B->next;
        free(tempNode);
    }
    while (C != NULL)
    {
        Node *tempNode = C;
        C = C->next;
        free(tempNode);
    }
    while (temp != NULL)
    {
        Node * tempNode = temp;
        temp = temp->next;
        free(tempNode);
    }

    return 0;
}

void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void CreateFromTail(LinkList L, int elenum)
{
    Node * r, * s;
    r = L;
    int num;
    for (int i = 0; i < elenum; i++)

    {
        scanf("%d", &num);
        s = (Node *)malloc(sizeof(Node));
        s->data = num;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

Node * Locate(LinkList L, int key)
{
    Node * p = L->next;
    while (p != NULL)

    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

int DelList(LinkList L, Node *R)
{
    Node * pre = L;
    while ((pre->next != NULL) && (pre->next != R))
        pre = pre->next;

    if (pre->next == NULL)
        return 0;

    Node * r = pre->next;
    pre->next = r->next;
    free(r);
    return 1;
}