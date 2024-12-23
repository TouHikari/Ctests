/*
写两个函数，分别求两个整数的最大公约数和最小公倍数，用主函数调用这两个函数，并输出结果。
输入描述：两个整数
输出描述：最大公约数和最小公倍数
*/

#include <stdio.h>

int greatest_common_divisor(int a, int b);
int least_common_multiple(int a, int b);

int main(void)
{
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("The greatest common divisor of two numbers is %d.\n",
            greatest_common_divisor(a, b));
    printf("The least common multiple of two numbers is %d.\n",
            least_common_multiple(a, b));

    return 0;
}

int greatest_common_divisor(int a, int b)
{
    int result;
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    result = (a < b) ? a : b;
    while (1)
    {
        if (a % result || b % result)
        {
            result--;
        }
        else
        {
            return result;
        }
    }
}

int least_common_multiple(int a, int b)
{
    int result;

    if (a < 0 || b < 0)
    {
        printf("Error: Least common multiple cannot be negative! ");
        printf("(Error code: -1)\n\t*");
        return EOF;
    }
    
    result = (a > b) ? a : b;
    while (1)
    {
    if (result % a || result % b)
    {
        result++;
    }
    else
    {
        return result;
    }   
    }
}