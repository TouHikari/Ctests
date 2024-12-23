/*
定义联合体（共用体），包含三个不同类型成员并声明联合体数组变量。分别给数组元素的不同
成员变量赋值，并输出数组所有元素三个成员变量的值。
输入描述：（无）
输出描述：成员变量的值
*/

#include <stdio.h>

union types
{
    int integer;
    double long_float;
    char character;
};

int main(void)
{
    union types something[3] = {
        { .integer = 99 },
        { .long_float = 3.1415926 },
        { .character = 'P' }
    };

    printf("The integer is %d.\n", something[0].integer);
    printf("The long float is %lf.\n", something[1].long_float);
    printf("The character is %c.", something[2].character);
    
    return 0;
}