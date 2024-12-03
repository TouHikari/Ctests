/*
使用sizeof运算符计算short int、int、long int、char、float、double、long double
数据类型所占的存储空间。
输入描述：（无）
输出描述：各存储空间值
*/

#include <stdio.h>

int main(void)
{
    printf("Type:        Storage space:\n");
    printf("short int    %-3dBytes\n", sizeof(short int));
    printf("int          %-3dBytes\n", sizeof(int));
    printf("long int     %-3dBytes\n", sizeof(long int));
    printf("char         %-3dBytes\n", sizeof(char));
    printf("float        %-3dBytes\n", sizeof(float));
    printf("double       %-3dBytes\n", sizeof(double));
    printf("long double  %-3dBytes\n", sizeof(long double));

    return 0;
}