/*
用fopen()函数创建txt文件，将用户输入的字符写入文件，直到用户按下Enter键结束。
输入描述：字符
输出描述：提示信息
*/

#include <stdio.h>
#include <stdlib.h>

#define STLEN 101

int main(void)
{
    char ch;
    FILE *fp;

    if ((fp = fopen("input.txt", "w")) == NULL)
    {
        fprintf(stderr, "Failed to write to file! ");
        exit(EXIT_FAILURE);
    }
    
    printf("Please enter the content to be saved \n"
            "(press enter to stop):\n\t");
    while ((ch = getchar()) != '\n')
    {
        putc(ch, fp);
    }
    
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close the file! ");
        exit(EXIT_FAILURE);
    }
    printf("Your input has been successfully saved to input.txt! ");

    return 0;
}