/*
定义一个二维数组并赋初值，定义一级指针变量和二级指针变量。分别使用以下方法输出各元素
值使用数组下标方式输出数组各元素值；使用二级指针变量输出数组各元素值。
输入描述：（无）
输出描述：数组各元素值
*/

#include <stdio.h>
#define ROW 3
#define COLUMN 5

int main(void)
{
    int array[ROW][COLUMN] = {
        { 0, 1, 2, 3, 4 },
        { 5, 6, 7, 8, 9 },
        { 1, 3, 5, 7, 9 }
    };
    int * ptr1 = array[0];
    int ** ptr2 = &ptr1;

    printf("Method 1:\n\t");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n\t");
    }

    printf("\nMethon 2:\n\t");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            printf("%d ", *(*ptr2 + (i * COLUMN + j)));
        }
        printf("\n\t");
    }

    return 0;
}