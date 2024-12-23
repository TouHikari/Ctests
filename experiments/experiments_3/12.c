/*
输入10个整数，使用数组求它们的平均值，并输出大于平均值的数据的个数。
输入描述：10个整数
输出描述：平均值、个数
*/

#include <stdio.h>
#include <string.h>
#define LENGTH 10

int main(void)
{
    int array[LENGTH];
    int count = 0;
    double avrg = 0.;
    printf("Enter 10 integers: ");
    for (int i = 0; i < LENGTH; i++)
    {
        scanf("%d", &array[i]);
        avrg += array[i];
    }

    avrg /= LENGTH;
    for (int i = 0; i < LENGTH; i++)
    {
        if (array[i] > avrg)
        {
            count++;
        }
    }

    printf("The average is %lf.\n", avrg);
    printf("The number of those bigger than average is %d.", count);
    
    return 0;
}