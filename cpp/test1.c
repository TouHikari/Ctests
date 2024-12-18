#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * compress(char * src);

int main(void)
{
    char src[100];
    scanf("%s", src);

    char * ps = compress(src);

    puts(ps);

    return 0;
}

char * compress(char * src)
{
    static char result[100];
    result[0] = '\0';
    char temp = src[0];

    if (temp == '\0')
    {
        return src;
    }

    int i = 0;
    while (src[i] != '\0')
    {
        int count = 0;
        while (1)
        {
            if (src[i] == temp)
                count++;
            else
                break;
            i++;
        }
        if (count >= 3)
        {
            sprintf(strchr(result, '\0'),
                    "%c%d\0", temp, count);
        }
        else
        {
            for (int j = 0; j < count; j++)
            {
                sprintf(strchr(result, '\0'),
                        "%c\0", temp);
            }
        }
        temp = src[i];
    }
    return result;
}