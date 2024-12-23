/*
定义整型变量i赋值奇数，计算i/2。再使用(float)强制类型转换后计算。分别输出计算结果。
输入描述：（无）
输出描述：计算结果
*/

#include <stdio.h>

int main(void)
{
    int i = 9;

    printf("The result of i/2 is %d.\n", i / 2);
    printf("The result of (float)i/2 is %f.", (float)i / 2);

    return 0;
}