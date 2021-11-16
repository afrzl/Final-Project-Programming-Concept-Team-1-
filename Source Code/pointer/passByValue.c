#include <stdio.h>
#define PHI 3.14

void luas(float jari);
int main()
{
    float jari;
    printf("Masukkan jari-jari lingkaran : ");
    scanf("%f", &jari);

    printf("Jari-jari lingkaran adalah %.2f\n", jari);

    luas(jari);

    printf("Luas lingkaran adalah %.2f \n", jari);

    return 0;
}

void luas(float jari)
{
    jari = PHI * jari * jari;
}
