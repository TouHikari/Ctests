/*
使用二维数组，求一个5×5矩阵对角线元素之和。
输入描述：5×5矩阵
输出描述：对角线元素之和
*/

#include <stdio.h>
#define SIDE_LENGTH 5

int main(void)
{
    int matrix[SIDE_LENGTH][SIDE_LENGTH];
    int sum = 0;
    printf("Enter a 5*5 matrix:\n");
    for (int i = 0; i < SIDE_LENGTH; i++)
    {
        for (int j = 0; j < SIDE_LENGTH; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    
    for (int i = 0; i < SIDE_LENGTH; i++)
    {
        sum += matrix[i][i];
        sum += matrix[i][SIDE_LENGTH - 1 - i];
    }
    if (SIDE_LENGTH % 2)
    {
        sum -= matrix[SIDE_LENGTH / 2][SIDE_LENGTH / 2];
    }
    
    printf("The sum of diagonals is %d.\n", sum);

    return 0;
}