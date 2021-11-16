#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataMahasiswa
{
    unsigned int nim;
    char name[100];
    double ipk;
    struct dataMahasiswa *nextPtr;
};

struct dataParkir
{
    unsigned int nopol;
    char name[100];
    struct dataParkir *nextPtr;
};

typedef struct dataMahasiswa DataMahasiswa;
typedef DataMahasiswa *DataMahasiswaPtr;

typedef struct dataParkir DataParkir;
typedef DataParkir *DataParkirPtr;

DataMahasiswaPtr startPtrMahasiswa = NULL;
DataParkirPtr startPtrParkir = NULL;

void insertMahasiswa(DataMahasiswaPtr *sPtr, unsigned int nim, char *name, double ipk), printListMahasiswa(DataMahasiswaPtr currentPtr), refreshStructMahasiswa(), addRecordMahasiswa(), store(), updateRecordMahasiswa();
int choiceMahasiswa(void), isEmptyMahasiswa(DataMahasiswaPtr sPtr), deleteMahasiswa(int nim), updateMahasiswa(int nim);
unsigned int dataChoiceMahasiswa(void), dataChoice(void);

void push(DataParkirPtr *topPtr, unsigned int nopol, char *name), printStack(DataParkirPtr currentPtr), addRecord();
int choiceParkir(void), pop(DataParkirPtr *topPtr), isEmpty(DataParkirPtr topPtr);
unsigned int dataChoiceParkir(void);

int wait()
{
    char c;
    printf("\nTekan enter untuk kembali ke menu sebelumnya!");
    scanf("%c", &c);
}

int main(void)
{
    char c;
    unsigned int choice;

    while ((choice = dataChoice()) != 0)
    {
        switch (choice)
        {
        case 1:
            choiceMahasiswa();
            break;
        case 2:
            choiceParkir();
            break;
        // case 3:
        //     updateRecordMahasiswa(1);
        //     break;
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
           "[1] Penerapan linked list dan BST\n"
           "[2] Penerapan stack\n"
           "[3] Penerapan queue\n"
           "[0] Exit program.\n\n");

    unsigned int choice;
    printf("%s", ">>>> Masukkan Menu: ");
    scanf("%u", &choice);
    return choice;
}

/*
===================================================================================================================================================
CODE UNTUK PENERAPAN LINKED LIST DAN BST
===================================================================================================================================================
*/

int choiceMahasiswa(void)
{
    char c;
    unsigned int choice;
    refreshStructMahasiswa();

    while ((choice = dataChoiceMahasiswa()) != 0)
    {
        switch (choice)
        {
        case 1:
            printListMahasiswa(startPtrMahasiswa);
            scanf("%c", &c);
            wait();
            break;
        case 2:
            addRecordMahasiswa();
            scanf("%c", &c);
            wait();
            break;
        case 3:
            updateRecordMahasiswa(1);
            scanf("%c", &c);
            wait();
            break;
        case 4:
            updateRecordMahasiswa(2);
            scanf("%c", &c);
            wait();
            break;
        case 5:
            store();
            scanf("%c", &c);
            wait();
            break;
        default:
            puts("Incorrect choice");
            break;
        }
    }
}

unsigned int dataChoiceMahasiswa(void)
{
    printf("\n========================================================================================================================\n");
    printf("%s",
           "\n===> Penerapan Linked List dan BST <===\n\n"
           "\nMasukkan menu di bawah ini:\n"
           "[1] View Mahasiswa\n"
           "[2] Add Mahasiswa\n"
           "[3] Update Mahasiswa\n"
           "[4] Delete Mahasiswa\n"
           "[5] Store in File\n"
           "[0] Exit program.\n\n");

    unsigned int choice;
    printf("%s", ">>>> Masukkan Menu: ");
    scanf("%u", &choice);
    return choice;
}

void refreshStructMahasiswa()
{
    unsigned int nim;
    char name[100];
    double ipk;

    FILE *cfPtr = fopen("mahasiswa.txt", "r");

    fscanf(cfPtr, "%d%29s%lf", &nim, name, &ipk);

    if (cfPtr != NULL)
    {
        while (!feof(cfPtr))
        {
            insertMahasiswa(&startPtrMahasiswa, nim, name, ipk);
            fscanf(cfPtr, "%d%29s%lf", &nim, name, &ipk);
        }
    }
    else
    {
        puts("File could not be opened.");
    }
}

void updateRecordMahasiswa(int menu)
{
    unsigned int nim;
    if (!isEmptyMahasiswa(startPtrMahasiswa))
    {
        printf("%s", "Masukkan NIM yang akan ");
        if (menu == 1)
        {
            printf("diubah :");
        }
        else
        {
            printf("dihapus :");
        }

        scanf("%d", &nim);
        if (menu == 1)
        {
            if (updateMahasiswa(nim))
            {
                printf("%d deleted.\n", nim);
            }
            else
            {
                printf("%d not found.\n\n", nim);
            }
        }
        else
        {
            if (deleteMahasiswa(nim))
            {
                printf("%d deleted.\n", nim);
            }
            else
            {
                printf("%d not found.\n\n", nim);
            }
        }
    }
    else
    {
        puts("List is empty.\n");
    }
}

int deleteMahasiswa(int nim)
{
    if (nim == startPtrMahasiswa->nim)
    {
        DataMahasiswaPtr tempPtr = startPtrMahasiswa;
        startPtrMahasiswa = startPtrMahasiswa->nextPtr;
        free(tempPtr);
        return nim;
    }
    else
    {
        DataMahasiswaPtr previousPtr = startPtrMahasiswa;
        DataMahasiswaPtr currentPtr = startPtrMahasiswa->nextPtr;

        while (currentPtr != NULL && currentPtr->nim != nim)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (currentPtr != NULL)
        {
            DataMahasiswaPtr tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return nim;
        }
    }
    return 0;
}

int updateMahasiswa(int nim)
{
    if (nim == startPtrMahasiswa->nim)
    {
        DataMahasiswaPtr currentPtr = startPtrMahasiswa;
        printf("%s", "Masukkan nama: ");
        scanf("%99s", &currentPtr->name);
        printf("%s", "Masukkan ipk: ");
        scanf("%lf", &currentPtr->ipk);

        return nim;
    }
    else
    {
        DataMahasiswaPtr previousPtr = startPtrMahasiswa;
        DataMahasiswaPtr currentPtr = startPtrMahasiswa->nextPtr;

        while (currentPtr != NULL && currentPtr->nim != nim)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (currentPtr != NULL)
        {
            DataMahasiswaPtr tempPtr = currentPtr;
            printf("%s", "Masukkan nama: ");
            scanf("%99s", &currentPtr->name);
            printf("%s", "Masukkan ipk: ");
            scanf("%lf", &currentPtr->ipk);
            return nim;
        }
    }
    return 0;
}

void insertMahasiswa(DataMahasiswaPtr *sPtr, unsigned int nim, char *name, double ipk)
{
    DataMahasiswaPtr newPtr = malloc(sizeof(DataMahasiswa)); // create node

    if (newPtr != NULL)
    {
        newPtr->nim = nim;
        strcpy(newPtr->name, name);
        newPtr->ipk = ipk;
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
    DataMahasiswaPtr currentPtr = startPtrMahasiswa;
    DataMahasiswaPtr nextPtr = startPtrMahasiswa->nextPtr;

    FILE *fPtr = fopen("mahasiswa.txt", "w");
    if (fPtr != NULL)
    {
        fprintf(fPtr, "%-10d%-29s%10.2f\n", currentPtr->nim, currentPtr->name, currentPtr->ipk);
        while (nextPtr != NULL)
        {
            currentPtr = nextPtr;
            nextPtr = currentPtr->nextPtr;
            fprintf(fPtr, "%-10d%-29s%10.2f\n", currentPtr->nim, currentPtr->name, currentPtr->ipk);
        }
    }
    else
    {
        puts("Something went wrong.");
    }
    fclose(fPtr);
    printf("Your data has been saved in file!\n");
}

int isEmptyMahasiswa(DataMahasiswaPtr sPtr)
{
    return sPtr == NULL;
}

void addRecordMahasiswa()
{
    unsigned int nim;
    char name[100];
    double ipk;

    printf("%s", "Masukkan NIM (1 - 100): ");
    scanf("%d", &nim);
    printf("%s", "Masukkan nama: ");
    scanf("%99s", &name);
    printf("%s", "Masukkan ipk: ");
    scanf("%lf", &ipk);

    insertMahasiswa(&startPtrMahasiswa, nim, name, ipk);
}

void printListMahasiswa(DataMahasiswaPtr currentPtr)
{
    if (isEmptyMahasiswa(currentPtr))
    {
        puts("List is empty.\n");
    }
    else
    {
        printf("Daftar Mahasiswa: \n\n");
        printf("%-10s%-29s%-10s\n", "NIM", "Nama", "IPK");

        while (currentPtr != NULL)
        {
            printf("%-10d%-29s%-10.2f\n", currentPtr->nim, currentPtr->name, currentPtr->ipk);
            currentPtr = currentPtr->nextPtr;
        }
    }
}

/*
===================================================================================================================================================
CODE UNTUK PENERAPAN STACK
===================================================================================================================================================
*/

int choiceParkir(void)
{
    char c;
    unsigned int choice;

    while ((choice = dataChoiceParkir()) != 0)
    {
        switch (choice)
        {
        case 1:
            printStack(startPtrParkir);
            scanf("%c", &c);
            wait();
            break;
        case 2:
            addRecord();
            break;
        case 3:
            if (!isEmpty(startPtrParkir))
            {
                printf("Kendaraan dengan nomor polisi %d telah dikeluarkan.\n", pop(&startPtrParkir));
            }
            scanf("%c", &c);
            wait();
            break;
        default:
            puts("Incorrect choice");
            break;
        }
    }
}

unsigned int dataChoiceParkir(void)
{
    printf("\n========================================================================================================================\n");
    printf("%s",
           "\n===> Aplikasi Parkir Satu Baris <===\n\n"
           "\nMasukkan menu di bawah ini:\n"
           "[1] Print kendaraan di tempat parkir\n"
           "[2] Tambah kendaraan\n"
           "[3] Keluarkan kendaraan\n"
           "[0] Kembali ke menu.\n\n");

    unsigned int choice;
    printf("%s", ">>>> Masukkan Menu: ");
    scanf("%u", &choice);
    return choice;
}

void push(DataParkirPtr *topPtr, unsigned int nopol, char *name)
{
    DataParkirPtr newPtr = malloc(sizeof(DataParkir));

    if (newPtr != NULL)
    {
        newPtr->nopol = nopol;
        strcpy(newPtr->name, name);
        newPtr->nextPtr = *topPtr;
        *topPtr = newPtr;
    }
    else
    {
        printf("%d not inserted. No memory available.\n", nopol);
    }
}

int pop(DataParkirPtr *topPtr)
{
    DataParkirPtr tempPtr = *topPtr;
    int popValue = (*topPtr)->nopol;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

void printStack(DataParkirPtr currentPtr)
{
    if (currentPtr == NULL)
    {
        puts("Tidak ada kendaraan di tempat parkir.\n");
    }
    else
    {
        puts("Data kendaraan yang terparkir:");

        while (currentPtr != NULL)
        {
            printf("| %s (%d) |", currentPtr->name, currentPtr->nopol);
            currentPtr = currentPtr->nextPtr;
        }
        printf("\n\n");
    }
}

int isEmpty(DataParkirPtr topPtr)
{
    return topPtr == NULL;
}

void addRecord()
{
    unsigned int nopol;
    char name[100];

    printf("%s", "Masukkan Nomor Polisi Kendaraan: ");
    scanf("%d", &nopol);
    printf("%s", "Masukkan Nama Kendaraan: ");
    scanf("%99s", name);

    push(&startPtrParkir, nopol, name);
}