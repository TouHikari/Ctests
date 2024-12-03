/*
定义一个函数，用来对字符串数组中的字符串从小到大排序（从左始ASCII码值大的字符串大）
使用二级指针作函数参数。在主函数中定义一个字符串数组，调用该函数对字符串数组排序并输
出排序结果。
输入描述：（无）
输出描述：多个字符串
*/

#include <stdio.h>
#include <string.h>
#define COUNT 5
#define LENGTH 101

void str_sort(char **ptr, int count);

int main(void)
{
    char str_array[COUNT][LENGTH] = {
        "This is the first string.",
        "And the second.",
        "Also, we have the third.",
        "Then the fourth.",
        "Finally, it's the fifth."
    };
    
    char *ptr[COUNT];
    for (int i = 0; i < COUNT; i++)
    {
        ptr[i] = str_array[i];
    }
    
    printf("Original:\n");
    for (int i = 0; i < COUNT; i++)
    {
        printf("\t%s\n", ptr[i]);
    }
    
    str_sort(ptr, COUNT);

    printf("\nSorted:\n");
    for (int i = 0; i < COUNT; i++)
    {
        printf("\t%s\n", ptr[i]);
    }

    return 0;
}

void str_sort(char **ptr, int count)
{
    char *temp;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (strcmp(ptr[j], ptr[j + 1]) > 0)
            {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}