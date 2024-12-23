/*
使用一维数组和指针变量声明两个字符串，使用至少三种方法分别输出这两个字符串第5个字符开
始的子串。
输入描述：（无）
输出描述：字符串
*/

#include <stdio.h>

int main(void)
{
    char str[] = {"This is the first string."};
    char * ptr = "And this is the second string.";

    printf("Orig:\n%s\n%s\n", str, ptr);

    printf("\nMethod 1:\n");
    printf("%s\n", str + 4);
    printf("%s\n", ptr + 4);

    printf("\nMethod 2:\n");
    printf("%s\n", &str[4]);
    printf("%s\n", &ptr[4]);

    printf("\nMethod 3:\n");
    fputs(str + 4, stdout);
    putchar('\n');
    fputs(ptr + 4, stdout);

    return 0;
}