#include <stdio.h>
#include <stdlib.h>

int flip();

int main()
{
    int tails = 0, heads = 0;
    for (int toss = 0; toss < 100; toss++)
    {
        int x = flip();
        printf("%d ", x);
        if (x == 0)
        {
            tails++;
        } else
        {
            heads++;
        }
    }
    printf("\nMenghasilkan heads sebanyak: %d kali", heads);
    printf("\nMenghasilkan tails sebanyak: %d kali", tails);
}

int flip()
{
    int i = rand() % 2;
    if(i == 0){
        return 0;
    } else {
        return 1;
    }
}