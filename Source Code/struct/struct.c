#include <stdio.h>
#include <string.h>

void displayBits(unsigned int value);

int main()
{
    // char *afrizalNama, *didanNama, *nisaNama;
    // int ageAfrizal;

    // afrizalNama = "Afrizal";
    // didanNama = "Didan";
    // nisaNama = "Nisa";

    // afrizalAge = 18;

    // printf("%s", afrizalNama);
    // printf("%s", didanNama);

    typedef struct Orang{
        char *nama;
        unsigned int age;
        char *makananKesukaan;
        struct Orang *Ayah;
        struct Orang *Ibu;
    } Orang;

    typedef enum foods {
        eBakso = 1,
        eSoto,
        eMieAyam,
        eBakmie
    } Foods;

    Foods afrizalLike = 1;
    char *foodsName[] = {"", "Bakso", "Soto", "Mie Ayam", "Bakmie"};

    Orang Afrizal, Ayah, Ibu;

    Orang oranglist[3] = {
        {"Afrizal", 18, foodsName[afrizalLike], &Ayah, &Ibu},
        {"Didan", 35},
        {"Nisa", 20}
    };

    Afrizal = oranglist[0];
    Ayah = oranglist[1];
    Ibu = oranglist[2];

    printf("%s", Afrizal.makananKesukaan);


    // if (afrizalLike = 1)
    // {
    //     printf("aFRIZAL suKA sOTO");
    // }
    
    // printf("%d", afrizalLike);

    // printf("%d", Afrizal.Ayah->age);


    // Afrizal.nama = "Afrizal";
    // // strcpy(Afrizal.nama , "Afrizal");
    // Afrizal.age = 18;

    // Didan.nama = "Hikmah";
    // Didan.age = 18;

    // printf("%s\n", Afrizal.nama);
    // printf("%d\n", Afrizal.age);
    // printf("%s\n", Didan.nama);
    // printf("%d", Didan.age);

    //BITWISE
    // and, or, xor
    // & | ^
    // displayBits(Ayah.age);
    // displayBits(Ibu.age);
    // displayBits(Ayah.age | Ibu.age);
}

void displayBits(unsigned int value)
{
    // declare displayMask and left shift 31 bits
    unsigned int displayMask = 1 << 31;

    printf("%10u = ", value);

    // loop through bits
    for (unsigned int c = 1; c <= 32; ++c)
    {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1; //shift value left by 1

        if (c % 8 == 0)
        {
            putchar(' ');
        }
    }

    putchar('\n');
}