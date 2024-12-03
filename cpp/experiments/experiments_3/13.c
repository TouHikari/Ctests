/*
输入一个字符串，将组成字符串的所有非英文字母的字符删除后输出。
输入描述：字符串
输出描述：新字符串
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 81

void str_moveforward(char str[], int order);

int main(void)
{
    char str[LENGTH];
    printf("Enter a string:\n\t");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';
    
    for (int i = 0; i < strlen(str); )
    {
        if (!(isalpha(str[i])))
        {
            str_moveforward(str, i);
        }
        else
        {
            i++;
        }
    }
    
    printf("Your string with only letters is:\n\t");
    fputs(str, stdout);
    
    return 0;
}

void str_moveforward(char str[], int order)
{
    while (str[order])
    {
        str[order] = str[order + 1];
        order++;
    }
    
    return;
}