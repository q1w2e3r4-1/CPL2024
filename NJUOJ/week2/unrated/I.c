#include<stdio.h>

int n;
int is_prime[50000005];

int main(){
    scanf("%d", &n);
    for(int i=2;i<=n;i++){
        is_prime[i] = 1;
    }

    for(int i=2;i<=n;i++){
        for(int j=i*2;j<=n;j+=i){
            is_prime[j] = 0;
        }
    }

    int cnt = 0;
    for(int i=2;i<=n;i++){
        if(is_prime[i]) cnt ++;
    }
    printf("%d", cnt);
}