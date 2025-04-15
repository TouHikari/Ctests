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

void initCrossList(CrossList * list, int rows, int cols);
void insertNode(CrossList * list, int row, int col, int value);
void printCrossList(CrossList * list);
void freeCrossList(CrossList * list);
void addCrossList(CrossList * list_A, CrossList * list_B, CrossList * result);

int main(void)
{
    int m, n, t1, t2;
    scanf("%d %d %d %d", &m, &n, &t1, &t2);

    CrossList list_A;
    initCrossList(&list_A, m, n);
    CrossList list_B;
    initCrossList(&list_B, m, n);
    CrossList result;
    initCrossList(&result, m, n);

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

    addCrossList(&list_A, &list_B, &result);

    printCrossList(&result);

    freeCrossList(&list_A);
    freeCrossList(&list_B);
    freeCrossList(&result);

    return 0;
}

// 初始化十字链表
void initCrossList(CrossList * list, int rows, int cols)
{
    list->rows = rows;
    list->cols = cols;
    list->rowHeads = (CrossNode **)calloc(rows, sizeof(CrossNode *));
    list->colHeads = (CrossNode **)calloc(cols, sizeof(CrossNode *));
}

// 插入节点
void insertNode(CrossList * list, int row, int col, int value)
{
    if (value == 0) return; // 不存储零值
    CrossNode * newNode = (CrossNode *)malloc(sizeof(CrossNode));
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
            printf("%d %d %d\n", current->row + 1, current->col + 1, current->value); // 输出为 1 索引
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