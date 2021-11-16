#include <stdio.h>

int main(void)
{
    FILE *cfPtr;
    if ((cfPtr = fopen("mahasiswa.txt", "r")) == NULL)
    {
        puts("File tidak bisa dibuka.");
    }
    else
    {
        unsigned int nim;
        char nama[30];
        double nilai;

        printf("%-10s%-13s%s\n", "NIM", "Nama", "Nilai");
        fscanf(cfPtr, "%d%29s%lf", &nim, nama, &nilai);

        while (!feof(cfPtr))
        {
            printf("%-10d%-13s%7.2f\n", nim, nama, nilai);
            fscanf(cfPtr, "%d%29s%lf", &nim, nama, &nilai);
        }

        fclose(cfPtr);
    }
}