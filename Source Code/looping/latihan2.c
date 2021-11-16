#include <stdio.h>

int main()
{
    int baris;
    printf("Silahkan masukkan angka : ");
    scanf("%d", &baris);

    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}