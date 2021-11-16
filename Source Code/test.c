#include <stdio.h>
#include <string.h>

int main() {
    char semangat[] = "Tetap semangat!!!! Dijaga terus kekkompakannyaa!!!! GODBLESS <3";
    int kamu[] = {53, 54, 52, 54, 1, 21, 17, 39, 1, 25, 35, 29, 11, 27, 16};
    int pasti = 15;
    int bisa = 0;

    for ( bisa = 0; bisa < 26; bisa++)
    {
        semangat[2 * bisa] = bisa + 65;
        semangat[2* bisa + 1] = bisa + 97;
    }
    for ( bisa = 0; bisa <= 10; bisa++)
    {
        semangat[62 - bisa] = 58 - bisa;
    }
    for ( bisa = pasti - 1; bisa >= 0; bisa--)
    {
        printf("%c", semangat[kamu[bisa]]);
    }
    printf("\n");

    return 0;
    
    
    
}