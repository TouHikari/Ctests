#include <stdio.h>
#include <math.h>

void find_root(double a, double b, double c);
void ascending_order(double * a, double * b);

int main(void)
{
    double a, b, c;
    printf("Input the value of a, b and c in equation ax^2+bx+c=0:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    find_root(a, b, c);

    return 0;
}

void find_root(double a, double b, double c)
{
    double delta, x1, x2;
    if (0 == a)
        printf("The value of a is 0! This is not a Binary Linear Equation!\n");
    else
    {
        delta = b * b - 4 * a * c;
        if (fabs(delta) < 1e-6)
        {
            x1 = (-b + sqrt(delta)) / 2 / a;
            printf("x1=x2=%g", x1);
        }
        else if (delta < 0)
        {
            printf("The equation has no real roots!\n");
            return;
        }
        else if (fabs(delta) >= 1e-6)
        {
            x1 = (-b + sqrt(delta)) / 2 / a;
            x2 = (-b - sqrt(delta)) / 2 / a;
            ascending_order(&x1, &x2);
            printf("x1=%g, x2=%g\n", x1, x2);
        }
    }

    return;
}

void ascending_order(double * a, double * b)
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