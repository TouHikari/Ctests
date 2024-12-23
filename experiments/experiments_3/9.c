/*
有一字符串，包含n个字符。将此字符串中从第m个字符开始的全部字符复制成为另一个字符串。
输入描述：数字n、字符串、数字m
输出描述：子串
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, m;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of m: ");
    scanf("%d", &m);
    getchar();
    printf("Enter the string:\n\t");
    char ch1[n], ch2[n - m + 1];
    fgets(ch1, n + 1, stdin);

    for (int i = m - 1; i < strlen(ch1); i++)
    {
        ch2[i - m + 1] = ch1[i];
    }
    ch2[n - m + 1] = '\0';

    printf("The child string is \"%s\".\n", ch2);

    return 0;
}