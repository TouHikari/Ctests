/*
定义一个函数，使用字符串指针作函数参数，用来比较两个字符串的大小（从左始，ASCII码值大
的字符串大）。在主函数中调用该函数，比较输入的两个字符串。
输入描述：两个字符串
输出描述：比较结果
*/

#include <stdio.h>
#define LENGTH 101

int str_cmp(char str1[], char str2[]);

int main(void)
{
    char string1[LENGTH];
    char string2[LENGTH];
    int difference;

    printf("Input two strings:\n\t");
    fgets(string1, LENGTH, stdin);
    putchar('\t');
    fgets(string2, LENGTH, stdin);

    if (!(difference = str_cmp(string1, string2)))
    {
        printf("The two strings are the same.\n");
    }
    else if ((difference = str_cmp(string1, string2)) > 0)
    {
        printf("The first string is bigger. (difference: %d)",
                difference);
    }
    else if ((difference = str_cmp(string1, string2)) < 0)
    {
        printf("The second string is bigger. (difference: %d)",
                difference);
    }

    return 0;
}

int str_cmp(char str1[], char str2[])
{
    int compare = 0, i = 0;

    while (str1[i] != '\0' || str2[i] != '\0')
    {
        compare = str1[i] - str2[i];
        if (compare)
        {
            break;
        }
        i++;
    }

    return compare;
}