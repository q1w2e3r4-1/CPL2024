#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int max = -2e9;
    if(a > max){
        max = a;
    }
    if(b > max){
        max = b;
    }
    if(c > max){
        max = c;
    }
    printf("%d",max);
}