#include <stdio.h>
#include <string.h>
#include <float.h>

int main()
{
    //Q1
    char firstname1[15], lastname1[15];
    printf("Enter your first and last name to continue...\n");
    scanf("%s %s", firstname1, lastname1);
    printf("%s,%s\n\n", lastname1, firstname1);

    //Q2
    char name2[15];
    printf("Enter your name to continue...\n");
    scanf("%s", name2);
    printf("\"%s\"\n", name2);
    printf("\"%20s\"\n", name2);
    printf("\"%-20s\"\n", name2);
    printf("%*s\n\n", strlen(name2)+3, name2);

    //Q3
    printf("Enter a float number to continue...\n");
    float fnum;
    scanf("%f", &fnum);
    printf("The input is %.1f or %.1e.\n", fnum, fnum);
    printf("The input is %+.3f or %.3e.\n\n", fnum, fnum);

    //Q4
    printf("Enter your height and name to continue...\n");
    float height;
    char name4[15];
    scanf("%f %s", &height, name4);
    height = height / 12 ;
    printf("%s, you are %.3f feet tall\n\n", name4, height);

    //Q5
    printf("Enter a download speed in Mb/s and a file size in MB...\n");
    float speed, size;
    scanf("%f %f", &speed, &size);
    printf("At %.2f magabits per second, a file of %.2f megabytes\n", speed, size);
    printf("downloads in %.2f seconds. \n\n", size/8/speed);

    //Q6
    printf("Enter your first name...\n");
    char firstname6[15], lastname6[15];
    scanf("%s", firstname6);
    printf("Enter your last name...\n");
    scanf("%s", lastname6);
    printf("%s %s\n%*d %*d\n", firstname6, lastname6, 
        strlen(firstname6), strlen(firstname6), 
        strlen(lastname6), strlen(lastname6));
    printf("%s %s\n%-*d %-*d\n\n", firstname6, lastname6, 
        strlen(firstname6), strlen(firstname6), 
        strlen(lastname6), strlen(lastname6));

    //Q7
    double doublenum = 1.0/3.0;
    float floatnum = 1.0/3.0;
    printf("Double = %.6f, %.12f, %.16f\n", doublenum, doublenum, doublenum);
    printf("FLoat = %.6f, %.12f %.16f\n", floatnum, floatnum, floatnum);
    printf("FLT_DIG = %d\n", FLT_DIG);
    printf("DBL_DIG = %d\n\n", DBL_DIG);

    //Q8
    printf("Enter mileage of travel and the amount of gasoline consumed...\n");
    float mile, gasoline, permile;
    scanf("%f %f", &mile, &gasoline);
    permile = mile / gasoline;
    printf("Miles per a gallon of gasoline = %.1f.\n", permile);
    permile = permile * 1.609 / 3.785;
    printf("Kilomitres per a litre of gasoline = %.1f.\n", permile);
    
    return 0;
}