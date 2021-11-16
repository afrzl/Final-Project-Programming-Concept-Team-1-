#include <stdio.h>

int main()
{
    char menu;
    int tinggi, panjang;

    // Mencetak tulisan-tulisan dengan printf
    printf("===== Tugas Praktikum 1: Program Control (Project-based) =====\n\n");
    printf("[A] Biodata\n");
    printf("[B] Pengerjaan Tugas\n");
    // End cetak tulisan

    //Menginput menu yang telah disediakan
    printf("Silahkan Masukkan Salah Satu Menu Diatas (case sensitive, pilih A atau B) : ");
    scanf("%c", &menu);
    //End input

    switch (menu) //memilih percabangan menu dengan switch
    {
    case 'A': //jika user memilih 'A' maka akan menampilkan biodata dengan case
        printf("\n==== Biodata Saya ====\n");
        printf("Nama\t: Muh. Nur Afrizal\n");
        printf("NIM\t: M0521046\n");
        break; //break untuk menghentikan percabangan ketika sudah menampilkan biodata
    case 'B':  //jika user memilih 'B' maka akan menampilkan program yang dibuat
        printf("\nMasukkan tinggi anak panah (maksimal 100): ");
        scanf("%i", &tinggi); //user menginput tinggi anak panah yang akan dibuat
        printf("Masukkan panjang anak panah (maksimal 100): ");
        scanf("%i", &panjang); //user menginput panjang anak panah yang akan dibuat
        printf("\n == HASIL ==\n\n");

        for (int i = 1; i <= tinggi; i++) //melakukan perulangan untuk mencetak bintang pada bagian atas anak panah dengan for
        {
            if (i == tinggi) //jika i berada pada akhir for (bagian tengah anak panah) maka akan mencetak bintang sebanyak panjang anak panah
            {
                for (int j = 1; j <= 100; j++) //mencetak bintang sesuai dengan panjang yang diinputkan dengan for
                {
                    printf("*");
                    if (j == panjang)
                    {
                        break;
                    }
                }
            }
            else //jika i tidak berada di akhir (tengah anak panah) maka akan mencetak spasi ( ) sebanyak panjang anak panah
            {
                for (int j = 1; j <= 100; j++) //mencetak spasi sesuai dengan panjang yang diinputkan
                {
                    printf(" ");
                    if (j == panjang)
                    {
                        break;
                    }
                }
            }

            /* Mencetak panah bagian atas dengan perulangan (for)
            membuat for dengan inisiasi j = 1 terlebih dahulu lalu akan berhenti ketika j <= i sehingga program akan mencetak seperti setiga dibagian atas anak panah
            Contoh ketika i = 1 maka akan mencetak * sebanyak 1 kali, jika i = 2 maka akan mencetak * 2 kali, dst. */
            for (int j = 1; j <= 100; j++)
            {
                printf("*");
                if (j == i)
                {
                    break;
                }
            }
            printf("\n"); //enter ketika perulangan diatas selesai, dilanjutkan ke i selanjutnya
        }

        //Melakukan perulangan untuk mencetak anak panah bagian bawah
        for (int i = 1; i <= tinggi - 1; i++) //melakukan perulangan dari 1 hingga tinggi yang diinput - 1, karena pada bagian bawah tidak butuh * di tengah anak panah
        {
            for (int j = 1; j <= 100; j++) //mencetak spasi ( ) sebanyak panjang yang diinputkan agar space dibawah * di tengah kosong
            {
                printf(" ");
                if (j == panjang)
                {
                    break;
                }
            }

            /* Melakukan perulangan dari j = i sampai j <= tinggi untuk mencetak *
            Contoh, jika i = 1 dan tinggi yang diinputkan 4, maka akan mencetak * sebanyak 4 kali,
            jika i = 2 dan tinggi yang diinputkan 4, maka akan mencetak * sebanyak 3 kali karena dimulai dari 2 sampai 4
            dst.
            */
            for (int j = i; j <= 100; j++)
            {
                printf("*");
                if (j == tinggi - 1)
                {
                    break;
                }
            }
            printf("\n");
        }
        break; //break untuk menghentikan program anak panah jika user menginputkan B

    //default akan menampilkan kesalahan karena user tidak menginputkan 'A' atau 'B'
    default:
        printf("Menu yang anda masukkan salah!");
        break;
    }
}