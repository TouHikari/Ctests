/*
使用scanf()函数读取用户输入的不同类型的整型数据，使用printf()语句分别将其输出。
输入描述：不同类型的整型数据
输出描述：用户输入的整型数据
*/

#include <stdio.h>

int main(void)
{
    char num1;
    signed char num2;
    unsigned char num3;
    short num4;
    unsigned short num5;
    int num6;
    unsigned int num7;
    long num8;
    unsigned long num9;
    long long num10;
    unsigned long long num11;

    printf("Enter the value of char: ");
    scanf("%c", &num1);
    getchar();
    printf("The value is %c.\n", num1);

    printf("Enter the value of signed char: ");
    scanf("%c", &num2);
    getchar();
    printf("The value is %c.\n", num2);
    
    printf("Enter the value of unsigned char: ");
    scanf("%c", &num3);
    getchar();
    printf("The value is %c.\n", num3);

    printf("Enter the value of short int: ");
    scanf("%d", &num4);
    printf("The value is %d.\n", num4);

    printf("Enter the value of unsigned short int: ");
    scanf("%u", &num5);
    printf("The value is %u.\n", num5);

    printf("Enter the value of int: ");
    scanf("%d", &num6);
    printf("The value is %d.\n", num6);

    printf("Enter the value of unsigned int: ");
    scanf("%u", &num7);
    printf("The value is %u.\n", num7);

    printf("Enter the value of long int: ");
    scanf("%ld", &num8);
    printf("The value is %ld.\n", num8);

    printf("Enter the value of unsigned long int: ");
    scanf("%lu", &num9);
    printf("The value is %lu.\n", num9);

    printf("Enter the value of long long int: ");
    scanf("%lld", &num10);
    printf("The value is %lld.\n", num10);

    printf("Enter the value of unsigned long long int: ");
    scanf("%llu", &num11);
    printf("The value is %llu.\n", num11);

    return 0;
}