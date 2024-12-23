/*
定义一个一维数组并赋初值，定义一级指针变量和二级指针变量。分别使用以下方法输出各元素
值使用数组下标方式输出各元素值；使用一级指针变量输出各元素值；使用二级指针变量输出数
组各元素值。
输入描述：（无）
输出描述：数组各元素值
*/

#include <stdio.h>
#define LENGTH 10

int main(void)
{
    int array[LENGTH] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int * ptr1 = array;
    int ** ptr2 = &ptr1;

    printf("Method 1:\n\t");
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\nMethod 2:\n\t");
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%d ", *(ptr1 + i));
    }
    
    printf("\nMethod 3:\n\t");
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%d ", *(*ptr2 + i));
    }

    return 0;
}