/*
写一函数实现功能将“周一至周日”转换为整数1”至7”。在主函数中调用该函数，对输入的字符串
转换并输出结果。
输入描述：字符串
输出描述：整数
*/

#include <stdio.h>
#include <string.h>
#define LENGTH 10

int tranfer_weekday(char weekday[]);

int main(void)
{
    char str[LENGTH];
    printf("Enter a weekday: ");
    scanf("%s", str);
    while (!tranfer_weekday(str))
    {
        printf("Invalid input! Try again: ");
        scanf("%s", str);
    }

    printf("The corresponding number is %d.", tranfer_weekday(str));

    return 0;
}

int tranfer_weekday(char weekday[])
{
    if (!strcmp(weekday, "Monday"))
    {
        return 1;
    }
    else if (!strcmp(weekday, "Tuesday"))
    {
        return 2;
    }
    else if (!strcmp(weekday, "Wednesday"))
    {
        return 3;
    }
    else if (!strcmp(weekday, "Thursday"))
    {
        return 4;
    }
    else if (!strcmp(weekday, "Friday"))
    {
        return 5;
    }
    else if (!strcmp(weekday, "Saturday"))
    {
        return 6;
    }
    else if (!strcmp(weekday, "Sunday"))
    {
        return 7;
    }
    else
    {
        return 0;
    }
}