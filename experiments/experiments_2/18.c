/*
声明整数变量x、y、z1、z2赋值x=20、y=11计算z1=(x++)+(x++)、z2=(++y)+(++y)、y*=x+2
并分别输出计算结果。
输入描述：（无）
输出描述：计算结果
*/

#include <stdio.h>

int main(void)
{
    int x = 20, y = 11;
    int z1, z2;
    z1 = (x++) + (x++);
    z2 = (++y) + (++y);

    printf("The result of \"z1 = (x++) + (x++)\" is %d.\n", z1);
    printf("The result of \"z2 = (++y) + (++y)\" is %d.\n", z2);
    printf("The result of \"y *= x + 2\" is %d.\n", y *= x + 2);

    return 0;
}