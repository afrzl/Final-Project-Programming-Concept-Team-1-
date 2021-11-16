#include <stdio.h>

int main()
{
    double triangle[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Masukkan sisi %d segitiga: ", i + 1);
        scanf("%d", &triangle[i]);
    }
}