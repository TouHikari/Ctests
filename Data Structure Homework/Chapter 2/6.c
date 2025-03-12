#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    struct DNode * pre;
    char data;
    int freq;
    struct DNode * next;
} DNode, * DoubleList;

void InitDLinkList(DoubleList * DL);
void CreateDLinkList(DoubleList DL, int elenum);
DNode * Locate(DoubleList DL, char e);
void SortDLinkList(DoubleList DL);
void PrintDLinkList(DoubleList DL);

int main(void)
{
    DoubleList DL1;
    InitDLinkList(&DL1);

    int m, n;
    scanf("%d %d", &m, &n);
    CreateDLinkList(DL1, m);

    for (int i = 0; i < n; i++)
    {
        char ch[2];
        scanf("%s", ch);
        Locate(DL1, ch[0]);
    }
    
    SortDLinkList(DL1);

    PrintDLinkList(DL1);

    return 0;
}

void InitDLinkList(DoubleList * DL)
{
    *DL = (DoubleList)malloc(sizeof(DNode));
    (*DL)->pre = *DL;
    (*DL)->freq = 0;
    (*DL)->next = *DL;
}

void CreateDLinkList(DoubleList DL, int elenum)
{
    DNode * rear = DL, * s;
    for (int i = 0; i < elenum; i++)
    {
        char addon[2];
        scanf("%s", addon);
        
        s = (DNode *)malloc(sizeof(DNode));
        s->freq = 0;
        s->data = addon[0];

        s->next = DL;
        s->pre = rear;
        rear->next = s;
        DL->pre = s;
        rear = s;
    }
}

DNode * Locate(DoubleList DL, char e)
{
    DNode * p = DL->next;
    while (p != DL)
    {
        if (p->data == e)
        {
            p->freq++;
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void SortDLinkList(DoubleList DL)
{
    if (DL->next == DL || DL->next->next == DL)
        return;

    DNode * current = DL->next->next;
    while (current != DL)
    {
        DNode * key = current;
        DNode * prev = current->pre;

        // 将当前节点插入到正确的位置
        while (prev != DL && prev->freq < key->freq)
        {
            prev = prev->pre;
        }

        // 如果 prev 不是当前节点的前一个节点，进行插入操作
        if (prev->next != key)
        {
            // 断开当前节点的链接
            key->pre->next = key->next;
            key->next->pre = key->pre;

            // 插入到 prev 后面
            key->next = prev->next;
            key->pre = prev;

            if (prev->next != DL) // 如果插入的不是头节点
                prev->next->pre = key;

            prev->next = key;
        }

        current = current->next; // 移动到下一个节点
    }
}

void PrintDLinkList(DoubleList DL)
{
    DNode * p = DL->next;
    while (p != DL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
}