#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 100

typedef struct {
    int * base;
    int front;
    int rear;
} SqQueue;

int InitQueue(SqQueue *Q);
int QueueLength(SqQueue Q);
int EnQueue(SqQueue *Q, int e);
int DeQueue(SqQueue *Q, int *e);
int GetHead(SqQueue Q);

int main(void)
{
    return 0;
}

int InitQueue(SqQueue *Q)
{
    Q->base = (SqQueue *)malloc(sizeof(int) * MAXQSIZE);
    if (!Q->base)
        return 0;
    Q->front = Q->rear = 0;
    return 1;
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

int EnQueue(SqQueue *Q, int e)
{
    if ((Q->rear + 1) % MAXQSIZE == Q->front)
        return 0;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return 1;
}

int DeQueue(SqQueue *Q, int *e)
{
    if (Q->front == Q->rear)
        return 0;
    e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    return 1;
}

int GetHead(SqQueue Q)
{
    if (Q.front != Q.rear)
        return Q.base[Q.front];
}