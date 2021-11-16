// Nama            : Putri Rizqi Khairunnisa
// NIM             : M0521062
// Kelas           : C
// Program Studi   : Informatika

//Tugas Kelas - Week 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa
{
    char nama[100];
    int NIM;
    double IPK;
} mahasiswa;

int printMenu()
{
    unsigned int inputUser;
    printf("|1|\t Random Access File\n");
    printf("|2|\t Sequential Access File\n");
    printf("|3|\t Keluar\n\n");
    printf("Silakan masukkan angka pilihan Anda: ");
    scanf("%u", &inputUser);

    return inputUser;
}

unsigned int menuRand()
{
    unsigned int inputUser;
    printf("|1|\t Tambah Data\n");
    printf("|2|\t Update Data\n");
    printf("|3|\t Lihat Data\n");
    printf("|4|\t Hapus Data\n");
    printf("|5|\t Pindah Data ke Sequential Access File\n");
    printf("Silakan masukkan angka pilihan Anda: ");
    scanf("%u", &inputUser);

    return inputUser;
}

unsigned int menuSeq()
{
    unsigned int inputUser;

    printf("|1|\t Tambah Data\n");
    printf("|2|\t Lihat Data\n");
    printf("|3|\t Hapus Data\n");
    printf("|4|\t Pindah Data ke Random Access File\n");
    printf("Silakan masukkan angka pilihan Anda: ");
    scanf("%u", &inputUser);

    return inputUser;
}

//randomn access file
void tambahDataRand();
void updateDataRand();
void lihatDataRand();
void hapusDataRand();
void pindahDataRand();

//sequential access file
void tambahDataSeq();
void lihatDataSeq();
void hapusDataSeq();
void pindahDataSeq();

int main()
{
    unsigned int inputMenu;
    do
    {
        unsigned int inputRand, inputSeq;
        inputMenu = printMenu();
        switch (inputMenu)
        {
        case 1:
            inputRand = menuRand();
            switch (inputRand)
            {
            case 1:
                tambahDataRand();
                break;
            case 2:
                updateDataRand();
                break;
            case 3:
                lihatDataRand();
                break;
            case 4:
                hapusDataRand();
                break;
            case 5:
                pindahDataRand();
                break;
            default:
                printf("Angka yang Anda masukkan salah!\n");
                printf("Silakan masukkan angka 1-5\n\n");
                break;
            }
            break;
        case 2:
            inputSeq = menuSeq();
            switch (inputSeq)
            {
            case 1:
                tambahDataSeq();
                break;
            case 2:
                lihatDataSeq();
                break;
            case 3:
                hapusDataSeq();
                break;
            case 4:
                pindahDataSeq();
                break;
            default:
                printf("Angka yang Anda masukkan salah!\n");
                printf("Silakan masukkan angka 1-4\n\n");
                break;
            }
            break;
        }
        if (inputMenu < 0 || inputMenu > 3)
        {
            printf("Angka yang Anda masukkan salah!\n");
            printf("Silakan masukkan angka 1-2.\n\n");
        }
    } while (inputMenu != 3);
    return 0;
}

void tambahDataRand()
{
    FILE *fPtr = fopen("mahasiswa.dat", "rb");

    if (fPtr == NULL)
    {
        fPtr = fopen("mahasiswa.dat", "wb");
        if (fPtr != NULL)
        {
            struct Mahasiswa blank = {"", 0, 0};
            for (int a = 0; a < 101; a++)
            {
                fwrite(&blank, sizeof(struct Mahasiswa), 1, fPtr);
            }
            int jmlInput;
            printf("Masukkan jumlah data yang akan ditambah: ");
            scanf("%d", &jmlInput);
            for (int i = 0; i < jmlInput; i++)
            {
                printf("Data ke-%d\n", i + 1);
                printf("Masukkan nama mahasiswa: ");
                scanf("%s", mahasiswa.nama);
                printf("Masukkan NIM mahasiswa (1-100): ");
                scanf("%d", &mahasiswa.NIM);
                printf("Masukkan IPK mahasiswa: ");
                scanf("%lf", &mahasiswa.IPK);
                if (mahasiswa.NIM > 100)
                {
                    printf("NIM yang Anda masukkan salah! Data tidak dapat ditambahkan.\n\n");
                    main();
                }

                fseek(fPtr, (mahasiswa.NIM - 1) * sizeof(struct Mahasiswa), SEEK_SET);
                fwrite(&mahasiswa, sizeof(struct Mahasiswa), 1, fPtr);
            }
            printf("Data berhasil ditambahkan!\n\n");
            fclose(fPtr);
        }
        else
        {
            printf("File tidak dapat dibuka.\n\n");
        }
    }
    else
    {
        fPtr = fopen("mahasiswa.dat", "rb+");
        if (fPtr != NULL)
        {
            int jmlInput;
            printf("Masukkan jumlah data yang akan ditambah: ");
            scanf("%d", &jmlInput);
            for (int i = 0; i < jmlInput; i++)
            {
                printf("Data ke-%d\n", i + 1);
                printf("Masukkan nama mahasiswa: ");
                scanf("%s", mahasiswa.nama);
                printf("Masukkan NIM mahasiswa (1-100): ");
                scanf("%d", &mahasiswa.NIM);
                printf("Masukkan IPK mahasiswa: ");
                scanf("%lf", &mahasiswa.IPK);
                if (mahasiswa.NIM > 100)
                {
                    printf("NIM yang Anda masukkan salah! Data tidak dapat ditambahkan.\n\n");
                    main();
                }

                struct Mahasiswa blank;
                fseek(fPtr, (mahasiswa.NIM - 1) * sizeof(struct Mahasiswa), SEEK_SET);
                fread(&blank, sizeof(struct Mahasiswa), 1, fPtr);
                if (blank.NIM != 0)
                {
                    printf("Data mahasiswa dengam NIM %d sudah ada. Data tidak dapat ditambahkan\n\n", mahasiswa.NIM);
                    main();
                }
                fseek(fPtr, (mahasiswa.NIM - 1) * sizeof(struct Mahasiswa), SEEK_SET);
                fwrite(&mahasiswa, sizeof(struct Mahasiswa), 1, fPtr);
            }
            printf("Data berhasil ditambahkan!\n\n");
            fclose(fPtr);
        }
        else
        {
            printf("Data tidak dapat ditambahkan.\n\n");
        }
    }
    fclose(fPtr);
}

void updateDataRand()
{
    FILE *fPtr = fopen("mahasiswa.dat", "rb+");
    int nim;
    if (fPtr != NULL)
    {
        printf("Masukkan NIM data mahasiswa yang ingin di-update: ");
        scanf("%d", &nim);
        fseek(fPtr, (nim - 1) * sizeof(struct Mahasiswa), SEEK_SET);
        fread(&mahasiswa, sizeof(struct Mahasiswa), 1, fPtr);
        if (mahasiswa.NIM == 0)
        {
            printf("Data mahasiswa dengan NIM %d belum ditambahkan! Data tidak dapat di update.\n\n", mahasiswa.NIM);
            main();
        }
        printf("%-16s%-11s%-11s\n", "NAMA", "NIM", "IPK");
        printf("%-16s%-11d%-11.2f\n", mahasiswa.nama, mahasiswa.NIM, mahasiswa.IPK);
        fseek(fPtr, (nim - 1) * sizeof(struct Mahasiswa), SEEK_SET);
        struct Mahasiswa mahasiswa = {"", 0, 0};
        fwrite(&mahasiswa, sizeof(struct Mahasiswa), 1, fPtr);
        printf("\n");
        printf("Masukkan nama mahasiswa yang baru: ");
        scanf("%s", mahasiswa.nama);
        printf("Masukkan NIM mahasiswa yang baru (1-100): ");
        scanf("%d", &mahasiswa.NIM);
        printf("Masukkan IPK mahasiswa yang baru: ");
        scanf("%lf", &mahasiswa.IPK);
        struct Mahasiswa blank;
        fseek(fPtr, (mahasiswa.NIM - 1) * sizeof(struct Mahasiswa), SEEK_SET);
        fread(&blank, sizeof(struct Mahasiswa), 1, fPtr);
        if (blank.NIM != 0)
        {
            printf("Data mahasiswa dengam NIM %d sudah ada. Data tidak dapat ditambahkan\n\n", mahasiswa.NIM);
            main();
        }
        fseek(fPtr, (mahasiswa.NIM - 1) * sizeof(struct Mahasiswa), SEEK_SET);
        fwrite(&mahasiswa, sizeof(struct Mahasiswa), 1, fPtr);
        printf("Data berhasil di update!\n\n");
        fclose(fPtr);
    }
    else
    {
        printf("File tidak dapat dibuka.\n\n");
    }
    fclose(fPtr);
}

void lihatDataRand()
{
    FILE *fPtr = fopen("mahasiswa.dat", "rb");
    if (fPtr != NULL)
    {
        printf("%-16s%-11s%-11s\n", "NAMA", "NIM", "IPK");
        rewind(fPtr);
        while (!feof(fPtr))
        {
            fread(&mahasiswa, sizeof(struct Mahasiswa), 1, fPtr);
            if (mahasiswa.NIM != 0)
            {
                printf("%-16s%-11d%-11.2f\n", mahasiswa.nama, mahasiswa.NIM, mahasiswa.IPK);
            }
            else
            {
                continue;
            }
        }
        printf("\n");
        fclose(fPtr);
    }
    else
    {
        printf("File tidak dapat dibuka.\n\n");
    }
    fclose(fPtr);
}

void hapusDataRand()
{
    FILE *fPtr = fopen("mahasiswa.dat", "rb+");
    if (fPtr != NULL)
    {
        int nim;
        printf("Masukkan NIM data mahasiswa yang akan dihapus (1-100): ");
        scanf("%d", &nim);
        fseek(fPtr, (nim - 1) * sizeof(struct Mahasiswa), SEEK_SET);
        struct Mahasiswa blank = {"", 0, 0};
        fwrite(&blank, sizeof(struct Mahasiswa), 1, fPtr);
        printf("Data berhasil dihapus!\n");
        fclose(fPtr);
    }
    else
    {
        printf("File tidak dapat dibuka.\n\n");
    }
}

void pindahDataRand()
{
    FILE *fPtr = fopen("mahasiswa.dat", "r");
    rewind(fPtr);
    if (fPtr != NULL)
    {
        FILE *fPtr2 = fopen("mahasiswaFromDat.txt", "w");
        if (fPtr2 != NULL)
        {
            fprintf(fPtr2, "%-16s%-11s%-11s\n", "NAMA", "NIM", "IPK");
            while (!feof(fPtr))
            {
                fread(&mahasiswa, sizeof(struct Mahasiswa), 1, fPtr);
                if (mahasiswa.NIM != 0)
                {
                    fprintf(fPtr2, "%-16s%-11d%-11.2f\n", mahasiswa.nama, mahasiswa.NIM, mahasiswa.IPK);
                }
                else
                {
                    continue;
                }
            }
            printf("File berhasil dipindahkan!\n\n");
            fclose(fPtr);
            fclose(fPtr2);
        }
        else
        {
            printf("File tidak dapat dipindahkan.\n\n");
        }
    }
    else
    {
        printf("File tidak dapat dibuka.\n\n");
    }
}

void tambahDataSeq()
{
    FILE *fPtr = fopen("mahasiswa.txt", "r");
    rewind(fPtr);
    if (fPtr == NULL)
    {
        fPtr = fopen("mahasiswa.txt", "w");
        if (fPtr != NULL)
        {
            int jmlInput;
            printf("Masukkan jumlah data yang akan ditambah: ");
            scanf("%d", &jmlInput);
            fprintf(fPtr, "%-16s%-11s%-11s\n", "NAMA", "NIM", "IPK");
            for (int i = 0; i < jmlInput; i++)
            {
                printf("Data ke-%d\n", i + 1);
                printf("Masukkan nama mahasiswa: ");
                scanf("%s", mahasiswa.nama);
                printf("Masukkan NIM mahasiswa (1-100): ");
                scanf("%d", &mahasiswa.NIM);
                printf("Masukkan IPK mahasiswa: ");
                scanf("%lf", &mahasiswa.IPK);

                fprintf(fPtr, "%-16s%-11d%-11.2f\n", mahasiswa.nama, mahasiswa.NIM, mahasiswa.IPK);
            }
            printf("Data berhasil ditambahkan!\n\n");
        }
        else
        {
            printf("File tidak dapat dibuka.\n\n");
        }
    }
    else
    {
        fPtr = fopen("mahasiswa.txt", "a+");
        if (fPtr != NULL)
        {
            int jmlInput;
            printf("Masukkan jumlah data yang akan ditambah: ");
            scanf("%d", &jmlInput);
            for (int i = 0; i < jmlInput; i++)
            {
                printf("Data ke-%d\n", i + 1);
                printf("Masukkan nama mahasiswa: ");
                scanf("%s", mahasiswa.nama);
                printf("Masukkan NIM mahasiswa (1-100): ");
                scanf("%d", &mahasiswa.NIM);
                printf("Masukkan IPK mahasiswa: ");
                scanf("%lf", &mahasiswa.IPK);

                fprintf(fPtr, "%-16s%-11d%-11.2f\n", mahasiswa.nama, mahasiswa.NIM, mahasiswa.IPK);
            }
            printf("Data berhasil ditambahkan!\n\n");
            fclose(fPtr);
        }
        else
        {
            printf("File tidak dapat dibuka.\n\n");
        }
    }
    fclose(fPtr);
}

void lihatDataSeq()
{
    FILE *fPtr = fopen("mahasiswa.txt", "r");
    rewind(fPtr);
    if (fPtr != NULL)
    {
        char line[250];
        fgets(line, 250, fPtr);
        while (!feof(fPtr))
        {
            if (strcmp(line, " ") == 0)
            {
                continue;
            }
            printf("%s", line);
            fgets(line, 250, fPtr);
        }
        fclose(fPtr);
        printf("\n");
    }
    else
    {
        printf("File tidak dapat dibuka");
    }
    fclose(fPtr);
}

void hapusDataSeq()
{
    FILE *fPtr = fopen("mahasiswa.txt", "a+");
    rewind(fPtr);
    if (fPtr != NULL)
    {
        int NIM;
        printf("Masukkan NIM data mahasiswa yang akan dihapus (1-100): ");
        scanf("%d", &NIM);
        rewind(fPtr);
        FILE *fPtr2 = fopen("mahasiswa1.txt", "w");
        if (fPtr2 != NULL)
        {
            char nama[100], nim[50], ipk[10];
            fscanf(fPtr, "%s %s %s", nama, nim, ipk);
            fprintf(fPtr2, "%-16s%-11s%-11s\n", nama, nim, ipk);
            fscanf(fPtr, "%s %d %lf", mahasiswa.nama, &mahasiswa.NIM, &mahasiswa.IPK);
            while (!feof(fPtr))
            {
                if (mahasiswa.NIM != NIM)
                {
                    fprintf(fPtr2, "%-16s%-11d%-11.2f\n", mahasiswa.nama, mahasiswa.NIM, mahasiswa.IPK);
                    fscanf(fPtr, "%s %d %lf", mahasiswa.nama, &mahasiswa.NIM, &mahasiswa.IPK);
                }
                else
                {
                    fscanf(fPtr, "%s %d %lf", mahasiswa.nama, &mahasiswa.NIM, &mahasiswa.IPK);
                    continue;
                }
            }
            fclose(fPtr);
            fclose(fPtr2);
            remove("mahasiswa.txt");
            rename("mahasiswa1.txt", "mahasiswa.txt");
            printf("Data berhasil dihapus!\n\n");
            fPtr = fopen("mahasiswa.txt", "r+");
        }
        else
        {
            printf("File tidak dapat dibuka\n\n");
        }
    }
    else
    {
        printf("File tidak dapat dibuka\n\n");
    }
}

void pindahDataSeq()
{
    FILE *fPtr = fopen("mahasiswa.txt", "r");
    FILE *fPtr2;
    rewind(fPtr);
    if (fPtr != NULL)
    {
        fPtr2 = fopen("mahasiswaFromTxt.dat", "wb");
        if (fPtr2 != NULL)
        {
            char nama[100], nim[50], ipk[10];
            fscanf(fPtr, "%s %s %s", nama, nim, ipk);
            fscanf(fPtr, "%s %d %lf", mahasiswa.nama, &mahasiswa.NIM, &mahasiswa.IPK);
            while (!feof(fPtr))
            {
                fwrite(&mahasiswa, sizeof(struct Mahasiswa), 1, fPtr2);
                fscanf(fPtr, "%s %d %lf", mahasiswa.nama, &mahasiswa.NIM, &mahasiswa.IPK);
            }
            printf("Data berhasil dipindahkan!\n\n");
            fclose(fPtr);
            fclose(fPtr2);
        }
        else
        {
            printf("Data tidak dapat dipindahkan.\n\n");
        }
    }
    else
    {
        printf("File tidak dapat dibuka\n\n");
    }
}