/*
使用fgets()函数从txt文件中读取字符串，并逐项输出显示。
输入描述：提示信息
输出描述：提示信息和字符串
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 101

int main(void)
{
    FILE *fp;
    char str[LENGTH];

    if ((fp = fopen("text.txt", "r")) == NULL)
    {
        fprintf(stderr, "Failed to read text.txt!");
        exit(EXIT_FAILURE);
    }

    printf("The content of text.txt:\n");
    while (fgets(str, LENGTH, fp) != NULL)
    {
        fputs(str, stdout);
    }

    if (fclose(fp) != 0)
    {
        printf("Failed to close text.txt!");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}