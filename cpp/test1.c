#include <stdio.h>
#include <string.h>

#define LENGTH 31

char op[5] = { '+', '-', '*', '/', '%' };

int main(void)
{
    char str[LENGTH];
    printf("Enter the formula "
            "(\"a op b\" or \"a b op\" or \"op a b\"): ");
    fgets(str, LENGTH, stdin);

    int i = 0;
    int find = 0;
    for (; i < strlen(str); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (op[j] == str[i])
            {
                find = 1;
                break;
            }
        }
        if (find)
        {
            break;
        }
    }

    if (!find)
    {
        printf("No valid operator found.\n");
        return 1;
    }

    int operator;
    switch (str[i]) {
    case '+':
        operator = 0;
        break;
    case '-':
        operator = 1;
        break;
    case '*':
        operator = 2;
        break;
    case '/':
        operator = 3;
        break;
    case '%':
        operator = 4;
        break;
    }

    str[i] = ' ';

    int a, b, result;
    sscanf(str, "%d %d", &a, &b);
    
    if (operator == 3 && b == 0)
    {
        printf("Error: Division by zero.\n");
        return 1;
    }
    if (operator == 4 && b == 0)
    {
        printf("Error: Modulus by zero.\n");
        return 1;
    }

    switch (operator) {
    case 0:
        result = a + b;
        break;
    case 1:
        result = a - b;
        break;
    case 2:
        result = a * b;
        break;
    case 3:
        result = a / b;
        break;
    case 4:
        result = a % b;
        break;
    }

    printf("The result of \"%d %c %d\" is %d.",
            a, op[operator], b, result);

    return 0;
}