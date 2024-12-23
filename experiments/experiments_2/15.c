/*
声明整型变量ch1、ch2和浮点型变量f1、f2并进行初始化然后整型变量ch1和字符型常量‘a’进
行相加运算，整型变量ch1和浮点型变量f1进行相加运算f1赋值给ch2或ch1赋值给f2并分别输
出运算结果。
输入描述：（无）
输出描述：运算结果
*/

#include <stdio.h>

int main(void)
{
    int ch1 = 3, ch2;
    float f1 = 2.123, f2;
    ch2 = f1;
    f2 = ch1;

    printf("The value of ch1 + \'a\' is %d.\n", ch1 + 'a');
    printf("The value of ch1 + f1 is %f.\n", ch1 + f1);
    printf("The value of ch2 is %d.\n", ch2);
    printf("The value of f2 is %f.\n", f2);

    return 0;
}