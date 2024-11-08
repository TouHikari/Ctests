#include <stdio.h>

int main()
{
    const int ASCII_A = 65;
    char letter;
    int count;
    printf("Input a capital letter to continue...\n");
    scanf("%c", &letter);

    count = letter - ASCII_A;

    for(int i = 1; i <= count + 1; i++)
    {
        for(int j = 1; j <= count - i + 1; j++)
        {
            printf(" ");
        }

        for(int j = 0; j < i - 1; j++)
        {
            printf("%c", ASCII_A + j);
        }

        for(int k = i - 1; k >= 0; k--)
        {
            printf("%c", ASCII_A + k);
        }
        
        printf("\n");
    }
}