/*
定义并初始化一个整型数组然后定义指针变量，使用该指针变量输出显示整型数组的所有值，
并输出距离指针的距离为3的元素的值。
输入描述：（无）
输出描述：一组数值
*/

#include <stdio.h>

int main(void)
{
    int num[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int temp = 0;
    int * ptr = num;

    printf("The array is:\n\t");
    for (int i = 0; i < sizeof(num) / sizeof(temp); i++)
    {
        printf("%d ", *ptr++);
    }
    ptr--;
    printf("\nThe element with a distance of 3 from the pointer: %d",
            *(ptr - 3));

    return 0;
}