#include <stdio.h>

int main(void)
{
    FILE *cfPtr;

    if ((cfPtr = fopen("mahasiswa.txt", "w")) == NULL)
    {
        puts("File tidak bisa dibuka!");
    }
    else
    {
        puts("Masukkan NIM, Nama, dan Nilai");
        puts("Masukkan EOF untuk menghentikan input.");
        printf("%s", "? ");

        unsigned int nim;
        char nama[30];
        double nilai;

        scanf("%d%29s%lf", &nim, nama, &nilai);

        while (!feof(stdin))
        {
            fprintf(cfPtr, "%d %s %.2f\n", nim, nama, nilai);
            printf("%s", "? ");
            scanf("%d%29s%lf", &nim, nama, &nilai);
        }

        fclose(cfPtr);
    }
}