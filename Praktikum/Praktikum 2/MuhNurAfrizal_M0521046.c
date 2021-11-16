/*
NAMA        : MUH. NUR AFRIZAL
NIM         : M0521046
PRODI       : INFORMATIKA
MATA KULIAH : KONSEP PEMROGRAMAN
KELAS       : B
*/

/*
WARNING!!!
PROGRAM INI HANYA BERJALAN DI PLATFORM WINDOWS
KARENA DIDALAMNYA BERISI PERINTAH YANG HANYA BISA DIJALANKAN DI PLATFORM WINDOWS
*/

//include library-library yang dibutuhkan
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//end include library

//declare function function yang digunakan di dalam program
int bulan(int), user_login(), login(int), daftar(), about(), captcha(int);
//end

//declare variabel yang akan digunakan
char nama_depan[255], nama_belakang[255], nim[10], tmp_lahir[255], bulan_lahir[255], lahir_lengkap[255];
int tgl_lahir, bln_lahir, thn_lahir, sudah_daftar;
//end

//fungsi main, yaitu fungsi yang akan dijalankan pertama kali pada saat program ini dijalankan
int main()
{
    char menu; //declare variabel yang dibutuhkan

    // Mencetak menu dengan printf
    printf("\n===== Tugas Praktikum 2: C Function (Project-based) =====\n\n");
    printf("[A] Daftar Akun\n");
    printf("[B] Login\n");
    printf("[C] Tentang Saya\n");
    printf("[X] Untuk keluar dari program\n");
    // End cetak tulisan

    //Menginput menu yang telah disediakan
    printf("Silahkan Masukkan Salah Satu Menu Diatas : ");
    scanf("%c", &menu);
    //End input

    //melakukan perintah sesuai dengan menu yang diinputkan user dengan percabangan
    if (menu == 'A' || menu == 'a') //jika user menginputkan character 'A' atau 'a'
    {
        daftar(); //fungsi daftar akan dijalankan
    }
    else if (menu == 'B' || menu == 'b') //jika user menginputkan character 'B' atau 'b'
    {
        login(3); //fungsi login akan dijalankan
    }
    else if (menu == 'C' || menu == 'c') //jika user menginputkan character 'C' atau 'c'
    {
        about(); //fungsi about akan dijalankan
    }
    else if (menu == 'X' || menu == 'x') //jika user menginputkan character 'X' atau 'x'
    {
        printf("Program Keluar");
        exit(EXIT_SUCCESS); //program akan keluar
    }
    else //jika user menginputkan character yang lain akan menampilkan pesan
    {
        printf("Menu yang anda masukkan salah\n");
    }
}
//end fungsi main

//fungsi untuk mengubah bulan ke- yang diinputkan menjadi nama bulan
int bulan(int bln)
{
    // dengan menggunakan switch maka akan memberikan percabangan tentang bulan yang diinput menjadi nama bulan
    switch (bln)
    {
    case 1:
        sprintf(bulan_lahir, "Januari");
        break;
    case 2:
        sprintf(bulan_lahir, "Februari");
        break;
    case 3:
        sprintf(bulan_lahir, "Maret");
        break;
    case 4:
        sprintf(bulan_lahir, "April");
        break;
    case 5:
        sprintf(bulan_lahir, "Mei");
        break;
    case 6:
        sprintf(bulan_lahir, "Juni");
        break;
    case 7:
        sprintf(bulan_lahir, "Juli");
        break;
    case 8:
        sprintf(bulan_lahir, "Agustus");
        break;
    case 9:
        sprintf(bulan_lahir, "September");
        break;
    case 10:
        sprintf(bulan_lahir, "Oktober");
        break;
    case 11:
        sprintf(bulan_lahir, "November");
        break;
    case 12:
        sprintf(bulan_lahir, "Desember");
        break;

    default:
        break;
    }
}
//end fungsi ubah bulan

//fungsi yang menampilkan data user ketika telah login
int user_login()
{
    char nama_lengkap[255], tanggal_lahir[255]; //declare variabel yang dibutuhkan
    //mulai mencetak data-data yang akan ditampilkan pada fungsi
    printf("\n\n=== Inilah Informasi Pribadi Anda: ===\n");
    printf("Nama Lengkap\t\t: %s %s\n", nama_depan, nama_belakang);
    printf("NIM\t\t\t: %s\n", nim);
    printf("Tempat, Tanggal Lahir\t: ");
    bulan(bln_lahir);                                                                     //memanggil fungsi bulan untuk mendapatkan nama bulan
    sprintf(lahir_lengkap, "%s, %d %s %d", tmp_lahir, tgl_lahir, bulan_lahir, thn_lahir); //memasukkan variabel tmp_lahir, tgl_lahir, bulan_lahir, dan thn_lahir ke dalam variabel lahir_lengkap
    printf("%s", lahir_lengkap);
    printf("\n\n--- Terimakasih Telah Menggunakan Program Ini. ---\n");
    printf("--- Program Keluar. ---\n");
    //end cetak
}
//end fungsi menampilkan data user ketika login

//fungsi untuk login setelah user mendaftar dengan nilai awal 3 untuk maksimal kesempatan login
int login(int x)
{
    char nim_login[8]; //declare variabel yang akan digunakan di fungsi ini
    if (sudah_daftar == 1)
    {
        printf("\n=== Login ===\n");

        printf("Silahkan masukkan NIM (case sensitive): ");
        scanf("%s", nim_login);
        // percabangan untuk kesempatan login user
        if (x > 1) //jika kesempatan user untuk login masih lebih dari 1 maka menjalankan perintah dibawah
        {
            //mencocokkan nim
            if (!strcmp(nim_login, nim)) //mencocokkan data yang diinput jika nim sama dengan nim yang didaftarkan maka akan me-run fungsi user_login
            {
                user_login(); //fungsi user login dijalankan
            }
            else //namun jika data yang diinputkan tidak cocok akan menampilkan percabangan lagi dibawah ini
            {
                //pengecekan kata
                if (strstr(nim_login, nim) != NULL) //jika terdapat kata yang sama pada nim yang diinputkan di login dengan nim yang diinput di daftar maka akan menampilkan pesan dibawah
                {
                    printf("NIM yang anda masukkan hampir benar. ");
                }
                else //jika tidak ada yang sama maka akan menampilkan pesan dibawah
                {
                    printf("NIM yang anda masukkan salah. ");
                }
                //end pengecekan data

                printf("Anda diberi kesempatan %d kali lagi.\n", x - 1);
                login(x - 1); //karena nim yang diinputkan salah maka akan me-run fungsi login kembali dengan kesempatan dikurangi 1
            }
            //end mencocokkan nim
        }
        else //jika kesempatan login user sudah habis maka akan menjalankan perintah seperti dibawah
        {
            printf("\nAnda sudah salah 3x, apakah anda robot?");
            captcha(3); //menjalankan function captcha
        }
    }
    else
    {
        printf("Anda belum mendaftar akun, silahkan mendaftar akun terlebih dahulu.\n\n");
        daftar();
    }
}
//end fungsi login

//fungsi captcha yang akan merandom angka 1-10;
int captcha(int x)
{
    if (x >= 1)
    {
        int angka1, angka2, hasil, hasil2; //declare variabel yang dibutuhkan
        printf("\nSebelum login silahkan verifikasi bahwa anda bukan robot.\n");
        //mengacak angka random dari 1 - 10
        srand((unsigned)time(NULL));
        angka1 = 1 + rand() % 10;
        angka2 = 1 + rand() % 10;
        //end acak angka
        hasil = angka1 + angka2; //jumlah benar untuk penjumlahan 2 angka random tadi
        printf("%d + %d = ", angka1, angka2);
        scanf("%d", &hasil2); //menanyakan kepada user hasil dari penjumlahan angka random
        if (hasil2 == hasil)  //jika hasil yang diinputkan user benar maka akan menuju ke form login kembali
        {
            login(3); //jika jawaban user benar maka akan diarahkan kembali ke fungsi login
        }
        else //jika jawaban user yang diinputkan salah
        {
            captcha(x - 1); //fungsi captcha akan dijalankan kembali dengan x = x-1
        }
    }
    else //jika kesempatan captcha sudah habis maka program akan mendeteksi robot dan program dikeluarkan
    {
        printf("Anda terdeteksi robot. Program keluar.");
        exit(EXIT_SUCCESS); //program akan keluar
    }
}

//fungsi daftar akun
int daftar()
{
    char daftar_lagi;
    if (sudah_daftar == 1) //jika user sudah pernah mendaftar akun, dibuktikan dengan variabel sudah_daftar berisi 1
    {
        printf("Anda sudah pernah mendaftar akun, apakah anda akan mendaftarkan akun lagi?\n");
        printf("Ketik Y/T :"); //akan ditanyakan apakah akan mendaftar kembali atau tidak
        scanf("%c", &daftar_lagi);
        if (daftar_lagi == 'Y') //jika user menjawab Y
        {
            sudah_daftar = 0; //variabel sudah_daftar akan direset kembali ke 0
            daftar();         //dan fungsi daftar akan dijalankan kembali
        }
        else if (daftar_lagi == 'T') //jika user menjawab T
        {
            login(3); //fungsi login akan dijalankan
        }
        else //jika user tidak menginput Y/T
        {
            printf("Menu yang anda masukkan salah");
            daftar(); //fungsi daftar dijalankan kembali
        }
    }

    //user menginputkan data-data yang diperlukan
    printf("\n=== Daftar Akun ===\n");
    printf("Masukkan nama depan: ");
    scanf(" %[^\n]", nama_depan);
    printf("Masukkan nama belakang: ");
    scanf(" %[^\n]", nama_belakang);
    printf("NIM: ");
    scanf("%s", nim);
    printf("Tempat Lahir: ");
    scanf("%s", tmp_lahir);
    for (;;) //melakukan perulangan untuk memastikan tanggal lahir yang diinputkan antara 1-31
    {
        printf("Tanggal Lahir (01-31): ");
        scanf("%d", &tgl_lahir);
        if (tgl_lahir >= 1 && tgl_lahir <= 31)
        {
            break;
        }
        else
        {
            printf("Tanggal lahir harus antara 1-31\n");
        }
    }
    for (;;) //melakukan perulangan untuk memastikan bulan lahir yang diinputkan antara 1-12
    {
        printf("Bulan Lahir (1-12): ");
        scanf("%d", &bln_lahir);
        if (bln_lahir >= 1 && bln_lahir <= 12)
        {
            break;
        }
        else
        {
            printf("Tanggal lahir harus antara 1-12\n");
        }
    }
    printf("Tahun Lahir (Ex: 2003): ");
    scanf("%d", &thn_lahir);
    //end input data
    system("cls"); //jika user sudah menginputkan data maka layar akan dibersihkan *NOTE: FUNGSI CLS HANYA BERLAKU DI WINDOWS, JIKA ANDA MENGGUNAKAN OS LAIN SILAHKAN GANTI LINE INI
    printf("\nAkun sudah berhasil dibuat. Silahkan login\n");
    sudah_daftar = 1; //memberi nilai ke variabel sudah_daftar menjadi 1 untuk memberi kode bahwa user sudah daftar akun
    login(3);         //menjalankan fungsi login dengan kesempatan login 3x
}
//end fungsi daftar akun

//fungsi untuk menampilkan data diri saya
int about()
{
    printf("\n==== Biodata Saya ====\n");
    printf("Nama\t: Muh. Nur Afrizal\n");
    printf("NIM\t: M0521046\n");
    printf("Prodi\t: Informatika\n");
    printf("Kelas\t: B\n");
}
//end fungsi menampilkan data diri

/*
TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI
COPYRIGHT: MUH. NUR AFRIZAL
*/