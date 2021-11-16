#include <stdio.h>

int main()
{
    double celcius, fahrenheit;
    printf("Celcius \t Fahrenheit\n");
    for (int i = 30; i <= 50; i++)
    {
        fahrenheit = 1.8;
        printf("%d\t%d\n", i, fahrenheit * i);
    }
}