/*
写一函数实现功能找出一列数中最大数所在的位置。在主函数中调用该函数找出输入的一列数中
最大数所在的位置。
输入描述：n个数
输出描述：最大数所在位置
*/

#include <stdio.h>

int * maximum_locate(int arr[], int length);

int main(void)
{
    int n;
    printf("Enter the number of array: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d numbers:\n\t", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    printf("The location of the maximum is %d.",
            maximum_locate(array, n) - array + 1);

    return 0;
}

int * maximum_locate(int arr[], int length)
{
    int * ptr = arr;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > *ptr)
        {
            ptr = &arr[i];
        }
    }

    return ptr;
}