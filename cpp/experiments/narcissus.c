/*
水仙花数判断。要求输入一个三位数的正整数如果用户输入不合法（小
于100或大于999），则输出1，返回。否则，判断该三位数是否为水仙花数，
若它的各位数字的3次幂之和等于它本身，如153=1^3+5^3+3^3，则是水仙
花数，否则不是水仙花数。

输入
一个正整数
输出
若不是三位数，则输出1并返回；若是则判断是否为水仙花数，是
则输出YES，不是则输出NO。

样例1：
输入：80
输出：-1
样例2：
输入：1234
输出：-1
样例3：
输入：153
输出：YES
样例4：
输入：103
输出：NO
*/

#include <stdio.h>

void get_digits(int num, int * a, int * b, int * c);
char * narcissus(int num, int a, int b, int c);

int main(void)
{
    int num, a, b, c;
    scanf("%d", &num);

    get_digits(num, &a, &b, &c);
    printf("%s", narcissus(num, a, b, c));

    return 0;
}

void get_digits(int num, int * a, int * b, int * c)
{
    *a = num / 100;
    *b = (num % 100) / 10;
    *c = num % 10;

    return;
}

char * narcissus(int num, int a, int b, int c)
{
    int result = a * a * a + b * b * b + c * c * c;
    if (num <= 100 || num >= 999)
        return "-1";
    if (num == result)
        return "YES";
    else
        return "NO";
}