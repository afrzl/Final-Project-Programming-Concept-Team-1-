/*
NAMA        : MUH. NUR AFRIZAL
NIM         : M0521046
PRODI       : INFORMATIKA
MATA KULIAH : KONSEP PEMROGRAMAN
KELAS       : B
*/

/*
Tugas Praktikum 5: Topik C Lanjutan - Struct dan Enum (Project-based)
Tugas Praktikum 5: Topik C Lanjutan - Struct dan Enum (Project-based)
Tugas Praktikum 5: Topik C Lanjutan - Struct dan Enum (Project-based)
*/

/* Include library-library yang dibutuhkan */
#include <stdio.h>
#include <string.h>
/* End include library */

// Prototype
typedef struct Tanggal_lahir
{
    unsigned tanggal;
    unsigned bulan;
    unsigned tahun;
} Tanggal_lahir;

typedef struct
{
    unsigned int id;
    char *username;
    char *nama_lengkap;
    char *pass;
    unsigned int role;
    struct Tanggal_lahir tgl_lhr;
} Accounts;
// End Prototype

// Input data dummy ke struct account
Accounts account[100] = {
    {0, "admin", "admin nama lengkap", "admin123", 1, 5, 6, 2003},
    {1, "admin2", "admin2 nama lengkap", "admin234", 1, 5, 11, 2009},
    {2, "kasir", "kasir nama lengkap", "kasir123", 2, 5, 6, 2003},
    {3, "kasir2", "kasir2 nama lengkap", "kasir123", 2, 5, 11, 2009},
};
// End input data dummy

// declare variabel dan fungsi yang akan digunakan secara universal
unsigned int countAccount = 4;

int login(), sudahLogin(const Accounts *user), convertMonth(const int *bulanAngka, char *bulanHuruf), listUser(const Accounts *user, const int role), signup(), resetPassword();
// end declare

//fungsi main, yaitu fungsi yang akan dijalankan pertama kali pada saat program ini dijalankan
int main()
{
    // prototype
    typedef enum
    {
        eLogin = 1,
        eSignup,
    } Menu;
    // end prototype

    unsigned int menu;
    for (;;) //menjalankan infinite looping
    {
        printf("\n========================================================================================================================\n");
        printf("%s%s%s%s%s",
               "\n===> Tugas Praktikum 5: Topik C Lanjutan - Struct dan Enum (Project-based) <===",
               "\n===> LOGIN APLIKASI <===\n\n",
               "[1] Login\n",
               "[2] Sign Up\n",
               "[0] Exit Program\n");
        printf(">>> Silahkan Masukkan Salah Satu Menu Diatas : ");
        scanf("%u", &menu); //meminta user menginputkan variabel menu
        //End input
        Menu eMenu = menu;
        if (eMenu == eLogin) //jika user menginputkan sesuai dengan eLogin
        {
            login(); //menjalankan function login
            break;
        }
        else if (eMenu == eSignup) //jika user menginputkan sesuai dengan eSignup
        {
            signup(); //menjalankan function signup
            break;
        }
        else if (eMenu == 0)
        {
            puts(">>> Program Keluar <<<"); //jika menu yang diinputkan == 0 maka program keluar
            break;
        }
        else //jika user menginputkan selain diatas akan menampilkan pesan
        {
            printf(">> Menu yang anda masukkan salah <<\n");
        }
    }
}
//end fungsi main

//function login
int login()
{
    printf("\n========================================================================================================================\n");
    char username[100], password[100];

    printf("%s", "\n\n>>> Form Login <<<\n");
    printf("%s", "\nMasukkan Username: ");
    scanf("%s", &username);
    printf("%s", "Masukkan Password: ");
    scanf("%s", &password);

    for (int i = 0; i < countAccount; i++) //melakukan looping sebanyak var countAccount
    {
        if (!strcmp(username, account[i].username) && !strcmp(password, account[i].pass)) //jika username dan password sesuai
        {
            sudahLogin(&account[i]); //function sudahLogin akan dijalankan dengan struct account ke i sebagai parameter
            break;
        }
        if (i == countAccount - 1) //jika i mencapai countAccount - 1 (kombinasi username dan atau password salah)
        {
            puts(">> Username/password salah <<");
            login(); //function login dijalankan kembali
            break;
        }
    }
}
// end function login()

// function sudahLogin dengan parameter struct dari account dengan index yang telah diinputkan pada form login
int sudahLogin(const Accounts *user)
{
    printf("\n========================================================================================================================\n");
    char month[100];
    convertMonth(&user->tgl_lhr.bulan, month); //function convertMonth dijalankan dengan parameter tgl_lhr dari struct account yang telah login dan char month yang telah dideclare sebelumnya

    //mencetak biodata dari account yang telah login
    printf(">>> Anda berhasil login dengan biodata sebagai berikut : <<<\n\n");
    printf("%s %s\n%s %s\n%s %d %s %d\n",
           "Username\t: ", user->username,
           "Nama Lengkap\t: ", user->nama_lengkap,
           "Tanggal Lahir\t: ", user->tgl_lhr.tanggal, month, user->tgl_lhr.tahun);

    // percabangan jika member role dari struct account bernilai 1 (admin) maka akan menjalankan function listUser, jika role 2 (kasir) maka akan melakukan pemilihan apakah akan mengganti password
    if (user->role == 1)
    {
        //melakukan pemilihan apakah user yg login dengan role kasir akan mengganti password atau tidak
        typedef enum
        {
            eAdmin = 1,
            eKasir,
            eUbahPass,
        } Menu;
        unsigned int menu;
        while (menu != 0)
        {
            printf("%s%s%s%s%s",
                   "\n>>>>> SETTING ADMIN <<<<<\n\n",
                   "[1] List Admin\n",
                   "[2] List Kasir\n",
                   "[3] Ubah Password\n",
                   "[0] Keluar\n");
            printf(">>> Silahkan Masukkan Salah Satu Menu Diatas : ");
            scanf("%u", &menu);
            Menu eMenu = menu;
            if (eMenu == eAdmin)
            {
                listUser(user, 1);
            }
            else if (eMenu == eKasir)
            {
                listUser(user, 2);
            }
            else if (eMenu == eUbahPass) //jika user memilih untuk mengubah password
            {
                char newPassword[100];
                //user menginput password baru
                printf(">> Masukkan password yang baru: ");
                scanf("%s", &newPassword);
                resetPassword(&user->id, &newPassword); //function resetPassword() dijalankan dengan id user dan password baru sebagai parameter
                login();
                break;
            }
            else if (eMenu > 3)
            {
                puts(">> Menu yang anda masukkan salah.");
            }
        }
    }
    else
    {
        //melakukan pemilihan apakah user yg login dengan role kasir akan mengganti password atau tidak
        typedef enum
        {
            eUbahPass = 1,
        } Menu;
        unsigned int menu;
        while (menu != 0)
        {
            printf("%s%s%s",
                   "\n>>>>> SETTING KASIR <<<<<\n\n",
                   "[1] Ubah Password\n",
                   "[0] Keluar\n");
            printf(">>> Silahkan Masukkan Salah Satu Menu Diatas : ");
            scanf("%u", &menu);
            Menu eMenu = menu;
            if (eMenu == eUbahPass) //jika user memilih untuk mengubah password
            {
                char newPassword[100];
                //user menginput password baru
                printf(">> Masukkan password yang baru: ");
                scanf("%s", &newPassword);
                resetPassword(&user->id, &newPassword); //function resetPassword() dijalankan dengan id user dan password baru sebagai parameter
                login();
                break;
            }
            else if (eMenu > 1)
            {
                puts(">> Menu yang anda masukkan salah.");
            }
        }
    }
    main();
}
//end function sudahLogin()

// function listUser dijalankan dengan id user dan role user sebagai parameter
int listUser(const Accounts *user, const int role)
{
    if (role == 1) //jika user memilih 1 (list admin) maka akan print seluruh data akun admin selain dirinya
    {
        int count = 1;
        for (int i = 0; i < countAccount; i++)
        {
            if (account[i].id == user->id || account[i].role != role)
            {
                continue;
            }
            printf("%d.\t%s\t\t:%d\n\t%s\t:%s\n\t%s\t:%s\n",
                   count, "Id", account[i].id,
                   "Username", account[i].username,
                   "Nama Lengkap", account[i].nama_lengkap);
            count++;
        }
    }
    else if (role == 2) //jika user memilih 2 (list kasir) maka akan print seluruh data akun kasir
    {
        int count = 1;
        for (int i = 0; i < countAccount; i++)
        {
            if (account[i].role != role)
            {
                continue;
            }
            printf("%d.\t%s\t\t:%d\n\t%s\t:%s\n\t%s\t:%s\n",
                   count, "Id", account[i].id,
                   "Username", account[i].username,
                   "Nama Lengkap", account[i].nama_lengkap);
            count++;
        }
    }
    //admin diberikan akses untuk mereset password admin atau kasir selain dirinya
    int id_reset;
    printf("%s", "Masukkan id yang akan direset password (-1 jika tidak ada): ");
    scanf("%d", &id_reset);
    if (id_reset != -1) //jika user menginput id yang telah ada di struct maka akan menjalankan function resetPassword()
    {
        for (int i = 0; i < countAccount; i++)
        {
            if (account[i].id == id_reset)
            {
                resetPassword(&id_reset, "password"); //function reset password dijalankan dengan id_reset dan string password sebagai parameter
                break;
            }
            if (i == countAccount - 1)
            {
                printf("Akun dengan id #%d tidak ditemukan\n",
                       id_reset);
                break;
            }
        }
    }
}
//end function listUser()

// function signUp()
int signup()
{
    printf("\n========================================================================================================================\n");
    char username[100], nama_lengkap[100], pass[100];
    unsigned int role, tgl, bln, thn;
    //user diminta untuk menginput username, password, nama lengkap, role (1/2), tanggal lahir
    printf("%s", "\n\n>>> Form Sign Up <<<\n");
    printf("%s", "Masukkan username: ");
    scanf("%s", &username);
    printf("%s", "Masukkan pasword: ");
    scanf("%s", &pass);
    printf("%s", "Masukkan nama lengkap: ");
    scanf(" %99[^\n]", &nama_lengkap);
    for (;;)
    {
        printf("%s", "Masukkan role (1 = admin, 2 = kasir): ");
        scanf("%u", &role);
        if (role == 1 || role == 2)
        {
            break;
        }
    }
    for (;;)
    {
        printf("%s", "Masukkan tanggal lahir: ");
        scanf("%u", &tgl);
        if (tgl <= 31)
        {
            break;
        }
    }
    for (;;)
    {
        printf("%s", "Masukkan bulan lahir: ");
        scanf("%u", &bln);
        if (bln <= 12)
        {
            break;
        }
    }
    printf("%s", "Masukkan tahun lahir: ");
    scanf("%u", &thn);
    //variabel-variabel yang telah diinputkan user sebelumnya dimasukkan ke dalam struct masing-masing field
    account[countAccount].id = countAccount;
    account[countAccount].username = username;
    account[countAccount].nama_lengkap = nama_lengkap;
    account[countAccount].pass = pass;
    account[countAccount].tgl_lhr.tanggal = tgl;
    account[countAccount].tgl_lhr.bulan = bln;
    account[countAccount].tgl_lhr.tahun = thn;
    if (role == 1)
    {
        account[countAccount].role = role;
    }
    else
    {
        account[countAccount].role = role;
    }
    countAccount++;
    login(); //function login akan dijalankan
}
//end function signUp()

//function resetPassword() dengan id_reset dan resetPassword sebagai parameter
int resetPassword(const int *id_reset, char *resetPassword)
{
    for (int i = 0; i < countAccount; i++) //melakukan looping sebanyak jumlah akun yang ada
    {
        if (account[i].id == *id_reset) //jika id sudah ditemukan maka akan mereplace account[i].pass dengan var resetPassword yang dijadikan parameter function
        {
            account[i].pass = resetPassword;
            printf("Akun dengan id #%d telah direset passwordnya menjadi %s\n",
                   *id_reset, resetPassword);
            break;
        }
    }
}
//end function resetPassword()

//function convertMonth dengan bulanAngka dan bulanHuruf sebagai parameter yang berfungsi untuk mengubah bulan yang sebelumnya int menjadi nama bulan tersebut
int convertMonth(const int *bulanAngka, char *bulanHuruf)
{
    //prototype enum nama bulan
    typedef enum
    {
        eJanuari = 1,
        eFebruari,
        eMaret,
        eApril,
        eMei,
        eJuni,
        eJuli,
        eAgustus,
        eSeptember,
        eOktober,
        eNovember,
        eDesember
    } Nama_bulan;

    Nama_bulan bulan = *bulanAngka;
    switch (bulan) //percabangan dengan kondisi angkaBulan yang dijadikan parameter sebelumnya
    {
    case eJanuari:
        strcpy(bulanHuruf, "Januari");
        break;
    case eFebruari:
        strcpy(bulanHuruf, "Februari");
        break;
    case eMaret:
        strcpy(bulanHuruf, "Maret");
        break;
    case eApril:
        strcpy(bulanHuruf, "April");
        break;
    case eMei:
        strcpy(bulanHuruf, "Mei");
        break;
    case eJuni:
        strcpy(bulanHuruf, "Juni");
        break;
    case eJuli:
        strcpy(bulanHuruf, "Juli");
        break;
    case eAgustus:
        strcpy(bulanHuruf, "Agustus");
        break;
    case eSeptember:
        strcpy(bulanHuruf, "September");
        break;
    case eOktober:
        strcpy(bulanHuruf, "Oktober");
        break;
    case eNovember:
        strcpy(bulanHuruf, "November");
        break;
    case eDesember:
        strcpy(bulanHuruf, "Desember");
        break;

    default:
        break;
    }
}
//end function convertMonth()

/*
TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI
COPYRIGHT: MUH. NUR AFRIZAL
*/