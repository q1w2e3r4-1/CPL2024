#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int MAX = 32768;
int get_big_random(){
    int big = rand() - MAX / 2;
    int small = rand();
    return big * MAX + small;
}

const int MOD = 10;
int main(){
    srand(time(0));
    
    int a[6] = {0};
    for(int i=0;i<6;i++){
        a[i] = get_big_random();
    }

    a[0] = a[2] = a[4];
    for(int i=0;i<6;i++){
        printf("%d ", a[i]);
    }

    printf("\n");
}