#include <stdio.h>
#include <string.h>

void modifKalimat(char *sPtr, char *sPtr2);

int main(void)
{
    char string1[] = "saya suka makan";
    char string2[] = "nasi mandi";

    printf("String1 sebelum dimodifikasi: %s\n", string1);
    modifKalimat(string1, string2);
    printf("String1 setelah dimodifikasi: %s\n", string1);
}

void modifKalimat(char *sPtr, char *sPtr2)
{
    char temp[20];
    strncpy(temp, sPtr, 10);
    temp[10] = '\0';
    strcpy(sPtr, temp);
    //tambahkan code disini
    strcat(sPtr, &sPtr2[5]);
}