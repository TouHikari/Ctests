#include <stdio.h>
#include <stdlib.h>

typedef struct TupNode
{
    int row;                // 行号
    int col;                // 列号
    int dat;                // 元素值
    struct TupNode * next;  // 后驱结点指针
} TupNode, * TSMatrix;      // 三元组结点定义

// 初始化三元组链表
// 返回值：1 成功，0 失败
int initTSMatrix(TSMatrix * TSM);
// 插入三元组结点
// 返回值：1 成功，0 失败
int insTupNode(TSMatrix TSM, int row, int col, int dat);
// 销毁三元组链表
void destroyTSMatrix(TSMatrix TSM);
// 相加两个三元组链表
// 返回值：相加后的矩阵
TSMatrix addTSMatrix(TSMatrix TSM1, TSMatrix TSM2);
// 打印矩阵
void printTSMatrix(TSMatrix TSM);

int main(void)
{
    // 创建三元组链表
    // 头结点不存储数据，实际数据从头结点的 next 开始存储
    TSMatrix TSM1, TSM2, addedTSM;
    initTSMatrix(&TSM1);
    initTSMatrix(&TSM2);
    initTSMatrix(&addedTSM);
    if (!TSM1 || !TSM2 || !addedTSM)
    {
        // 初始化失败
        destroyTSMatrix(TSM1);
        destroyTSMatrix(TSM2);
        destroyTSMatrix(addedTSM);
        return 1;
    }

    // 读取两个三元组链表的行、列值和两个矩阵的非零元素个数
    // 格式：行 列 非零元素个数1 非零元素个数2
    int row, col, num1, num2;
    scanf("%d %d %d %d", &row, &col, &num1, &num2);

    // 读取两个矩阵的数据
    // 格式：行 列 值
    for (int i = 0; i < num1; i++)
    {
        int r, c, d;
        scanf("%d %d %d", &r, &c, &d);
        if (!insTupNode(TSM1, r, c, d))
        {
            // 插入失败，销毁链表并返回
            destroyTSMatrix(TSM1);
            return 1;
        }
    }
    for (int i = 0; i < num2; i++)
    {
        int r, c, d;
        scanf("%d %d %d", &r, &c, &d);
        if (!insTupNode(TSM2, r, c, d))
        {
            // 插入失败，销毁链表并返回
            destroyTSMatrix(TSM2);
            return 1;
        }
    }

    // 相加两个三元组链表
    addedTSM = addTSMatrix(TSM1, TSM2);

    // 打印相加后的矩阵
    // 格式：行 列 值
    printTSMatrix(addedTSM);

    // 销毁矩阵
    destroyTSMatrix(addedTSM);
    destroyTSMatrix(TSM2);
    destroyTSMatrix(TSM1);

    return 0;
}

// 初始化三元组链表
// 返回值：1 成功，0 失败
int initTSMatrix(TSMatrix * TSM)
{
    // 分配头结点内存
    (*TSM) = (TSMatrix)malloc(sizeof(TupNode));
    if ((*TSM) == NULL)
    {
        // 内存分配失败
        return 0;
    }

    // 初始化头结点
    (*TSM)->row = (*TSM)->col = (*TSM)->dat = 0;    // 头结点不存储数据
    (*TSM)->next = NULL;                            // 初始化后驱指针为空

    return 1;
}

// 插入三元组结点
// 返回值：1 成功，0 失败
int insTupNode(TSMatrix TSM, int row, int col, int dat)
{
    // 如果 TSM 为空，则返回 0
    // 如果 dat 为 0，则不插入该节点，直接返回 1
    if (!TSM)
        return 0;
    if (dat == 0)
        return 1;

    // 找到合适的插入位置：保持 (row, col) 递增顺序
    TupNode * prev = TSM;
    TupNode * curr = TSM->next;
    while (curr != NULL)
    {
        // 如果 curr 比 (row, col) 小，则继续往后
        if (curr->row < row || (curr->row == row && curr->col < col))
        {
            prev = curr;
            curr = curr->next;
        }
        else
        {
            // 如果刚好相等，更新其 dat
            if (curr->row == row && curr->col == col)
            {
                curr->dat = dat;
                return 1;
            }
            // 如果 curr > (row, col) 则在 prev 和 curr 之间插入
            break;
        }
    }

    // 创建新节点
    TupNode * p_new = (TupNode *)malloc(sizeof(TupNode));
    if (!p_new)
    {
        // 内存分配失败
        return 0;
    }
    p_new->row = row;
    p_new->col = col;
    p_new->dat = dat;
    p_new->next = curr;
    prev->next = p_new;

    return 1;
}

// 销毁三元组链表
void destroyTSMatrix(TSMatrix TSM)
{
    // 如果链表本身就是空的，直接返回
    if (TSM == NULL)
    {
        return;
    }

    // 创建指针 p_cur 和 p_next
    // p_cur 用于遍历链表，p_next 用于临时存储下一个结点的地址
    TupNode * p_cur = TSM->next;
    TupNode * p_next;

    // 循环释放所有数据结点
    while (p_cur != NULL)
    {
        p_next = p_cur->next;
        free(p_cur);
        p_cur = p_next;
    }

    // 所有数据结点都释放完毕后，最后释放头结点
    free(TSM);
}

// 相加两个三元组链表
// 返回值：相加后的矩阵
TSMatrix addTSMatrix(TSMatrix TSM1, TSMatrix TSM2)
{
    // 创建新的三元组链表
    TSMatrix TSM = NULL;
    initTSMatrix(&TSM);
    if (!TSM)
        return NULL;

    // 创建指针 p_cur1 和 p_cur2，分别指向两个矩阵的当前结点
    TupNode * p_cur1 = TSM1->next;
    TupNode * p_cur2 = TSM2->next;

    // 遍历两个矩阵
    while (p_cur1 != NULL && p_cur2 != NULL)
    {
        // 如果 p_cur1 < p_cur2，则插入 p_cur1 的数据
        if (p_cur1->row < p_cur2->row || (p_cur1->row == p_cur2->row && p_cur1->col < p_cur2->col))
        {
            insTupNode(TSM, p_cur1->row, p_cur1->col, p_cur1->dat);
            p_cur1 = p_cur1->next;
        }
        // 如果 p_cur1 > p_cur2，则插入 p_cur2 的数据
        else if (p_cur1->row > p_cur2->row || (p_cur1->row == p_cur2->row && p_cur1->col > p_cur2->col))
        {
            insTupNode(TSM, p_cur2->row, p_cur2->col, p_cur2->dat);
            p_cur2 = p_cur2->next;
        }
        // 如果相等，则相加后插入
        else
        {
            insTupNode(TSM, p_cur1->row, p_cur1->col, (p_cur1->dat + p_cur2->dat));
            // 移动到下一个结点
            p_cur1 = p_cur1->next;
            p_cur2 = p_cur2->next;
        }
    }

    // 插入剩余的结点
    while (p_cur1 != NULL)
    {
        insTupNode(TSM, p_cur1->row, p_cur1->col, p_cur1->dat);
        p_cur1 = p_cur1->next;
    }
    while (p_cur2 != NULL)
    {
        insTupNode(TSM, p_cur2->row, p_cur2->col, p_cur2->dat);
        p_cur2 = p_cur2->next;
    }

    // 返回相加后的矩阵
    return TSM;
}

// 打印矩阵
void printTSMatrix(TSMatrix TSM)
{
    // 如果 TSM 为空，则返回
    if (!TSM)
        return;

    // 创建指针 p_cur，指向当前结点
    TupNode * p_cur = TSM->next;
    while (p_cur != NULL)
    {
        // 打印当前结点的行号、列号和元素值
        // 格式：行 列 值
        printf("%d %d %d", p_cur->row, p_cur->col, p_cur->dat);
        p_cur = p_cur->next;
        // 如果不是最后一个结点，则换行
        if (p_cur != NULL)
            printf("\n");
    }
}