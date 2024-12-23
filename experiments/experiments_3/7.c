/*
输入一行字符，利用字符型数组分别统计出其中英文字母、数字、空格和其他字符的个数。
输入描述：字符串
输出描述：统计值
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LENGTH 50

int main(void)
{
    char ch[LENGTH];
    int letters = 0;
    int numbers = 0;
    int spaces = 0;
    int others = 0;
    printf("Enter a string: \n\t");
    fgets(ch, LENGTH, stdin);

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
    
    printf("letters = %d.\n", letters);
    printf("numbers = %d.\n", numbers);
    printf("spaces = %d.\n", spaces);
    printf("others = %d.\n", others);

    return 0;
}