/*
分别打开三个txt文件，并将后两个文件中的内容逐个字符地复制到第一个文件中。
输入描述：提示信息
输出描述：提示信息
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *read;
    FILE *write;
    char ch;

    // Open 1.txt
    printf("Opening 1.txt...\n");
    if ((write = fopen("1.txt", "a")) == NULL)
    {
        fprintf(stderr, "Failed to write to 1.txt!");
        exit(EXIT_FAILURE);
    }
    // Open 2.txt
    printf("Opening 2.txt...\n");
    if ((read = fopen("2.txt", "r")) == NULL)
    {
        fprintf(stderr, "Failed to read 2.txt!");
        exit(EXIT_FAILURE);
    }

    // Write 2.txt to 1.txt
    printf("Writing 2.txt to the end of 1.txt...\n");
    while ((ch = getc(read)) != EOF)
    {
        putc(ch, write);
    }
    // Close 2.txt
    printf("Closing 2.txt...\n");
    if (fclose(read) != 0)
    {
        fprintf(stderr, "Failed to close 2.txt! ");
        exit(EXIT_FAILURE);
    }
    
    // Open 3.txt
    printf("Opening 3.txt...\n");
    if ((read = fopen("3.txt", "r")) == NULL)
    {
        fprintf(stderr, "Failed to read 3.txt!");
        exit(EXIT_FAILURE);
    }
    
    // Write 3.txt to 1.txt
    printf("Writing 3.txt to the end of 1.txt...\n");
    while ((ch = getc(read)) != EOF)
    {
        putc(ch, write);
    }
    // Close 3.txt
    printf("Closing 3.txt...\n");
    if (fclose(read) != 0)
    {
        fprintf(stderr, "Failed to close 3.txt! ");
        exit(EXIT_FAILURE);
    }

    printf("The contents of 2.txt and 3.txt have been\n"
            "copied character by character into 1.txt!");

    return 0;
}