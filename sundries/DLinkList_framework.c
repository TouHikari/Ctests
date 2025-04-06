#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 双向链表
typedef struct DNode {
    int data;               // 数据域
    struct DNode * prior;   // 前驱指针域
    struct DNode * next;    // 后继指针域
} DNode, * aa;

// 初始化一个双向链表
aa InitDLinkList(aa *DL);
// 销毁双向链表
void DestroyDLinkList(aa *DL);
// 求双向链表长度
int GetDLinkListLength(aa DL);
// 向双向链表中第 i 个位置插入值为 e 的新元素
int DLinkIns(aa DL, int i, int e);
// 从双链表中删除第 i 个元素，并将删除的元素值保存到变量 e 中
int DLinkDel(aa DL, int i, int *e);
// 打印链表存储的数字，按小数输出
void PrintDecimalDLinkList(aa DL);
// 复制一个双向链表
aa CopyDLinkList(aa DL);
// 两个双向链表表示的数相加，结果存储在新的双向链表中
aa AddDLinkList(aa a, aa b);
// 双向链表表示的数与整数相乘，结果存储在新的双向链表中
aa MulDLinkListByInt(aa a, int factor);
// 两个双向链表表示的数相乘，结果存储在新的双向链表中
aa MulDLinkList(aa a, aa b);
// 创建表示常数的双向链表
aa CreateConstant(int constant);

int main(void)
{
    return 0;
}

// 初始化一个双向链表
aa InitDLinkList(aa *DL)
{
    // 申请内存以存储新表头
    *DL = (aa)malloc(sizeof(DNode));
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
void DestroyDLinkList(aa *DL)
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

// 求双向链表长度
int GetDLinkListLength(aa DL)
{
    int length = 0;
    aa p = DL;
    while (p->next != DL)
    {
        length++;
        p = p->next;
    }
    return length;
}

// 向双向链表中第 i 个位置插入值为 e 的新元素
int DLinkIns(aa DL, int i, int e)
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
int DLinkDel(aa DL, int i, int *e)
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
void PrintDecimalDLinkList(aa DL)
{
    aa p = DL->next;
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
aa CopyDLinkList(aa DL)
{
    aa copy;
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
aa AddDLinkList(aa a, aa b)
{
    aa result;
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
aa MulDLinkListByInt(aa a, int factor)
{
    aa result;
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
aa MulDLinkList(aa a, aa b)
{
    aa result;
    if (!InitDLinkList(&result))
        exit(1);        // 内存分配失败

    DNode *pa = a->prior; // 从最低位开始
    int pos_a = 1;

    while (pa != a)
    {
        int carry = 0;
        aa temp;
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
        aa new_result = AddDLinkList(result, temp);
        DestroyDLinkList(&result);
        DestroyDLinkList(&temp);
        result = new_result;

        pa = pa->prior;
        pos_a++;
    }

    return result;
}

// 创建表示常数的双向链表
aa CreateConstant(int constant)
{
    aa constantDL;
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