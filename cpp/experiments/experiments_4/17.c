/*
写一函数实现功能构造一个长方形或直角三角形并打印显示出来。在主函数中调用该函数，对用户
的输入要求显示相应的图像如
6666666666
6        6
6        6
6        6
6666666666
输入描述：垂直两边的长度和边缘字符、图形类别
输出描述：长方形或直角三角形
*/

#include <stdio.h>

void draw_rectangle(int length, int width, char margin);
void draw_triangle(int length, int width, char margin);

int main(void)
{
    int length, width, mode;
    char margin;

    printf("Enter the figure you want to draw");
    printf("(1 for rectangle, 2 for traingle): ");
    scanf("%d", &mode);
    printf("Enter the width of the figure: ");
    scanf("%d", &width);
    if (1 == mode)
    {
        printf("Enter the length of the figure: ");
        scanf("%d", &length);
    }
    printf("Enter the character which is for the margin: ");
    getchar();
    scanf("%c", &margin);

    switch (mode)
    {
    case 1:
        draw_rectangle(length, width, margin);
        break;
    case 2:
        draw_triangle(length, width, margin);
        break;
    default:
        printf("Promgramme error! Exitting...");
        break;
    }

    return 0;
}

void draw_rectangle(int length, int width, char margin)
{
    for (int i = 0; i < length; i++)
    {
        putchar(margin);
    }
    putchar('\n');
    
    for (int i = 2; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (0 == j || length - 1 == j)
            {
                putchar(margin);
            }
            else
            {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    for (int i = 0; i < length; i++)
    {
        putchar(margin);
    }
    putchar('\n');
    
    return;
}

void draw_triangle(int length, int width, char margin)
{
    for (int i = 0; i < width; i++)
    {
        if (0 == i)
        {
            putchar(margin);
        }
        else if (width - 1 == i)
        {
            for (int j = 0; j < width; j++)
            {
                putchar(margin);
            }
            
        }
        else
        {
            putchar(margin);
            for (int j = 1; j < i; j++)
            {
                putchar(' ');
            }
            putchar(margin);
        }
        putchar('\n');
    }

    return;
}