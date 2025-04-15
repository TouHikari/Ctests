#include <stdio.h>
#include <stdlib.h>

// 十字链表的节点定义
typedef struct CrossNode
{
    int row, col;               // 行号和列号
    int value;                  // 节点的值
    struct CrossNode * right;   // 指向同一行的下一个节点
    struct CrossNode * down;    // 指向同一列的下一个节点
} CrossNode;

// 十字链表的头节点定义
typedef struct
{
    int rows, cols;             // 矩阵的行数和列数
    CrossNode ** rowHeads;      // 行头指针数组
    CrossNode ** colHeads;      // 列头指针数组
} CrossList;

// 初始化十字链表
void initCrossList(CrossList * list, int rows, int cols);
// 插入节点
void insertNode(CrossList * list, int row, int col, int value);
// 打印十字链表
void printCrossList(CrossList * list);
// 释放十字链表
void freeCrossList(CrossList * list);
// 相加十字链表
// 将两个十字链表相加，结果存储在 result 中
void addCrossList(CrossList * list_A, CrossList * list_B, CrossList * result);

int main(void)
{
    // 读取矩阵的行数、列数和非零元素个数
    // 格式：行 列 非零元素个数1 非零元素个数2
    int m, n, t1, t2;
    scanf("%d %d %d %d", &m, &n, &t1, &t2);

    // 初始化十字链表
    // list_A 和 list_B 用于存储两个矩阵
    // result 用于存储相加后的结果
    CrossList list_A;
    CrossList list_B;
    CrossList result;
    initCrossList(&list_A, m, n);
    initCrossList(&list_B, m, n);
    initCrossList(&result, m, n);

    // 读取两个矩阵的数据
    // 格式：行 列 值
    for (int i = 0; i < t1; i++)
    {
        int row, col, value;
        scanf("%d %d %d", &row, &col, &value);
        insertNode(&list_A, row - 1, col - 1, value); // 修正输入为 0 索引
    }
    for (int i = 0; i < t2; i++)
    {
        int row, col, value;
        scanf("%d %d %d", &row, &col, &value);
        insertNode(&list_B, row - 1, col - 1, value); // 修正输入为 0 索引
    }

    // 相加两个十字链表
    // 将结果存储在 result 中
    addCrossList(&list_A, &list_B, &result);

    // 打印相加后的结果
    printCrossList(&result);

    // 释放十字链表
    freeCrossList(&result);
    freeCrossList(&list_B);
    freeCrossList(&list_A);

    return 0;
}

// 初始化十字链表
void initCrossList(CrossList * list, int rows, int cols)
{
    // 分配内存并初始化行头指针和列头指针
    list->rows = rows;
    list->cols = cols;
    list->rowHeads = (CrossNode **)calloc(rows, sizeof(CrossNode *));
    list->colHeads = (CrossNode **)calloc(cols, sizeof(CrossNode *));
    if (!list->rowHeads || !list->colHeads)
    {
        // 内存分配失败，释放已分配的内存并退出
        free(list->rowHeads);
        free(list->colHeads);
        exit(EXIT_FAILURE);
    }
}

// 插入节点
void insertNode(CrossList * list, int row, int col, int value)
{
    if (value == 0)
    {
        // 不存储零值
        return;
    }

    // 创建新节点
    CrossNode * newNode = (CrossNode *)malloc(sizeof(CrossNode));
    if (!newNode)
    {
        // 内存分配失败，释放已分配的内存并退出
        free(newNode);
        exit(EXIT_FAILURE);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->right = NULL;
    newNode->down = NULL;

    // 插入到行链表
    CrossNode ** rowPtr = &list->rowHeads[row];
    while (*rowPtr && (*rowPtr)->col < col)
    {
        rowPtr = &(*rowPtr)->right;
    }
    newNode->right = *rowPtr;
    *rowPtr = newNode;

    // 插入到列链表
    CrossNode ** colPtr = &list->colHeads[col];
    while (*colPtr && (*colPtr)->row < row)
    {
        colPtr = &(*colPtr)->down;
    }
    newNode->down = *colPtr;
    *colPtr = newNode;
}

// 打印十字链表
void printCrossList(CrossList * list)
{
    for (int i = 0; i < list->rows; i++)
    {
        CrossNode * current = list->rowHeads[i];
        while (current)
        {
            // 输出为 1 索引
            printf("%d %d %d\n", current->row + 1, current->col + 1, current->value);
            current = current->right;
        }
    }
}

// 释放十字链表
void freeCrossList(CrossList * list)
{
    for (int i = 0; i < list->rows; i++)
    {
        CrossNode * current = list->rowHeads[i];
        while (current)
        {
            CrossNode * temp = current;
            current = current->right;
            free(temp);
        }
    }
    free(list->rowHeads);
    free(list->colHeads);
}

// 相加十字链表
void addCrossList(CrossList * list_A, CrossList * list_B, CrossList * result)
{
    for (int i = 0; i < list_A->rows; i++)
    {
        // 创建两个结点指针用于遍历两个十字链表
        CrossNode * currentA = list_A->rowHeads[i];
        CrossNode * currentB = list_B->rowHeads[i];
        
        while (currentA || currentB)
        {
            int col;
            int value = 0;

            if (currentA && (!currentB || currentA->col < currentB->col))
            {
                col = currentA->col;
                value = currentA->value;
                currentA = currentA->right;
            }
            else if (currentB && (!currentA || currentB->col < currentA->col))
            {
                col = currentB->col;
                value = currentB->value;
                currentB = currentB->right;
            }
            else
            {
                col = currentA->col;
                value = currentA->value + currentB->value;
                currentA = currentA->right;
                currentB = currentB->right;
            }

            if (value != 0)
            {
                insertNode(result, i, col, value);
            }
        }
    }
}