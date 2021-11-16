#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, modusCount = 0, hasilModus, x[1000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    hasilModus = x[0];

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (x[i] == x[j])
            {
                temp++;
            }
            if (temp > modusCount)
            {
                hasilModus = x[i];
                modusCount = temp;
            }
            else if (temp == modusCount && x[i] > hasilModus)
            {
                temp = modusCount;
                hasilModus = x[i];
            }
        }
    }
    printf("%d", hasilModus);
    
    return 0;
}
