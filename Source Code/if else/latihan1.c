#include <stdio.h>

int main()
{
    char pw[255];

    printf("----- SILAHKAN LOGIN ------");
    printf("Masukkan password anda : ");
    scanf("%s", &pw);

    if (strcmp(pw, "afrizal") == 0)
    {
        printf("SELAMAT ANDA TELAH LOGIN!");
    }
    else
    {
        printf("PASSWORD SALAH!!");
    }
}