#include <stdio.h>
#include <string.h>
 
int main() {
    const char *str = "Hello, World!";
    char ch = 'o';
    
    char *lastO = strrchr(str, ch);
    
    if (lastO != NULL) {
        printf("Last '%c' found at position: %ld\n", ch, lastO - str);
    } else {
        printf("'%c' not found in the string.\n", ch);
    }
    
    return 0;
}