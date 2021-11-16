/*  Nama    : Mohammad Al Furqon
    NIM     : M0521044
    Kelas   : Informatika B
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct
{
    char line[40];
    char NIM[50];
    char nama[50];
    double IPK;
} bdt;

void clearbuffer()
{
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

int tulisMahasiswa()
{
    FILE *f;

    f = fopen("biodata.bin", "wb");

    if (!f)
    {
        printf("EROR : File Tidak Dapat Dibuat!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; feof; i++)
    {
        printf("\nData ke-%d\n", i + 1);
        printf("NIM \t\t: ");
        scanf("%s", bdt.NIM);
        clearbuffer();
        printf("Nama \t\t: ");
        scanf("%[^\n]", bdt.nama);
        clearbuffer();
        printf("IPK \t\t: ");
        scanf("%lf", &bdt.IPK);
        clearbuffer();

        f = fopen("biodata.bin", "wb");

        if (f != NULL)
        {
            fwrite(bdt.NIM, 100 * sizeof(char), 1, f);
            fwrite(bdt.nama, 50 * sizeof(char), 1, f);
            fwrite(&bdt.IPK, sizeof(double), 1, f);
            fclose(f);
            printf("Sukses!\n");
        }
        fclose(f);
        printf("\nData Telah Disimpan Ke File biodata.bin");
    }
    return 0;
}
int bacaMahasiswa()
{
    FILE *f;
    int i;
    f = fopen("biodata.bin", "rb");
    while (fread(&bdt, sizeof(bdt), f) == 1)
    {
        printf("%s %s %.2f", bdt.NIM, bdt.nama, bdt.IPK);
        printf("\n");
    }
    fclose(f);
}
int updateMahasiswa()
{
    FILE *f;
    char n[80];
    int flag = 0;
    f = fopen("biodata.bin", "rb");
    if (f = NULL)
    {
        printf("File Tidak Bisa Dibuka!");
        exit(1);
        fclose(f);
    }
    printf("Masukkan NIM Mahasiswa Yang Ingin Dirubah : ");
    scanf("%s", &n);
    while (fread(&bdt, sizeof(bdt), 1, f) == 1)
    {
        if (strcmp(bdt.NIM, n) == 0)
        {
            puts("Masukkan Data Baru");
            printf("NIM : ");
            scanf("%s", bdt.NIM);
            printf("Nama : ");
            scanf("%s", bdt.nama);
            printf("IPK : ");
            scanf("%lf", &bdt.IPK);
            fseek(f, -sizeof(bdt), 1);
            fwrite(&bdt, sizeof(bdt), 1, f);
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {
        printf("\n Sukses!");
    }
    else
    {
        printf("Gagal!");
    }
    fclose(f);
}
int main(void)
{

    unsigned int menuPilihan;
    puts("Menu Sequential Access File (.txt):");
    puts("1. Tulis Data Mahasiswa");
    puts("2. List Data Mahasiswa");
    printf("\nPilihan : ");
    scanf("%u", &menuPilihan);
    system("cls");
    {
        switch (menuPilihan)
        {
        case 1:
            tulisMahasiswa();
            break;
        case 2:
            bacaMahasiswa();
            break;
        case 3:
            updateMahasiswa();
            break;

        default:
            puts("Maaf Pilihan Menu Tidak Diketahui");
            break;
        }
    }
}