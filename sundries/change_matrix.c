#include <stdio.h>
#define LENGTH 5

int * change_matrix(int length, int temp[][length], int arr[][length]);

int main(void)
{
    int array[LENGTH][LENGTH];
    int temp[LENGTH][LENGTH];
    
    printf("Enter the %d*%d array: \n", LENGTH, LENGTH);
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            scanf("%d", &temp[i][j]);
        }
    }

    change_matrix(LENGTH, temp, array);

    printf("The changed matrix is:\n");
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            printf("%d ", array[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

int * change_matrix(int length, int temp[][length], int arr[][length])
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            arr[i][j] = temp[j][i];
        }
    }

    return arr[0];
}