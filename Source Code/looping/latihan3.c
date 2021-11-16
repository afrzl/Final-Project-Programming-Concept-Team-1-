#include <stdio.h>

int main()
{
    int panjang, lebar;
    printf("----- PROGRAM MEMBUAT PERSEGI PANJANG ----- \n");
    printf("Masukkan Panjang : ");
    scanf("%d", &panjang);
    printf("Masukkan Lebar : ");
    scanf("%d", &lebar);

    printf("----- HASIL ----- \n");
    for (int i = 1; i <= lebar; i++)
    {
        if (i == 1 || i == lebar)
        {
            for (int j = 0; j < panjang; j++)
            {
                printf(" * ");
            }
            printf("\n");
        }
        else
        {
            for (int k = 1; k <= panjang; k++)
            {
                if (k == 1 || k == panjang)
                {
                    printf(" * ");
                }
                else
                {
                    printf("   ");
                }
            }
            printf("\n");
        }
    }
}