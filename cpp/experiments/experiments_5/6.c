/*
写一函数使用指针变量作为形参，对字符串进行倒置操作。在主函数中定义一个字符串变量并
初始化，调用定义的函数对该字符串进行倒置操作，并输出操作前和操作后的变量值。
输入描述：（无）
输出描述：字符串、倒置字符串
*/

#include <stdio.h>
#include <string.h>

char * strrvs(char * ptr, int length);

int main(void)
{
    char str[] = {"This is a string."};
    char * ptr = str;

    printf("Before: str = \"%s\".\n", str);

    strrvs(ptr, strlen(str));

    printf("After: str = \"%s\".\n", str);

    return 0;
}

char * strrvs(char * ptr, int length)
{
    char temp[length];

    for (int i = 0; i < length; i++)
    {
        temp[i] = *(ptr + length - 1 - i);
    }
    for (int i = 0; i < length; i++)
    {
        *(ptr + i) = temp[i];
    }
    *(ptr + length) = '\0';

    return ptr;
}