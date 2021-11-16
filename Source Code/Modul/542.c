#include <stdio.h>

int main(void)
{
    int c; // variable to hold character input by user

    if ((c = getchar()) != EOF)
    {
        main();
        printf("%c", c);
    }
}