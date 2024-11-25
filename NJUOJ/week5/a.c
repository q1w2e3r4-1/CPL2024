#include<stdio.h>

int n,t;

int f(int a, int t){
    int ret = 0;
    for(int i=0;i<a;i++){
        ret *= 10;
        ret += t;
    }
    return ret;
}

int main(){
    scanf("%d %d", &n, &t);
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum += f(i,t);
    }

    printf("%d", sum);
}