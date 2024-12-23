/*
学生有如下信息姓名、学号、所学课程和成绩；所学课程包括两部分，基础课和专业课基础课有
三门课，数学、信息基础、英语都是必选课；专业课有三门课，计算机理论、软件工程、网络安
全只能选修其中一门课。定义一个数据类型，用于存储上面的学生信息。定义两个函数，分别用
于输入赋值和输出学生信息。在主函数中声明自定义数据类型变量和调用自定义函数，读取输入
和赋值并输出变量值。
输入描述：学生信息
输出描述：学生信息
*/

#include <stdio.h>
#include <string.h>

#define BASIC_COURSE 3
#define COURSE_LENG 31
#define NAME_LENG 31

struct Curriculum
{
    char basic_course[BASIC_COURSE][COURSE_LENG];
    int basic_score[BASIC_COURSE];
    char professional_course[COURSE_LENG];
    int professional_score;
};

typedef struct Student
{
    char name[NAME_LENG];
    long student_ID;
    struct Curriculum curriculum;
} INFO;

void input_info(INFO * student);
void output_info(INFO * student);

int main(void)
{
    INFO student;
    INFO * ptr = &student;

    input_info(ptr);
    output_info(ptr);

    return 0;
}

void input_info(INFO * student)
{
    int profession;

    printf("Enter a student's name: ");
    scanf("%s", student->name);

    printf("Enter the Student ID number: ");
    scanf("%ld", &student->student_ID);

    strcpy(student->curriculum.basic_course[0],
            "Maths");
    printf("Enter grade for %s: ",
            student->curriculum.basic_course[0]);
    scanf("%d", &student->curriculum.basic_score[0]);
    
    strcpy(student->curriculum.basic_course[1],
            "Information Fundamentals");
    printf("Enter grade for %s: ",
            student->curriculum.basic_course[1]);
    scanf("%d", &student->curriculum.basic_score[1]);

    strcpy(student->curriculum.basic_course[2],
            "English");
    printf("Enter grade for %s: ",
            student->curriculum.basic_course[2]);
    scanf("%d", &student->curriculum.basic_score[2]);

    printf("Enter the professional course "
            "(1 for Computer Theory, 2 for Software Engineering "
            "3 for Network Security): ");
    scanf("%d", &profession);
    if (1 == profession)
        strcpy(student->curriculum.professional_course,
                "Computer Theory");
    else if (2 == profession)
        strcpy(student->curriculum.professional_course,
                "Software Engineering");
    else if (3 == profession)
        strcpy(student->curriculum.professional_course,
                "Network Security");

    printf("Enter grade for %s: ",
            student->curriculum.professional_course);
    scanf("%d", &student->curriculum.professional_score);
}

void output_info(INFO * student)
{
    printf( "\n********************Student Info********************\n"
            "Name: %s\n"
            "Student ID: %d\n"
            "Basic courses and scores:\n"
            "\t%s: %d\n"
            "\t%s: %d\n"
            "\t%s: %d\n"
            "Professional course and score:\n"
            "\t%s: %d",
            student->name,
            student->student_ID,
            student->curriculum.basic_course[0],
            student->curriculum.basic_score[0],
            student->curriculum.basic_course[1],
            student->curriculum.basic_score[1],
            student->curriculum.basic_course[2],
            student->curriculum.basic_score[2],
            student->curriculum.professional_course,
            student->curriculum.professional_score );
}