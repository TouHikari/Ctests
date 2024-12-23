/*
定义一个二维数组变量，使用取地址运算得到该变量的地址，使用sizeof运算符得该变量占用的
内存单元数量，并输出该变量的地址和内存单元数量。
输入描述：（无）
输出描述：地址和数值
*/

#include <stdio.h>
#define ROW 2
#define COLUMN 3

int main(void)
{
    int arr[ROW][COLUMN] = {
        1, 2, 3,
        7, 8, 9
    };
    
    printf("Address: %p.\n", &arr[0][0]);
    printf("Memory occupied: %d.\n", sizeof(arr));

    return 0;
}