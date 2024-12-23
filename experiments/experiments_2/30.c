/*
使用scanf()读取用户输入的数据，并判断是否是整数。若是，输出整数；否则，请用户重新输入。
输入描述：数据（数字或字符）
输出描述：整数或提示
*/

#include <stdio.h>

int main(void)
{
    int input;
    char ch;
    while (1)
    {
        while (!(scanf(" %d", &input)))
        {
            printf("Illegal input! (0x01)Try again!\n");
            scanf("%*s");
        }
        if ((ch = getchar()) == '.')
        {
            printf("Illegal input! (0x02)Try again!\n");
            scanf("%*s");
            continue;
        }
        break;
    }    
    printf("The integer is %d.\n", input);

    return 0;
}