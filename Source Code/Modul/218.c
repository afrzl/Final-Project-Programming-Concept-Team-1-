#include <stdio.h>

/* BUKU C How to Program. With an Introduction to C++
Hal 97. Nomor 2.18 */

int main()
{
    int curahTertinggi, curahIni;
    printf("==== PROGRAM PENGECEKAN CURAH HUJAN ====\n");
    printf("\nSilahkan Masukkan Curah Hujan Tertinggi : ");
    scanf("%d", &curahTertinggi);

    printf("Silahkan Masukkan Curah Hujan Saat Ini : ");
    scanf("%d", &curahIni);

    if (curahIni > curahTertinggi)
    {
        printf("\nCurah hujan saat ini melebihi batas tertinggi!");
    }
}