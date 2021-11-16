/*
NAMA        : MUH. NUR AFRIZAL
NIM         : M0521046
PRODI       : INFORMATIKA
MATA KULIAH : KONSEP PEMROGRAMAN
KELAS       : B
*/

/*
Tugas Kelas - Week 10
Tugas Kelas - Week 10
Tugas Kelas - Week 10
*/

#include <stdio.h>
#include <string.h>

struct dataMahasiswa
{
    unsigned int nim;
    char name[30];
    double ipk;
};

unsigned int dataChoice(void), byteChoice(void), seqChoice(void);
int rawByte(), seqData();
void listRecordDat(FILE *fPtr), addRecordDat(FILE *fPtr), updateRecordDat(FILE *fPtr), deleteRecordDat(FILE *fPtr), exportTxt(FILE *fPtr);
void listRecordTxt(FILE *fPtr), addRecordTxt(FILE *fPtr), deleteRecordTxt(FILE *fPtr), exportDat(FILE *fPtr);

int main(void)
{
    unsigned int menuChoice;

    while ((menuChoice = dataChoice()) != 0)
    {
        switch (menuChoice)
        {
        case 1:
            rawByte();
            break;
        case 2:
            seqData();
            break;
        default:
            puts("Pilihan salah");
            break;
        }
    }
}

unsigned int dataChoice(void)
{
    printf("%s", "\nMasukkan pilihan menggunakan data\n"
                 "1 - Menggunakan raw byte (diakses random) (.dat)\n"
                 "2 - Menggunakan sequential data (.txt)\n"
                 "0 - Keluar dari program.\n");

    unsigned int menuChoice;
    printf("%s", ">>>> Masukkan Menu: ");
    scanf("%u", &menuChoice);
    return menuChoice;
}

int rawByte()
{
    FILE *cfPtr;

    if ((cfPtr = fopen("mahasiswa.dat", "rb+")) == NULL)
    {
        if ((cfPtr = fopen("mahasiswa.dat", "wb")) == NULL)
        {
            puts("File could not be opened.");
        }
        else
        {
            struct dataMahasiswa blankClient = {0, "", 0.0};
            for (unsigned int i = 1; i <= 1000; ++i)
            {
                fwrite(&blankClient, sizeof(struct dataMahasiswa), 1, cfPtr);
            }
            rawByte();
        }
    }
    else
    {
        unsigned int choice;

        while ((choice = byteChoice()) != 0)
        {
            switch (choice)
            {
            case 1:
                listRecordDat(cfPtr);
                break;
            case 2:
                addRecordDat(cfPtr);
                break;
            case 3:
                updateRecordDat(cfPtr);
                break;
            case 4:
                deleteRecordDat(cfPtr);
                break;
            case 5:
                exportTxt(cfPtr);
                break;
            default:
                puts("Incorrect choice");
                break;
            }
        }
        fclose(cfPtr);
    }
}

unsigned int byteChoice(void)
{
    printf("%s", "\nMasukkan menu di bawah ini:\n"
                 "1 - List Mahasiswa\n"
                 "2 - Tambah Mahasiswa\n"
                 "3 - Update Mahasiswa\n"
                 "4 - Hapus Mahasiswa\n"
                 "5 - Pindahkan Ke Sequential Access File\n"
                 "0 - Keluar dari program.\n");

    unsigned int choice;
    printf("%s", ">>>> Masukkan Menu: ");
    scanf("%u", &choice);
    return choice;
}

int seqData()
{
    FILE *cfPtr;

    if ((cfPtr = fopen("mahasiswa.txt", "a+")) == NULL)
    {
        puts("File could not be opened.");
    }
    else
    {
        unsigned int choice;

        while ((choice = seqChoice()) != 0)
        {
            switch (choice)
            {
            case 1:
                listRecordTxt(cfPtr);
                break;
            case 2:
                addRecordTxt(cfPtr);
                break;
            case 3:
                deleteRecordTxt(cfPtr);
                break;
            case 4:
                exportDat(cfPtr);
                break;
            default:
                puts("Incorrect choice");
                break;
            }
        }
        fclose(cfPtr);
    }
}

unsigned int seqChoice(void)
{
    unsigned int choice;
    printf("%s", "\nMasukkan menu di bawah ini:\n"
                 "1 - List Mahasiswa\n"
                 "2 - Tambah Mahasiswa\n"
                 "3 - Hapus Mahasiswa\n"
                 "4 - Pindahkan Ke Raw Byte File\n"
                 "0 - Keluar dari program.\n");
    printf("%s", ">>>> Masukkan Menu: ");
    scanf("%u", &choice);
    return choice;
}

void listRecordDat(FILE *readPtr)
{
    printf("%-10s%-29s%10s\n",
           "NIM", "Nama", "IPK");

    rewind(readPtr);
    while (!feof(readPtr))
    {
        struct dataMahasiswa client = {0, "", 0.0};
        int result =
            fread(&client, sizeof(struct dataMahasiswa), 1, readPtr);

        if (result != 0 && client.nim != 0)
        {
            printf("%-10d%-29s%10.2f\n",
                   client.nim, client.name, client.ipk);
        }
    }
}

void addRecordDat(FILE *addPtr)
{
    printf("%s", "Masukkan NIM (1 - 100): ");
    unsigned int nim;
    scanf("%d", &nim);

    fseek(addPtr, (nim - 1) * sizeof(struct dataMahasiswa),
          SEEK_SET);

    struct dataMahasiswa client = {0, "", 0.0};

    fread(&client, sizeof(struct dataMahasiswa), 1, addPtr);
    if (client.nim != 0)
    {
        printf("Account #%d already contains information.\n",
               client.nim);
    }
    else
    {
        printf("%s", "Masukkan nama, ipk: \n? ");
        scanf("%29s%lf", &client.name, &client.ipk);

        client.nim = nim;

        fseek(addPtr, (client.nim - 1) * sizeof(struct dataMahasiswa), SEEK_SET);
        fwrite(&client,
               sizeof(struct dataMahasiswa), 1, addPtr);
    }
}

void updateRecordDat(FILE *updatePtr)
{
    printf("%s", "Masukkan NIM (1 - 100): ");
    unsigned int nim;
    scanf("%d", &nim);

    fseek(updatePtr, (nim - 1) * sizeof(struct dataMahasiswa),
          SEEK_SET);

    struct dataMahasiswa client = {0, "", 0.0};

    fread(&client, sizeof(struct dataMahasiswa), 1, updatePtr);

    if (client.nim == 0)
    {
        printf("Account #%d has no information.\n", nim);
    }
    else
    {
        printf("%-10d%-29s%10.2f\n\n",
               client.nim, client.name, client.ipk);

        printf("%s", "Masukkan nama, IPK yang baru: \n? ");
        scanf("%29s%lf", &client.name, &client.ipk);

        printf("%-10d%-29s%10.2f\n\n",
               client.nim, client.name, client.ipk);

        fseek(updatePtr, (nim - 1) * sizeof(struct dataMahasiswa),
              SEEK_SET);
        fwrite(&client, sizeof(struct dataMahasiswa), 1, updatePtr);
    }
}

void deleteRecordDat(FILE *deletePtr)
{
    printf("%s", "Masukkan NIM yang akan dihapus (1 - 100): ");
    unsigned int nim;
    scanf("%u", &nim);
    struct dataMahasiswa client;

    fseek(deletePtr, (nim - 1) * sizeof(struct dataMahasiswa),
          SEEK_SET);

    fread(&client, sizeof(struct dataMahasiswa), 1, deletePtr);

    if (client.nim != nim)
    {
        printf("NIM #%d tidak ditemukan.\n", nim);
    }
    else
    {
        fseek(deletePtr, (nim - 1) * sizeof(struct dataMahasiswa),
              SEEK_SET);

        struct dataMahasiswa blankClient;
        blankClient.nim = 0;
        strcpy(blankClient.name, "");
        blankClient.ipk = 0;

        fwrite(&blankClient,
               sizeof(struct dataMahasiswa), 1, deletePtr);

        printf("Akun dengan nim #%d telah dihapus\n", nim);
    }
}

void exportTxt(FILE *exportPtr)
{
    FILE *txtPtr;

    if ((txtPtr = fopen("mahasiswa.txt", "w")) == NULL)
    {
        puts("File could not be opened.");
    }
    else
    {
        rewind(exportPtr);

        while (!feof(exportPtr))
        {
            struct dataMahasiswa client = {0, "", 0.0};
            int result =
                fread(&client, sizeof(struct dataMahasiswa), 1, exportPtr);

            if (result != 0 && client.nim != 0)
            {
                fprintf(txtPtr, "%-10d%-29s%10.2f\n",
                        client.nim, client.name, client.ipk);
            }
        }
        puts("Konten telah diexport ke sequential file (.txt) dengan nama mahasiswa.txt (mengganti baru jika sebelumnya sudah ada).");
        fclose(txtPtr);
    }
}

void listRecordTxt(FILE *readPtr)
{
    struct dataMahasiswa client = {0, "", 0.0};
    printf("%-10s%-29s%-10s\n", "NIM", "Nama", "IPK");

    rewind(readPtr);

    fscanf(readPtr, "%d%29s%lf", &client.nim, client.name, &client.ipk);
    while (!feof(readPtr))
    {
        printf("%-10d%-29s%-10.2f\n", client.nim, client.name, client.ipk);
        fscanf(readPtr, "%d%29s%lf", &client.nim, client.name, &client.ipk);
    }
}

void addRecordTxt(FILE *addPtr)
{
    puts("Masukkan NIM, Nama, IPK (Masukkan EOF untuk berhenti) :");
    printf("%s", "? ");

    struct dataMahasiswa client = {0, "", 0.0};
    struct dataMahasiswa check = {0, "", 0.0};

    scanf("%d%29s%lf", &client.nim, client.name, &client.ipk);
    rewind(addPtr);

    fscanf(addPtr, "%d%29s%lf", &check.nim, check.name, &check.ipk);
    while (!feof(stdin))
    {
        int stop = 0;
        while (!feof(addPtr))
        {
            if (client.nim == check.nim)
            {
                printf("NIM #%d sudah digunakan!\n", client.nim);
                stop = 1;
                break;
            }
            fscanf(addPtr, "%d%29s%lf", &check.nim, check.name, &check.ipk);
        }
        printf("%s", "? ");
        if (stop == 0)
        {
            fprintf(addPtr, "%-10d%-29s%10.2f\n", client.nim, client.name, client.ipk);
        }
        scanf("%d%29s%lf", &client.nim, client.name, &client.ipk);
        rewind(addPtr);
        stop = 0;
    }
}

void deleteRecordTxt(FILE *deletePtr)
{
    printf("%s", "Masukkan NIM yang akan dihapus (1 - 100): ");
    unsigned int nim;
    scanf("%d", &nim);

    struct dataMahasiswa client = {0, "", 0.0};
    rewind(deletePtr);

    FILE *tempPtr;
    if ((tempPtr = fopen("temp.txt", "w")) == NULL)
    {
        puts("File could not be opened.");
    }
    else
    {
        fscanf(deletePtr, "%10d%29s%lf", &client.nim, client.name, &client.ipk);
        while (!feof(deletePtr))
        {
            if (client.nim != nim)
            {
                fprintf(tempPtr, "%-10d%-29s%10.2f\n", client.nim, client.name, client.ipk);
            }
            fscanf(deletePtr, "%d%29s%lf", &client.nim, client.name, &client.ipk);
        }

        fclose(deletePtr);
        fclose(tempPtr);

        remove("mahasiswa.txt");
        rename("temp.txt", "mahasiswa.txt");

        printf("NIM #%d telah dihapus.\n", nim);
        deletePtr = fopen("mahasiswa.txt", "r+");
    }
}

void exportDat(FILE *exportPtr)
{
    FILE *datPtr;

    struct dataMahasiswa client = {0, "", 0.0};

    if ((datPtr = fopen("mahasiswa.dat", "wb")) == NULL)
    {
        puts("File could not be opened.");
    }
    else
    {
        rewind(exportPtr);

        while (!feof(exportPtr))
        {
            fscanf(exportPtr, "%d%29s%lf", &client.nim, client.name, &client.ipk);
            fseek(datPtr, (client.nim - 1) * sizeof(struct dataMahasiswa), SEEK_SET);
            fwrite(&client, sizeof(struct dataMahasiswa), 1, datPtr);
        }
        puts("Konten telah diexport ke raw byte file (.dat) dengan nama mahasiswa.dat");
    }
    fclose(datPtr);
}