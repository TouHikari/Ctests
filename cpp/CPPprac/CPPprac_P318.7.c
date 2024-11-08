#include <stdio.h>
#define SIZE1 2
#define SIZE2 6

void cube_ptr_ar_copy(int size1, int size2, 
                    double source[][size2], double target[][size2]);
void show_array(double array[], int size);

int main(void)
{
    double square[SIZE1][SIZE2] = 
                { { 1., 2., 3., 4., 5., 6. }, { 7., 8., 9., 10., 11., 12. } };
    double target[SIZE1][SIZE2];
    int size1 = SIZE1;
    int size2 = SIZE2;

    for (int i = 0; i < SIZE1; i++)
        show_array(square[i], SIZE2);
    for (int i = 0; i < SIZE1; i++)
        show_array(target[i], SIZE2);

    cube_ptr_ar_copy(size1, size2, square, target);

    for (int i = 0; i < SIZE1; i++)
        show_array(square[i], SIZE2);
    for (int i = 0; i < SIZE1; i++)
        show_array(target[i], SIZE2);

    return 0;
}

void cube_ptr_ar_copy(int size1, int size2, 
                    double source[][size2], double target[][size2])
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            target[i][j] = source[i][j];
        }
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