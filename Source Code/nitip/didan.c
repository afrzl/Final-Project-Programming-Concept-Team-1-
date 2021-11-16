/*
Tugas Kelas - Week 10
Nama          : Muhammad Nur Hikmah Ramadhan
NIM           : M0521054
Kelas         : B
Mata Kuliah   : Konsep Pemrograman
Program Studi : Informatika
Fakultas      : Fakultas Matematika dan Ilmu Pengetahuan Alam

Universitas Sebeleas Maret


File Processing
*/

#include <stdio.h>
#include <string.h>

struct formMahasiswa
{
    unsigned int nim;
    char nama[30];
    double ipkMahasiswa;
};

unsigned int opsiData(void), opsiByte(void), opsiSequent(void);
int rawByte(), sequentData();
void tambahDat(FILE *fPtr), hapusDat(FILE *fPtr), perbaruiDat(FILE *fPtr), daftarDat(FILE *fPtr), convertTOtxt(FILE *fPtr);
void tambahTxt(FILE *fPtr), hapusTxt(FILE *fPtr), daftarTxt(FILE *fPtr), convertTOdat(FILE *fPtr);

int main(void)
{
    unsigned int opsiFile;
    while ((opsiFile = opsiData()) != 0)
    {
        switch (opsiFile)
        {
        case 1:
            rawByte();
            break;
        case 2:
            sequentData();
            break;
        default:
            puts("Anda tidak memasukkan opsi yang benar.");
            break;
        }
    }
}

unsigned int opsiData(void)
{
    unsigned int opsiFile;

    printf("%s", "\nSilahkan pilih opsi file yang ingin Anda gunakan\n"
                 "1 Raw Byte (.dat)\n"
                 "2 Sequential Data (.txt)\n"
                 "0 Keluar\n"
                 "---> Masukkan opsi yang Anda pilih :");
    scanf("%u", &opsiFile);
    return opsiFile;
}

int rawByte()
{
    FILE *cfPtr;

    if ((cfPtr = fopen("Mahasiswa.dat", "rb+")) == NULL)
    {
        if ((cfPtr = fopen("Mahasiswa.dat", "wb")) == NULL)
        {
            puts("File Anda tidak terdapat pada file direktori.");
        }
        else
        {
            struct formMahasiswa blankClient = {0, "", 0.0};
            for (unsigned int i = 1; i <= 1000; ++i)
            {
                fwrite(&blankClient, sizeof(struct formMahasiswa), 1, cfPtr);
            }
            rawByte();
        }
    }
    else
    {
        unsigned int opsi;

        while ((opsi = opsiByte()) != 0)
        {
            switch (opsi)
            {
            case 1:
                tambahDat(cfPtr);
                break;
            case 2:
                hapusDat(cfPtr);
                break;
            case 3:
                perbaruiDat(cfPtr);
                break;
            case 4:
                daftarDat(cfPtr);
                break;
            case 5:
                convertTOtxt(cfPtr);
                break;
            default:
                puts("Anda tidak memasukkan opsi yang benar.");
                break;
            }
        }
        fclose(cfPtr);
    }
}

unsigned int opsiByte(void)
{
    unsigned int opsi;
    printf("%s", "\nSilahkan pilih opsi fitur yang ingin Anda gunakan\n"
                 "1 Tambah Data Mahasiswa\n"
                 "2 Hapus Data Mahasiswa\n"
                 "3 Perbarui Data Mahasiswa\n"
                 "4 Lihat Data Mahasiswa\n"
                 "5 Convert .dat ke .txt\n"
                 "0 Keluar\n"
                 "---> Masukkan opsi yang Anda pilih :");
    scanf("%u", &opsi);
    return opsi;
}

int sequentData()
{
    FILE *cfPtr;

    if ((cfPtr = fopen("Mahasiswa.txt", "a+")) == NULL)
    {
        puts("File Anda tidak terdapat pada file direktori.");
    }
    else
    {
        unsigned int opsi;

        while ((opsi = opsiSequent()) != 0)
        {
            switch (opsi)
            {
            case 1:
                tambahTxt(cfPtr);
                break;
            case 2:
                hapusTxt(cfPtr);
                break;
            case 3:
                daftarTxt(cfPtr);
                break;
            case 4:
                convertTOdat(cfPtr);
                break;
            default:
                puts("Anda tidak memasukkan opsi yang benar.");
                break;
            }
        }
        fclose(cfPtr);
    }
}

unsigned int opsiSequent(void)
{
    unsigned int opsi;
    printf("%s", "\nSilahkan pilih opsi fitur yang ingin Anda gunakan\n"
                 "1 Tambah Data Mahasiswa\n"
                 "2 Hapus Data Mahasiswa\n"
                 "3 Lihat Data Mahasiswa\n"
                 "4 Convert .txt ke .dat\n"
                 "0 Keluar\n"
                 "--> Masukkan opsi yang Anda pilih :");
    scanf("%u", &opsi);
    return opsi;
}

void tambahDat(FILE *addPtr)
{
    printf("%s", "Masukkan NIM dengan ketentuan <1-100> :");
    unsigned int nim;
    scanf("%d", &nim);

    fseek(addPtr, (nim - 1) * sizeof(struct formMahasiswa), SEEK_SET);
    struct formMahasiswa client = {0, "", 0.0};

    fread(&client, sizeof(struct formMahasiswa), 1, addPtr);
    if (client.nim != 0)
    {
        printf("Data #%d telah terdapat pada file.\n", client.nim);
    }
    else
    {
        printf("%s", "Masukkan nama, ipk : \n? ");
        scanf("%29s %lf", &client.nama, &client.ipkMahasiswa);

        client.nim = nim;

        fseek(addPtr, (client.nim - 1) * sizeof(struct formMahasiswa), SEEK_SET);
        fwrite(&client, sizeof(struct formMahasiswa), 1, addPtr);
    }
}

void hapusDat(FILE *deletePtr)
{
    printf("%s", "Masukkan NIM yang akan Anda hapus dengan ketentuan <1 - 100> :");
    unsigned int nim;
    scanf("%u", &nim);
    struct formMahasiswa client;

    fseek(deletePtr, (nim - 1) * sizeof(struct formMahasiswa), SEEK_SET);

    fread(&client, sizeof(struct formMahasiswa), 1, deletePtr);

    if (client.nim != nim)
    {
        printf("Data #%d tidak terdapat pada file.\n", nim);
    }
    else
    {
        fseek(deletePtr, (nim - 1) * sizeof(struct formMahasiswa), SEEK_SET);

        struct formMahasiswa blankClient;
        blankClient.nim = 0;
        strcpy(blankClient.nama, "");
        blankClient.ipkMahasiswa = 0;

        fwrite(&blankClient,
               sizeof(struct formMahasiswa), 1, deletePtr);

        printf("Data dengan nim #%d telah dihapus\n", nim);
    }
}

void perbaruiDat(FILE *updatePtr)
{
    printf("%s", "Masukkan NIM dengan ketentuan <1-100> :");
    unsigned int nim;
    scanf("%d", &nim);

    fseek(updatePtr, (nim - 1) * sizeof(struct formMahasiswa), SEEK_SET);

    struct formMahasiswa client = {0, "", 0.0};

    fread(&client, sizeof(struct formMahasiswa), 1, updatePtr);

    if (client.nim == 0)
    {
        printf("Data #%d tidak terdapat pada file.\n", nim);
    }
    else
    {
        printf("%-10d%-29s%10.2f\n\n", client.nim, client.nama, client.ipkMahasiswa);
        printf("%s", "Masukkan nama, IPK yang merupakan perbaikan : \n? ");
        scanf("%29s %lf", &client.nama, &client.ipkMahasiswa);
        printf("%-10d%-29s%10.2f\n\n", client.nim, client.nama, client.ipkMahasiswa);

        fseek(updatePtr, (nim - 1) * sizeof(struct formMahasiswa), SEEK_SET);
        fwrite(&client, sizeof(struct formMahasiswa), 1, updatePtr);
    }
}

void daftarDat(FILE *readPtr)
{
    printf("%-10s%-29s%10s\n", "NIM", "Nama", "IPK");

    rewind(readPtr);
    while (!feof(readPtr))
    {
        struct formMahasiswa client = {0, "", 0.0};
        int result = fread(&client, sizeof(struct formMahasiswa), 1, readPtr);

        if (result != 0 && client.nim != 0)
        {
            printf("%-10d%-29s%10.2f\n", client.nim, client.nama, client.ipkMahasiswa);
        }
    }
}

void convertTOtxt(FILE *convertPtr)
{
    FILE *txtPtr;

    if ((txtPtr = fopen("Mahasiswa.txt", "w")) == NULL)
    {
        puts("File Anda tidak terdapat pada file direktori.");
    }
    else
    {
        rewind(convertPtr);

        while (!feof(convertPtr))
        {
            struct formMahasiswa client = {0, "", 0.0};
            int result = fread(&client, sizeof(struct formMahasiswa), 1, convertPtr);

            if (result != 0 && client.nim != 0)
            {
                fprintf(txtPtr, "%-10d%-29s%10.2f\n", client.nim, client.nama, client.ipkMahasiswa);
            }
        }
        puts("Konten telah diconvert ke dalam bentuk sequential file (.txt) dengan nama Mahasiswa.txt !!!replace pada file yang sudah ada!!!.");
        fclose(txtPtr);
    }
}

void tambahTxt(FILE *addPtr)
{
    puts("Masukkan NIM Nama IPK, !!!Masukkan EOF untuk menyudahi!!! :");
    printf("%s", "? ");

    struct formMahasiswa client = {0, "", 0.0};
    struct formMahasiswa check = {0, "", 0.0};

    scanf("%d%29s%lf", &client.nim, client.nama, &client.ipkMahasiswa);
    rewind(addPtr);

    fscanf(addPtr, "%d%29s%lf", &check.nim, check.nama, &check.ipkMahasiswa);
    while (!feof(stdin))
    {
        int stop = 0;
        while (!feof(addPtr))
        {
            if (client.nim == check.nim)
            {
                printf("Data #%d telah terdapat pada file.\n", client.nim);
                stop = 1;
                break;
            }
            fscanf(addPtr, "%d%29s%lf", &check.nim, check.nama, &check.ipkMahasiswa);
        }
        printf("%s", "? ");
        if (stop == 0)
        {
            fprintf(addPtr, "%-10d%-29s%10.2f\n", client.nim, client.nama, client.ipkMahasiswa);
        }
        scanf("%d%29s%lf", &client.nim, client.nama, &client.ipkMahasiswa);
        rewind(addPtr);
        stop = 0;
    }
}

void hapusTxt(FILE *deletePtr)
{
    printf("%s", "Masukkan NIM yang akan Anda hapus dengan ketentuan <1 - 100> :");
    unsigned int nim;
    scanf("%d", &nim);

    struct formMahasiswa client = {0, "", 0.0};
    rewind(deletePtr);

    FILE *sementaraPtr;
    if ((sementaraPtr = fopen("sementara.txt", "w")) == NULL)
    {
        puts("File Anda tidak terdapat pada file direktori.");
    }
    else
    {
        fscanf(deletePtr, "%10d%29s%lf", &client.nim, client.nama, &client.ipkMahasiswa);
        while (!feof(deletePtr))
        {
            if (client.nim != nim)
            {
                fprintf(sementaraPtr, "%-10d%-29s%10.2f\n", client.nim, client.nama, client.ipkMahasiswa);
            }
            fscanf(deletePtr, "%d%29s%lf", &client.nim, client.nama, &client.ipkMahasiswa);
        }

        fclose(deletePtr);
        fclose(sementaraPtr);

        remove("Mahasiswa.txt");
        rename("sementara.txt", "Mahasiswa.txt");

        printf("Data dengan nim #%d telah dihapus\n", nim);
        deletePtr = fopen("Mahasiswa.txt", "r+");
    }
}

void daftarTxt(FILE *readPtr)
{
    struct formMahasiswa client = {0, "", 0.0};
    printf("%-10s%-29s%-10s\n", "NIM", "Nama", "IPK");

    rewind(readPtr);

    fscanf(readPtr, "%d%29s%lf", &client.nim, client.nama, &client.ipkMahasiswa);
    while (!feof(readPtr))
    {
        printf("%-10d%-29s%-10.2f\n", client.nim, client.nama, client.ipkMahasiswa);
        fscanf(readPtr, "%d%29s%lf", &client.nim, client.nama, &client.ipkMahasiswa);
    }
}

void convertTOdat(FILE *convertPtr)
{
    FILE *datPtr;

    struct formMahasiswa client = {0, "", 0.0};

    if ((datPtr = fopen("Mahasiswa.dat", "wb")) == NULL)
    {
        puts("File Anda tidak terdapat pada file direktori.");
    }
    else
    {
        rewind(convertPtr);

        while (!feof(convertPtr))
        {
            fscanf(convertPtr, "%d%29s%lf", &client.nim, client.nama, &client.ipkMahasiswa);
            fseek(datPtr, (client.nim - 1) * sizeof(struct formMahasiswa), SEEK_SET);
            fwrite(&client, sizeof(struct formMahasiswa), 1, datPtr);
        }
        puts("Konten telah diconvert ke dalam bentuk raw byte file (.dat) dengan nama Mahasiswa.dat");
    }
    fclose(datPtr);
}
