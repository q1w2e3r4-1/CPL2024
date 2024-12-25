#include<stdio.h>

int a[10000000];

int main(){
    memset(a, -1, sizeof(a));
    // for(int i=0;i<10000000;i++) a[i] = -1;

    long long sum = 0;
    for(int i=0;i<10000000;i++){
        sum += a[i];
    }
    printf("%lld", sum);
}