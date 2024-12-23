/*
使用二维数组，将输入的5×5二维数组转置，即行列互换。
输入描述：5×5矩阵
输出描述：转置后的矩阵
*/

#include <stdio.h>
#define LENGTH 5

int main(void)
{
    int array[LENGTH][LENGTH];
    int temp[LENGTH][LENGTH];
    printf("Enter the 5*5 array: \n");
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            scanf("%d", &temp[i][j]);
        }
    }

    printf("The changed matrix is:\n");
    
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            array[i][j] = temp[j][i];
            printf("%d ", array[i][j]);
        }
        putchar('\n');
    }

    return 0;
}