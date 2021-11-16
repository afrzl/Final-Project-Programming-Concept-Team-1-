#include<stdio.h>
int main(){
    int i=5,j;
    j=++i+++i+++i;
    printf("%d %d",i,j);
    return 0;
}
