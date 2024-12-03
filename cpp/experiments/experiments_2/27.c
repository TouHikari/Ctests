/*
“1”至“7”分别代表“周一”至“周日”，分别使用if条件语句和switch…case语句编程，将输入的
整数转换为相应的周几并输出。
输入描述：整数
输出描述：周几
*/

#include <stdio.h>

int main(void)
{
    printf("Enter the number of the day: ");
    // if
    {
        char ch = getchar();
        if ('1' == ch)
            printf("Monday.\n");
        if ('2' == ch)
            printf("Tuesday.\n");
        if ('3' == ch)
            printf("Wednesday.\n");
        if ('4' == ch)
            printf("Thursday.\n");
        if ('5' == ch)
            printf("Friday.\n");
        if ('6' == ch)
            printf("Saturday.\n");
        if ('7' == ch)
            printf("Sunday.\n");
        getchar();
    }

    printf("Enter the number of the day: ");
    // switch...case
    {
        char ch = getchar();
        switch (ch)
        {
        case '1':
            printf("Monday.\n");
            break;
        case '2':
            printf("Tuesday.\n");
            break;
        case '3':
            printf("Wednesday.\n");
            break;
        case '4':
            printf("Thursday.\n");
            break;
        case '5':
            printf("Friday.\n");
            break;
        case '6':
            printf("Saturday.\n");
            break;
        case '7': 
            printf("Sunday.\n");
            break;
        }
    }
    
    return 0;
}