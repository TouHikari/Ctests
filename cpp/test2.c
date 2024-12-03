/*
字符串查找

问题描述：
给出一个字符串和多行文字，输出在这些文字中出现了指定字符串的行。程序还需要
支持大小写敏感选项：
	当选项打开时，表示同一个字母的大写和小写看作不同的字符:
	当选项关闭时，表示同一个字母的大写和小写看作相同的字符。

输入说明：
输入数据的第一行为一个字符串s，由大小写英文字母组成，长度不超过100。
第二行包含一个数字，表示大小写敏感选项。当数字为0时表示大小写不敏感，当数字
为1时表示大小写敏感。
第三行包含一个整数n，表示给出的文字行数。
接下来n行，每行包含一个字符串，字符串由大小写英文字母组成，不含空格和其他字
符。每个字符串的长度不超过100。

输出说明：
输出多行，每行包含一个字符串，按出现的顺序依次给出那些包含了字符串s的行。

输入样例：
Hello
1
5
HelloWorld
HiHiHelloHiHi
GreplsAGreatTool
HELLO
HELLOisNOTHello

输出样例：
HelloWorld
HiHiHelloHiHi
HELLOisNOTHello
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLENGTH 101

void input_arguments(char str[], int * mode, int * lines);
void input_strings(int count, char strings[][MAXLENGTH]);
void str_find(int mode, int count,
            const char ori_str[], const char strs[][MAXLENGTH]);

int main(void)
{
    char s[MAXLENGTH];
    int mode; // 1 for Case Sensitive and 0 for Case Insensitive
    int n;
    char str[1000][MAXLENGTH];
    input_arguments(s, &mode, &n); // Read input arguments

    input_strings(n, str); // Read input strings

    str_find(mode, n, s, str); // Find and output

    return 0;
}

void input_arguments(char str[], int * mode, int * lines)
{
    // Read input arguments

    fgets(str, MAXLENGTH, stdin);
    str[strcspn(str, "\n")] = '\0';

    scanf("%d", mode);

    scanf("%d", lines);

    getchar();
}

void input_strings(int count, char strings[][MAXLENGTH])
{
    // Read input strings
    for (int i = 0; i < count; i++)
    {
        fgets(strings[i], MAXLENGTH, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0';
    }
}

void str_find(int mode, int count,
            const char ori_str[], const char strs[][MAXLENGTH])
{
    if (mode) // Case sensitive
    {
        for (int i = 0; i < count; i++)
        {
            if (strstr(strs[i], ori_str))
            {
                fputs(strs[i], stdout);
                printf("\n");
            }
        }
    }
    else // Case insensitive
    {
        char cmp_str_l[MAXLENGTH];
        strcpy(cmp_str_l, ori_str);
        
        // To lower case for original string
        for (int i = 0; cmp_str_l[i]; i++)
        {
            cmp_str_l[i] = tolower(cmp_str_l[i]);
        }

        for (int i = 0; i < count; i++)
        {
            char temp[MAXLENGTH];
            strcpy(temp, strs[i]);

            // To lower case for input strings
            for (int j = 0; temp[j]; j++)
            {
                temp[j] = tolower(temp[j]);
            }

            if (strstr(temp, cmp_str_l))
            {
                fputs(strs[i], stdout);
                printf("\n");
            }
        }
    }
}