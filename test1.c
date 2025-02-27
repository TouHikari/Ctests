#include <stdio.h>

void swap1(int a, int b)
{
    int c;
    c = a;
    a = b;
    b = c;
    printf("swap1 中的 a = %d, b = %d, c = %d", a, b, c);
}

void swap2(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void main(void)
{
    int x = 100, y = 800;
    swap1(x, y);
    printf("\n调用 swap1 后 x = %d, y = %d", x, y);
    x = 100;
    y = 800;
    swap2(&x, &y);
    printf("\n调用 swap2 后 x = %d, y = %d", x, y);
}