/*
使用struct关键字定义了一个结构体date，用来保存日期。在date结构体中，分别定义表示年、
月、日三个数据的成员变量。用该结构体类型定义的变量存储用户输入的生日判断是否合理并输出显示。
输入描述：数值
输出描述：结果或生日
*/

#include <stdio.h>
#include <string.h>

struct date
{
    int month;
    int day;
    int year;
};

const char months[12][10] = {
    {"January"}, {"February"}, {"March"},
    {"April"},   {"May"},      {"June"},
    {"July"},    {"August"},   {"September"},
    {"October"}, {"November"}, {"December"}
};

int main(void)
{
    struct date user;
    printf("Enter your birthday ([month]/[day]/[year]): ");

    if (3 == scanf("%d/%d/%d",
                    &user.month, &user.day, &user.year)
        && user.month <= 12)
    {
        char tail[3];
        switch (user.day)
        {
        case 1:
        case 21:
        case 31:
            strcpy(tail, "st");
            break;

        case 2:
        case 22:
            strcpy(tail, "nd");
            break;

        case 3:
        case 23:
            strcpy(tail, "rd");
            break;
        
        default:
            strcpy(tail, "th");
            break;
        }
        
        printf("Your birthday is %s %d%s, %d!",
                months[user.month - 1], user.day, tail, user.year);
    }
    else
    {
        printf("Invalid input! Exiting...");
    }
    
    return 0;
}