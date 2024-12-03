/*
定义整数变量a、b和z，接着为变量a和b赋值，然后通过逗号运算符为变量z赋值z=(a++,++b+a)
并输出运算结果。
输入描述：（无）
输出描述：运算结果
*/

#include <stdio.h>

int main(void)
{
    int a, b, z;
    a = 10;
    b = 20;
    z = (a++, ++b + a);

    printf("a = %d, b = %d, z = %d.\n", a, b, z);

    return 0;
}