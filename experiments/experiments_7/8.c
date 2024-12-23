/*
创建一个新dat文件，接收输入的三个整数，使用putw()函数，向该文件中写入整型数据（该数据
是以二进制格式保存，可使用UltraEdit等软件查看）。使用getw(函数从该二进制文件中读取三
个整型数据并输出显示。
输入描述：提示信息和整数
输出描述：提示信息和整数
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    int write;

    if ((fp = fopen("integers.dat", "w+")) == NULL)
    {
        fprintf(stderr, "Failed to open integers.dat!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &write);
        putw(write, fp);
    }

    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close Students.txt!");
        exit(EXIT_FAILURE);
    }
        
    return 0;
}