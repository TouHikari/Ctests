/*
用简单素数筛选法求n以内的素数并计算后m个素数的和。
输入描述：n和m值
输出描述：素数，后m个素数的和
*/

#include <stdio.h>
#include <math.h>

int is_prime(int n);

int main(void)
{
    int n, m;
    int sum = 0;
    int count = 0;
    printf("Enter a number n, to know the prime numbers\n");
    printf("below it and the sum of the last m ones.\n\n");

    printf("The number n is: ");
    while (!scanf("%d", &n) || n < 2)
    {
        printf("Illegal input! Try again!\n");
        printf("The number n is: ");
    }
    
    printf("The number m is: ");
    while (!scanf("%d", &m) || m > n)
    {
        printf("Illegal input! Try again!\n");
        printf("The number m is: ");
    }

    int prime[n];
    for (int i = 2; i <= n; i++)
    {
        if (is_prime(i))
        {
            prime[count++] = i;
        }
    }

    for (int i = count - m; i < count; i++)
    {
        sum += prime[i];
    }

    printf("\nAll the prime numbers:");
    for (int i = 0; i < count; i++)
    {
        printf(" %-1d", prime[i]);
    }
    printf(".\nThe sum of the last %d ones: %d.", m, sum);
    
    return 0;
}

int is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}