#include <stdio.h>
#include <math.h>

void prime_number(long * array, int n);

int main()
{
    int n;
    scanf("%d", &n);
    long array[n];
    for (int i = 0; i < n; i++)
        scanf("%ld", &array[i]);
    prime_number(array, n);

    return 0;
}

void prime_number(long * array, int n)
{
    int prime_true = 0;
    for (int i = 0; i < n; i++)
    {
        for (long j = 2; j < sqrt(array[i]); j++)
            if (array[i] % j == 0)
                prime_true += 1;
        if (0 == prime_true && array[i] != 1)
            printf("%ld ", array[i]);
        prime_true = 0;
    }

    return;
}