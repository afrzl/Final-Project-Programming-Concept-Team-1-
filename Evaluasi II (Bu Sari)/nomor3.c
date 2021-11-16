#include <stdio.h>

int hitung(int *input1, int *input2, int *output)
{
    *input1 += 20;
    *input2 += 10;
    *output = *input1 * *input2;
}

int hitung2(int x, int y)
{
    return x * y;
}

int main(void)
{
    int output = 0, input1 = 10, input2 = 20;
    printf("input1:%d\n", input1);
    printf("input2:%d\n", input2);
    hitung(&input1, &input2, &output);
    printf("hasil perhitungan 1: %d\n", output);
    printf("input1:%d\n", input1);
    printf("input2:%d\n", input2);
    printf("hasil perhitungan 2: %d\n", hitung2(input1, input2));
}