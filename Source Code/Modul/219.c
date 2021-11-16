#include <stdio.h>

/* BUKU C How to Program. With an Introduction to C++
Hal 97. Nomor 2.19 */

int main()
{
    int x, y, z, sum, average, product, smallest, largest;
    printf("Enter three different integers: ");
    scanf("%d %d %d", &x, &y, &z);

    sum = x + y + z;
    average = sum / 3;
    product = x * y * z;
    smallest = x;
    if (y < smallest)
    {
        smallest = y;
        if (z < smallest)
        {
            smallest = z;
        }
    }
    largest = x;
    if (y > largest)
    {
        largest = y;
        if (z > largest)
        {
            largest = z;
        }
    }
    printf("\n===============");
    printf("\n\nEnter three different integers: %d %d %d\n", x, y, z);
    printf("Sum is %d\n", sum);
    printf("Average is %d\n", average);
    printf("Product is %d\n", product);
    printf("Smallest is %d\n", smallest);
    printf("Largest is %d\n", largest);
}