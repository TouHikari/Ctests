/*
定义一个枚举类型，用来存储星期。声明枚举类型变量根据输入给枚举类型变量赋值，并输出
枚举类型变量的值。
输入描述：字符串或数值
输出描述：变量的值
*/

#include <stdio.h>
#include <string.h>

enum weekdays
{
    MONDAY = 1, TUESDAY, WEDNESDAY,
    THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

int main(void)
{
    enum weekdays day;
    char input[10];

    scanf("%s", input);

    if (sscanf(input, "%d", &day) == 1 &&
                (day >= MONDAY && day <= SUNDAY))
    {
        printf("The input value of variable is %d.", day);
        day = 0;
    }
    
    if (strcmp(input, "Monday") == 0)
    {
        day = MONDAY;
    }
    else if (strcmp(input, "Tuesday") == 0)
    {
        day = TUESDAY;
    }
    else if (strcmp(input, "Wednesday") == 0)
    {
        day = WEDNESDAY;
    }
    else if (strcmp(input, "Thursday") == 0)
    {
        day = THURSDAY;
    }
    else if (strcmp(input, "Friday") == 0)
    {
        day = FRIDAY;
    }
    else if (strcmp(input, "Saturday") == 0)
    {
        day = SATURDAY;
    }
    else if (strcmp(input, "Sunday") == 0)
    {
        day = SUNDAY;
    }
    else
    {
        day = 0;
    }
    (day != 0) ? printf("The value of variable is %d.", day) : day;

    return 0;
}