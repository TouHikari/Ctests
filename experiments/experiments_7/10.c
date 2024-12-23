/*
创建一个txt文件，写入用户的输入、读取文件的内容。使用ftell(函数在每次写读后输出文件
指针的位置，读写转换时使用rewind()函数进行指针的移动。
输入描述：提示信息和字符
输出描述：提示信息、文件指针位置、字符
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char ch;

    if ((fp = fopen("input.txt", "w+")) == NULL)
    {
        fprintf(stderr, "Failed to open input.txt for writing!");
        exit(EXIT_FAILURE);
    }

    printf("Please enter the content to be saved \n"
            "(press enter to stop):\n\t");
    while ((ch = getchar()) != '\n')
    {
        putc(ch, fp);
    }

    printf("Now file pointer is at %p.\n", ftell(fp));
    rewind(fp);

    printf("The content of input.txt is:\n\t");
    while ((ch = getc(fp)) != EOF)
    {
        putchar(ch);
    }

    printf("\nNow file pointer is at %p.\n", ftell(fp));
    
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close the file! ");
        exit(EXIT_FAILURE);
    }

    return 0;
}