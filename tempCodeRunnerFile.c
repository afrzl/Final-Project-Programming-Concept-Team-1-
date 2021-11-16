#include <stdio.h>

int hitung(int *nilai4, int *nilai5)
{
    *nilai4 = *nilai5;
}

int main()
{
    int nilai1 = 10;
    int nilai2 = 20;
    int nilai3;
    
    int * const nilai 4 = &nilai1;
    int * nilai 5 = &nilai3;
    int nilai6 = nilai3;

    hitung(&nilai4, &nilai5);

    *nilai4 = 15;
    nilai4 = &nilai2;
}