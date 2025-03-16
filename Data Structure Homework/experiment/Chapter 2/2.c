#include <stdio.h>
#include <stdlib.h>

// 双向链表
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
        // 若申请内存成功，前驱与后继指针置空
        (*DL)->prior = NULL;
        (*DL)->next = NULL;
        return *DL;
    }
    else
        // 若申请内存失败，返回空指针
        return NULL;
}

// 向链表末尾添加元素
void DLinkInsertEnd(DLinkList DL, int data)
{
    DLinkList p = DL;       // 声明链表指针
    while (p->next)
        p = p->next;        // 找到最后一个结点

    // 建立新结点，并且连接到链表中
    DLinkList p_new = (DLinkList)malloc(sizeof(DNode));
    p_new->data = data;
    p->next = p_new;
    p_new->prior = p;
    p_new->next = NULL;
}

// 遍历链表并输出指定位数的小数
// 链表第一个结点中存储整数部分，之后每个结点存储一位小数
void PrintDLinkList(DLinkList DL, int digits)
{
    DLinkList p = DL->next;

    // 输出整数部分
    printf("%d.", p->data);

    // 输出小数部分
    p = p->next;
    for (int i = 0; i < digits; i++)
    {
        printf("%d", p->data);
        if (p->next)        // 若未到链表末尾
            p = p->next;    // 指针后移
    }
    printf("\n");           // 打印完成后换行
}

// 精确计算 Pi 的值，至少保证小数点后 500 位的正确性
DLinkList ComputePi(void)
{
    DLinkList num;          // num 为每次相加的 R(n)
    DLinkList sum;          // sum 最终的值约等于 Pi
    InitDLinkList(&num);
    InitDLinkList(&sum);

    // 给链表补够 600 位来进行计算，避免计算精度影响到最后几位结果
    for (int i = 0; i < 600; i++)
    {
        DLinkInsertEnd(num, 0);
        DLinkInsertEnd(sum, 0);
    }
    // p1, p2 为指向两个链表的指针 
    DLinkList p1 = num->next;
    DLinkList p2 = sum->next;
    // 使两个链表除头节点外第一个节点的数据为2，计算直接从 R(2) 开始计算，简化了计算
    p1->data = 2;
    p2->data = 2;

    // 指向 num 和 sum 的尾节点
    while (p1->next)
        p1 = p1->next;
    DLinkList numtail = p1;
    while (p2->next)
        p2 = p2->next;
    DLinkList sumtail = p2;

    // 开始运算
    int temp = 0;   // 计算过程中产生的临时数据
    int ret = 0;    // 计算过程中产生的借位 or 进位
    int t;          // 计算时有规律出现的除数 2n + 1
    for (int j = 1, t = 3; j < 10000; j++, t = t + 2)
    {
        // j 同时承担计数和做乘数的任务
        // 先计算乘法（即公式中 R(n) * n）
        DLinkList p3 = numtail;
        ret = 0;
        while (p3)
        {
            temp = p3->data * j + ret;
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
    return sum;
}

int main(void)
{
    DLinkList result;

    // 读取要求输出的的 Pi 的小数位数
    int n;
    scanf("%d", &n);

    result = ComputePi();

    PrintDLinkList(result, n);
    return 0;
}