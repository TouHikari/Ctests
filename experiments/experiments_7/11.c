/*
使用fseek()函数按照输入的序号读取第9题dat文件中相应序号的学生信息，并输出显示查询的
结果。
输入描述：序号
输出描述：学生信息或提示
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
    struct Student student;
    int index;

    printf("Enter the order number of the student: ");
    scanf("%d", &index);
    index--;

    if ((fp = fopen("Students.dat", "rb")) == NULL)
    {
        fprintf(stderr, "Failed to open Students.dat!");
        exit(EXIT_FAILURE);
    }

    size_t studentSize = sizeof(struct Student);
    long offset = index * studentSize;

    if (fseek(fp, offset, SEEK_SET) != 0)
    {
        fprintf(stderr, "Failed to locate!");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    if (fread(&student, studentSize, 1, fp) != 1)
    {
        fprintf(stderr, "Failed to read Students' information!");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    printf("Name: %s\nStudent ID: %ld\nMath: %d\nEnglish: %d\n",
           student.name, student.studentID,
           student.score.math, student.score.english);

    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Failed to close Students.dat!");
        exit(EXIT_FAILURE);
    }

    return 0;
}