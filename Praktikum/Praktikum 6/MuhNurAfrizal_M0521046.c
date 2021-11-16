/*
NAMA        : MUH. NUR AFRIZAL
NIM         : M0521046
PRODI       : INFORMATIKA
MATA KULIAH : KONSEP PEMROGRAMAN
KELAS       : B
*/

/*
Tugas Praktikum 6: File Processing (Project-based)
Tugas Praktikum 6: File Processing (Project-based)
Tugas Praktikum 6: File Processing (Project-based)
*/

/* Include library-library yang dibutuhkan */
#include <stdio.h>
#include <string.h>
/* End include library */

// Prototype
typedef struct dataMahasiswa
{
    unsigned int nim;
    char name[100];
    char prodi[50];
    double ipk;
} DataMahasiswa;
// End Prototype

//array of struct
DataMahasiswa mahasiswa[1000];

int count, alert = 0; //declare var count untuk menghitung jumlah data dan var alert untuk penanda alert save

// declare fungsi yang akan digunakan
unsigned int dataChoice(void), byteChoice(void);
void listRecord(), refreshStruct(), store();
int addRecord(), updateRecord(), deleteRecord();
int wait();
// end declare

//function main()
int main(void)
{
    unsigned int choice;
    char pause;
    refreshStruct();                     //function refreshStruct() dijalankan yang berguna untuk memngisi array of struct berdasarkan file
    while ((choice = dataChoice()) != 0) //pemilihan menu yang dijalankan ketika user mengetik menu
    {
        switch (choice)
        {
        case 1:
            listRecord();
            break;
        case 2:
            addRecord();
            break;
        case 3:
            updateRecord();
            break;
        case 4:
            deleteRecord();
            break;
        case 5:
            store();
            break;
        default:
            puts("Incorrect choice");
            break;
        }
        //user akan ditahan untuk melihat menu yang telah diinputkan, dan akan berlanjut lagi ketika user menginput apa saja
        scanf("%c", &pause);
        wait();
    }
    //jika alert bernilai 1 maka akan menjalankan peringatan bahwa perubahan data belum disimpan di file
    if (alert == 1)
    {
        unsigned int save;
        printf("Your data hasn't been saved, will you save it? (Press 1 to save) : ");
        scanf("%u", &save);
        if (save == 1)
        {
            store();
        }
    }
}
// end function main()

//function dataChoice() yaitu function yang berfungsi untuk menampilkan list menu dan meminta user menginputkan menu
unsigned int dataChoice(void)
{
    printf("\n========================================================================================================================\n");
    printf("%s",
           "\n===> Tugas Praktikum 6: File Processing (Project-based) <==="
           "\n===> Data Mahasiswa <===\n\n"
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
// end function dataChoice()

// function refreshStruct() yang digunakan untuk menarik data dari file binary ke struct
void refreshStruct()
{
    FILE *fPtr = fopen("mahasiswa.bin", "rb"); //pointer cFptr membuka file mahasiswa.bin dengan mode RB

    if (fPtr != NULL) //jika file tidak NULL (ditemukan)
    {
        for (int i = 0; !feof(fPtr); i++) //meloop sampai eof
        {
            DataMahasiswa client = {0, "", "", 0.0};                     //membuat var client dari struct dataMahasiswa
            int result = fread(&client, sizeof(DataMahasiswa), 1, fPtr); //membaca file binary dan dimasukkan ke dalam var client

            if (result != 0 && client.nim != 0) //jika result != 0 dan client.nim != (nim tidak kosong di file maupun di result)
            {
                //mengcopy data dari var client ke var mahasiswa dengan index ke i
                mahasiswa[i].nim = client.nim;
                strcpy(mahasiswa[i].name, client.name);
                strcpy(mahasiswa[i].prodi, client.prodi);
                mahasiswa[i].ipk = client.ipk;
                count++; //var count diincrement
            }
        }
    }
    fclose(fPtr); //menutup file
}
// end function refreshStruct()

// function store()
void store()
{
    FILE *fPtr = fopen("mahasiswa.bin", "wb"); //pointer cFptr membuka file mahasiswa.bin dengan mode WB
    if (fPtr != NULL)                          //jika file tidak NULL (ditemukan)
    {
        fwrite(mahasiswa, sizeof(DataMahasiswa), count, fPtr); //menulis struct DataMahasiswa ke dalam file
    }
    else //jika file bermasalah
    {
        puts("Something went wrong.");
    }
    fclose(fPtr); //menutup file
    printf("Your data has been saved in file!\n");
    alert = 0; //alert dikembalikan ke 0 karena file sudah disimpan
}
// end function store()

// function listRecord()
void listRecord()
{
    printf("%-10s%-50s%-30s%-10s\n",
           "NIM", "Nama", "Prodi", "IPK");
    for (int i = 0; i < count; i++) //loop sampai var count
    {
        //mengeprint mahasiswa index ke i ke console setiap kali loop
        printf("%-10d%-50s%-30s%-10.2lf\n", mahasiswa[i].nim, mahasiswa[i].name, mahasiswa[i].prodi, mahasiswa[i].ipk);
    }
}
//end function listRecord()

// function addRecord()
int addRecord()
{
    unsigned int nim;
    printf("%s", "Masukkan NIM (1 - 100): ");
    scanf("%d", &nim); //user menginput nim

    for (int i = 0; i < count; i++) //loop sampai dengan count
    {
        if (nim == mahasiswa[i].nim) //jika nim yang diinputkan sama dengan nim mahasiswa index ke i
        {
            printf("NIM %d already exist.\n", nim);
            return 0; //mereturn 0
        }
    }
    //jika nim belum ada maka user menginput data-data dan dimasukkan ke mahasiswa index count (data terakhir)
    printf("%s", "Masukkan nama: ");
    scanf("%100s", mahasiswa[count].name);
    printf("%s", "Masukkan prodi: ");
    scanf("%50s", mahasiswa[count].prodi);
    printf("%s", "Masukkan ipk: ");
    scanf("%lf", &mahasiswa[count].ipk);

    mahasiswa[count].nim = nim;
    printf("NIM %d has been saved.\n", nim);

    count++;   //count diincrement
    alert = 1; //value alert menjadi 1 karena ada data yg belum disimpan di file
    return 0;
}
// end function addRecord()

// function deleteRecord()
int deleteRecord()
{
    listRecord();
    unsigned int nim;
    printf("%s", "Masukkan NIM yang akan dihapus: ");
    scanf("%d", &nim);              //user menginput nim yang akan dihapus
    for (int i = 0; i < count; i++) //loop sampai count
    {
        if (nim == mahasiswa[i].nim) //jika nim sama dengan nim mahasiswa index ke i
        {
            count--;                        //count akan didecrement
            for (int j = i; j < count; j++) //looping sampai count
            {
                mahasiswa[j] = mahasiswa[j + 1]; //swab data mahasiswa index ke j dengan mahasiswa index ke j+1
            }
            printf("Mahasiswa NIM %d has been deleted.\n", nim);
            alert = 1; //alert dirubah menjadi 1 karena ada data yang belum disimpan ke file
            return 0;  //return 0
        }
    }
    printf("NIM %d doesn't exist!\n", nim); //jika setelah looping tidak ditemukan nim yang cocok maka akan mengeprint NIM doesn't exist
    return 0;
}
// end function deleteRecord()

// function updateRecord()
int updateRecord()
{
    listRecord();
    unsigned int nim;
    printf("%s", "Enter NIM to be change: ");
    scanf("%d", &nim);              //user menginput nim yang akan diubah
    for (int i = 0; i < count; i++) //loop sampai count
    {
        if (nim == mahasiswa[i].nim) //jika nim sama dengan nim mahasiswa index ke i
        {
            //user menginput data-data yang akan dirubah dan akan mereplace var mahasiswa index ke i
            printf("%s", "Masukkan nama: ");
            scanf("%100s", mahasiswa[i].name);
            printf("%s", "Masukkan prodi: ");
            scanf("%50s", mahasiswa[i].prodi);
            printf("%s", "Masukkan ipk: ");
            scanf("%lf", &mahasiswa[i].ipk);

            printf("NIM %d has been changed!\n", nim);
            alert = 1; //alert dirubah menjadi 1 karena ada data yang belum disimpan ke file
            return 0;  //mereturn 0
        }
    }
    printf("NIM %d doesn't exist!\n", nim); //jika setelah looping tidak ditemukan nim yang cocok maka akan mengeprint NIM doesn't exist
    return 0;
}
// end function updateRecord()

// function wait() yang digunakan untuk pause looping dan melanjutkan setelah user menginputkan sesuatu
int wait()
{
    char c;
    scanf("%c", &c);
    return 0;
}
//end function wait()

/*
TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI
COPYRIGHT: MUH. NUR AFRIZAL
*/