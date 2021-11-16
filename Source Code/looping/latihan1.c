#include <stdio.h>

int main()

{
    printf("Soal pertama\n");

    char nama[50], kota[50], kuliah[50], prodi[50];
    int usia;

    printf("Saha ngaran maneh teh?");
    scanf("%s", &nama);

    printf("Umurna sabraha?");
    scanf("%i", &usia);

    printf("Sia asal mana ?");
    scanf("%s", &kota);

    printf("Maneh kuliah dimana?");
    scanf("%s", &kuliah);

    printf("Kuliah jurusan naon euy?");
    scanf("%s", &prodi);

    printf("Maneh teh %s? asa ketemu wae jeung aing. Alus euy ayeuna mah geus %i taun pan? Kuliah na di %s prodi %s. Ai imah teh di &s? Aing ge mahasiswa %s", nama, usia, kuliah, prodi, kuliah);

    return 0;
}