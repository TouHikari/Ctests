/*
定义一个二维数组变量，使用指针变量对二维数组赋值（使用单循环），并使用指针变量输出二维
数组元素值单循环。
输入描述：（无）
输出描述：数组元素值
*/

#include <stdio.h>
#define ROW 5
#define COLUMN 3

int main(void)
{
    int arr[ROW][COLUMN];
    int * ptr = arr[0];

    for (int i = 0; i < ROW * COLUMN; i++)
    {
        *ptr++ = (i + 1) * 2;
    }
    
    ptr = arr[0];
    for (int i = 0; i < ROW * COLUMN; i++)
    {
        printf("%-3d", *ptr++);
        if (!((i + 1) % COLUMN))
        {
            putchar('\n');
        }
    }
    

    return 0;
}