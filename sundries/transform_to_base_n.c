#include <stdio.h>
void to_base_n(unsigned long number, int  n);

int main(void)
{
    unsigned long number;
    int n;
    printf("Enter an integer (q to quit): \n");
    while (scanf("%lu", &number) == 1)
    {
        printf("To how many bases? Enter between 2 and 10:\n");
        if ((scanf("%d", &n)) == 1 && n >= 2 && n <= 10)
        {
            printf("Equivalent: ");
            to_base_n(number, n);
            putchar('\n');
            printf("Enter an integer (q to quit): \n");
        }
        else
        {
            printf("Illegal input! Try again. \n");
            printf("Enter an integer (q to quit): \n");
        }

    }
    printf("Done. \n");
    
    return 0;
}

void to_base_n(unsigned long number, int  n)
{
    int r;
    r = number % n;
    if (number >= n)
        to_base_n(number / n, n);
    printf("%d", r);
    
    return;
}