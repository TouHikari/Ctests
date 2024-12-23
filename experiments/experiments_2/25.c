/*
分别使用while循环语句、do…while循环语句、for循环语句、goto跳转语句计算1加到100的总
和，并输出计算结果。
输入描述：（无）
输出描述：运算结果
*/

#include <stdio.h>

int main(void)
{
    // while
    {
        int i = 1;
        int sum = 0;
        while (i <= 100)
            sum += i++;
        printf("The sum of 1 to 100 is %d.\n", sum);
    }
    
    // do...while
    {
        int i = 1;
        int sum = 0;
        do
        {
            sum += i++;
        } while (i <= 100);
        printf("The sum of 1 to 100 is %d.\n", sum);
    }

    // for
    {
        int i;
        int sum = 0;
        for (int i = 1; i <= 100; i++)
            sum += i;
        printf("The sum of 1 to 100 is %d.\n", sum);
    }

    // goto
    {
        int i = 1;
        int sum = 0;
        a: sum += i++;
        if (i <= 100)
            goto a;
        printf("The sum of 1 to 100 is %d.\n", sum);
    }
    
    return 0;
}