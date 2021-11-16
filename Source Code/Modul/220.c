#include <stdio.h>

/* BUKU C How to Program. With an Introduction to C++
Hal 97. Nomor 2.20 */

int main()
{
    int detik, hours, minutes, seconds, sisaMenit;
    printf("==== PROGRAM MENYEDERHANAKAN DETIK ====\n");
    printf("\nSilahkan masukkan detik: ");
    scanf("%d", &detik);

    hours = detik / 3600;
    sisaMenit = detik % 3600;
    minutes = sisaMenit / 60;
    seconds = sisaMenit % 60;

    printf("HASIL => %d:%d:%d", hours, minutes, seconds);
}