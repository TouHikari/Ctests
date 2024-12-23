#include "welcome.c"
#include "student.c"

const char VERSION[] = "v0.0.1";

int main(void)
{
    welcome();
    students_core();

    return 0;
}