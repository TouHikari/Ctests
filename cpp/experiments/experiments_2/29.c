/*
使用printf()函数输出如下图形。
   3
  3 3
 3   3
3     3
 3   3
  3 3
   3
输入描述：（无）
输出描述：菱形图形
*/

#include <stdio.h>

int main(void)
{
    int n = 3;

    for (int i = 0; i <= n; i++)
    {
        for (int j = n; j > i; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < (2 * i + 1); j++)
        {
            if (j == 0 || j == (2 * i))
            {
                printf("3");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n; j > i; j--)
        {
            printf(" ");
        }
        for (int j = 0; j < (2 * i + 1); j++)
        {
            if (j == 0 || j == (2 * i))
            {
                printf("3");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}