/*
定义一个函数，将整型数值转换为对应的月份字符串，要求函数的返回值是字符串。在主函数中
调用该函数，对用户的输入进行转换并输出结果。
输入描述：数值
输出描述：月份
*/

#include <stdio.h>
#include <string.h>

char * to_month(int number);

int main(void)
{
    char month[10];
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);
    while (n < 1 || n > 12)
    {
        printf("Invalid input! Try again: ");
        scanf("%d", &n);
    }

    strcpy(month, to_month(n));

    printf("The month is %s.", month);

    return 0;
}

char * to_month(int number)
{
    static char months[12][10] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return &months[number - 1][0];
}