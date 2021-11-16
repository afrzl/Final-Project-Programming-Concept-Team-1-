#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    int x[100][100];

    scanf("%d", &m);
    scanf("%d", &n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &x[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m-1; j >= 0; j--)
        {
            printf("%d ", x[j][i]);
        }
        printf("\n");
    }
    return 0;
}
