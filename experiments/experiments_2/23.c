/*
声明整型变量a赋值2，先计算a%=4-1再计算a+=a*=a-=a*=3并分别输出计算结果。
输入描述：（无）
输出描述：计算结果
*/

#include <stdio.h>

int main(void)
{
    int a = 2;
    
    printf("The result of \"a %%= 4 - 1\" is %d.\n", a %= 4 - 1);
    printf("The result of \"a += a *= a -= a *= 3\" is %d.\n", a += a *= a -= a *= 3);

    return 0;
}