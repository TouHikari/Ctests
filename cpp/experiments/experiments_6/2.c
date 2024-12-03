/*
定义成绩结构体，包括数学成绩、英语成绩、编程成绩等成员；定义学生结构体，包括姓名、学
号、成绩等成员声明初始化变量存储三位学生的信息并输出显示各学生的信息。
输入描述：（无）
输出描述：各学生信息
*/

#include <stdio.h>

struct scores
{
    float maths;
    float english;
    float coding;
};

struct student
{
    char name[21];
    int student_id;
    struct scores scores;
};

int main(void)
{
    struct student students[3] = {
        {
            "Isabelle Martinez",
            970053,
            { 80.6, 130.1, 146.1, }
        },
        {
            "Justin White",
            978148,
            { 80.1, 94.3, 95.0 }
        },
        {
            "Eula Marshall",
            451817,
            { 132.7, 87.8, 128.0 }
        }
    };

    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\nStudent ID: %d\nScores:\n",
                students[i].name, students[i].student_id);
        printf("\tMaths: %.1f\n", students[i].scores.maths);
        printf("\tEnglish: %.1f\n", students[i].scores.english);
        printf("\tCoding: %.1f\n", students[i].scores.coding);
        putchar('\n');
    }
    
    return 0;
}