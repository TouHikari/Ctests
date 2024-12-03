/*
声明double_Complex变量a赋初值，然后将变量a加上另一个复数赋值给变量b，使用printf()
函数输出。
输入描述：（无）
输出描述：复数
*/

#include <stdio.h>
#include <complex.h>

int main(void)
{
    double complex a = 3. + 5. * I;
    double complex b = a + 5. + 8. * I;

    printf("a = %g + %gi.\n", creal(a), cimag(a));
    printf("b = %g + %gi.\n", creal(b), cimag(b));

    return 0;
}