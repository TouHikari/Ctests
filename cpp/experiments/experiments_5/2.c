/*
定义两个int型变量，并给两个变量赋初值。定义一个类型为float的指针变量。通过指针变量
使用间接寻址运算符将一个整型变量内存单元的值赋值给另一个整型变量并输出赋值前和赋值
后的值。
输入描述：（无）
输出描述：赋值前和赋值后的值
*/

#include <stdio.h>

int main(void)
{
    int num1 = 13, num2 = 99;
    float * ptr;

    printf("Originally num1 = %d, num2 = %d.\n", num1, num2);

    *ptr = num1;
    num2 = *ptr;

    printf("Now num1 = %d, num2 = %d.\n", num1, num2);

    return 0;
}