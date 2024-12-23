/*
输入摄氏温度值，然后按照公式华氏度=摄氏度×1.8计算华氏温度值并输出显示。
输入描述：摄氏温度值
输出描述：华氏温度值
*/

#include <stdio.h>

int main(void)
{
    double celsius, fahrenheit;
    printf("Enter Celsius degree: ");
    scanf("%lf", &celsius);

    fahrenheit = 32 + celsius * 1.8;

    printf("Fahrenheit degree is %g.\n", fahrenheit);

    return 0;
}