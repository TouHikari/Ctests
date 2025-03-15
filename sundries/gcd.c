#include <stdio.h>

int gcd(int a, int b);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", gcd(a, b));

    return 0;
}

int gcd(int a, int b)
{
    int divisor;
    
    if (0 == a && 0 != b)
        return b;
    else if (0 != a && 0 == b)
        return a;
    else if (a == 0 && b == 0)
        return 0;

    divisor = (a <= b) ? a : b;
    while ( !((a % divisor == 0) && (b % divisor == 0)) )
        divisor--;

    return divisor;
}