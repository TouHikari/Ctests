/*
使输入的一个字符串按反序存放，并输出。
输入描述：字符串
输出描述：反序字符串
*/

#include <stdio.h>
#include <string.h>
#define LENGTH 50

int main(void)
{
    char ch[LENGTH], temp[LENGTH];
    printf("Enter a string:\n\t");
    fgets(temp, LENGTH, stdin);

    for (int i = 0; i < strlen(temp); i++)
    {
        ch[i] = temp[strlen(temp) - 2 - i];
    }
    ch[strlen(temp)] = '\0';
    
    printf("The reverse string is: \n\t");
    fputs(ch, stdout);

    return 0;
}