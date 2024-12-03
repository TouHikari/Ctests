/*
有三个整数a、b、c，由键盘输入，使用if条件语句编程输出其中的最大的数。
输入描述：三个整数
输出描述：最大数
*/

#include <stdio.h>

int main(void)
{
    int a, b, c;
    int max = a;
    printf("Enter the values of a, b and c: ");
    scanf("%d %d %d", &a, &b, &c);

    if (max < b)
        max = b;
    if (max < c)
        max = c;
    
    printf("The maximum among a, b and c is %d.\n", max);
    
    return 0;
}