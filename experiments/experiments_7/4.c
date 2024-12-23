/*
使用gets()数和fputs()函数在txt文件的最后添加新的内容。
输入描述：提示信息和字符串
输出描述：提示信息
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 101

int main(void)
{
    FILE *fp;
    char str[LENGTH];

    if ((fp = fopen("input.txt", "a")) == NULL)
    {
        fprintf(stderr, "Failed to write to input.txt!");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the string to be added to input.txt:\n\t");
    gets(str);
    fputs(str, fp);

    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close the file! ");
        exit(EXIT_FAILURE);
    }
    
    printf("The string has successfully added!");

    return 0;
}