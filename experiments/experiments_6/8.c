/*
定义一个结构体类型，在该结构体类型中嵌入联合体类型的定义，联合体类型包含三个不同类型
的成员变量，结构体类型中的另一个变量用来标记联合体类型中保存的数据类型。定义两个函数，
一个用于给结构体中的数据成员赋值，一个用于按结构体类型中标记的类型输出数据。在主函数
中声明结构体变量和调用两个函数，根据输入的类型和数值赋值并输出。
输入描述：类型和数值
输出描述：类型和数值
*/

#include <stdio.h>
#include <string.h>

struct bad_boy
{
    int which; // 0 for int, 1 for double, 2 for char
    union types
    {
        int integer;
        double long_float;
        char character;
    };
};

void assign_struct(struct bad_boy * boy);
void output_struct(struct bad_boy * boy);

int main(void)
{
    struct bad_boy this;
    struct bad_boy * ptr = &this;
    assign_struct(ptr);

    output_struct(ptr);
    
    return 0;
}

void assign_struct(struct bad_boy * boy)
{
    char type[11];

    printf("Input the type of the variable ");
    printf("(0 for int, 1 for double, 2 for char): ");
    scanf("%d", &boy->which);
    getchar();

    if (0 == boy->which)
    {
        strcpy(type, "integer");
    }
    else if (1 == boy->which)
    {
        strcpy(type, "long float");
    }
    else if (2 == boy->which)
    {
        strcpy(type, "character");
    }

    printf("Enter the value of %s: ", type);
    if (0 == boy->which)
    {
        scanf("%d", &boy->integer);
    }
    else if (1 == boy->which)
    {
        scanf("%lf",& boy->long_float);
    }
    else if (2 == boy->which)
    {
        scanf("%c", &boy->character);
    }
}

void output_struct(struct bad_boy * boy)
{
    char type[11];

    if (0 == boy->which)
    {
        strcpy(type, "integer");
    }
    else if (1 == boy->which)
    {
        strcpy(type, "long float");
    }
    else if (2 == boy->which)
    {
        strcpy(type, "character");
    }

    printf("\nThe input type is %s.\n", type);

    if (0 == boy->which)
    {
        printf("And the value is %d.", boy->integer);
    }
    else if (1 == boy->which)
    {
        printf("And the value is %lf.", boy->long_float);
    }
    else if (2 == boy->which)
    {
        printf("And the value is %c.", boy->character);
    }
}