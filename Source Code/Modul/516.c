#include <stdio.h>

int main()
{
    int x, y, segitiga;
    int side_x[segitiga], side_y[segitiga];
    int luas[segitiga];
    printf("Masukkan jumlah segitiga: ");
    scanf("%d", &segitiga);

    for (int i = 0; i < segitiga; i++)
    {
        printf("Masukkan sisi 1 segitiga %d: ", i + 1);
        scanf("%d", &x);
        printf("Masukkan sisi 2 segitiga %d: ", i + 1);
        scanf("%d", &y);

        side_x[i] = x;
        side_y[i] = y;

        luas[i] = luasSegitiga(x, y);
    }

    printf("\n\nNo.\tSide1\tSide2\tLuas\n");
    for (int i = 1; i <= segitiga; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i, side_x[i - 1], side_y[i - 1], luas[i - 1]);
    }
}

int luasSegitiga(int x, int y)
{
    int luas;
    luas = 0.5 * x * y;
    return luas;
}