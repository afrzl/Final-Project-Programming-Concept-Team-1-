#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataPasien
{
    unsigned int no_antrian;
    char name[100];
    struct dataPasien *nextPtr;
};

typedef struct dataPasien DataPasien;
typedef DataPasien *DataPasienPtr;

DataPasienPtr headPtr = NULL;
DataPasienPtr tailPtr = NULL;

int count_antrian = 0;

void printQueue(DataPasienPtr currentPtr), addRecordPasien(), enqueue(DataPasienPtr *headPtr, DataPasienPtr *tailPtr, char *name), dequeue(DataPasienPtr *headPtr, DataPasienPtr *tailPtr);
int isEmptyPasien(DataPasienPtr headPtr);
unsigned int dataChoicePasien(void);

int wait()
{
    char c;
    printf("\n>>>>> Tekan enter untuk kembali ke menu sebelumnya!");
    scanf("%c", &c);
}

int main(void)
{
    char name[100];
    char c;
    unsigned int choice;

    while ((choice = dataChoicePasien()) != 0)
    {
        switch (choice)
        {
        case 1:
            printQueue(headPtr);
            scanf("%c", &c);
            wait();
            break;
        case 2:
            addRecordPasien();
            break;
        case 3:
            if (!isEmptyPasien(headPtr))
            {
                dequeue(&headPtr, &tailPtr);
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

unsigned int dataChoicePasien(void)
{
    printf("\n========================================================================================================================\n");
    printf("%s",
           "\n===> Aplikasi Antrian Pasien <===\n\n"
           "\nMasukkan menu di bawah ini:\n"
           "[1] Print antrian pasien\n"
           "[2] Tambah pasien\n"
           "[3] Panggil pasien\n"
           "[0] Kembali ke menu.\n\n");

    unsigned int choice;
    printf("%s", ">>>> Masukkan Menu: ");
    scanf("%u", &choice);
    return choice;
}

void addRecordPasien()
{
    char name[100];

    printf("%s", "Masukkan Nama Pasien: ");
    scanf("%99s", name);
    count_antrian++;

    enqueue(&headPtr, &tailPtr, name);
}

void enqueue(DataPasienPtr *headPtr, DataPasienPtr *tailPtr, char *name)
{
    DataPasienPtr newPtr = malloc(sizeof(DataPasien));
    if (newPtr != NULL)
    {
        newPtr->no_antrian = count_antrian;
        strcpy(newPtr->name, name);
        newPtr->nextPtr = NULL;

        if (isEmptyPasien(*headPtr))
        {
            *headPtr = newPtr;
        }
        else
        {
            (*tailPtr)->nextPtr = newPtr;
        }
        *tailPtr = newPtr;
    }
    else
    {
        printf("%s not inserted. No memory available.\n", name);
    }
}

void dequeue(DataPasienPtr *headPtr, DataPasienPtr *tailPtr)
{
    char name[100];
    strcpy(name, (*headPtr)->name);
    DataPasienPtr tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if (*headPtr == NULL)
    {
        *tailPtr = NULL;
    }

    printf("Antrian selanjutnya dengan nomor %d atas nama %s\n", tempPtr->no_antrian, tempPtr->name);
    free(tempPtr);
}

int isEmptyPasien(DataPasienPtr headPtr)
{
    return headPtr == NULL;
}

void printQueue(DataPasienPtr currentPtr)
{
    if (currentPtr == NULL)
    {
        puts("Tidak ada antrian.\n");
    }
    else
    {
        puts("Antrian pasien :");

        while (currentPtr != NULL)
        {
            printf("%d. %s \n", currentPtr->no_antrian, currentPtr->name);
            currentPtr = currentPtr->nextPtr;
        }
    }
}