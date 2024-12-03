/*
使用“?”运算符为y赋值。为变量x赋值11，判断x>9是否为真，真则将100赋给y，假则y赋值200
并输出结果。使用if…else重复上述运算并输出结果。
输入描述：（无）
输出描述：运算结果
*/

#include <stdio.h>

int main(void)
{
    int x = 11;

    int y = x > 9 ? 100 : 200;
    printf("The value of y is %d.\n", y);

    if (x > 9)
        y = 100;
    else
        y = 200;
    printf("The value of y is %d.\n", y);

    return 0;
}