/*
利用ASCII码的特点，将小写字母转换为大写字母。
输入描述：小写字母
输出描述：对应的大写字母
*/

#include <stdio.h>

int main(void)
{
    char ch;
    printf("Enter a lowercase letter (/ to exit): ");
    while ((ch = getchar()) != '/')
    {
        printf("The uppercase letter is %c.\n", ch - 32);
        getchar();
        printf("Enter a lowercase letter (/ to exit): ");
    }
    printf("Done.");
    
    return 0;
}