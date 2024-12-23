/*
定义员工结构体，包括姓名、性别、生日、住址、电话、入职日期等成员。定义一个输出函数，
实现员工信息的打印输出，用该员工结构体类型变量指针作为参数。在主函数中声明员工结构体
变量并初始化三名员工信息，并调用输出函数输出各员工的信息。
输入描述：（无）
输出描述：各员工信息
*/

#include <stdio.h>
#include <string.h>

struct date
{
    int month;
    int day;
    int year;
};

struct staff
{
    char name[21];
    char gender[11];
    struct date birthday;
    char address[101];
    long telephone;
    struct date entry_date;
};

void staff_info_out(struct staff * staff);
void date_out(struct date * date);

int main(void)
{
    struct staff staff[3] = {
        {
            "Amelia Huff",
            "Female",
            { 12, 1, 2006 },
            "Burkina Faso",
            17603296594,
            { 3, 2, 2022 }
        },
        {
            "Raymond Carlson",
            "Female",
            { 10, 28, 2002 },
            "Gabon",
            15551647612,
            { 7, 23, 2024 }
        },
        {
            "Louis Stephens",
            "Female",
            { 3, 19, 2005 },
            "Vietnam",
            14264262469,
            { 4, 16, 2024 }
        }
    };
    struct staff * ptr = staff;

    for (int i = 0; i < 3; i++)
    {
        staff_info_out(ptr + i);
    }

    return 0;
}

void staff_info_out(struct staff * staff)
{
    printf("Name: %s\nGender: %s\n",
            staff->name, staff->gender);
    printf("Birthday: ");
    date_out(&(staff->birthday));
    printf("\nAddress: %s\nTelephone: %ld\n",
            staff->address, staff->telephone);
    printf("Entry date: ");
    date_out(&(staff->entry_date));
    printf("\n\n");
}

void date_out(struct date * date)
{
    static const char months[12][10] = {
        {"January"}, {"February"}, {"March"},
        {"April"},   {"May"},      {"June"},
        {"July"},    {"August"},   {"September"},
        {"October"}, {"November"}, {"December"}
    };

    char tail[3];
    switch (date->day)
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
    
    printf("%s %d%s, %d",
            months[date->month - 1],
            date->day, tail, date->year);
}