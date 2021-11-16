#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataParkir
{
    unsigned int nopol;
    char name[100];
    struct dataParkir *nextPtr;
};

typedef struct dataParkir DataParkir;
typedef DataParkir *DataParkirPtr;

DataParkirPtr startPtrParkir = NULL;

void push(DataParkirPtr *topPtr, unsigned int nopol, char *name), printStack(DataParkirPtr currentPtr), addRecord();
int pop(DataParkirPtr *topPtr), isEmpty(DataParkirPtr topPtr);

unsigned int dataChoiceParkir(void);

int wait()
{
    char c;
    printf("\n>>>>> Tekan enter untuk kembali ke menu sebelumnya!");
    scanf("%c", &c);
}

int main(void)
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
            scanf("%c", &c);
            wait();
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
    // if stack is empty
    if (currentPtr == NULL)
    {
        puts("Tidak ada kendaraan di tempat parkir.\n");
    }
    else
    {
        puts("Data kendaraan yang terparkir:");

        // while not the end of the stack
        while (currentPtr != NULL)
        {
            printf("%s (%d)\n", currentPtr->name, currentPtr->nopol);
            currentPtr = currentPtr->nextPtr;
        }
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