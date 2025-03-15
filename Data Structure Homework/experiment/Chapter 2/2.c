#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 双向链表
typedef struct DNode {
    int data;               // 数据域
    struct DNode * prior;   // 前驱指针域
    struct DNode * next;    // 后继指针域
} DNode, * DLinkList;

// 初始化一个双向链表
DLinkList InitDLinkList(DLinkList *DL);
// 销毁双向链表
void DestroyDLinkList(DLinkList *DL);
// 向双向链表中第 i 个位置插入值为 e 的新元素
int DLinkIns(DLinkList DL, int i, int e);
// 从双链表中删除第 i 个元素，并将删除的元素值保存到变量 e 中
int DLinkDel(DLinkList DL, int i, int *e);
// 打印链表存储的数字，按小数输出
void PrintDecimalDLinkList(DLinkList DL);
// 复制一个双向链表
DLinkList CopyDLinkList(DLinkList DL);
// 两个双向链表表示的数相加，结果存储在新的双向链表中
DLinkList AddDLinkList(DLinkList a, DLinkList b);
// 双向链表表示的数与整数相乘，结果存储在新的双向链表中
DLinkList MulDLinkListByInt(DLinkList a, int factor);
// 两个双向链表表示的数相乘，结果存储在新的双向链表中
DLinkList MulDLinkList(DLinkList a, DLinkList b);
// 创建表示常数的双向链表
DLinkList CreateConstant(int constant);
// 读取输入
void GetInput(int *a);
// 清空读取缓冲区
void ClearBuffer(void);
// 大数除法，将结果依次保存在双向链表中
DLinkList BigDiv(int numerator, int denominator, int digits);
// 计算 Pi 的函数，digits 为小数位数
DLinkList ComputePi(int digits);

int main(void)
{
    int digits;
    GetInput(&digits);
    DLinkList pi;
    pi = ComputePi(digits);
    PrintDecimalDLinkList(pi);
    DestroyDLinkList(&pi);
    return 0;
}

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
    else                // 若申请内存失败
        return NULL;
}

// 销毁双向链表
void DestroyDLinkList(DLinkList *DL)
{
    DNode * p = (*DL)->next;
    while (p != *DL)    // 从表头的下一个结点开始依次释放各结点内存
    {
        DNode * temp = p;
        p = p->next;
        free(temp);
    }
    free(*DL);          // 最后释放表头内存
    *DL = NULL;         // 防止悬空指针
}

// 向双向链表中第 i 个位置插入值为 e 的新元素
int DLinkIns(DLinkList DL, int i, int e)
{
    DNode * s, * p;

    if (i <= 0)         // 检查待插入的位置 i 是否合理
        return false;

    p = DL;             // 从表头开始
    int k = 0;

    // 寻找第 i-1 个节点
    while (p->next != DL && k < i - 1)
    {
        p = p->next;
        k++;
    }

    if (k != i - 1)
    {
        // 插入位置超过当前链表长度 +1 但允许插入到末尾（size + 1）
        if (k < i - 1)
            return false;   // 插入位置不合理
    }

    // 创建新结点并插入到链表中
    s = (DNode *)malloc(sizeof(DNode));
    if (s)
    {
        s->data = e;
        s->next = p->next;
        s->prior = p;
        p->next->prior = s;
        p->next = s;
        return true;
    }
    else                // 若申请内存失败
        return false;
}

// 从双链表中删除第 i 个元素，并将删除的元素值保存到变量 e 中
int DLinkDel(DLinkList DL, int i, int *e)
{
    DNode * p;

    if (i <= 0)         // 检查待删除的位置 i 是否合理
        return false;
    if (DL->next == DL)
        return false;   // 检查是否为空表

    p = DL->next;
    int k = 1;

    // 寻找第 i 个节点
    while (p != DL && k < i)
    {
        p = p->next;
        k++;
    }

    if (p == DL || k != i)
        return false;   // 删除位置不合理

    // 断开结点的连接，释放内存
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return true;
}

// 打印链表存储的数字，按小数输出
void PrintDecimalDLinkList(DLinkList DL)
{
    DLinkList p = DL->next;
    bool first_flag = true;
    while (p != DL)
    {
        if (first_flag)
        {
            printf("%d.", p->data);
            first_flag = false;
        }
        else
            printf("%d", p->data);
        p = p->next;
    }
}

// 复制一个双向链表
DLinkList CopyDLinkList(DLinkList DL)
{
    DLinkList copy;
    if (!InitDLinkList(&copy))
        exit(1);        // 内存分配失败

    DNode * p = DL->next;
    int pos = 1;
    while (p != DL)
    {
        if (!DLinkIns(copy, pos, p->data))
        {
            DestroyDLinkList(&copy);
            exit(1);    // 插入失败
        }
        p = p->next;
        pos++;
    }

    return copy;
}

// 两个双向链表表示的数相加，结果存储在新的双向链表中
DLinkList AddDLinkList(DLinkList a, DLinkList b)
{
    DLinkList result;
    if (!InitDLinkList(&result))
        exit(1);        // 内存分配失败

    DNode *pa = a->prior; // 从最低位开始
    DNode *pb = b->prior;
    int carry = 0;
    int pos = 1;

    while (pa != a || pb != b || carry != 0)
    {
        int sum = carry;
        if (pa != a)
        {
            sum += pa->data;
            pa = pa->prior;
        }
        if (pb != b)
        {
            sum += pb->data;
            pb = pb->prior;
        }
        carry = sum / 10;
        int digit = sum % 10;
        DLinkIns(result, pos, digit);
        pos++;
    }

    return result;
}

// 双向链表表示的数与整数相乘，结果存储在新的双向链表中
DLinkList MulDLinkListByInt(DLinkList a, int factor)
{
    DLinkList result;
    if (!InitDLinkList(&result))
        exit(1);        // 内存分配失败

    DNode * pa = a->prior; // 从最低位开始
    int carry = 0;
    int pos = 1;

    while (pa != a || carry != 0)
    {
        int product = carry;
        if (pa != a)
        {
            product += pa->data * factor;
            pa = pa->prior;
        }
        carry = product / 10;
        int digit = product % 10;
        DLinkIns(result, pos, digit);
        pos++;
    }

    return result;
}

// 两个双向链表表示的数相乘，结果存储在新的双向链表中
DLinkList MulDLinkList(DLinkList a, DLinkList b)
{
    DLinkList result;
    if (!InitDLinkList(&result))
        exit(1);        // 内存分配失败

    DNode *pa = a->prior; // 从最低位开始
    int pos_a = 1;

    while (pa != a)
    {
        int carry = 0;
        DLinkList temp;
        if (!InitDLinkList(&temp))
        {
            DestroyDLinkList(&result);
            exit(1);    // 内存分配失败
        }

        // 将 b 逆序相乘
        DNode *pb = b->prior;
        int pos_b = 1;
        while (pb != b)
        {
            int product = pa->data * pb->data + carry;
            carry = product / 10;
            int digit = product % 10;
            DLinkIns(temp, pos_b, digit);
            pb = pb->prior;
            pos_b++;
        }
        if (carry > 0)
        {
            DLinkIns(temp, pos_b, carry);
        }

        // 根据 a 的位数调整 temp 的位置（相当于乘以 10^(pos_a-1)）
        for (int i = 1; i < pos_a; i++)
        {
            DLinkIns(temp, 1, 0);
        }

        // 将 temp 加到 result 上
        DLinkList new_result = AddDLinkList(result, temp);
        DestroyDLinkList(&result);
        DestroyDLinkList(&temp);
        result = new_result;

        pa = pa->prior;
        pos_a++;
    }

    return result;
}

// 创建表示常数的双向链表
DLinkList CreateConstant(int constant)
{
    DLinkList constantDL;
    if (!InitDLinkList(&constantDL))
        exit(1);        // 内存分配失败

    // 假设 constant 是一个非负整数
    if (constant == 0)
    {
        DLinkIns(constantDL, 1, 0);
        return constantDL;
    }

    int pos = 1;
    while (constant > 0)
    {
        int digit = constant % 10;
        DLinkIns(constantDL, pos, digit);
        constant /= 10;
        pos++;
    }

    return constantDL;
}

// 读取输入
void GetInput(int *a)
{
    scanf("%d", a);
    ClearBuffer();
}

// 清空读取缓冲区
void ClearBuffer(void)
{
    char ch;
    while ((ch = getchar()) != '\n')
        continue;
}

// 大数除法，将结果依次保存在双向链表中
DLinkList BigDiv(int numerator, int denominator, int digits)
{
    // 声明并初始化一个双向链表头，用于保存各位计算结果
    DLinkList p_DLinkList;
    if (!InitDLinkList(&p_DLinkList))
        exit(1);        // 内存分配失败

    // 获取整数部分
    int integer_part = numerator / denominator;
    if (!DLinkIns(p_DLinkList, 1, integer_part))
    {   // 插入整数部分失败
        DestroyDLinkList(&p_DLinkList);
        exit(1);
    }

    // 计算小数部分
    int remainder = numerator % denominator;
    for (int i = 2; i <= digits + 1; i++) // 从第二个位置开始插入小数位
    {
        remainder *= 10;
        int digit = remainder / denominator;
        remainder = remainder % denominator;
        if (!DLinkIns(p_DLinkList, i, digit))
        {   // 插入小数位失败
            DestroyDLinkList(&p_DLinkList);
            exit(1);
        }
    }
    return p_DLinkList; // 返回存储结果的链表，其中第一个结点为整数部分，后面各结点为小数位
}

// 计算 Pi 的函数，digits 为小数位数
DLinkList ComputePi(int digits)
{
    // 计算连分数的层数，选择 digits 作为层数
    int max_k = digits;

    // 初始化最内层：2
    DLinkList current = CreateConstant(2);

    for (int k = max_k; k >= 1; k--)
    {
        // 计算分母部分：2k + 1
        int denominator = 2 * k + 1;

        // 计算分子部分：k
        int numerator = k;

        // 计算 k / (2k + 1) 的 BigDiv 结果
        DLinkList fraction = BigDiv(numerator, denominator, digits);

        // 将 current 与 fraction 相乘
        DLinkList multiplied = MulDLinkList(current, fraction);

        // 创建常数 2 的双向链表
        DLinkList two = CreateConstant(2);

        // 将 multiplied 与 2 相加
        DLinkList temp = AddDLinkList(two, multiplied);

        // 释放临时变量
        DestroyDLinkList(&current);
        DestroyDLinkList(&multiplied);
        DestroyDLinkList(&two);
        DestroyDLinkList(&fraction);

        // 更新 current
        current = temp;
    }

    return current;
}