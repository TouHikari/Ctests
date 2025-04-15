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
// 矩阵转置
// 返回值：转置后的矩阵
TSMatrix transposeTSMatrix(TSMatrix TSM);
// 打印矩阵
void printTSMatrix(TSMatrix TSM);

int main(void)
{
    // 创建三元组链表
    // 头结点不存储数据，实际数据从头结点的 next 开始存储
    TSMatrix TSM;
    initTSMatrix(&TSM);
    if (!TSM)
    {
        // 初始化失败
        destroyTSMatrix(TSM);
        return 1;
    }

    // 读取行数和列数
    // 输入格式：行 列
    int rows, cols;
    scanf("%d %d", &rows, &cols); // 行数和列数在该程序中未使用

    // 输入三元组数据
    // 输入格式：行 列 值，0 0 0 结束
    int row, col, dat;
    scanf("%d %d %d", &row, &col, &dat);
    while (!(row == 0 && col == 0 && dat == 0))
    {
        if (!insTupNode(TSM, row, col, dat))
        {
            // 插入失败，可能是内存不足等原因
            destroyTSMatrix(TSM);
            return 1;
        }
        scanf("%d %d %d", &row, &col, &dat);
    }

    // 创建转置矩阵
    TSMatrix transposed = transposeTSMatrix(TSM);
    if (!transposed)
    {
        // 转置失败，可能是内存不足等原因
        destroyTSMatrix(TSM);
        return 1;
    }

    // 打印转置矩阵
    printTSMatrix(transposed);

    // 销毁矩阵
    destroyTSMatrix(transposed);
    destroyTSMatrix(TSM);

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
    if (TSM == NULL) {
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

// 矩阵转置
// 返回值：转置后的矩阵
TSMatrix transposeTSMatrix(TSMatrix TSM)
{
    // 如果 TSM 为空，则返回 NULL
    if (!TSM)
        return NULL;

    // 创建转置矩阵
    // 头结点不存储数据，实际数据从头结点的 next 开始存储
    TSMatrix TSM_transpose;
    initTSMatrix(&TSM_transpose);
    if (!TSM_transpose)
    {
        // 如果内存分配失败，则返回 NULL
        return NULL;
    }

    // 创建指针 p_cur，指向当前结点
    // 遍历原矩阵 TSM 的每个结点，将其转置后插入到 TSM_transpose 中
    TupNode * p_cur = TSM->next;
    while (p_cur != NULL)
    {
        insTupNode(TSM_transpose, p_cur->col, p_cur->row, p_cur->dat);
        p_cur = p_cur->next;
    }

    // 返回转置后的矩阵
    return TSM_transpose;
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