#include <stdio.h>
#include <math.h>

static const char *msg[] = { "Sunday", "Monday", "Tuesday",
                             "Wednesday", "Thursday", "Friday",
                             "Saturday",
                           };

void get_a_day(const char **p)
{
    static int i = 0;
    *p = msg[i % 7];
    i++;
}

int main(int argc, char const *argv[])
{
    const char *firstday = NULL;
    const char *secondday = NULL;
    get_a_day(&firstday);
    get_a_day(&secondday);
    printf("%s\t%s\n", firstday, secondday);
    return 0;
}
