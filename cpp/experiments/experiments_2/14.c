/*
分别定义单精度浮点型变量a、双精度浮点型变量b和长双精度浮点型变量c通过scanf()函数获取
用户输入的相应数据通过printf()函数分别采用十进制记数法和指数记数法输出。
输入描述：实数
输出描述：对应的十进制记数和指数记数
*/

#include <stdio.h>

int main(void)
{
    float a;
    double b;
    long double c;
    printf("Enter the values of a, b and c: ");
    scanf("%f %lf %llf", &a, &b, &c);

    printf("The value of a is %f or %e.\n", a, a);
    printf("The value of b is %lf or %le.\n", b, b);
    printf("The value of c is %Lf or %Le.\n", c, c);

    return 0;
}