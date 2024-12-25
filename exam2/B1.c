#include<stdio.h>
#define int long long
int n,R,m,target;
int d[1000005];

int check(int bar){
    int cnt = 0, sum = 0;
    for(int i=1;i<=n;i++){
        if(d[i] >= R) continue;
        if(d[i] <= bar) continue;
        cnt ++;
        sum += d[i] - bar;
    }

    if(cnt < m) return 0;
    if(sum < target) return 0;
    return 1;
}

signed main(){
    scanf("%d %d %d %d", &n, &R, &m, &target);
    for(int i=1;i<=n;i++) scanf("%d", &d[i]);  

    int l = 0, r = R-1;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }

    if(!check(l)){
        printf("-1");
    }
    else{
        printf("%d", l);
    }
}