/*
NAMA        : MUH. NUR AFRIZAL
NIM         : M0521046
PRODI       : INFORMATIKA
MATA KULIAH : KONSEP PEMROGRAMAN
KELAS       : B
*/

/*
Tugas Praktikum 3: Array (Project-based)
*/


//include library-library yang dibutuhkan
#include <stdio.h>
#include <stdlib.h>
//end include library

//declare function dan variable yang digunakan di dalam program
int about(), inputMatriks1(), inputMatriks2(), penjumlahan(), pengurangan(), perkalian(), determinan(), transpose();
int matriks1[2][2], matriks2[2][2];
//end

//fungsi main, yaitu fungsi yang akan dijalankan pertama kali pada saat program ini dijalankan
int main()
{
    char menu; //declare variabel yang dibutuhkan

    // Mencetak menu dengan printf
    printf("\n===== Tugas Praktikum 3: Array (Project-based) =====");
    printf("\n===== PROGRAM OPERASI MATRIKS =====");
    printf("\n===== SILAHKAN PILIH OPERASI DIBAWAH =====\n\n");
    printf("[A] Penjumlahan\n");
    printf("[B] Pengurangan\n");
    printf("[C] Perkalian\n");
    printf("[D] Determinan\n");
    printf("[E] Transpose\n");
    printf("[X] Untuk keluar dari program\n");
    // End cetak tulisan

    //Menginput menu yang telah disediakan
    printf("Silahkan Masukkan Salah Satu Menu Diatas : ");
    scanf("%c", &menu);
    //End input

    //melakukan perintah sesuai dengan menu yang diinputkan user dengan percabangan
    if (menu == 'A' || menu == 'a') //jika user menginputkan character 'A' atau 'a'
    {
        inputMatriks2(); //fungsi inputMatriks2 akan dijalankan
        penjumlahan(matriks1, matriks2); //fungsi penjumlahan akan dijalankan
    }
    else if (menu == 'B' || menu == 'b') //jika user menginputkan character 'B' atau 'b'
    {
        inputMatriks2(); //fungsi inputMatriks2 akan dijalankan
        pengurangan(matriks1, matriks2); //fungsi pengurangan akan dijalankan
    }
    else if (menu == 'C' || menu == 'c') //jika user menginputkan character 'C' atau 'c'
    {
        inputMatriks2(); //fungsi inputMatriks2 akan dijalankan
        perkalian(matriks1, matriks2); //fungsi perkalian akan dijalankan
    }
    else if (menu == 'D' || menu == 'd') //jika user menginputkan character 'C' atau 'c'
    {
        inputMatriks1(); //fungsi inputMatriks1 akan dijalankan
        determinan(matriks1); //fungsi determinan akan dijalankan
    }
    else if (menu == 'E' || menu == 'e') //jika user menginputkan character 'C' atau 'c'
    {
        inputMatriks1(); //fungsi inputMatriks1 akan dijalankan
        transpose(matriks1); //fungsi transpose akan dijalankan
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

//fungsi untuk menginput matriks berordo 2x2 sebanyak 1 buah
int inputMatriks1()
{
    printf("Masukkan nilai matriks 2x2 dibawah ini: \n");
    for (int i = 0; i < 2; i++) //melakukan perulangan untuk baris
    {
        for (int j = 0; j < 2; j++) //melakukan perulangan untuk kolom
        {
            scanf("%d", &matriks1[i][j]); //user menginput sebuah angka yang akan menjadi matriks [i][j]
        }
    }
}
//end fungsi menginput matriks berordo 2x2 sebanyak 1 buah

//fungsi untuk menginput matriks berordo 2x2 sebanyak 2 buah
int inputMatriks2()
{
    printf("Masukkan nilai 2 matriks 2x2 dibawah ini: \n");
    printf("Matriks 1: \n"); 
    for (int i = 0; i < 2; i++) //user menginput matriks 2x2 yang pertama
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &matriks1[i][j]);
        }
    }
    printf("Matriks 2: \n"); 
    for (int i = 0; i < 2; i++) //user menginput matriks 2x2 yang kedua
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &matriks2[i][j]);
        }
    }
}
//end fungsi menginput matriks berordo 2x2 sebanyak 2 buah

//fungsi untuk menjumlahkan matriks pertama dan kedua yang telah diinputkan
int penjumlahan(int matriks1[2][2], int matriks2[2][2]) //matriks1 dan matriks2 dijadikan parameter karena untuk operasi penjumlahan membutuhkan 2 matriks.
{
    /*
        Dikarenakan pada operasi penjumlahan matriks adalah seperti ini :
        _    _       _   _       _             _
       |      |     |     |     |               |
       | a  b |  +  | e f |  =  | a + e   b + f |
       | c  d |     | g h |     | c + e   c + g |
       |_    _|     |_   _|     |_             _|
        
        maka untuk penjumlahan matriks akan menjumlahkan matriks1 dengan index [i][j] dengan matriks2 berindex sama.
    */
    int hasil[2][2]; //declare variabel untuk matriks ordo 2x2 yang akan menampung hasilnya
    printf("\nHasil: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            hasil[i][j] = matriks1[i][j] + matriks2[i][j]; //menjumlahkan matriks pertama dan kedua yang mempunyai index yang sama
            printf("%d\t", hasil[i][j]); //mengoutput matriks hasil penjumlahan yang berindex [i][j]
        }
        printf("\n"); //jika index kolom matriks sudah sampai kolom ke-2 maka akan berganti baris
    }
}
//end fungsi penjumlahan matriks

//fungsi untuk mengurangkan matriks pertama dan kedua yang telah diinputkan
int pengurangan(int matriks1[2][2], int matriks2[2][2]) //matriks1 dan matriks2 dijadikan parameter karena untuk operasi pengurangan membutuhkan 2 matriks.
{
    /*
        Dikarenakan pada operasi pengurangan matriks adalah seperti ini :
        _    _       _   _       _             _
       |      |     |     |     |               |
       | a  b |  -  | e f |  =  | a - e   b - f |
       | c  d |     | g h |     | c - e   c - g |
       |_    _|     |_   _|     |_             _|
        
        maka untuk pengurangan matriks akan mengurangkan matriks1 dengan index [i][j] dengan matriks2 berindex sama.
    */
    int hasil[2][2]; //declare variabel untuk matriks ordo 2x2 yang akan menampung hasilnya
    printf("\nHasil: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            hasil[i][j] = matriks1[i][j] - matriks2[i][j]; //mengurangkan matriks pertama dan kedua yang mempunyai index yang sama
            printf("%d\t", hasil[i][j]); //mengoutput matriks hasil pengurangan yang berindex [i][j]
        }
        printf("\n"); //jika index kolom matriks sudah sampai kolom ke-2 maka akan berganti baris
    }
}
//end fungsi penjumlahan matriks

//fungsi untuk mengalikan matriks pertama dan kedua yang telah diinputkan
int perkalian(int matriks1[2][2], int matriks2[2][2]) //matriks1 dan matriks2 dijadikan parameter karena untuk operasi perkalian membutuhkan 2 matriks.
{
    /*
        Dikarenakan pada operasi perkalian matriks adalah seperti ini :
        _    _       _   _       _                     _
       |      |     |     |     |                       |
       | a  b |  .  | e f |  =  | a.e + b.g   a.f + b.h |
       | c  d |     | g h |     | c.e + d.g   c.d + d.h |
       |_    _|     |_   _|     |_                     _|
        
        maka untuk perkalian matriks membutuhkan suatu variabel yang menampung jumlah dari perkalian antar index seperti a.e + b.g, dan akan direset ketika variabel tersebut digunakan untuk menjumlahkan index yang lainnya.
    */

    int hasil[2][2], jumlah = 0; //declare variabel hasil untuk matriks ordo 2x2 yang akan menampung hasilnya, dan variabel jumlah untuk menampung hasil penjumlahan dari perkalian antar index matriks
    printf("\nHasil: \n");
    for (int i = 0; i < 2; i++) //melakukan perulangan untuk kolom
    {
        for (int j = 0; j < 2; j++) //melakukan perulangan untuk baris
        {
            for (int k = 0; k < 2; k++) //melakukan perulangan sampai 2 dikarenakan matriks yang kedua mempunyai 2 baris
            {
                jumlah += matriks1[i][k] * matriks2[k][j]; //mengalikan matriks1 dengan index [i][k] dengan matriks2 berindex [k][j] lalu hasilnya dijumlahkan dengan variabel jumlah sebelumnya
            }
            hasil[i][j] = jumlah; //matriks hasil dengan index[i][j] merupakan jumlah dari perkalian yang telah dilakukan sebelumnya
            printf("%d\t", hasil[i][j]);
            jumlah = 0; //variabel jumlah direset kembali untuk melakukan penghitungan index setelahnya
        }
        printf("\n");
    }
}
//fungsi untuk mengalikan matriks pertama dan kedua yang telah diinputkan

//fungsi untuk mencari determinan suatu matriks
int determinan(int matriks1[2][2]) //matriks1 dijadikan parameter karena untuk mencari determinan hanya membutuhkan 1 buah matriks
{
    /*
        Dikarenakan untuk mencari determinan sebuah matriks berordo 2x2 adalah seperti ini :

       |      |  
       | a  b |  = (a.d) - (b.c)
       | c  d |  
       |      |  
        
        maka untuk menghitung determinannya menjadi :
        (matriks1[0][0] * matriks1[1][1]) - (matriks1[0][1] * matriks1[1][0]);
    */
    int hasil = (matriks1[0][0] * matriks1[1][1]) - (matriks1[0][1] * matriks1[1][0]);
    printf("\nDeterminan matriks adalah: %d\n", hasil);
}
//end fungsi determinan

//fungsi untuk mentranspose matriks
int transpose(int matriks1[2][2]) //matriks1 dijadikan parameter dikarenakan hanya membutuhkan 1 matriks saja
{
    /*
        Dikarenakan untuk melakukan transpose pada matriks 2x2 adalah seperti ini :
        _    _       _   _ 
       |      |     |     |
       | a  b |  =  | a c |
       | c  d |     | b d |
       |_    _|     |_   _|
        
        maka fungsi ini akan merubah index matriks [i][j] menjadi [j][i]
    */
    int hasil[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            hasil[j][i] = matriks1[i][j]; //matriks [j][i] akan sama dengan matriks1[i][j]
        }
    }
    //array hasil akan ditampilkan di layar
    printf("\nHasil: \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\t", hasil[i][j]);
        }
        printf("\n");
    }
}
//end fungsi transpose matriks

/*
TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI
COPYRIGHT: MUH. NUR AFRIZAL
*/