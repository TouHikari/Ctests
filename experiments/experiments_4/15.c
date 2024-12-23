/*
写一函数实现功能求三个自然数的最大数。在主函数中调用该函数，对输入的数值计算并输出结果。
输入描述：一串数值
输出描述：前三个数的最大数
*/

#include <stdio.h>

int max_of_three(void);

int main(void)
{
    printf("Enter a string of numbers:\n\t");

    printf("The maximum of the first three numbers is %d.",
            max_of_three());

    return 0;
}

int max_of_three(void)
{
    int max, temp;

    scanf("%d", &max);
    scanf("%d", &temp);
    max = (temp > max) ? temp : max;
    scanf("%d", &temp);
    max = (temp > max) ? temp : max;

    while (getchar() != '\n')
        continue;
    
    return max;
}