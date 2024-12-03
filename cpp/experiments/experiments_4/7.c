/*
写一函数，在主函数中调用将两个字符串连接。
输入描述：两行字符串
输出描述：串连后的字符串
*/

#include <stdio.h>
#include <string.h>
#define LENGTH 100

char * strscat(char ch1[], const char ch2[], const int length);

int main(void)
{
    char str1[LENGTH], str2[LENGTH];
    printf("Enter two lines of strings:\n\t");
    fgets(str1, LENGTH, stdin);
    putchar('\t');
    fgets(str2, LENGTH, stdin);

    strscat(str1, str2, LENGTH);

    fputs(str1, stdout);

    return 0;
}

char * strscat(char ch1[], const char ch2[], const int length)
{
    int i;

    if (strchr(ch1, '\n'))
    {
        *strchr(ch1, '\n') = '\0';
    }
    
    int location = strlen(ch1);

    for (i = 0; i < length - location; i++)
    {
        ch1[location + i] = ch2[i];
    }
    ch1[location + i + 1] = '\0';

    return ch1;
}