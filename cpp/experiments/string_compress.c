/*
字符串压缩

有一种简单的字符串压缩算法，对于字符串中连续出现的同一个英文字符，用该字符加上连续出
现的次数来表示(连续出现次数小于3时不压缩)。
例如，字符串aaaaabbbabaaaaaaaaaaaaabbbb可压缩为a5b3aba13b4。
请设计一个程序，采用该压缩方法对字符串压缩并输出。请编写一个函数compress，采用该压缩
方法对字符串rc,进行压缩。

函数定义如下:
char *compress(char *src);

返回值:
指向压缩后的字符串数据

参数:
src:输入/输出参数，输入表示待压缩字符串，输出表示压缩后的字符串

主函数输入说明:
输入第一行为源字符串src(长度小于100)，该字符串只包含大小写字母

主函数输出说明:
输出一个数据，表示压缩后的字符串。

主函数输入样例:
aaaaabbbabaaaaaaaaaaaaabbbb

主函数输出样例:
a5b3aba13b4
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * compress(char * src);

int main(void)
{
    char src[100];
    scanf("%s", src);

    char * ps = compress(src);

    puts(ps);

    return 0;
}

char * compress(char * src)
{
    static char result[100];
    result[0] = '\0';
    char temp = src[0];

    if (temp == '\0')
    {
        return src;
    }

    int i = 0;
    while (src[i] != '\0')
    {
        int count = 0;
        while (1)
        {
            if (src[i] == temp)
                count++;
            else
                break;
            i++;
        }
        if (count >= 3)
        {
            sprintf(strchr(result, '\0'),
                    "%c%d\0", temp, count);
        }
        else
        {
            for (int j = 0; j < count; j++)
            {
                sprintf(strchr(result, '\0'),
                        "%c\0", temp);
            }
        }
        temp = src[i];
    }
    return result;
}