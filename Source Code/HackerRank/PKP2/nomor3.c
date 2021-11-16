#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    long int a[10000], b[10000], c[10000], n[10000];

    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%ld", &a[i]);
        scanf("%ld", &b[i]);
        scanf("%ld", &c[i]);
        scanf("%ld", &n[i]);
    }

    for (int i = 0; i < t; i++)
    {
        int max = a[i];
        if (b[i] > max)
        {
            max = b[i];
        }
        if (c[i] > max)
        {
            max = c[i];
        }
        
        int sum = (max-a[i]) + (max-b[i]) + (max-c[i]);

        if (sum == n[i])
        {
            printf("YES");
        } else
        {
            printf("NO");
        }
        printf("\n");
    }
    return 0;
}
