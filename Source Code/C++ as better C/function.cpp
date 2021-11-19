#include <iostream>

// using std::cout;
// using std::endl;
// using std::cin;

using namespace std;

    // TANPA FUNCTION

// int main()
// {
//     int bilangan1, bilangan2, jumlah;
//     cout << "Masukkan bilangan 1 = ";
//     cin >> bilangan1;
//     cout << "Masukkan bilangan 2 = ";
//     cin >> bilangan2;

//     jumlah = bilangan1 + bilangan2;
//     cout << "Jumlah = " << jumlah << endl;

// }

    // DENGAN FUNCTION
    
int fungsiPenjumlahan(int a, int b)
{
    return a+b;
}

int main()
{
    int bilangan1, bilangan2, jumlah;
    cout << "Masukkan bilangan 1 = ";
    cin >> bilangan1;
    cout << "Masukkan bilangan 2 = ";
    cin >> bilangan2;

    jumlah = fungsiPenjumlahan(bilangan1, bilangan2);
    cout << "Jumlah = " << jumlah << endl;

}