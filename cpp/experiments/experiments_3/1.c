/*
定义一个float数组存储输入的n个值计算数组的总和与平均值并输出。
输入描述：n个数值
输出描述：总和、平均值
*/

#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    float array[n], avrg;
    float sum = 0.;

    printf("Enter all the numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &array[i]);
        sum += array[i];
    }
    avrg = sum / n;

    printf("The sum is %f. \nThe average is %f.\n",
            sum, avrg);

    return 0;
}