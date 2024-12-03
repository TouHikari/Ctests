/*
输入一行字符串（可能含有空格）原样输出，再将字符串以空格分割依次按行输出
输入描述：一行字符串
输出描述：若干行子串
*/

#include <stdio.h>
#include <string.h>
#define LENGTH 80

int main(void)
{
    char ch[LENGTH], temp[LENGTH];
    fgets(ch, sizeof(ch), stdin);
    strcpy(temp, ch);

    fputs(ch, stdout);

    for (int i = 0; i < strlen(temp); i++)
    {
        if (' ' == temp[i])
        {
            temp[i] = '\n';
        }
    }
    
    fputs(temp, stdout);

    return 0;
}