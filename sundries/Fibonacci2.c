#include <stdio.h>

int main(void)
{
    long long f1 = 1, f2 = 1;
    long long f3;
    int count = 0, n;
    printf("Enter how many numbers to print: ");
    scanf("%d", &n);

    printf("%-5lld %-5lld ", f1, f2);
    count += 2;

    for (int i = 0; i <= n; i++)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        printf("%-5lld ", f3);
        count++;
        if (5 == count)
        {
            putchar('\n');
            count = 0;
        }
    }
    
    return 0;
}