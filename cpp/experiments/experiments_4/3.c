/*
定义包含两个参数的函数该函数实现两个整数的对换。在主函数中声明两个变量，调用该函数对
两个变量值对换并输出。
输入描述：两个数
输出描述：对换的数
*/

#include <stdio.h>

void swap_two_integers(int a, int b);

int main(void)
{
    int a, b;
    printf("Enter two integers to swap the values: ");
    scanf("%d %d", &a, &b);

    swap_two_integers(a, b);

    return 0;
}

void swap_two_integers(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("After swap: %d, %d.\n", a, b);

    return;
}