#include<stdio.h>        
int main(){
    int a=2;
    a=a++ + ~++a;
    printf("%d",a);
    return 0;
}
