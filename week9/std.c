#include<stdio.h>

int n,k;
int alive[100005];
int alive_cnt;

int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        alive[i] = 1;
    }
    alive_cnt = n;

    int cnt = 0;
    int idx = 1;
    while(alive_cnt != 1){
        if(alive[idx]){
            cnt ++;
            if(cnt == k){
                // printf("%d was killed\n", idx);
                alive[idx] = 0;
                alive_cnt --;
                cnt = 0;
            }
        }
        idx ++;
        if(idx > n) idx -= n;
    }

    for(int i=1;i<=n;i++){
        if(alive[i]){
            printf("%d", i);
        }
    }
}