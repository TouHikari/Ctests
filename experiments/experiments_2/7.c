/*
使用scanf(函数读取用户输入的十进制、十六进制和八进制的整型数据。使用printf语句分别
将其输出。
输入描述：不同进制的整型数据
输出描述：用户输入的整型数据
*/

#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter decimal number: ");
    scanf("%d", &number);
    printf("The decimal number is %d.\n", number);

    printf("Enter hexadecimal number: ");
    scanf("%x", &number);
    printf("The hexadecimal number is %#x.\n", number);

    printf("Enter octal number: ");
    scanf("%o", &number);
    printf("The octal number is %#o.\n", number);

    return 0;
}