#include <stdio.h>

int Fibonacci(void);

int main(void)
{
    printf("Enter a positive integer to know the Fibonacci number there. \n");
    printf("(press ctrl+c to stop the programme. )\n");
    while (1)
    {
        Fibonacci();
    }
    printf("Done. \n");

    return 0;
}

int Fibonacci(void)
{
    unsigned long long n, first, second, number;
    first = second = number = 0;
    while ((scanf("%d", &n)) != 1 || n <= 0)
    {
        scanf("%*s");
        printf("Illegal input! Try again. \n");
    }
    if (n <= 2 && n > 0)
        printf("The number is %llu. \n\nEnter another integer! \n", 1);
    else if (n >= 3)
    {
        first = second = 1;
        for (int i = 3; i <= n; i++)
        {
            number = first + second;
            first = second;
            second = number;
        }
        printf("The number is %llu. \n\nEnter another integer! \n", number);
    }
    printf("(press ctrl+c to stop the programme. )\n");
    return 0;
}