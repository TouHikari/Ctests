/*
使用fprintf()和结构体将学生的学号、姓名及各科成绩保存到txt文件中，各数据项用其他符号
或空格分隔开每个学生的信息占一行（至少5条学生信息）。
输入描述：提示信息和学生信息
输出描述：提示信息
*/

#include <stdio.h>
#include <stdlib.h>

struct Score
{
    int math;
    int english;
};

struct Student
{
    long studentID;
    char name[31];
    struct Score score;
};

int main(void)
{
    struct Student students[5] = {
        {
            2024308065,
            "Tommy Wade",
            { 91, 95 }
        },
        {
            2024303520,
            "Ricardo Thompson",
            { 94, 120 }
        },
        {
            2024307677,
            "Teresa Daniel",
            { 128, 132 }
        },
        {
            2024302002,
            "Cole Willis",
            { 94, 125 }
        },
        {
            2024304655,
            "Tommy Simon",
            { 147, 97 }
        },
    };

    FILE *fp;

    printf("Opening Students.txt...\n");
    if ((fp = fopen("Students.txt", "w+")) == NULL)
    {
        fprintf(stderr, "Failed to write to Students.txt!");
        exit(EXIT_FAILURE);
    }

    printf("Writing students' info to Students.txt...\n");
    for (int i = 0; i < 5; i++)
    {
        fprintf(fp, "StudentID=%ld, Name=%s, Math=%d, English=%d",
                students[i].studentID, students[i].name,
                students[i].score.math, students[i].score.english);
        putc('\n', fp);
    }
    
    printf("Closing Students.txt...\n");
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close Students.txt!");
        exit(EXIT_FAILURE);
    }
    
    printf("Done!");
    return 0;
}