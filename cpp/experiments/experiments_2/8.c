/*
定义字符变量c1、c2、c3、c4将十进制整数97和98分别赋给c1和c2，c3和c4分别赋值两个字符
a和b并输出它们的值。
输入描述：（无）
输出描述：c1、c2、c3、c4的值
*/

#include <stdio.h>

int main(void)
{
    char c1, c2, c3, c4;
    c1 = 97;
    c2 = 98;
    c3 = 'a';
    c4 = 'b';

    printf("The values of c1, c2, c3 and c4 are:\n");
    printf("%c %c %c %c", c1, c2, c3, c4);

    return 0;
}