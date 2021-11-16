#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataMahasiswa
{
    char fakultas;
    int prodi;
    int ta;
    int nim;
    char name[100];
    struct dataMahasiswa *nextPtr;
};

typedef struct dataMahasiswa DataMahasiswa;
typedef DataMahasiswa *DataMahasiswaPtr;

DataMahasiswaPtr startPtr = NULL;

void insert(DataMahasiswaPtr *sPtr, char fakultas, int prodi, int ta, int nim, char *name), printList(DataMahasiswaPtr currentPtr), printAngkatan(DataMahasiswaPtr currentPtr), refreshStruct(), addRecord(), store(), updateRecord();
int isEmpty(DataMahasiswaPtr sPtr);
int delete (int nim), update(int nim);
unsigned int dataChoice(void);

int main(void)
{
    unsigned int choice;
    refreshStruct();

    while ((choice = dataChoice()) != 0)
    {
        choice = dataChoice();
        switch (choice)
        {
        case 1:
            printList(startPtr);
            break;
        case 2:
            addRecord();
            break;
        case 3:
            printAngkatan(startPtr);
        case 4:
            store();
            break;
        default:
            puts("Incorrect choice");
            break;
        }
    }
}

unsigned int dataChoice(void)
{
    printf("\n========================================================================================================================\n");
    printf("%s",
           "\n===> Tugas Praktikum 6: File Processing (Project-based) <==="
           "\n===> Data Mahasiswa <===\n\n"
           "\nMasukkan menu di bawah ini:\n"
           "[1] View Mahasiswa (Penerapan linked list)\n"
           "[2] Add Mahasiswa\n"
           "[3] List Angkatana\n"
           "[4] Store in File\n"
           "[0] Exit program.\n\n");

    unsigned int choice;
    printf("%s", ">>>> Masukkan Menu: ");
    scanf("%u", &choice);
    return choice;
}

void refreshStruct()
{
    char fakultas;
    int prodi;
    int ta;
    int nim;
    char name[100];

    FILE *cfPtr = fopen("mahasiswa.txt", "r");

    fscanf(cfPtr, "%c%d%d%d%29s%lf", &fakultas, &prodi, &ta, &nim, name);

    if (cfPtr != NULL)
    {
        while (!feof(cfPtr))
        {
            insert(&startPtr, fakultas, prodi, ta, nim, name);
            fscanf(cfPtr, "%c%d%d%d%29s%lf", &fakultas, &prodi, &ta, &nim, name);
        }
    }
    else
    {
        puts("File could not be opened.");
    }
}

void insert(DataMahasiswaPtr *sPtr, char fakultas, int prodi, int ta, int nim, char *name)
{
    DataMahasiswaPtr newPtr = malloc(sizeof(DataMahasiswa));

    if (newPtr != NULL)
    {
        newPtr->fakultas = fakultas;
        newPtr->prodi = prodi;
        newPtr->ta = ta;
        newPtr->nim = nim;

        strcpy(newPtr->name, name);
        newPtr->nextPtr = NULL;

        DataMahasiswaPtr previousPtr = NULL;
        DataMahasiswaPtr currentPtr = *sPtr;

        while (currentPtr != NULL && nim > currentPtr->nim)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("%d not inserted. No memory available.\n", nim);
    }
}

void store()
{
    DataMahasiswaPtr currentPtr = startPtr;
    DataMahasiswaPtr nextPtr = startPtr->nextPtr;

    FILE *fPtr = fopen("mahasiswa.txt", "w");
    if (fPtr != NULL)
    {
        fprintf(fPtr, "%c%d%d%d%-29s\n", currentPtr->fakultas, currentPtr->prodi, currentPtr->ta, currentPtr->nim, currentPtr->name);
        while (nextPtr != NULL)
        {
            currentPtr = nextPtr;
            nextPtr = currentPtr->nextPtr;
            fprintf(fPtr, "%c%d%d%d%-29s\n", currentPtr->fakultas, currentPtr->prodi, currentPtr->ta, currentPtr->nim, currentPtr->name);
        }
    }
    else
    {
        puts("Something went wrong.");
    }
    fclose(fPtr);
    printf("Your data has been saved in file!\n");
}

int isEmpty(DataMahasiswaPtr sPtr)
{
    return sPtr == NULL;
}

void addRecord()
{
    char fakultas;
    int prodi, ta, nim;
    char name[100];

    printf("%s", "Masukkan NIM sesuai dengan format (contoh : M0521046): \n");
    printf("%s", "2 digit kode prodi (contoh : 05): ");
    printf("%s", "Kode Fakultas : ");
    scanf("%c", &fakultas);
    scanf("%d", &prodi);
    printf("%s", "2 digit tahun angkatan (contoh : 21): ");
    scanf("%d", &ta);
    printf("%s", "Masukkan 3 digit NIM terakhir (contoh : 046): ");
    scanf("%d", &nim);
    printf("%s", "Masukkan nama: ");
    scanf("%99s", name);

    insert(&startPtr, fakultas, prodi, ta, nim, name);
}

void printList(DataMahasiswaPtr currentPtr)
{
    if (isEmpty(currentPtr))
    {
        puts("List is empty.\n");
    }
    else
    {
        printf("Daftar Mahasiswa: \n\n");
        printf("%-10s%-29s%-10s\n", "NIM", "Nama", "IPK");

        while (currentPtr != NULL)
        {
            printf("%c%d%d%d%-29s\n", currentPtr->fakultas, currentPtr->prodi, currentPtr->ta, currentPtr->nim, currentPtr->name);
            currentPtr = currentPtr->nextPtr;
        }
    }
}

void printAngkatan(DataMahasiswaPtr currentPtr)
{
    int ta;
    printf("%s", "Masukkan 2 digit tahun angkatan (contoh : 21): ");
    scanf("%d", &ta);
    if (isEmpty(currentPtr))
    {
        puts("List is empty.\n");
    }
    else
    {
        printf("Daftar Mahasiswa: \n\n");
        printf("%-10s%-29s%-10s\n", "NIM", "Nama", "IPK");

        while (currentPtr != NULL)
        {
            if (currentPtr->ta == ta)
            {
                printf("%c%d%d%d%-29s\n", currentPtr->fakultas, currentPtr->prodi, currentPtr->ta, currentPtr->nim, currentPtr->name);
            }
            currentPtr = currentPtr->nextPtr;
        }
    }
}