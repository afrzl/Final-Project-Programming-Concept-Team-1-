#include <stdio.h>

int main()
{
    int count, sum = 0;
    printf("Jumlah angka: ");
    scanf("%d", &count);

    int angka[count];
    for (int i = 0; i < count; i++)
    {
        printf("Masukkan angka ke-%d: ", i + 1);
        scanf("%d", &angka[i]);
        sum += angka[i];
    }
    printf("\n\nPenjumlahan dari bilangan diatas yaitu %d", sum);
    printf("\nRata-rata dari bilangan diatas yaitu %d", sum / count);
}