/*
分别为单精度浮点型变量a和双精度浮点型变量b赋值5890.1和1134.5678并输出。
输入描述：（无）
输出描述：a和b的值
*/

#include <stdio.h>

int main(void)
{
    float a = 5890.1;
    double b = 1134.5678;

    printf("The values of a and b are: %f, %lf.\n", a, b);

    return 0;
}