/*
输入n个整数，对输入的n个数进行排序并输出。
输入描述：n个整数
输出描述：排序后的序列
*/

#include <stdio.h>

int * bubble_sort(int array[], int n);

int main(void)
{
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter %d numbers:\n\t");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("The sorted array is:\n\t");
    bubble_sort(array, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    
    return 0;
}

int * bubble_sort(int array[], int n)
{
    int temp;

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
            else
            {
                continue;
            }
        }
    }
    
    return array;
}