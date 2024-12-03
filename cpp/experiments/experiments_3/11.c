/*
将输入的字符串正序和反序连接，形成新串并输出。
输入描述：字符串
输出描述：新字符串
*/

#include <stdio.h>
#include <string.h>
#define LENGTH 80

int main(void)
{
    char str[LENGTH], temp[LENGTH];
    fgets(str, sizeof(str), stdin);
    
    for (int i = 0; i < strlen(str); i++)
    {
        if ('\n' == str[i])
        {
            str[i] = '\0';
        }
    }
    

    for (int i = 0; i < strlen(temp); i++)
    {
        temp[i] = str[strlen(str) - 1 - i];
    }
    strcat(str, temp);

    fputs(str, stdout);
    
    return 0;
}