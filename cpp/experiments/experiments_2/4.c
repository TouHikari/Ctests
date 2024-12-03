/*
输入两个整数a和b，计算a+b的和。
输入描述：输入两个整数
输出描述：两个整数的和
*/

#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Enter the values of a and b: ");
    scanf("%d %d", &a, &b);

    printf("The sum of a and b is %d.\n", a + b);

    return 0;
}