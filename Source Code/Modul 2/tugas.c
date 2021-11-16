#include <stdio.h>

const float phi = 3.14152965f;
int main()
{
    float jari = 0.0f;
    float volume = 0.0f;
    printf("Masukkan jari-jari bola : ");
    scanf("%f", &jari);

    volume = 0.5*phi*jari*jari*jari;
    printf("Volume setengah dari bola tersebut adalah %2.f", volume);
}
