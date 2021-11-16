#include <stdio.h>

/* BUKU C How to Program. With an Introduction to C++
Hal 97. Nomor 2.17 */

int main()
{
    int u, a, t, v, s;
    printf("Masukkan u : ");
    scanf("%d", &u);
    printf("Masukkan a : ");
    scanf("%d", &a);
    printf("Masukkan t : ");
    scanf("%d", &t);

    v = u + a * t;
    printf("--PROGRAM MENCARI KECEPATAN--\n");
    printf("v = %d", v);
    printf("\n\n");

    s = u * t + 0.5 * a * t * t;
    printf("--PROGRAM MENCARI JARAK--\n");
    printf("s = %d", s);
}