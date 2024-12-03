/*
声明字符型变量a赋值为‘A’，然后将其地址赋给指针型变量p，最后将地址p中的数值赋给字符型
变量b并输出b的值。
输入描述：（无）
输出描述：变量b的值
*/

#include <stdio.h>

int main(void)
{
    char a = 'A';
    char * p = &a;
    char b = *p;

    printf("The value of b is %d.\n", b);

    return 0;
}