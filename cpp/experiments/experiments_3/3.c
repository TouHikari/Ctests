/*
定义一个3×3二维数组，分别用4种方式获取数组的首地址，分别用3种方式获取每一行的首地
址，并将结果输出。
输入描述：（无）
输出描述：数组首地址、每一行的首地址
*/

#include <stdio.h>
#define LENGTH 3

int main(void)
{
    int array[LENGTH][LENGTH] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };

    printf("Head address of the array: %p.\n", array);
    printf("Head address of the array: %p.\n", array[0]);
    printf("Head address of the array: %p.\n", &array[0][0]);
    printf("Head address of the array: %p.\n", (array[0] + 0));

    putchar('\n');

    printf("Head address of line 0: %p.\n", array);
    printf("Head address of line 1: %p.\n", array[1]);
    printf("Head address of line 2: %p.\n", &array[2][0]);

    return 0;
}