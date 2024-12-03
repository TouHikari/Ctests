/*
定义2个整型变量初始化和3个整型指针变量pmax、pmin、pt用指针变量比较两个整型变量的值，
并用pmax保存较大数的地址pmin保存较小数的地址然后用pmax和pmin输出较大值和较小值。
输入描述：（无）
输出描述：两个整数值
*/

#include <stdio.h>

int main(void)
{
    int num1 = 13, num2 = 99;
    int * pmax = &num1;
    int * pmin = &num1;
    int * pt = &num2;

    pmax = (*pmax > *pt) ? pmax : pt;
    pmin = (*pmin < *pt) ? pmin : pt;

    printf("max = %d, min = %d.\n", *pmax, *pmin);

    return 0;
}