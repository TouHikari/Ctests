#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;               // 数据域
    struct DNode * prior;   // 前驱指针域
    struct DNode * next;    // 后继指针域
} DNode, * DLinkList;

// 初始化一个双向链表
DLinkList InitDLinkList(DLinkList *DL)
{
    // 申请内存以存储新表头
    *DL = (DLinkList)malloc(sizeof(DNode));
    if (*DL)
    {
        (*DL)->prior = *DL;
        (*DL)->next = *DL;
        return *DL;
    }
    else
        // 若申请内存失败
        return NULL;
}

// 尾插法向链表中添加元素
void DLinkInsert(DLinkList list, int data)
{
    DLinkList p = list;
    if (p == NULL)
        return;
    else
    {
        while (p->next)
            p = p->next;
        DLinkList pnew = (DLinkList)malloc(sizeof(DNode));
        pnew->data = data;
        p->next = pnew;
        pnew->prior = p;
        pnew->next = NULL;
    }
}

void PrintDLinkList(DLinkList list, int n)
{
    // 遍历链表并输出指定位数的小数 
    DLinkList p = list;
    p = p->next;
    printf("%d.", p->data);
    int i;
    p = p->next;
    for (i = 0; i < n; i++)
    {
        printf("%d", p->data);
        if (p->next)
        {
            p = p->next;
        }
    }
    printf("\n");
}

int main(void)
{
    DLinkList num;      // num为每次相加的 R(n); 
    DLinkList sum;      // sum最终的值约等于 Pi；
    num = (DLinkList)malloc(sizeof(DNode));
    sum = (DLinkList)malloc(sizeof(DNode));
    num->prior = NULL;
    sum->prior = NULL;
    num->next = NULL;
    sum->next = NULL;
    // n 为题目要求输出的的 Pi 的小数位数； 
    int n;
    scanf("%d", &n);
    // 给链表补够600位来进行计算,因为我的精度要达到500 
    int i;
    for (i = 0; i < 600; i++)
    {
        DLinkInsert(num, 0);
        DLinkInsert(sum, 0);
    }
    // p1,p2为指向两个链表的指针 
    DLinkList p1 = num->next;
    DLinkList p2 = sum->next;
    // 使两个链表除头节点外第一个节点的数据为2，计算直接从R2开始计算，简化了计算 
    p1->data = 2;
    p2->data = 2;
    // 指向num,和sum的尾节点
    while (p1->next)
    {
        p1 = p1->next;
    }
    DLinkList numtail = p1;
    while (p2->next)
    {
        p2 = p2->next;
    }
    DLinkList sumtail = p2;
    // 开始运算； 
    int temp = 0;   // 计算过程中产生的临时数据 
    int ret = 0;    // 计算过程中产生的借位or进位
    int t;          // 计算时有规律出现的除数 2n + 1
    for (i = 1, t = 3; i < 10000; i++, t = t + 2)
    {
        // i 同时承担计数和做乘数的任务 
        // 先计算乘法（即公式中 R(n) * n） 
        DLinkList p3 = numtail;
        ret = 0;
        while (p3)
        {
            temp = p3->data * i + ret;
            p3->data = temp % 10;
            ret = temp / 10;
            p3 = p3->prior;
        }
        ret = 0;
        p3 = num->next;
        // 计算除法（即公式中的 R(n) * n / (2 * n + 1)）
        while (p3)
        {
            temp = p3->data + ret * 10;
            ret = temp % t;
            p3->data = temp / t;
            p3 = p3->next;
        }
        ret = 0;
        DLinkList  p4 = sumtail;
        p3 = numtail;
        // 将得到的 R(n) 的值加入到结果中 
        while (p3 && p4)
        {
            temp = p3->data + p4->data + ret;
            ret = temp / 10;
            p4->data = temp % 10;
            p3 = p3->prior;
            p4 = p4->prior;
        }
    }
    PrintDLinkList(sum, n);
    return 0;
}