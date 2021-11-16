#include <stdio.h>

int main(void)
{
    char s[] = "No akun";
    char t[] = "Nama pemilik akun";
    char u[] = "Saldo awal";
    char v[] = "Daftar transaksi";
    char w[] = "Saldo akhir";
    char x = ':';
    double a = 2380000.78;
    double b = -17000.398;
    double c = -100299.7280;

    printf("%-20s%c%30d\n%-20s%c%30s\n%-20s%c%+30.2f\n%-20s%c\n\n%45.2f\n%45.2f\n%48s\n%45.2f\n\n%-20s%c%+30.2f",
           s, x, 1234567890,
           t, x, "Maharani Jayanti",
           u, x, a,
           v, x,
           b,
           c,
           "------------ +",
           b + c,
           w, x, a + b + c);
}