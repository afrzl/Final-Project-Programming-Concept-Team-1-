#include <stdio.h>

/* BUKU C How to Program. With an Introduction to C++
Hal 97. Nomor 2.16 */

int main()
{
    int angka1, angka2, sum, product, difference, remainder;
    float quotient;
    printf("Masukkan dua angka : ");
    scanf("%d %d", &angka1, &angka2);

    printf("========================\n");
    sum = angka1 + angka2;
    product = angka1 * angka2;
    difference = angka1 - angka2;
    quotient = angka1 / angka2;
    remainder = angka1 % angka2;
    printf("SUM\t\t%d + %d = %d\n", angka1, angka2, sum);
    printf("PRODUCT\t\t%d * %d = %d\n", angka1, angka2, product);
    printf("DIFFERENT\t%d - %d = %d\n", angka1, angka2, difference);
    printf("QUOTIENT\t%d / %d = %d\n", angka1, angka2, quotient);
    printf("REMAINDER\t%d mod %d = %d\n", angka1, angka2, remainder);
}