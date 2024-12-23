/*
写一函数实现功能求n以内的素数。在主函数中调用该函数计算这些素数的和。
输入描述：n的值
输出描述：素数、素数和
*/

#include <stdio.h>

int prime_number(long array[], int n);

int main(void)
{
    int n, count;
    int sum_prime = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    while (n < 2)
    {
        printf("Invalid input! Enter again: ");
        scanf("%d", &n);
    }

    long temp[n / 2 + 1];
    count = prime_number(temp, n);

    long prime[count];
    printf("The prime numbers within %d:\n\t", n);
    for (int i = 0; i < count; i++)
    {
        prime[i] = temp[i];
        printf("%d ", prime[i]);
        sum_prime += prime[i];
    }
    printf("\nThe sum of these prime numbers is %d.\n", sum_prime);

    return 0;
}

int prime_number(long array[], int n)
{
    int i = 0, count = 0;

    if (2 == n)
    {
        array[count] = 2;
        count++;
    }
    else
    {
        array[count] = 2;
        count++;
        array[count] = 3;
        count++;

        for (int j = 5; j <= n; j += 2)
        {
            for (i = 0; array[i] * array[i] <= j; i++)
            {
                if (j % array[i] == 0)
                {
                    break;
                }
            }
            if (array[i] * array[i] > j)
            {
                array[count] = j;
                count++;
            }
        }
    }

    return count;
}