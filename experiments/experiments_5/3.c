/*
定义一个整型变量初始化和一个整型指针变量将整型变量的地址赋值给指针变量；修改整型变量
的值设置；修改指针变量指向的内存单元的值。输出各阶段整型变量、指针变量、指针变量指向
的内存单元的值。
输入描述：（无）
输出描述：各阶段的变量值
*/

#include <stdio.h>

int main(void)
{
    int num = 13;
    int * ptr = &num;
    printf("Step 1: num = %d, ptr = %p, value pointed by ptr = %d.\n",
            num, ptr, *ptr);

    num = 99;
    printf("Step 2: num = %d, ptr = %p, value pointed by ptr = %d.\n",
            num, ptr, *ptr);

    *ptr = 88;
    printf("Step 3: num = %d, ptr = %p, value pointed by ptr = %d.\n",
            num, ptr, *ptr);

    return 0;
}