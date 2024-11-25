#include<stdio.h>

int is_prime(int x){
    if(x == 1) return 0;
    for(int i=2;i*i<=x;i++){
        if(x % i == 0) return 0;
    }
    return 1;
}

int rev(int x){
    int ret = 0;
    while(x){
        int t = x % 10;
        ret *= 10;
        ret += t;

        x /= 10;
    }
    return ret;
    // if(x == 1000) return 1;
    // if(x <= 9) return x;
    // else if(x <= 99){
    //     int shi = x / 10;
    //     int ge = x % 10;
    //     return ge * 10 + shi;
    // }
    // else{
    //     int ge = x % 10;
    //     int shi = x / 10 % 10;
    //     int bai = x % 100;
    //     return ge * 100 + shi * 10 + bai * 1;
    // }
}

int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x = i;
        int y = rev(x);
        if(is_prime(x) && is_prime(y)){
            ans ++;
            // printf("%d ", x);
        }
    }
    printf("%d", ans);
}