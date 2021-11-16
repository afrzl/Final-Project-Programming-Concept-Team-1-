// ex06_18.c
// What does this program do?
#include <stdio.h>
#define MAX 10
// function prototype
void functionName(const int b[], size_t startSubscript, size_t size);
// function main begins program execution
int main(void)
{
    // initialize p
    int p[MAX] = {5, 7, 2, 1, 0, 4, 3, 0, 6, 8};

    puts("Answer is:");
    functionName(p, 0, MAX);
    puts("");
} // end main

// What does this function do?
void functionName(const int b[], size_t startSubscript, size_t size)
{
    if (startSubscript < size)
    {
        functionName(b, startSubscript + 1, size);
        printf("%d ", b[startSubscript] * 5);
    } //end if

} // end function functionName