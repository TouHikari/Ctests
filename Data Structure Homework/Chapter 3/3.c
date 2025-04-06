#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * base;
    int rear;
    int length;
} SqQueue;

int InitQueue(SqQueue *Q, int SIZE);
int EnQueue(SqQueue *Q, int e, int SIZE);
int DeQueue(SqQueue *Q, int *e);
int GetHead(SqQueue Q);

int main(void)
{
    int N;
    scanf("%d", &N);

    SqQueue Q;
    InitQueue(&Q, N);

    char ch = '\0';
    do
    {
        int elem;
        scanf("%d", &elem);
        EnQueue(&Q, elem, N);
        ch = getchar();
    } while (ch != '\n');

    if (Q.length == N)
        printf("yes\n");
    else
        printf("no\n");
    
    int out_num;
    scanf("%d", &out_num);

    int temp;
    do
    {
        DeQueue(&Q, &temp);
    } while (temp != out_num);

    int * p = &Q.base[Q.rear - Q.length];
    for (int i = 0; i < Q.length; i++)
    {
        printf("%d", *p);
        p++;
        if (i != Q.length - 1)
            printf(" ");
    }
    printf("\n");
    printf("%d", GetHead(Q));

    free(Q.base);
    return 0;
}

int InitQueue(SqQueue *Q, int SIZE)
{
    Q->base = (int *)malloc(sizeof(int) * SIZE);
    if (!Q->base)
        return 0;
    Q->rear = Q->length = 0;
    return 1;
}

int EnQueue(SqQueue *Q, int e, int SIZE)
{
    if (Q->length == SIZE)
        return 0;
    Q->base[Q->rear] = e;
    Q->rear++;
    Q->length++;
    return 1;
}

int DeQueue(SqQueue *Q, int *e)
{
    if (Q->length == 0)
        return 0;
    *e = Q->base[Q->rear - Q->length];
    Q->length--;
    return 1;
}

int GetHead(SqQueue Q)
{
    if (Q.length != 0)
        return Q.base[Q.rear - Q.length];
}