#include <stdio.h>
#define N 10

int main(void)
{
    int a[N];
    int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int j = 1; j < N; j++)
    {
        for (int i = 0; i < N - j; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
            else
            {
                continue;
            }
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    
    
    return 0;
}