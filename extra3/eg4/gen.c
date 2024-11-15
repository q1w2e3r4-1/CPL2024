#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int MAX = 32768;
int get_big_random(){
    int high = rand() - MAX / 2;
    int low = rand();

    return high * MAX + low; 
}

const int MOD = 10;
int main(){
    srand(time(0));
    
    // int mx = 0, mn = 0;
    // for(int i=1;i<=100000;i++){
    //     int x = rand();
    //     if(x > mx) mx = x;
    //     if(x < mn) mn = x;
    // }
    // printf("%d %d\n",mx, mn);
    FILE* file = freopen("1.in", "w", stdout);
    for(int i=0;i<6;i++){
        printf("%d ", get_big_random() % MOD);
    }
    printf("\n");
}