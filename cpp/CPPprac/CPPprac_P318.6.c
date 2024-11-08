#include <stdio.h>
#define SIZE 6

void reverse_array(double * array, int size);
void show_array(double array[], int size);

int main(void)
{
    double array[SIZE] = { 1, 2, 3, 4, 5, 6 };
    show_array(array, SIZE);
    reverse_array(array, SIZE);
    show_array(array, SIZE);

    return 0;
}

void reverse_array(double * array, int size)
{
    double temp[size];
    for (int i = 0; i < size; i++)
    {
        *(temp + i) = *(array + size - 1 - i);
    }
    for (int i = 0; i < size; i++)
    {
        *(array + i) = *(temp + i);
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