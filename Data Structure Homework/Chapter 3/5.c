#include <stdio.h>

void MoveArray(int arr[], int length, int digits);

int main(void)
{
    int length, digits;
    scanf("%d %d", &length, &digits);

    int arr[length];
    for (int i = 0; i < length; i++)
        scanf("%d", &arr[i]);
    
    MoveArray(arr, length, digits);

    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);

    return 0;
}

void MoveArray(int arr[], int length, int digits)
{
    int temp = arr[length - 1];
    for (int j = 0; j < digits; j++)
    {
        for (int i = 0; i < length - 1; i++)
        {
            arr[length - 1 - i] = arr[length - 2 - i];
        }
        arr[0] = temp;
        temp = arr[length - 1];
    }
}