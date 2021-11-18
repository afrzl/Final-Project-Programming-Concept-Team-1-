#include <stdio.h>

int main()
{
    int i = 1;
    while (i < 10)
    {
        int j = 1;
        if (i % 2 == 1)
        {
            while (j <= i)
            {
                printf("%d ", j);
                j++;
            }
            printf("\n");
        }
        i++;
    }
}