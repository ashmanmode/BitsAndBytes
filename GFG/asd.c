#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "abcdefgh";
    int j = 10;

    sprintf (str, "%s-%d", str, j);
    printf ("%s", str);
    printf ("\n");

    strcat(str, (char *)10);
    printf ("%s", str);
    printf ("\n");

    return 0;
}