#include <stdio.h>

int main()
{
    char fakultas;
    int prodi, ta, nim;
    char name[100];

    printf("%s", "Masukkan NIM sesuai dengan format (contoh : M0521046): \n");
    printf("%s", "Kode Fakultas : ");
    scanf("%c", &fakultas);
    printf("%s", "2 digit kode prodi (contoh : 05): ");
    scanf("%d", &prodi);
    printf("%s", "2 digit tahun angkatan (contoh : 21): ");
    scanf("%d", &ta);
    printf("%s", "Masukkan 3 digit NIM terakhir (contoh : 046): ");
    scanf("%d", &nim);
    printf("%s", "Masukkan nama: ");
    scanf("%99s", &name);
}