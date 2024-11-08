#include <stdio.h>

void order(double * a, double * b, double * c);
void max(double * a, double * b);

int main(void)
{
    double a, b, c;
    printf("Enter the value of a, b and c. \na = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    order(&a, &b, &c);
    
    return 0;
}

void order(double * a, double * b, double * c)
{
    max(a, b);
    max(b, c);
    max(a, b);
    printf("Now a = %lf, b = %lf, c = %lf. \n", *a, *b, *c);

    return;
}

void max(double * a, double * b)
{
    double temp;
    if (*a > *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    return;
}