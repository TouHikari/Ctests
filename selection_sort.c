#include <stdio.h>
#define LENGTH 100

int * selection_sort(int array[], int length);

int main(void)
{
    int array[LENGTH];
    int i = 0;

    printf("Enter up to %d integers (type 'q' to stop):\n\t", LENGTH);
    while (i < LENGTH && scanf("%d", &array[i]) == 1)
    {
        i++;
    }

    selection_sort(array, i);

    printf("The sorted array is:\n\t");
    for (int j = 0; j < i; j++)
    {
        printf("%d ", array[j]);
    }

    return 0;
}

int * selection_sort(int array[], int length)
{
    int temp;

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[i])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return array;
}