/*
声明和定义排序函数。在主函数中调用该函数实现对数组的排序并输出。
输入描述：一组数
输出描述：排序后的序列
*/

#include <stdio.h>
#define LENGTH 10

int * selection_sort(int array[], int length);

int main(void)
{
    int array[LENGTH];
    printf("Enter %d numbers to sort:\n\t", LENGTH);
    for (int i = 0; i < LENGTH; i++)
    {
        scanf("%d", &array[i]);
    }
    
    selection_sort(array, LENGTH);

    printf("The sorted array is:\n");
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}

int * selection_sort(int array[], int length)
{
    int temp;

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[i])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return array;
}