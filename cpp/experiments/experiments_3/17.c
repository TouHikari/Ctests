/*
输出一个整数序列中与指定数字相同的数的个数。
输入描述：一个整数序列和一个整数
输出描述：相同数的个数
*/

#include <stdio.h>
#define LENGTH 100

int main(void)
{
    int array[LENGTH], find;
    int count = 0;
    int i = 0;

    printf("Enter up to %d integers (type 'q' to stop):\n\t", LENGTH);
    while (i < LENGTH && scanf("%d", &array[i]) == 1)
    {
        i++;
    }
    
    while (getchar() != '\n')
    {
        continue;
    }

    printf("Enter the number you want to find: ");
    scanf("%d", &find);
    for (int j = 0; j < LENGTH; j++)
    {
        if (array[j] == find)
        {
            count++;
        }
    }
    
    printf("The number of \"%d\" is %d.", find, count);
    
    return 0;
}