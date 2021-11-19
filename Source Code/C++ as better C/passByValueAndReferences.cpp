#include <bits/stdc++.h>

using namespace std;

void fungsiA(int x);
void fungsiB(int &x);
int fungsiC(int x1 = 1, int x2 = 1, int x3 = 1);

int main()
{
    int x = 10;

    fungsiA(x);
    cout << "nilai x adalah :" << x << endl;

    fungsiB(x);
    cout << "nilai x adalah :" << x << endl;

    int a = 10, b = 20;
    cout << "Hasil perkalian :" << fungsiC(a, b) << endl;

}

void fungsiA(int x) //pass by value
{
    x = x * x;
}

void fungsiB(int &x) //pass by reference
{
    x = x * x;
}

int fungsiC(int x1, int x2, int x3)
{
    int hasilPerkalian = x1 * x2 * x3;
    return hasilPerkalian;
}