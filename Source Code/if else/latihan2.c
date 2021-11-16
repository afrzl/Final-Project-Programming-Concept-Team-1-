#include <stdio.h>

int main()
{
    char grade;
    int nilai;
    printf("--- PROGRAM PEMBUAT GRADE NILAI --- \n");
    printf("Silahkan masukkan nilai : ");
    scanf("%d", &nilai);

    if (nilai >= 91)
    {
        grade = 'A';
    }
    else if (nilai >= 81)
    {
        grade = 'B';
    }
    else if (nilai >= 71)
    {
        grade = 'C';
    }
    else
    {
        grade = 'D';
    }

    printf("------------------------- \n");
    printf("Grade nilai anda adalah : %c", grade);
}