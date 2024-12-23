#include <stdio.h>
#include <string.h>

void function(char * ptr[]);

int main(void)
{
    char strings[5][40] = {
        "This is the first one.",
        "And this is the second.",
        "Also, I'm the third.",
        "Don't forget the fourth!",
        "So it's the last one."
    };

    char * ptr[5] = {strings[0], strings[1], strings[2], strings[3], strings[4]};

    function(ptr);

    for (int i = 0; i < 5; i++)
    {
        puts(ptr[i]);
    }
    

    return 0;
}

void function(char * ptr[])
{
    char * temp;
    for (int i = 1; i < 5; i++)
    {
        for (int j = 0; j < 5 - i; j++)
        {
            if (strcmp(ptr[j], ptr[j + 1]) > 0)
            {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
    
}