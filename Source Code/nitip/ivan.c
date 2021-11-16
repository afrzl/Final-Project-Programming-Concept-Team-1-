#include <stdio.h>
void displayBits(int value);
struct person
{
    char nama[30];
    int umur;
    float berat;
    float tinggi;
};

void bmi(float berat, float tinggi)
{
    float hasil;
    hasil = (berat) / ((tinggi / 100) * (tinggi / 100));
    printf("hasil BMI: %f\n", hasil);
    if (hasil < 18.5)
    {
        printf("berat badan kurang");
    }
    else if (hasil > 18.5 && hasil < 22.9)
    {
        printf("berat badan normal");
    }
    else if (hasil > 23 & hasil < 29, 9)
    {
        printf("berat badan berlebihan");
    }
    else if (hasil < 30)
    {
        printf("obesitas");
    }
}

int main()
{
    struct person *personPtr, person1;
    personPtr = &person1;

    printf("Masukkan Nama panggilan : ");
    scanf("%s", &personPtr->nama);

    printf("Masukkan Umur: ");
    scanf("%d", &personPtr->umur);

    printf("Masukkan berat: ");
    scanf("%f", &personPtr->berat);

    printf("Masukkan tinggi: ");
    scanf("%f", &personPtr->tinggi);

    printf("Hasil:\n");
    printf("Nama: %s\n", personPtr->nama);
    printf("Umur: %d\n", personPtr->umur);
    printf("Berat: %f\n", personPtr->berat);
    printf("Tinggi: %f\n", personPtr->tinggi);

    bmi(personPtr->berat, personPtr->tinggi);

    return 0;
}
