#include <stdio.h>
#define PHI 3.14

int main()
{
    float jari, luas, keliling;
    printf("Masukkan jari-jari lingkaran : ");
    scanf("%f", &jari);

    luas = PHI * jari * jari;
    keliling = 2 * PHI * jari;

    printf("Luas lingkaran adalah %.2f \n", luas);
    printf("Keliling lingkaran adalah %.2f", keliling);

    return 0;
}
