/*
“1”至“7”分别代表“周一”至“周日”，分别使用if条件语句和switch…case语句编程，将输入的
整数转换为相应的周几并输出。
        x,      x<1
    y = 2x-1,   1≤x<103
        x-11,   x≥10
输入描述：整数
输出描述：周几
*/

#include <stdio.h>

int main(void)
{
    double x, y;
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    if (x < 1)
        y = x;
    else if (1 <= x && x < 10)
        y = 2 * x - 1;
    else if (x >= 10)
        y = 3 * x - 11;
    
    printf("The value of y is %lf.\n", y);
    
    return 0;
}