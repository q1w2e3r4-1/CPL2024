#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int n;
int a[105] = {0};
int cnt[1000005] = {0};

int main(){
    srand(time(0));
    // printf("%d", rand());
    n = 10;

    for(int i=1;i<=n;i++){
        a[i] = i;
    }

    for(int i=1;i<=100000;i++){
        int x = rand() % n + 1;
        int y = rand() % n + 1;

        int tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
    }

    for(int i=1;i<=n;i++){
        printf("%d ", a[i]);
    }
}