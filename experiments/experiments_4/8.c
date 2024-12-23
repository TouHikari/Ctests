/*
输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。写三个函数：
①输入10个数；②进行处理；③输出10个数。
输入描述：10个整数
输出描述：处理后的十个数
*/

#include <stdio.h>
#define LENGTH 10

int * swap_min_max(int array[], int length);
int * input_array(int array[], int n);
int * output_array(int array[], int n);

int main(void)
{
    int array[LENGTH];
    printf("Enter 10 integers:\n\t");

    input_array(array, LENGTH);
    swap_min_max(array, LENGTH);
    printf("The changed array is:\n\t");
    output_array(array, LENGTH);

    return 0;
}

int * swap_min_max(int array[], int length)
{
    int * ptr_min = &array[0];
    int temp;

    for (int i = 0; i < length; i++)
    {
        if (array[i] < *ptr_min)
        {
            ptr_min = &array[i];
        }
    }
    temp = *ptr_min;
    *ptr_min = array[0];
    array[0] = temp;


    int * ptr_max = &array[0];

    for (int i = 0; i < length; i++)
    {
        if (array[i] > *ptr_max)
        {
            ptr_max = &array[i];
        }
    }
    temp = *ptr_max;
    *ptr_max = array[length - 1];
    array[length - 1] = temp;
    
    return array;
}

int * input_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    
    return array;
}

int * output_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    
    return array;
}