#include <stdio.h>
#define SIZE 5

void copy_arr(double target1[], const double source[], int size);
void copy_ptr(double * target2, const double * source, int size);
void copy_ptrs(double target3[], const double * start, double * end);
void show_array(double array[], int size);

int main(void)
{
    double source[SIZE] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double target1[SIZE];
    double target2[SIZE];
    double target3[SIZE];

    copy_arr(target1, source, SIZE);
    copy_ptr(target2, source, SIZE);
    copy_ptrs(target3, source, source + SIZE);

    show_array(target1, SIZE);
    show_array(target2, SIZE);
    show_array(target3, SIZE);

    return 0;
}

void copy_arr(double target1[], const double source[], int size)
{
    for (int i = 0; i < size; i++)
    {
        target1[i] = source[i];
    }
    return;
}

void copy_ptr(double * target2, const double * source, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(target2 + i) = *(source + i);
    }
    return;
}

void copy_ptrs(double target3[], const double * start, double * end)
{
    int i = 0;
    while (start < end)
    {
        *(target3 + i) = *start;
        start++;
        i++;
    }
    return;
}

void show_array(double array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%4.2f ", array[i]);
    }
    printf("\n");

    return;
}