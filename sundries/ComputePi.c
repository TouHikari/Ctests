#include <stdio.h>
#include <stdlib.h>

// 定义双向链表
typedef struct DNode {
    int data;               // 数据域
    struct DNode * prior;   // 前驱指针域
    struct DNode * next;    // 后继指针域
} DNode, * aa;

// 初始化一个双向链表
aa InitDLinkList(aa *DL);
// 销毁双向链表
void DestroyDLinkList(aa *DL);
// 向链表末尾添加元素
void DLinkInsertEnd(aa DL, int data);
// 遍历链表并输出指定位数的小数
// 链表第一个结点中存储整数部分，之后每个结点存储一位小数
void PrintDLinkList(aa DL, int digits);
// 大数加法，将结果保存在 num2 中，两个加数必须小数位相同
aa BigAdd(aa num1, aa num2);
// 大数与一个 int 型的乘法，原地相乘将结果保存在 num 中
aa BigMul(aa num, int multiplier);
// 大数与一个 int 型的除法，原地相除将结果保存在 num 中
aa BigDiv(aa num, int divisor);
// 精确计算 Pi 的值，至少保证小数点后 digits 位的正确性
aa ComputePi(int digits);

int main(void)
{
    // 存放结果的双向链表
    aa result;
    
    // 读取要求输出的的 Pi 的小数位数
    int n;
    scanf("%d", &n);
    
    // 将计算结果写入链表
    result = ComputePi(n);
    
    // 打印计算结果
    PrintDLinkList(result, n);
    
    // 释放内存
    DestroyDLinkList(&result);
    
    return 0;
}

// 初始化一个双向链表
aa InitDLinkList(aa *DL)
{
    // 申请内存以存储新表头
    *DL = (aa)malloc(sizeof(DNode));
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

// 销毁双向链表
void DestroyDLinkList(aa *DL)
{
    DNode * p = (*DL)->next;
    while (p != NULL)   // 从表头的下一个结点开始依次释放各结点内存
    {
        DNode * temp = p;
        p = p->next;
        free(temp);
    }
    free(*DL);          // 最后释放表头内存
    *DL = NULL;         // 防止悬空指针
}

// 向链表末尾添加元素
void DLinkInsertEnd(aa DL, int data)
{
    aa p = DL;   // 声明链表指针
    while (p->next)
        p = p->next;    // 找到最后一个结点

    // 建立新结点，并且连接到链表中
    aa p_new = (aa)malloc(sizeof(DNode));
    p_new->data = data;
    p->next = p_new;
    p_new->prior = p;
    p_new->next = NULL;
}

// 遍历链表并输出指定位数的小数
// 链表第一个结点中存储整数部分，之后每个结点存储一位小数
void PrintDLinkList(aa DL, int digits)
{
    aa p = DL->next;

    // 输出整数部分
    printf("%d.", p->data);

    // 输出小数部分
    p = p->next;
    for (int i = 0; i < digits; i++)
    {
        printf("%d", p->data);
        if (p->next)        // 若未到链表末尾
            p = p->next;    // 指针后移一位
    }
    printf("\n");           // 打印完成后换行
}

// 大数加法，将结果保存在 num2 中，两个加数必须小数位相同
aa BigAdd(aa num1, aa num2)
{
    // 创建两个指针，分别移动到两个链表末尾
    aa p1 = num1;
    aa p2 = num2;
    while (p1->next)
        p1 = p1->next;
    while (p2->next)
        p2 = p2->next;

    int ret = 0;        // 存放进位值
    int temp = 0;       // 存放临时值
    while (p1 && p2)    // 相加并将结果保存在 num2 中
    {
        temp = p1->data + p2->data + ret;
        ret = temp / 10;
        p2->data = temp % 10;
        p1 = p1->prior;
        p2 = p2->prior;
    }
    return num2;
}

// 大数与一个 int 型的乘法，原地相乘将结果保存在 num 中
aa BigMul(aa num, int multiplier)
{
    // 创建指针，移动到链表末尾
    aa p = num;
    while (p->next)
        p = p->next;
    
    int ret = 0;        // 存放进位值
    int temp = 0;       // 存放临时值
    while (p)
    {
        temp = p->data * multiplier + ret;
        p->data = temp % 10;
        ret = temp / 10;
        p = p->prior;
    }
    return num;
}

// 大数与一个 int 型的除法，原地相除将结果保存在 num 中
aa BigDiv(aa num, int divisor)
{
    aa p = num->next;

    int ret = 0;        // 存放进位值
    int temp = 0;       // 存放临时值
    while (p)
    {
        temp = p->data + ret * 10;
        ret = temp % divisor;
        p->data = temp / divisor;
        p = p->next;
    }
    return num;
}

// 精确计算 Pi 的值，至少保证小数点后 digits 位的正确性
aa ComputePi(int digits)
{
    aa num;          // num 为每次相加的 R(n)
    aa sum;          // sum 最终的值约等于 Pi
    InitDLinkList(&num);
    InitDLinkList(&sum);

    // 给链表多补 100 位来进行计算，避免计算精度影响到最后几位结果
    for (int i = 0; i < digits + 100; i++)
    {
        DLinkInsertEnd(num, 0);
        DLinkInsertEnd(sum, 0);
    }

    // p1, p2 为指向两个链表的指针 
    aa p1 = num->next;
    aa p2 = sum->next;
    // 使两个链表除头节点外第一个节点的数据为2，计算直接从 R(2) 开始计算，简化了计算
    p1->data = 2;
    p2->data = 2;

    // 开始运算
    for (int j = 1, t = 3; j < 10000; j++, t += 2)
    {
        BigMul(num, j);
        BigDiv(num, t);
        BigAdd(num, sum);
    }

    DestroyDLinkList(&num);
    return sum;
}