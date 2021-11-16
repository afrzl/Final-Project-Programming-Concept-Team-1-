#include <stdio.h>

int main()
{
    //PERSEGI PANJANG
    int panjang, lebar;
    panjang = 9;
    lebar = 9;
    for (int i = 1; i <= lebar; i++)
    {
        if (i == 1 || i == lebar)
        {
            for (int j = 1; j <= panjang; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            for (int k = 1; k <= panjang; k++)
            {
                if (k == 1 || k == panjang)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    printf("\n\n");
    //LINGKARAN
    for (int i = 1; i <= lebar; i++)
    {
        if (i == 1 || i == lebar)
        {
            for (int j = 1; j <= panjang / 3; j++)
            {
                printf(" ");
            }
            for (int j = 1; j <= panjang / 3; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        else if (i == 2 || i == lebar - 1)
        {
            for (int j = 1; j <= panjang; j++)
            {
                if (j == 2 || j == panjang - 1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        else
        {
            for (int j = 1; j <= panjang; j++)
            {
                if (j == 1 || j == panjang)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    printf("\n\n");
    //ANAK PANAH
    int anakPanah1 = 5;
    int anakPanah2 = 3;
    int anakPanah3 = 6;
    for (int i = 1; i <= anakPanah2; i++)
    {
        for (int j = 2; j < anakPanah1 - i; j++)
            printf(" ");
        for (int j = 0; j < (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
    for (int i = 1; i <= anakPanah3; i++)
    {
        for (int j = 0; j < anakPanah1 / 2; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }

    printf("\n\n");
    //DIAMOND
    for (int i = 5; i >= 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            printf(" ");
        }
        printf("*");
        for (int j = 0; j < 2 *; j++)
        {
        }
    }
}