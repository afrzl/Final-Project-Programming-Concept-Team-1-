#include <bits/stdc++.h>

using namespace std;

template <class T>
T fungsiTerbesar(T a, T b, T c)
{
    T angkaTerbesar = (a > b) ? a : b;
    angkaTerbesar = (angkaTerbesar < c) ? c : angkaTerbesar;
    return angkaTerbesar;
}

int main()
{
    int a = 10, b = 50, c = 25;
    cout << "Angka terbesar : " << fungsiTerbesar(a, b, c) << endl;
}