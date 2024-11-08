#include <stdio.h>
#define SIZE 6

void sum_array(int * array1, int * array2, int * array3,int size);
void show_array(int * array, int size, char * name);

int main(void)
{
    int array1[SIZE] = { 4, 3, 7, 3, 5, 9 };
    int array2[SIZE] = { 9, 1, 3, 5, 2, 7 };
    int array3[SIZE];

    sum_array(array1, array2, array3, SIZE);

    show_array(array1, SIZE, "array1 = ");
    show_array(array2, SIZE, "array2 = ");
    show_array(array3, SIZE, "array3 = ");

    return 0;
}

void sum_array(int * array1, int * array2, int * array3,int size)
{
    for (int i = 0; i < size; i++)
    {
        *(array3 + i) = *(array1 + i) + *(array2 + i);
    }
    
    return;
}

void show_int_array(int * array, int size, char * name)
{
    printf("%s", name);
    for (int i = 0; i < size; i++)
    {
        printf("%3d ", *(array + i));
    }
    printf("\n");

    return;
}