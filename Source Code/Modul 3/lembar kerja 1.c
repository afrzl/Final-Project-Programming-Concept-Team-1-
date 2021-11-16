#include <stdio.h>

int main()
{
    int tertinggi;
    int andi = 75;
    int budi = 68;
    int arif = 78;
    int mira = 74;
    int ahmad = 65;
    if(andi > tertinggi) {
        tertinggi = andi;
    }
    if(budi > tertinggi) {
        tertinggi = budi;
    }
    if(arif > tertinggi) {
        tertinggi = arif;
    }
    if(mira > tertinggi) {
        tertinggi = mira;
    }
    if(ahmad > tertinggi) {
        tertinggi = ahmad;
    }
    printf("Nilai tertinggi yaitu %i", tertinggi);
}
