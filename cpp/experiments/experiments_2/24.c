/*
声明整型变量a和b并赋值，然后通过计算逻辑表达式a&&b，执行不同的程序代码。如果为逻辑
“真”，则执行语句c=a|b，反之则执行c=!a并输出结果。
输入描述：（无）
输出描述：运算结果
*/

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;
    int c;
    if (a && b)
        c = a | b;
    else
        c = !a;
    printf("The value of c is %d.\n", c);
    
    return 0;
}