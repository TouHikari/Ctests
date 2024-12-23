/*
定义两个整型变量初始化不同值和一个整型指针变量，使指针变量指向第一个整型变量，输出
整型指针变量指向的内存值。然后使指针变量指向第二个整型变量，输出整型指针变量指向的
内存值。
输入描述：（无）
输出描述：内存值
*/

#include <stdio.h>

int main(void)
{
    int num1 = 13, num2 = 99;
    int * ptr = &num1;
    printf("The value pointed by ptr is %d.\n", *ptr);

    ptr = &num2;
    printf("Now the value pointed by ptr is %d.\n", *ptr);

    return 0;
}