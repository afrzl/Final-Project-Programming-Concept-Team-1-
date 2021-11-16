/*
NAMA        : MUH. NUR AFRIZAL
NIM         : M0521046
PRODI       : INFORMATIKA
MATA KULIAH : KONSEP PEMROGRAMAN
KELAS       : B
*/

/*
Tugas Praktikum 4: Pointer (Project-based)
*/

/* Include library yang dibutuhkan */
#include <stdio.h>
/* End include library */

/* Declare function yang akan di load di program */
int sort(), mean(), median(), modus();
/* End declare */

/* Function main, function yang akan dijalankan pertama kali ketika program di load */
int main()
{
    /* declare variabel yang akan digunakan di program */
    int data[100], n, hasilModus, modusCount;
    float hasilMean, hasilMedian;
    char menu;
    /* End declare */

    /* Mencetak judul program di console */
    printf("\n===== Tugas Praktikum 4: Pointer (Project-based) =====");
    printf("\n===== PROGRAM MENGHITUNG MEAN, MEDIAN, MODUS =====");
    /* End cetak judul program */

    /* User diminta untuk menginput jumlah data yang akan dimasukkan beserta isi datanya */
    printf("\n\nMasukkan jumlah data terlebih dahulu (max 100): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Masukkan data ke-%d: ", i+1);
        scanf("%d", &data[i]);
    }
    /* End input data */

    /* function mean, sort, median, dan modus dijalankan */
    mean(&n, &data, &hasilMean);
    sort(&n, &data);
    median(&n, &data, &hasilMedian);
    modus(&n, &data, &hasilModus, &modusCount);
    /* End function run */
    
    /* Mencetak hasil dari function sort di console */
    printf("\n\nData terurut yaitu sebagai berikut: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
    /* End cetak hasil dari function sort */
    
    /* Mencetak hasil dari function mean, median, dan modus ke console */
    printf("\nMean dari data yang anda masukkan adalah %.2f\n", hasilMean);
    printf("Median dari data yang anda masukkan adalah %.1f\n", hasilMedian);
    printf("Modus dari data yang anda masukkan adalah %d sebanyak %d data\n", hasilModus, modusCount);
    /* End cetak hasil dari function mean, median, dan modus */
}
/* End function main */

/* Function sort yang berfungsi untuk mengurutkan data yang diinputkan dari terkecil ke terbesar */
int sort(const int *n, int *data)
{
    int temp; /* Declare variabel temp untuk tempat menampung nilai sementara */
    for (int i = 0; i < *n - 1; i++) /* Loop var i dari 0 ke n - 1 */
    {
        for (int j = 0; j < *n - 1; j++) /* Loop var j dari 0 ke n - 1 */
        {
            if (data[j] > data[j+1]) /* Jika data j lebih dari data j + 1 */
            {
                /* data[j] dan data[j+1] akan ditukar */
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}
/* End function */

/* Function mean */
int mean(int *n, int *data, float *hasilMean)
{
    int sum = 0; /* Declare var sum sebagai variabel untuk menampung jumlah dari semua data */
    /* Menghitung total dari semua data dengan looping */
    for (int i = 0; i < *n; i++)
    {
        sum += data[i];
    }
    /* End hitung total data */

    /* Menghitung mean dengan operasi penjumlahan data yang telah dilakukan sebelumnya lalu dibagi dengan jumlah data dan diubah ke type data float */
    *hasilMean = (float)sum / *n;
}
/* End function main */

/* Function median */
int median(int *n, int *data, float *hasilMedian)
{
    /*  
    Membuat percabangan :
    Jika jumlah data genap maka mediannya yaitu index data ke n/2-1 ditambahkan dengan index data ke n/2 lalu dibagi 2
    JIka jumlah data ganjil maka mediannya yaitu index data ke n/2
    */
    if (*n % 2 == 0)
    {
        *hasilMedian = (float)(data[*n/2-1] + data[*n/2]) / 2;
    } else
    {
        *hasilMedian = data[*n/2];
    }
    /* End if */
}
/* End function median */

/* Function modus */
int modus(int *n, int *data, int *hasilModus, int *modusCount)
{
    *hasilModus = data[0]; /* Mengisi var hasil modus awal dengan data[0] */
    *modusCount = 0; /* Mengisi var modusCount dengan nilai awal 0 */

    for (int i = 0; i < *n; i++) /* Looping var i dari 0  sampai n */
    {
        int temp = 0; /* Membuat var temp sebagai tempat untuk menampung sementara dengan nilai awal 0 */
        for (int j = 0; j < *n; j++) /* Looping var j dari 0 sampai n */
        {
            /* Jika data[i] sama dengan data[j] maka var temp akan ditambah 1 */
            if (data[i] == data[j])
            {
                temp++;
            }
            /* End */

            /* Jika var temp lebih dari var modusCount maka var hasilModus akan diganti dengan data[i] dan var modusCount akan diganti dengan var temp */
            if (temp > *modusCount)
            {
                *hasilModus = data[i];
                *modusCount = temp;
            }
            /* Sedangkan jika var temp sama dengan var modusCount dan data[i] lebih besar dari var hasilModus maka var temp akan diganti dengan var modusCount dan var hasilModus akan diganti dengan data[i] */
            else if (temp == *modusCount && data[i] > *hasilModus)
            {
                temp = *modusCount;
                *hasilModus = data[i];
            }
            /* End if */
        }
        /* End looping var j */
    }
    /* End looping var i */
}
/* End function modus */