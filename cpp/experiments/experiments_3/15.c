/*
输入n个整数存放在数组a中，输出最大数所在位置。
输入描述：n个整数
输出描述：最大数所在位置
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int n;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    const int * max = a;
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] > *max)
        {
            max = &a[i];
        }
    }
    
    printf("The location of the maximum is %d.", max - a);
    
    return 0;
}