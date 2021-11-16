#include <stdio.h>

int main()
{
    float alas = 0.0f;
    float tinggi = 0.0f;
    float luas = 0.0f;

    printf("Masukkan alas segitiga : ");
    scanf("%f", &alas);
    printf("Masukkan tinggi segitiga : ");
    scanf("%f", &tinggi);

    luas = 0.5*alas*tinggi;
    printf("Luas segitiga sama kaki tersebut adalah %.2f", luas);

}
