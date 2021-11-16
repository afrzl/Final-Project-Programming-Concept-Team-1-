#include <stdio.h>

int main()
{
    int nim[100] = {1, 2, 3, 4, 5};

    FILE *fPtr = fopen("mahasiswa.bin", "wb");
    if (fPtr != NULL)
    {
        fwrite(nim, sizeof(int), 5, fPtr);
    }
    else
    {
        puts("Something went wrong.");
    }
    fclose(fPtr);
    printf("Your data has been saved in file!\n");
}