#include <stdio.h>

int main()
{
    int x = 0;
    printf("number\tsquare\tcube\n");

    while (x <= 10)
    {
        printf("%d\t%d\t%d \n", x, x * x, x * x * x);
        x++;
    }
}