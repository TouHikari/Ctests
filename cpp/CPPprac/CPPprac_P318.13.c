#include <stdio.h>
#define SIZE1 3
#define SIZE2 5

int main(void)
{
    double array[SIZE1][SIZE2];
    double num1, num2, num3, num4, num5;
    double ave1, ave2, ave3;
    double max = 0;

    printf("Enter 5 numbers in 3 groups. \n");
    for (int i = 0; i < SIZE1; i++)
    {
        scanf("%lf %lf %lf %lf %lf", &num1, &num2, &num3, &num4, &num5);
        array[i][0] = num1;
        array[i][1] = num2;
        array[i][2] = num3;
        array[i][3] = num4;
        array[i][4] = num5;
        switch (i)
        {
        case 0:
            ave1 = (num1 + num2 + num3 + num4 + num5) / 5.;
            break;
        case 1:
            ave2 = (num1 + num2 + num3 + num4 + num5) / 5.;
            break;
        case 2:
            ave3 = (num1 + num2 + num3 + num4 + num5) / 5.;
            break;
        default:
            break;
        }
        if (i + 1 < SIZE1)
            printf("Enter another 5 numbers. \n");
    }
    
    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            if (array[i][j] > max)
            {
                max = array[i][j];
            }
        }
    }
    
    printf("Average1 = %.3lf\n", ave1);
    printf("Average2 = %.3lf\n", ave2);
    printf("Average3 = %.3lf\n", ave3);
    printf("Maximum = %.3lf\n", max);

    return 0;
}

