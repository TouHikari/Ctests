/*
将浮点型数据5.1的各位按照十六进制输出。
输入描述：（无）
输出描述：5.1的各位十六进制值
*/

#include <stdio.h>

int main(void)
{
    float num = 5.1;
    unsigned char * ptr = (unsigned char *) &num;

    printf("Every digit of \"5.1\" in hex: \n");
    for (int i = 0; i < sizeof(num); i++)
        printf("%02X ", ptr[i]);

    return 0;
}