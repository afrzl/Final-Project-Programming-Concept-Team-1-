#include <stdio.h>

int main(void)
{
    FILE *fp;
    char str[100];
    // fp = fopen("file.txt", "w+");
    // fputs("saat ini sedang ujian", fp);

    // fseek(fp, 5, SEEK_SET);
    // fputs(" ujian sedang berlangsung", fp);
    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return (-1);
    }
    if (fgets(str, 5, fp) != NULL)
    {
        puts(str);
    }
}