/*
写一函数实现功能将十进制数改为指数记数。在主函数中调用该函数，对输入的数值计算并输出
结果。
输入描述：一数值
输出描述：对应指数记数
*/

#include <stdio.h>
#define LENGTH 20

char * toindex(int number, char str[]);

int main(void)
{
    int num;
    char index_num[LENGTH];
    printf("Enter a number: ");
    scanf("%d", &num);

    toindex(num, index_num);

    printf("The exponential form of this number is ");
    fputs(index_num, stdout);

    return 0;
}

char * toindex(int number, char str[])
{
    int index = 0;
    double num = (double)number;
    
    sprintf(str, "%lE", num);

    return str;
}