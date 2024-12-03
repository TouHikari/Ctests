/*
编写一函数，统计字符串中字母、数字、空格和其它字符的个数，在主函数中输入字符串以及输
出上述结果。
输入描述：一行字符串
输出描述：4个数字统计数据
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 101

int * ch_statistics(const char ch[], int statistics[]);

int main(void)
{
    char ch[LENGTH];
    int statistics[4];
    printf("Enter a string: \n\t");
    fgets(ch, LENGTH, stdin);

    ch_statistics(ch, statistics);
    
    printf("letters = %d.\n", statistics[0]);
    printf("numbers = %d.\n", statistics[1]);
    printf("spaces = %d.\n", statistics[2]);
    printf("others = %d.\n", statistics[3]);

    return 0;
}

int * ch_statistics(const char ch[], int statistics[])
{
    int letters = 0;
    int numbers = 0;
    int spaces = 0;
    int others = 0;

    for (int i = 0; i < strlen(ch) - 1; i++)
    {
        if (isalpha(ch[i]))
            letters++;
        else if (isdigit(ch[i]))
            numbers++;
        else if (' ' == ch[i])
            spaces++;
        else
            others++;
    }
    
    statistics[0] = letters;
    statistics[1] = numbers;
    statistics[2] = spaces;
    statistics[3] = others;

    return statistics;
}