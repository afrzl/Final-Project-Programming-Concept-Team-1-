#include<stdio.h>
#define p(a,b) a##b
#define call(x) #x
int main(){
    do{
         int i=15,j=3;
         printf("%d",p(i-+,+j));
    }
    while(*(call(625)+3));
    return 0;
}
