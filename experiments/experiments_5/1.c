/*
定义整型变量和字符变量并进行初始化赋值。分别输出这两个变量的内存地址和变量的值内存单
元中的数据。
输入描述：（无）
输出描述：变量内存地址、变量值
*/

#include <stdio.h>

int main(void)
{
    int integer = 13;
    char character = 'X';

    printf("The address of integer is %p.\n", &integer);
    printf("The address of character is %p.\n", &character);

    printf("The value of integer is \"%d\".\n", integer);
    printf("The value of character is \"%c\".\n", character);

    return 0;
}