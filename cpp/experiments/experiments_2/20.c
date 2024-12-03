/*
声明变量a和b并赋值，分别执行按位与运算、按位或运算、按位异或运算、按位取反运算、左移
两位运算、右移三位运算来为变量z赋值并输出计算结果。
输入描述：（无）
输出描述：计算结果
*/

#include <stdio.h>

int main(void)
{
    int a = 100, b = 125;
    int z;

    printf("a = %d, b = %d.\n", a, b);
    z = a & b;
    printf("The result of \"z = a & b\" is %d.\n", z);
    z = a | b;
    printf("The result of \"z = a | b\" is %d.\n", z);
    z = a ^ b;
    printf("The result of \"z = a ^ b\" is %d.\n", z);
    z = ~ a;
    printf("The result of \"z = ~ a\" is %d.\n", z);
    z = ~ b;
    printf("The result of \"z = ~ b\" is %d.\n", z);
    z = a << 2;
    printf("The result of \"z = a << 2\" is %d.\n", z);
    z = b << 2;
    printf("The result of \"z = b << 2\" is %d.\n", z);
    z = a >> 3;
    printf("The result of \"z = a >> 3\" is %d.\n", z);
    z = b >> 3;
    printf("The result of \"z = b >> 3\" is %d.\n", z);

    return 0;
}