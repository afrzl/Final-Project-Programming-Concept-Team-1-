/*
NAMA        : MUH. NUR AFRIZAL
NIM         : M0521046
PRODI       : INFORMATIKA
MATA KULIAH : KONSEP PEMROGRAMAN
KELAS       : B
*/

/*
Tugas Kelas - Week 9 (18 Oktober 2021)
Tugas Kelas - Week 9 (18 Oktober 2021)
Tugas Kelas - Week 9 (18 Oktober 2021)
*/

#include <stdio.h>

struct Person
{
    char *firstName;
    char *lastName;
    unsigned int age;
    char gender;
    int foodLike;
    struct Person *father;
    struct Person *mother;
};

struct Person pers;

// typedef struct Person Person;
typedef enum foods
{
    eBakso = 1,
    eSoto,
    eMieAyam,
    eBakmie
} Foods;

void displayBits(unsigned int value);

int main()
{
    char *foodsName[] = {"", "Bakso", "Soto", "Mie Ayam", "Bakmie"};

    struct pers human, father, mother;
    struct pers person_list[3] = {
        {"Muh", "Nur Afrizal", 18, 'M', eMieAyam, &father, &mother},
        {"Mot", "Her", 30, 'F'},
        {"Fat", "Her", 35, 'M'}};

    human = person_list[0];
    mother = person_list[1];
    father = person_list[2];

    printf("%s%s %s\n%s%d%s\n%s%s\n%s%s\n%s%s %s\n%s%s %s\n\n",
           "My name is ", human.firstName, human.lastName,
           "My age is ", human.age, " years old",
           "and my gender is ", human.gender == 'M' ? "Male" : "Female",
           "My favorite food is ", foodsName[human.foodLike],
           "My father is ", human.father->firstName, human.father->lastName,
           "My mother is ", human.mother->firstName, human.mother->lastName);

    printf("Bit dari usia ayah adalah: \n");
    displayBits(human.father->age);
    printf("Bit dari usia ibu adalah: \n");
    displayBits(human.mother->age);
    printf("Usia ayah AND usia ibu adalah: \n");
    displayBits(human.father->age & human.mother->age);
    printf("Usia ayah OR usia ibu adalah: \n");
    displayBits(human.father->age | human.mother->age);
    printf("Usia ayah XOR usia ibu adalah: \n");
    displayBits(human.father->age ^ human.mother->age);
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