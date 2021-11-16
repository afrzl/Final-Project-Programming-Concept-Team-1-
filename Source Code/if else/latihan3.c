#include <stdio.h>

int main()
{
    char grade;
    printf("-----PROGRAM GRADE----- \n");
    printf("Masukkan grade nilai : ");
    scanf("%c", &grade);

    switch (toupper(grade))
    {
    case 'A':
        printf("Sangat Bagus! \n");
        break;
    case 'B':
        printf("Bagus! \n");
        break;
    case 'C':
        printf("JELEK! \n");
        break;

    default:
        printf("NGAWUR! \n");
        break;
    }

    printf("-----TERIMAKASIH SUDAH MENGGUNAKAN PROGRAM INI-----");
}