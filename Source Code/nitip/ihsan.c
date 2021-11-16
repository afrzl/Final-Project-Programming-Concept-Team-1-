#include <stdio.h>

struct orang
{
    char nama[40];
    char NIM[20];
    float nilai;
    float nilai2;
    float nilai3;
};

void rata(float nilai, float nilai2, float nilai3)
{
    float total;
    total = ((nilai + nilai2 + nilai3) / 3);
    printf("Rata Rata nilai = %f\n", total);

    if (total >= 95)
    {
        printf("\nAnda masuk 5 besar");
    }
    else if (total >= 85 && total < 95)
    {
        printf("\nAnda masuk 10 besar");
    }
    else if (total >= 80 && total < 85)
    {
        printf("\nAnda masuk 15 besar");
    }
    else if (total >= 70 && total < 80)
    {
        printf("\nAnda masuk 20 besar");
    }
    else if (total < 70)
    {
        printf("\nAnda masuk 30 besar");
    }
    else
    {
        printf("\ninput nilai yang anda masukan salah!");
    }
}

int main()
{
    struct orang *orngptr, nama1;

    orngptr = &nama1;

    printf("Masukan Nama Anda : ");
    scanf("%s", &orngptr->nama);

    printf("Masukan NIM anda : ");
    scanf("%s", &orngptr->NIM);
    printf("\n====Masukan Nilai Anda====\n");

    printf("\nNIlai Kalkulus : ");
    scanf("%f", &orngptr->nilai);

    printf("Nilai Statistik : ");
    scanf("%f", &orngptr->nilai2);

    printf("Nilai B.Indonesia : ");
    scanf("%f", &orngptr->nilai3);

    printf("\ntotal:\n");
    printf("Nama: %s\n", orngptr->nama);
    printf("NIM: %s\n", orngptr->NIM);

    printf("kalkulus: %f\n", orngptr->nilai);
    printf("statistik: %f\n", orngptr->nilai2);
    printf("B.Indonesia: %f\n", orngptr->nilai3);

    printf("\n");

    rata(orngptr->nilai, orngptr->nilai2, orngptr->nilai3);

    return 0;
}