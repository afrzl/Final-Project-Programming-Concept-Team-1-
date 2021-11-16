#include <stdio.h>

int main()
{
    printf("A\tA+3\tA+6\tA*9\n\n");

    for (int i = 7; i <= 35; i += 7)
    {
        printf("%d\t%d\t%d\t%d \n", i, i + 3, i + 6, i * 9);
    }
}