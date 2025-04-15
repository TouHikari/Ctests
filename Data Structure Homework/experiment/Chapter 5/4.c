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
// 相乘十字链表
// 将两个十字链表相乘，结果存储在 result 中
void multiplyCrossList(CrossList * list_A, CrossList * list_B, CrossList * result);

int main(void)
{
    // 读取第一个矩阵的行数、列数
    // 格式：行 列
    int m1, n1;
    scanf("%d %d", &m1, &n1);

    // 初始化第一个十字链表
    CrossList list_A;
    initCrossList(&list_A, m1, n1);

    // 读取第一个矩阵的各元素三元组
    // 格式：行 列 值，以 0 0 0 结束
    while (1)
    {
        // 读取三元组
        int row, col, value;
        scanf("%d %d %d", &row, &col, &value);
        if (row == 0 && col == 0 && value == 0)
        {
            // 结束输入
            break;
        }

        // 插入节点到十字链表
        // 注意：行和列从 1 开始，所以需要减去 1
        insertNode(&list_A, row - 1, col - 1, value);
    }

    // 读取第二个矩阵的行数、列数
    // 格式：行 列
    int m2, n2;
    scanf("%d %d", &m2, &n2);

    // 初始化第二个十字链表
    CrossList list_B;
    initCrossList(&list_B, m2, n2);

    // 读取第二个矩阵的各元素三元组
    // 格式：行 列 值，以 0 0 0 结束
    while (1)
    {
        // 读取三元组
        int row, col, value;
        scanf("%d %d %d", &row, &col, &value);
        if (row == 0 && col == 0 && value == 0)
        {
            // 结束输入
            break;
        }

        // 插入节点到十字链表
        // 注意：行和列从 1 开始，所以需要减去 1
        insertNode(&list_B, row - 1, col - 1, value);
    }

    // 相乘两个十字链表
    // 将结果存储在 result 中
    CrossList result;
    initCrossList(&result, m1, n2); // 结果矩阵的行数为第一个矩阵的行数，列数为第二个矩阵的列数
    multiplyCrossList(&list_A, &list_B, &result);

    // 打印相乘后的结果
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

// 相乘十字链表
// 将两个十字链表相乘，结果存储在 result 中
void multiplyCrossList(CrossList * list_A, CrossList * list_B, CrossList * result)
{
    // 检查矩阵是否可以相乘 (A的列数 == B的行数)
    if (list_A->cols != list_B->rows)
    {
        // 矩阵维度不匹配，无法相乘
        fprintf(stderr, "Error: Matrix dimensions mismatch for multiplication.\n");
        return;
    }

    // 遍历结果矩阵的每一个可能的行 i
    for (int i = 0; i < list_A->rows; i++)
    {
        // 遍历结果矩阵的每一个可能的列 j
        for (int j = 0; j < list_B->cols; j++)
        {
            int sum = 0; // 用于累加 Result[i][j] 的值
            CrossNode * nodeA = list_A->rowHeads[i]; // A 的第 i 行的头指针
            CrossNode * nodeB = list_B->colHeads[j]; // B 的第 j 列的头指针

            // 同时遍历 A 的行 i (按列 k 移动) 和 B 的列 j (按行 k 移动)
            while (nodeA != NULL && nodeB != NULL)
            {
                if (nodeA->col < nodeB->row)
                {
                    // A 的列号 k 太小，移动 A 的指针到同行下一个元素
                    nodeA = nodeA->right;
                }
                else if (nodeA->col > nodeB->row)
                {
                    // B 的行号 k 太小，移动 B 的指针到同列下一个元素
                    nodeB = nodeB->down;
                }
                else // nodeA->col == nodeB->row，找到了匹配的 k
                {
                    // 累加 A[i][k] * B[k][j]
                    sum += nodeA->value * nodeB->value;
                    // 同时移动两个指针，寻找下一个可能的 k
                    nodeA = nodeA->right;
                    nodeB = nodeB->down;
                }
            }

            // 如果累加和不为 0，则将其插入结果矩阵
            if (sum != 0)
            {
                insertNode(result, i, j, sum);
            }
        }
    }
}