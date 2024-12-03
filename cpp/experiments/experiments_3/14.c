/*
输入一串字符将其中的大写变成小写，并将新的字符串输出。
输入描述：字符串
输出描述：新字符串
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 81

int main(void)
{
    char str[LENGTH];
    printf("Enter a string:\n\t");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; i < strlen(str); i++)
    {
        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
    
    printf("The new string is:\n\t");
    fputs(str, stdout);
    
    return 0;
}