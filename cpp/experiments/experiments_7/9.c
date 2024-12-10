/*
创建一个新dat文件，使用fwrite()函数将第6题的学生信息保存为二进制文件。使用fread()函
数，从dat文件中读取数据并输出显示。
输入描述：提示信息
输出描述：提示信息和学生信息
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
    FILE *write, *read;
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

    if ((write = fopen("Students.dat", "wb")) == NULL)
    {
        fprintf(stderr, "Failed to open Students.dat for writing!");
        exit(EXIT_FAILURE);
    }

    printf("Writing student information to Students.dat...\n");
    fwrite(students, sizeof(struct Student), 5, write);

    if (fclose(write) != 0)
    {
        fprintf(stderr, "Failed to close Students.dat!");
        exit(EXIT_FAILURE);
    }

    if ((read = fopen("Students.dat", "rb")) == NULL)
    {
        fprintf(stderr, "Failed to open Students.dat for reading!");
        exit(EXIT_FAILURE);
    }

    printf("Reading student information from Students.dat...\n");
    struct Student readStudents[5];
    fread(readStudents, sizeof(struct Student), 5, read);

    for (int i = 0; i < 5; i++)
    {
        printf("StudentID: %ld, Name: %s, Math: %d, English: %d\n",
               readStudents[i].studentID, readStudents[i].name,
               readStudents[i].score.math, readStudents[i].score.english);
    }

    if (fclose(read) != 0)
    {
        fprintf(stderr, "Failed to close Students.dat!");
        exit(EXIT_FAILURE);
    }

    return 0;
}