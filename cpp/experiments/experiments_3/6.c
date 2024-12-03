/*
定义字符型数组a、b和s，其中a和b在声明时赋值，然后分别调用strlen()函数、strcat()函数
和strcpy()函数进行字符串的操作计算。a、b的长度、将b追加到a的末尾、将a复制到s，并分别
输出结果。
输入描述：（无）
输出描述：操作结果字符串
*/

#include <stdio.h>
#include <string.h>
#define LENGTH 50

int main(void)
{
    char a[] = {'I', ' ', 'a', 'm', ' ', 'A', '.', ' ', '\0'};
    char b[] = {'A', 'n', 'd', ' ', 'I', ' ', 
                'a', 'm', ' ', 'B', '.', ' ', '\0'};
    char s[LENGTH];

    printf("The length of a is %d. \n", strlen(a));
    printf("The length of b is %d. \n", strlen(b));
    putchar('\n');

    strcat(a, b);
    strcpy(s, a);

    printf("Now a is \"%s\"\n", a);
    printf("Now s is \"%s\"\n", s);

    return 0;
}