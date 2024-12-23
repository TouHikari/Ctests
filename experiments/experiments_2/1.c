/*
使用#define定义了符号常量PI表示3.1415，
然后使用PI和输入的圆半径计算圆的面积和周长并输出。
输入描述：圆半径
输出描述：圆面积、圆周长
*/

#include <stdio.h>
#define PI 3.1415

int main(void)
{
    double radius, area, circumference;
    printf("Enter the radius of circle: ");
    scanf("%lf", &radius);

    area = PI * radius * radius;
    circumference = PI * 2 * radius;

    printf("The area of circle is %g.\n", area);
    printf("The circumference of circle is %g.\n", circumference);

    return 0;
}