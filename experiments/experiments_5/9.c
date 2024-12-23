/*
定义一个二维数组变量，输出该数组的首地址、每行元素的首地址、每列元素的首地址、一行元素
的长度和。
输入描述：（无）
输出描述：地址和数值
*/

#include <stdio.h>
#define ROW 5
#define COLUMN 3

int main(void)
{
    int arr[ROW][COLUMN] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        1, 5, 9,
        2, 6, 0
    };
    int sum = 0;

    printf("Address of array: %p.\n", arr);
    putchar('\n');

    for (int i = 0; i < ROW; i++)
    {
        printf("Address of row %d: %p.\n", i + 1, arr[i]);
    }
    putchar('\n');

    for (int i = 0; i < COLUMN; i++)
    {
        printf("Address of column %d: %p.\n", i + 1, &arr[0][i]);
    }
    putchar('\n');

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            sum += arr[i][j];
        }
        printf("Sum of row %d: %d.\n", i + 1, sum);
        sum = 0;
    }
    
    return 0;
}