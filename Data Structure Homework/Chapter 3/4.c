#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * base;
    int front;
    int rear;
} SqQueue;

int InitQueue(SqQueue *Q, int SIZE);
int QueueLength(SqQueue Q, int SIZE);
int EnQueue(SqQueue *Q, int e, int SIZE);
int DeQueue(SqQueue *Q, int *e, int SIZE);
int GetHead(SqQueue Q);
void PrintQueue(SqQueue Q, int SIZE);
void Fibonacci(int max, int k);

int main(void)
{
    int max, k;
    scanf("%d %d", &max, &k);
    Fibonacci(max, k);
    return 0;
}

int InitQueue(SqQueue *Q, int SIZE)
{
    Q->base = (int *)malloc(sizeof(int) * SIZE);
    if (Q->base == NULL)
        return 0;
    Q->front = Q->rear = 0;
    return 1;
}

int QueueLength(SqQueue Q, int SIZE)
{
    return (Q.rear - Q.front + SIZE) % SIZE;
}

int EnQueue(SqQueue *Q, int e, int SIZE)
{
    if ((Q->rear + 1) % SIZE == Q->front)
        return 0;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % SIZE;
    return 1;
}

int DeQueue(SqQueue *Q, int *e, int SIZE)
{
    if (Q->front == Q->rear)
        return 0;
    if (e != NULL)
        *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % SIZE;
    return 1;
}

int GetHead(SqQueue Q)
{
    if (Q.front != Q.rear)
        return Q.base[Q.front];
}

void PrintQueue(SqQueue Q, int SIZE)
{
    int len = QueueLength(Q, SIZE);
    for (int i = 0; i < len; i++)
    {
        int idx = (Q.front + i) % SIZE;
        printf("%d", Q.base[idx]);
        if (i != len - 1)
            printf(" ");
    }
}

void Fibonacci(int max, int k)
{
    SqQueue arr;
    InitQueue(&arr, k + 1);

    for (int i = 0; i < k - 1; i++)
    {
        EnQueue(&arr, 0, k + 1);
    }
    EnQueue(&arr, 1, k + 1);

    while (1)
    {
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            int idx = (arr.front + i) % (k + 1);
            sum += arr.base[idx];
        }

        if (sum > max)
            break;

        DeQueue(&arr, NULL, k + 1);
        EnQueue(&arr, sum, k + 1);
    }

    PrintQueue(arr, k + 1);

    free(arr.base);
}