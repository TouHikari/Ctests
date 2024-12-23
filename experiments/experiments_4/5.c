/*
声明和定义一个递归函数，计算n的阶乘。
输入描述：一个自然数n
输出描述：n的阶乘
*/

#include <stdio.h>

long long factorial(int n);

int main(void)
{
    int n;
    scanf("%d", &n);

    printf("The factorial of n is %lld.\n",
            factorial(n));

    return 0;
}

long long factorial(int n)
{
    if (n > 0)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}