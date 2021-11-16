#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n, m;
    char pixel[10000], *result = "#Black&White";
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < n*m; i++)
    {
        scanf(" %c", &pixel[i]);
    }

    for (int i = 0; i < n*m; i++)
    {
        if (pixel[i] == 'C' || pixel[i] == 'M' || pixel[i] == 'Y')
        {
            result = "#Color";
            break;
        }
    }
    printf("%s", result);
    return 0;
}
