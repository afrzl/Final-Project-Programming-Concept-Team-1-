#include <stdio.h>

void main()
{
    int tinggi;
    printf("----- PROGRAM MEMBUAT SEGITIGA -----\n");
    printf("Silahkan masukkan tinggi : ");
    scanf("%d", &tinggi);

    for (int i = 1; i <= tinggi; i++)
    {
        for (int j = 1; j <= tinggi - i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
//   *
//  ***
// *****