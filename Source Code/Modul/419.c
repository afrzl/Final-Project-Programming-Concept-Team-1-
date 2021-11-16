#include <stdio.h>

int main()
{
    int product;
    double products[5] = {2.98, 4.50, 9.98, 4.49, 6.87};

    printf("Input product number: ");
    scanf("%d", &product);

    switch (product)
    {
    case 1:
        printf("$ %.2f", products[0]);
        break;

    case 2:
        printf("$ %.2f", products[1]);
        break;

    case 3:
        printf("$ %.2f", products[2]);
        break;

    case 4:
        printf("$ %.2f", products[3]);
        break;

    case 5:
        printf("$ %.2f", products[4]);
        break;

    default:
        printf("ANGKA SALAH!");
        break;
    }
}