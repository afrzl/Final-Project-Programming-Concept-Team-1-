#include <stdio.h>
const float phi = 3.14;

int main()
{
    float jari, tinggi, volume;
    printf("Masukkan jari-jari silinder : ");
    scanf("%f", &jari);
    printf("Masukkan tinggi silinder : ");
    scanf("%f", &tinggi);

    volume = phi*jari*jari*tinggi;
    printf("\nVolume silinder tersebut adalah : %.2f", volume);
}
