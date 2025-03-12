#include <stdio.h>
#define MAXSIZE 1000

typedef struct {
    int elem[MAXSIZE];
    int last;
} SeqList;

int Locate(SeqList L, int e);
int InsList(SeqList *L, int i, int e);

int main(void)
{
    int elenum;
    scanf("%d", &elenum);

    SeqList L;
    L.last = elenum - 1;
    for (int i = 0; i < elenum; i++)
    {
        scanf("%d", &L.elem[i]);
    }
    
    int addon;
    scanf("%d", &addon);

    InsList(&L, Locate(L, addon), addon);

    for (int i = 0; i <= L.last; i++)
    {
        printf("%d ", L.elem[i]);
    }

    return 0;
}

int Locate(SeqList L, int e)
{
    int i = 0;
    for (; i <= L.last; i++)
    {
        if (L.elem[i] >= e)
            break;
    }

    if (i == L.last)
        return i + 1;
    else
        return i;
}

int InsList(SeqList *L, int i, int e)
{
    int k;
    if (i > L->last + 1)
        return 0;

    for (k = L->last; k >= i; k--)
        L->elem[k + 1] = L->elem[k];
    L->elem[i] = e;
    L->last++;

    return 1;
}