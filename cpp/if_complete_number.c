#include <stdio.h>

int main(void)
{
    int sum;
    for (int i = 2; i <= 10000; i++)
    {
        sum = 0;
        for (int j = 1; j < i; j++)
        {
            if (!(i % j))
            {
                sum += j;
            }
        }
        if (sum == i)
        {
            printf("%d is a complete number.\n", i);
        }
    }
    
    return 0;
}