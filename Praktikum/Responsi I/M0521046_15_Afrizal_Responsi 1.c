#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Account {
    char *username;
    char *password;
};

char username[256], password[256];
int id_produk[256] = {12345, 23456};
char produk[100][256] = {"Es Kopi Susu", "Caffe Latte"};
int harga[256] = {16000, 18000};
int diskon[256] = {10, 5};
int jumlah_barang = 2;

int login(), dashboard_admin(char *username), list_produk(), penjualan(), tambah_barang();
int main()
{
    char title[] = "SELAMAT DATANG DI APLIKASI KASIR RESTAURANT X";
    for (int i = 0; i < strlen(title); i++)
    {
        printf("=");
    }
    printf("\n%s\n", title);
    for (int i = 0; i < strlen(title); i++)
    {
        printf("=");
    }
    printf("\n\n");
    login();
}

int login()
{
    struct Account admin, kasir;
    admin.username = "admin";
    admin.password = "pwadmin";

    kasir.username = "kasir";
    kasir.password = "pwkasir";

    printf("Masukkan username (X untuk exit) : ");
    scanf("%s", &username);
    if (!strcmp(username, "X") || !strcmp(username, "x"))
    {
        exit(EXIT_SUCCESS);
    }
    
    printf("Masukkan password : ");
    scanf("%s", &password);

    if (!strcmp(username, admin.username) && !strcmp(password, admin.password))
    {
        system("cls");
        dashboard_admin(username);
    } else if (!strcmp(username, kasir.username) && !strcmp(password, kasir.password))
    {
        system("cls");
        penjualan();
    } else
    {
        system("cls");
        printf("USERNAME ATAU PASSWORD SALAH!\n\n");
        main();
    }
}

int dashboard_admin(char *username)
{
    char menu;
    printf(">>>>>> SELAMAT DATANG %s <<<<<<", username);

    printf("\n\nMenu: \n [A] Daftar Produk \n [B] Penjualan\n [X] Logout\n\n");
    printf("Silahkan masukkan salah satu menu diatas : ");
    scanf("%c", &menu);
    switch (menu)
    {
    case 'A':
    case 'a':
        system("cls");
        list_produk();
        break;
    case 'B':
    case 'b':
        system("cls");
        penjualan();
        break;
    case 'X':
    case 'x':
        system("cls");
        main();
        break;

    default:
        system("cls");
        dashboard_admin(username);
        break;
    }
}

int list_produk()
{
    char menu;

    char title[] = " DAFTAR PRODUK RESTAURANT X";
    printf(" ");
    for (int i = 0; i < strlen(title); i++)
    {
        printf("=");
    }
    printf("\n%s\n ", title);
    for (int i = 0; i < strlen(title); i++)
    {
        printf("=");
    }
    printf("\n\n");

    printf("  ");
    for (int i = 0; i < 91; i++)
    {
        printf("-");
    }
    printf("\n");
    printf (" | %-10s | %-50s | %-10s | %-10s |\n", "Id Produk", "Nama Produk", "Harga", "Diskon");
    printf(" |");
    for (int i = 0; i < 91; i++)
    {
        printf("-");
    }
    printf("|\n");
    for (int i = 0; i < jumlah_barang; i++)
    {
        printf (" | %-10d | %-50s | %10d | %8d %% |\n", id_produk[i], produk[i], harga[i], diskon[i]);
    }
    printf(" |");
    for (int i = 0; i < 91; i++)
    {
        printf("_");
    }
    printf("|\n");

    printf(" Menampilkan total %d barang\n\n", jumlah_barang);
    printf(" Apakah anda akan menambahkan barang? (Y untuk ya / X untuk keluar) : ");
    scanf("%c", &menu);
    switch (menu)
    {
    case 'Y':
    case 'y':
        system("cls");
        tambah_barang();
        list_produk();
        break;
    case 'X':
    case 'x':
        system("cls");
        dashboard_admin(username);
        break;

    default:
        system("cls");
        list_produk();
        break;
    }
}

int tambah_barang()
{
    char title[] = " FORM INPUT PRODUK";
    printf(" ");
    for (int i = 0; i < strlen(title); i++)
    {
        printf("=");
    }
    printf("\n%s\n ", title);
    for (int i = 0; i < strlen(title); i++)
    {
        printf("=");
    }
    printf("\n\n");
    printf("Masukkan ID Produk: ");
    scanf("%d", &id_produk[jumlah_barang]);
    printf("Masukkan Nama Produk: ");
    scanf("%s", &produk[jumlah_barang]);
    printf("Masukkan Harga: ");
    scanf("%d", &harga[jumlah_barang]);
    printf("Masukkan Diskon (%%): ");
    scanf("%d", &diskon[jumlah_barang]);
    for (int i = 0; i < jumlah_barang; i++)
    {
        if (id_produk[jumlah_barang] == id_produk[i])
        {
            system("cls");
            printf("ID Produk telah ada!\n\n");
            tambah_barang();
        }
    }
    jumlah_barang++;
    list_produk();
}

int penjualan()
{
    int order[100][3];
    char order_produk[100][256];
    int jumlah_order = 0;
    int bayar = 0, tot_diskon = 0, sum = 0;
    int uang_bayar, transaksi;

    for (;;)
    {
        if (bayar == 0)
        {
        char title2[] = " DAFTAR PRODUK RESTAURANT X";
        printf(" ");
        for (int i = 0; i < strlen(title2); i++)
        {
            printf("=");
        }
        printf("\n%s\n ", title2);
        for (int i = 0; i < strlen(title2); i++)
        {
            printf("=");
        }
        printf("\n\n");

        printf("  ");
        for (int i = 0; i < 91; i++)
        {
            printf("-");
        }
        printf("\n");
        printf (" | %-10s | %-50s | %-10s | %-10s |\n", "Id Produk", "Nama Produk", "Harga", "Diskon");
        printf(" |");
        for (int i = 0; i < 91; i++)
        {
            printf("-");
        }
        printf("|\n");
        for (int i = 0; i < jumlah_barang; i++)
        {
            printf (" | %-10d | %-50s | %10d | %8d %% |\n", id_produk[i], produk[i], harga[i], diskon[i]);
        }
        printf(" |");
        for (int i = 0; i < 91; i++)
        {
            printf("_");
        }
        printf("|\n");

        printf(" Menampilkan total %d barang\n\n", jumlah_barang);
        }
        

        char title[] = " FORM PENJUALAN";
        printf(" ");
        for (int i = 0; i < strlen(title); i++)
        {
            printf("=");
        }
        printf("\n%s\n ", title);
        for (int i = 0; i < strlen(title); i++)
        {
            printf("=");
        }
        printf("\n\n");

        printf("  ");
        for (int i = 0; i < 91; i++)
        {
            printf("-");
        }
        printf("\n");
        printf (" | %-10s | %-50s | %-10s | %-10s |\n", "Id Produk", "Nama Produk", "Pcs", "Harga");
        printf(" |");
        for (int i = 0; i < 91; i++)
        {
            printf("-");
        }
        printf("|\n");
        for (int i = 0; i < jumlah_order; i++)
        {
            printf (" | %-10d | %-50s | %10d | %10d |\n", order[i][0], order_produk[i], order[i][1], order[i][2]);
        }
        printf(" |");
        for (int i = 0; i < 91; i++)
        {
            printf("_");
        }
        printf("|\n");
        if (bayar == 0)
        {
            printf("Masukkan ID Produk untuk order (-1 untuk selesai) : ");
            scanf("%d", &order[jumlah_order][0]);
            if (order[jumlah_order][0] == -1)
            {
                bayar = 1;
                system("cls");
            } else
            {   
                printf("Masukkan jumlah pcs : ");
                scanf("%d", &order[jumlah_order][1]);

                for (int i = 0; i < jumlah_barang; i++)
                {
                    if (id_produk[i] == order[jumlah_order][0])
                    {
                        order[jumlah_order][2] = (harga[i] * (100 - diskon[i])/100) * order[jumlah_order][1];
                        tot_diskon += harga[i]*diskon[i]/100;
                        sum += order[jumlah_order][2];
                        strcpy(order_produk[jumlah_order], produk[i]);
                        jumlah_order++;
                        break;
                    }
                }
                system("cls");
            }
        } else
        {
            printf ("  %75s   | %-10d |\n", "| Total : ", sum);
            printf ("  %75s   | %-6d pcs |\n", "| Item  : ", jumlah_order);
            printf ("  %75s   | ", "| CASH  : ");
            scanf("%10d", &uang_bayar);
            if (uang_bayar >= sum)
            {
                printf ("  %75s   | %-10d |\n", "| Change :", uang_bayar-sum);
                printf ("  %75s___|_%-10s_|\n", "|_________", "__________");
                if (tot_diskon != 0)
                {
                    printf("Selamat! Anda telah mendapatkan diskon sebesar %d", tot_diskon);
                }
                printf("\n\nApakah anda akan bertransaksi lagi? (-1 untuk logout isi ANGKA bebas untuk bertransaksi lagi) : ");
                bayar = 0;
                scanf("%d", &transaksi);
                switch (transaksi)
                {
                case -1:
                    system("cls");
                    main();
                    break;
                
                default:
                    system("cls");
                    penjualan();
                    break;
                }
            }
        }
    }
}