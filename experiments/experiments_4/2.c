/*
定义包含两个整型参数的函数该函数将两个参数的值对换。在主函数中声明两个变量，调用该函
数，分别输出调用函数前和调用函数后两个变量的值。
输入描述：两个数
输出描述：调用函数前和调用函数后的值
*/

#include <stdio.h>

void swap_two_integers(int * a, int * b);

int main(void)
{
    int a, b;
    printf("Enter two integers to swap the values: ");
    scanf("%d %d", &a, &b);

    printf("Before swap: %d, %d.\n", a, b);
    swap_two_integers(&a, &b);
    printf("After swap: %d, %d.\n", a, b);

    return 0;
}

void swap_two_integers(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}