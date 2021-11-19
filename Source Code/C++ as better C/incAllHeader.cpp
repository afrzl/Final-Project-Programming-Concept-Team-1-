    // include satu satu
// #include <iostream>
// #include <cstdlib>
// #include <ctime>

    // include semua header sekaligus
#include <bits/stdc++.h>

using namespace std;

int fungsiPenjumlahan(int array[], int i);

int main()
{
    const int N = 10;
    int bilanganAcak[N];

    srand(time(NULL));

    for (int i = 1; i <= N; i++)
    {
        bilanganAcak[i-1] = 1 + rand() % 100;
        cout << "Bilangan acak ke-" << i << " = " << bilanganAcak[i-1] << endl;
    }

    cout << "Jumlah = " << fungsiPenjumlahan(bilanganAcak, N-1);
    return 0;
}

int fungsiPenjumlahan(int array[], int i)
{
    if (i <= 0)
        return 0;
    else return array[i] + fungsiPenjumlahan(array, i-1);
}