/*
打开一个已有文件，使用fgetc()函数从文件中读取所有字符，并将读取的字符输出显示。
输入描述：（无）
输出描述：字符
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    FILE *fp;

    if ((fp = fopen("input.txt", "r")) == NULL)
    {
        fprintf(stderr, "Failed to open the file! ");
        exit(EXIT_FAILURE);
    }
    
    printf("The content of input.txt is:\n");
    while ((ch = getc(fp)) != EOF)
    {
        putchar(ch);
    }
    
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close the file! ");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}