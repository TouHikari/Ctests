#include <stdio.h>
#include <stdlib.h>

typedef struct TupNode
{
    int row;        // 行号
    int col;        // 列号
    int dat;        // 元素值
    struct TupNode * next; // 后驱结点指针
} TupNode, * TSMatrix;  // 三元组结点定义

int initTSMatrix(TSMatrix * TSM);
int insTupNode(TSMatrix TSM, int row, int col, int dat);
void destroyTSMatrix(TSMatrix TSM);
TSMatrix PlusTSMatrix(TSMatrix A, TSMatrix B);

int main(void)
{
    TSMatrix A, B, C;
    initTSMatrix(&A);
    initTSMatrix(&B);
    initTSMatrix(&C);

    int t1, t2, t3;
    scanf("%d %d", &t1, &t2);
    t3 = t1 + t2;
    for (int i = 0; i < t1; i++)
    {
        int row, col, dat;
        scanf("%d %d %d", &row, &col, &dat);
        insTupNode(A, row, col, dat);
    }
    for (int i = 0; i < t2; i++)
    {
        int row, col, dat;
        scanf("%d %d %d", &row, &col, &dat);
        insTupNode(B, row, col, dat);
    }

    C = PlusTSMatrix(A, B);

    for (TupNode * p = C->next; p != NULL; p = p->next)
    {
        printf("%d %d %d\n", p->row, p->col, p->dat);
    }

    destroyTSMatrix(A);
    destroyTSMatrix(B);
    destroyTSMatrix(C);

    return 0;
}

int initTSMatrix(TSMatrix * TSM)
{
    (*TSM) = (TSMatrix)malloc(sizeof(TupNode));
    if ((*TSM) == NULL)
        return 0;
    (*TSM)->row = (*TSM)->col = (*TSM)->dat = 0;
    (*TSM)->next = NULL;
    return 1;
}

int insTupNode(TSMatrix TSM, int row, int col, int dat)
{
    if (!TSM) return 0;
    if (dat == 0) return 1; // 如果不希望保存 dat=0 的节点，可直接跳过

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
                curr->dat += dat; // 根据需求可改为覆盖 curr->dat = dat
                // 如果更新后为 0，可以选择删除该节点
                if (curr->dat == 0)
                {
                    prev->next = curr->next;
                    free(curr);
                }
                return 1;
            }
            // 如果 curr > (row, col) 则在 prev 和 curr 之间插入
            break;
        }
    }

    // 创建新节点
    TupNode * p_new = (TupNode *)malloc(sizeof(TupNode));
    if (!p_new) return 0;
    p_new->row = row;
    p_new->col = col;
    p_new->dat = dat;
    p_new->next = curr;
    prev->next = p_new;

    return 1;
}

void destroyTSMatrix(TSMatrix TSM)
{
    TupNode * p_cur, * p_rear;
    p_cur = TSM->next;
    p_rear = TSM;
    while (p_cur != NULL)
    {
        p_rear = p_cur;
        p_cur = p_cur->next;
        free(p_rear);
    }
    free(TSM);
}

TSMatrix PlusTSMatrix(TSMatrix A, TSMatrix B)
{
    if (!A || !B) return NULL;

    TSMatrix C;
    initTSMatrix(&C);

    TupNode * p_a = A->next;
    TupNode * p_b = B->next;
    TupNode * p_c = C; // p_c 指向新表的头结点

    while (p_a != NULL && p_b != NULL)
    {
        // 比较 (row, col) 大小
        if (p_a->row < p_b->row ||
            (p_a->row == p_b->row && p_a->col < p_b->col))
        {
            // 新建节点链接到 C 的尾部
            TupNode * p_new = (TupNode *)malloc(sizeof(TupNode));
            p_new->row = p_a->row;
            p_new->col = p_a->col;
            p_new->dat = p_a->dat;
            p_new->next = NULL;

            p_c->next = p_new;
            p_c = p_new;
            p_a = p_a->next;
        }
        else if (p_a->row > p_b->row ||
            (p_a->row == p_b->row && p_a->col > p_b->col))
        {
            TupNode * p_new = (TupNode *)malloc(sizeof(TupNode));
            p_new->row = p_b->row;
            p_new->col = p_b->col;
            p_new->dat = p_b->dat;
            p_new->next = NULL;

            p_c->next = p_new;
            p_c = p_new;
            p_b = p_b->next;
        }
        else
        {
            // 相同行列下标，dat 相加
            int sum = p_a->dat + p_b->dat;
            // 如果 sum != 0 则插入
            if (sum != 0)
            {
                TupNode * p_new = (TupNode *)malloc(sizeof(TupNode));
                p_new->row = p_a->row;
                p_new->col = p_a->col;
                p_new->dat = sum;
                p_new->next = NULL;

                p_c->next = p_new;
                p_c = p_new;
            }
            // 同时前进
            p_a = p_a->next;
            p_b = p_b->next;
        }
    }

    // 将剩余的 A、B 直接挂到 C 后面
    while (p_a != NULL)
    {
        TupNode * p_new = (TupNode *)malloc(sizeof(TupNode));
        p_new->row = p_a->row;
        p_new->col = p_a->col;
        p_new->dat = p_a->dat;
        p_new->next = NULL;

        p_c->next = p_new;
        p_c = p_new;
        p_a = p_a->next;
    }
    while (p_b != NULL)
    {
        TupNode * p_new = (TupNode *)malloc(sizeof(TupNode));
        p_new->row = p_b->row;
        p_new->col = p_b->col;
        p_new->dat = p_b->dat;
        p_new->next = NULL;

        p_c->next = p_new;
        p_c = p_new;
        p_b = p_b->next;
    }

    return C;
}