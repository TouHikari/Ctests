#include <stdio.h>
#define SOLAR_MONTH_DAYS 31
#define LUNAR_MONTH_DAYS 30
#define LEAP_MONTH_DAYS 29
#define FEBRUARY_DAYS 28

int leap_year(int month, int day);
int common_year(int month, int day);

int main(void)
{
    int year, month, day, sums;
    scanf("%d%d%d", &year, &month, &day);

    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            sums = leap_year(month, day);
        else
            sums = common_year(month, day);
    }
    else
    {
        if (year % 4 == 0)
            sums = leap_year(month, day);
        else
            sums = common_year(month, day);
    }

    printf("日期是当年的第%d天", sums);

    return 0;
}

int leap_year(int month, int day)
{
    int sum;
    switch (month)
    {
    case 1:
        sum = 0;
        break;
    case 2:
        sum = SOLAR_MONTH_DAYS;
        break;
    case 3:
        sum = SOLAR_MONTH_DAYS + LEAP_MONTH_DAYS;
        break;
    case 4:
        sum = SOLAR_MONTH_DAYS * 2 + LEAP_MONTH_DAYS;
        break;
    case 5:
        sum = SOLAR_MONTH_DAYS * 2 + LEAP_MONTH_DAYS + LUNAR_MONTH_DAYS;
        break;
    case 6:
        sum = SOLAR_MONTH_DAYS * 3 + LEAP_MONTH_DAYS + LUNAR_MONTH_DAYS;
        break;
    case 7:
        sum = SOLAR_MONTH_DAYS * 3 + LEAP_MONTH_DAYS + LUNAR_MONTH_DAYS * 2;
        break;
    case 8:
        sum = SOLAR_MONTH_DAYS * 4 + LEAP_MONTH_DAYS + LUNAR_MONTH_DAYS * 2;
        break;
    case 9:
        sum = SOLAR_MONTH_DAYS * 5 + LEAP_MONTH_DAYS + LUNAR_MONTH_DAYS * 2;
        break;
    case 10:
        sum = SOLAR_MONTH_DAYS * 5 + LEAP_MONTH_DAYS + LUNAR_MONTH_DAYS * 3;
        break;
    case 11:
        sum = SOLAR_MONTH_DAYS * 6 + LEAP_MONTH_DAYS + LUNAR_MONTH_DAYS * 3;
        break;
    case 12:
        sum = SOLAR_MONTH_DAYS * 6 + LEAP_MONTH_DAYS + LUNAR_MONTH_DAYS * 4;
        break;
    }

    return sum + day;
}

int common_year(int month, int day)
{
    int sum;
    switch (month)
    {
    case 1:
        sum = 0;
        break;
    case 2:
        sum = SOLAR_MONTH_DAYS;
        break;
    case 3:
        sum = SOLAR_MONTH_DAYS + FEBRUARY_DAYS;
        break;
    case 4:
        sum = SOLAR_MONTH_DAYS * 2 + FEBRUARY_DAYS;
        break;
    case 5:
        sum = SOLAR_MONTH_DAYS * 2 + LUNAR_MONTH_DAYS + FEBRUARY_DAYS;
        break;
    case 6:
        sum = SOLAR_MONTH_DAYS * 3 + LUNAR_MONTH_DAYS + FEBRUARY_DAYS;
        break;
    case 7:
        sum = SOLAR_MONTH_DAYS * 3 + LUNAR_MONTH_DAYS * 2 + FEBRUARY_DAYS;
        break;
    case 8:
        sum = SOLAR_MONTH_DAYS * 4 + LUNAR_MONTH_DAYS * 2 + FEBRUARY_DAYS;
        break;
    case 9:
        sum = SOLAR_MONTH_DAYS * 5 + LUNAR_MONTH_DAYS * 2 + FEBRUARY_DAYS;
        break;
    case 10:
        sum = SOLAR_MONTH_DAYS * 5 + LUNAR_MONTH_DAYS * 3 + FEBRUARY_DAYS;
        break;
    case 11:
        sum = SOLAR_MONTH_DAYS * 6 + LUNAR_MONTH_DAYS * 3 + FEBRUARY_DAYS;
        break;
    case 12:
        sum = SOLAR_MONTH_DAYS * 6 + LUNAR_MONTH_DAYS * 4 + FEBRUARY_DAYS;
        break;
    }

    return sum + day;
}