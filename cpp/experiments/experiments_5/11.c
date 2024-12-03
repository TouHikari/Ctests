/*
定义两个函数使用指向一维数组的指针变量传递参数，一个函数用来获取输入的矩阵数据，另一个
用来计算矩阵对角线元素之和。在主函数中定义一个二维数组变量，用来保存矩阵调用这两个函数
计算输入的矩阵对角线元素之和。
输入描述：矩阵元素数值
输出描述：矩阵对角线元素之和
*/

#include <stdio.h>
#define SIZE 5

int * input_matrix(int side_length, int (* matrix)[side_length]);
int sum_diagonal(int side_length, int (* matrix)[side_length]);

int main(void)
{
    int matrix[SIZE][SIZE];
    input_matrix(SIZE, matrix);

    printf("The sum of two diagonals is %d.\n",
            sum_diagonal(SIZE, matrix));

    return 0;
}

int * input_matrix(int side_length, int (* matrix)[side_length])
{
    printf("Input a %d*%d matrix:\n", side_length, side_length);
    for (int i = 0; i < side_length * side_length; i++)
    {
        scanf("%d", &matrix[i / side_length][i % side_length]);
    }

    return *matrix;
}

int sum_diagonal(int side_length, int (* matrix)[side_length])
{
    int result = 0;

    for (int i = 0; i < side_length; i++)
    {
        result += matrix[i][i];
        result += matrix[side_length - 1 - i][side_length - 1 - i];
    }
    if (side_length % 2 == 1)
    {
        result -= matrix[side_length / 2][side_length / 2];
    }

    return result;
}