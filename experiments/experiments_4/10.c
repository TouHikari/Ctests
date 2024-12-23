/*
写一函数实现功能从n长的字符串中第m个字符开始的全部字符复制成为另一个字符串。在主函数
中调用该函数处理字符串。
输入描述：数字n、字符串、数字m
输出描述：子串
*/

#include <stdio.h>

char * str_cut(char str[], char sonstr[],
                int length, int cut_location);

int main(void)
{
    int n, m;
    printf("Enter the length of the string: ");
    scanf("%d", &n);
    getchar();

    char str1[n];
    printf("Enter the string:\n\t");
    fgets(str1, n, stdin);

    printf("Enter the cut location: ");
    scanf("%d", &m);

    char str2[n - m];
    printf("The son string is:\n\t");
    fputs(str_cut(str1, str2, n, m), stdout);

    return 0;
}

char * str_cut(char str[], char sonstr[],
                int length, int cut_location)
{
    for (int i = 0; i < length - cut_location; i++)
    {
        sonstr[i] = str[cut_location - 1 + i];
    }
    
    return sonstr;
}