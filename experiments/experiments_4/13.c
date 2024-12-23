/*
写一函数实现功能将字符串的大写变成小写。在主函数中调用该函数对输入的字符串操作并输出
结果。
输入描述：字符串
输出描述：新字符串
*/

#include <stdio.h>
#define LENGTH 101

char * ToUpper(char str[]);

int main(void)
{
    char str[LENGTH];
    printf("Enter a string:\n\t");
    fgets(str, LENGTH, stdin);

    printf("The new string is:\n\t");
    fputs(ToUpper(str), stdout);

    return 0;
}

char * ToUpper(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
    
    return str;
}