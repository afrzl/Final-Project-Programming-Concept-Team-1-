#include <stdio.h>

typedef struct Manusia
{
    char *NamaDepan;
    char *NamaBelakang;
    unsigned int Umur;
    char JenisKelamin;
    char *MakananFavorit;
    struct Manusia *Ayah;
    struct Manusia *Ibu;
} Manusia;

typedef enum Makanan
{
    eSoto = 1,
    eNasiGoreng,
    eSayurLodeh,
    eBakso
} Makanan;

void tampilan_bit(unsigned int value);

int main()
{

    Manusia Saya, Ayah, Ibu;
    char *NamaMakanan[] = {"", "Soto", "Nasi Goreng", "Sayur Lodeh", "Bakso"};

    Makanan MakananFavorit = 2;

    Saya.NamaDepan = "Ria";
    Saya.NamaBelakang = "Sina";
    Saya.MakananFavorit = NamaMakanan[MakananFavorit];
    Saya.JenisKelamin = 'F';
    Saya.Umur = 18;
    //AKU NAMBAHIN 2 LINE DIBAWAH INI
    Saya.Ayah = &Ayah;
    Saya.Ibu = &Ibu;

    Ibu.NamaDepan = "Sri";
    Ibu.NamaBelakang = "Rejeki";
    Ibu.Umur = 55;

    Ayah.NamaDepan = "Tri";
    Ayah.NamaBelakang = "Wahyudi";
    Ayah.Umur = 52;

    printf("%s%s %s\n%s%d%s\n%s%c\n%s%s\n%s%s %s\n%s%s %s\n\n",
           "Perkenalkan Nama Saya ", Saya.NamaDepan, Saya.NamaBelakang,
           "Saya berusia ", Saya.Umur, " tahun",
           "Saya berjenis kelamin : ", Saya.JenisKelamin,
           "Makanan favorit Saya adalah ", Saya.MakananFavorit,
           // AKU NGEDIT DISINI KURUNGNYA SALAH
           "Nama Ibu Saya adalah ", Saya.Ibu->NamaDepan, Saya.Ibu->NamaBelakang,
           "Nama Ayah Saya adalah ", Saya.Ayah->NamaDepan, Saya.Ayah->NamaBelakang);

    printf("Tampilan bit dari usia Ayah dan Ibu =\n");

    printf("Usia Ibu memiliki bit: \n");
    tampilan_bit(Saya.Ibu->Umur);
    printf("Usia Ayah memiliki bit: \n");
    tampilan_bit(Saya.Ayah->Umur);
    printf("Usia ayah AND usia Ibu adalah: \n");
    tampilan_bit(Saya.Ayah->Umur & Saya.Ibu->Umur);
    printf("Usia ayah OR usia Ibu adalah: \n");
    tampilan_bit(Saya.Ayah->Umur | Saya.Ibu->Umur);
    printf("Usia ayah XOR usia Ibu adalah: \n");
    tampilan_bit(Saya.Ayah->Umur ^ Saya.Ibu->Umur);

    return 0;
}

void tampilan_bit(unsigned int value)
{
    unsigned int mask_display = 1 << 31;

    printf("%10u = ", value);

    for (unsigned int c = 1; c <= 32; ++c)
    {
        putchar(value & mask_display ? '1' : '0');
        value <<= 1;

        if (c % 8 == 0)
        {
            putchar(' ');
        }
    }

    putchar('\n');
}
