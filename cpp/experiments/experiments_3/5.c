/*
声明一个字符数组，包含10个元素，接收用户输入，并将数组的值输出。
输入描述：字符串
输出描述：字符串
*/

#include <stdio.h>
#define LENGTH 10

int main(void)
{
    char ch[LENGTH];
    for (int i = 0; i < LENGTH; i++)
    {
        ch[i] = getchar();
    }
    ch[LENGTH - 1] = '\0';

    printf("Your input is \"%s\".\n", ch);
        
    return 0;
}