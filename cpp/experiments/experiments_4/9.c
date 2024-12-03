/*
写一函数实现功能有n个整数，使前面各数顺序向后移m个位置，最后m个数变成前面m个数。
在主函数中调用该函数处理数据。
输入描述：个数n、n个整数、移动的位置m
输出描述：处理后的数
*/

#include <stdio.h>

int * cycle_array(int array[], int length, int move_num);

int main(void)
{
    int n, m;
    printf("Enter the nunber of integers: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Enter the numbers:\n\t");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    
    printf("Enter the cycle number: ");
    scanf("%d", &m);

    cycle_array(numbers, n, m);
    printf("The cycled array is:\n\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}

int * cycle_array(int array[], int length, int move_num)
{
    int temp;

    for (int i = 0; i < move_num; i++)
    {
        temp = array[length - 1];
        for (int j = length - 1; j > 0; j--)
        {
            array[j] = array[j - 1];
        }
        array[0] = temp;
    }
    
    return array;
}