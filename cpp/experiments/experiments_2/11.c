/*
使用了两种方法输入字符，一种是使用c直接输入字符，另一种是使用%d输入字符的ASCII码，
并分别输出这两个字符及其ASCII码。
输入描述：字符、ASCII码
输出描述：对应字符及其ASCII码
*/

#include <stdio.h>

int main(void)
{
    char ch1;
    int ch2;
    printf("Enter a char and an ASCII code: \n");
    scanf(" %c", &ch1);
    scanf("%d", &ch2);

    printf("Char 1 is %c and its ASCII code is %d\n", ch1, ch1);
    printf("Char 2 is %c and its ASCII code is %d\n", ch2, ch2);

    return 0;
}