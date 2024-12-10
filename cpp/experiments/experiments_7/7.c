/*
使用fscanf()函数从第6题的文件中读取数据，并分别赋值到对应结构体数组元素的成员中。计
算每个学生的总分和平均分并输出显示。
输入描述：提示信息
输出描述：提示信息和学生分数
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
    FILE *fp;
    struct Student students[5];
    int totalScore, totalMath, totalEnglish;

    printf("Opening Students.txt...\n");
    if ((fp = fopen("Students.txt", "r")) == NULL)
    {
        fprintf(stderr, "Failed to read Students.txt!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "StudentID=%ld, Name=%[^,], Math=%d, English=%d\n",
                &students[i].studentID, students[i].name,
                &students[i].score.math, &students[i].score.english);
    }

    printf("Calculating scores...\n");
    totalMath = totalEnglish = 0;

    for (int i = 0; i < 5; i++)
    {
        totalMath += students[i].score.math;
        totalEnglish += students[i].score.english;
    }

    for (int i = 0; i < 5; i++)
    {
        totalScore = students[i].score.math +
                        students[i].score.english;
        printf("%s: Total score = %d, Average score = %.1f\n",
                students[i].name, totalScore, totalScore / 2.0);
    }

    printf("Closing Students.txt...\n");
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close Students.txt!");
        exit(EXIT_FAILURE);
    }

    return 0;
}