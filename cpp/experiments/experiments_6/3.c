/*
定义员工结构体，包括姓名、性别、生日、住址、电话、入职日期等成员。用该结构体变量存储
三名员工的信息并用指针变量输出显示各员工的信息。
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

void date_out(struct date date);

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
    struct staff * ptr = &staff[0];

    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\nGender: %s\n",
                (ptr + i)->name, (ptr + i)->gender);
        printf("Birthday: ");
        date_out((ptr + i)->birthday);
        printf("\nAddress: %s\nTelephone: %ld\n",
                (ptr + i)->address, (ptr + i)->telephone);
        printf("Entry date: ");
        date_out((ptr + i)->entry_date);
        printf("\n\n");
    }
    
    return 0;
}

void date_out(struct date date)
{
    static const char months[12][10] = {
        {"January"}, {"February"}, {"March"},
        {"April"},   {"May"},      {"June"},
        {"July"},    {"August"},   {"September"},
        {"October"}, {"November"}, {"December"}
    };

    char tail[3];
    switch (date.day)
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
            months[date.month - 1], date.day, tail, date.year);
}